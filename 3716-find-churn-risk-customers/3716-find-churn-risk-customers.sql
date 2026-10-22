with a as (
    select
        user_id,
        min(event_date) as s,
        max(event_date) as e,
        max(monthly_amount) as m,
        sum(case when event_type = 'downgrade' then 1 else 0 end) as d_sum,
        sum(case when event_type = 'cancel' then 1 else 0 end) as c_count
    from subscription_events
    group by user_id
),
b as (
    select
        user_id,
        plan_name as current_plan,
        monthly_amount as curr_amount,
        row_number() over (
            partition by user_id
            order by event_date desc
        ) as rn
    from subscription_events
    where user_id in (select user_id from a where d_sum >= 1 and c_count < 1)
),
c as (
    select
        a.user_id,
        b.current_plan,
        b.curr_amount as current_monthly_amount,
        a.m as max_historical_amount,
        datediff(a.e, a.s) as days_as_subscriber,
        round(b.curr_amount * 100.0 / nullif(a.m, 0), 2) as g
    from a
    join b on a.user_id = b.user_id
    where b.rn = 1
)
select
    user_id,
    current_plan,
    current_monthly_amount,
    max_historical_amount,
    days_as_subscriber
from c
where days_as_subscriber >= 60
  and g < 50 and current_plan <> 'null'
order by days_as_subscriber desc, user_id asc;