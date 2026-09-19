# Write your MySQL query statement below
select num from MyNumbers 
group by num
having count(*) = 1
union 
(select distinct (case when num is not null then null end) as num from 
MyNumbers)
order by num desc
limit 1;