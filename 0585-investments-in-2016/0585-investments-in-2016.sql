# Write your MySQL query statement below
with a as (
    select tiv_2015 from Insurance 
    group by tiv_2015
    having count(*) >= 2
),
b as (
    select lat, lon from Insurance
    group by lat, lon
    having count(*) = 1
)
select round(sum(tiv_2016),2) as tiv_2016 from Insurance 
where tiv_2015 IN (select tiv_2015 from a) and (lat, lon) IN (select lat, lon from b);