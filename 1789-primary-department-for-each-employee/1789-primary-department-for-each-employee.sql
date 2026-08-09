# Write your MySQL query statement below
select e.employee_id, avg(case when d.department_id is null then e.department_id
else d.department_id end) as department_id
from Employee e left join Employee d
on e.employee_id = d.employee_id and d.primary_flag = 'Y'
group by e.employee_id