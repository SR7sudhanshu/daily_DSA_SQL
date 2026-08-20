# Write your MySQL query statement below
with cte as (
    select distinct c.visited_on as dates
    from Customer c
    where (
        select count(distinct d.visited_on) from Customer d
        where d.visited_on <= c.visited_on
    ) >= 7
)
select cte.dates as visited_on, sum(b.amount) as amount, round(sum(b.amount)/7, 2) as average_amount
from cte join Customer as b
on cte.dates >= b.visited_on
where datediff(cte.dates, b.visited_on) < 7
group by cte.dates
order by cte.dates asc;