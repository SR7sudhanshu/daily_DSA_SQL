
with vd as (
select user_id,action_date
from activity
group by user_id,action_date
having count(*)=1
),
a as (
select user_id,action,count(*) as streak_length,min(action_date) as start_date,max(action_date) as end_date
from activity
where (user_id,action_date) in (
select user_id,action_date from vd
)
group by user_id,action
having datediff(max(action_date),min(action_date))+1=count(*)
),
b as (
select *,dense_rank() over (
partition by user_id
order by streak_length desc,action asc
) as ranking
from a
)
select user_id,action,streak_length,start_date,end_date
from b
where ranking=1 and streak_length>=5
order by streak_length desc,user_id asc;
