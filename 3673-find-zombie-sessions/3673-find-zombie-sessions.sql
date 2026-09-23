# Write your MySQL query statement bels
select session_id, user_id , 
timestampdiff(minute, min(event_timestamp) ,max(event_timestamp)) as session_duration_minutes, 
sum(case
    when event_type = 'scroll' then 1
    else 0
    end 
) as scroll_count
from app_events 
group by session_id, user_id 
having session_duration_minutes >= 30 and 
round(sum(
    case 
        when event_type = 'click' then 1 
        else 0
    end
) / coalesce(scroll_count, 0), 2) < 0.20 and
sum(
    case 
        when event_type = 'purchase' then 1
        else 0
    end
) = 0
and scroll_count >= 5
order by scroll_count desc;
