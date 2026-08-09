# Write your MySQL query statement below
select e.employee_id from 
Employees e left join Employees a 
    on e.manager_id = a.employee_id
where e.manager_id is not NULL and a.employee_id is NULL and e.salary < 30000
order by e.employee_id;