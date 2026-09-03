# Write your MySQL query statement below
with a as (
    select name, salary,departmentId, 
    dense_rank() over (partition by departmentId order by salary desc) as ranking
    from Employee
)
select d.name as Department, a.name as Employee , a.salary as Salary
from a join Department d 
on a.departmentId = d.id 
where a.ranking <= 3;
