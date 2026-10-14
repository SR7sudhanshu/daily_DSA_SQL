WITH input AS (
SELECT id,visit_date,people,
lag(people,1) over(order by visit_date) as prev1,
lag(people,2) over(order by visit_date) as prev2,
lead(people,1) over (order by visit_date) as next1,
lead(people,2) over (order by visit_date) as next2,
lag(id,1) over(order by visit_date) as previd1,
lag(id,2) over(order by visit_date) as previd2,
lead(id,1) over (order by visit_date) as nextid1,
lead(id,2) over (order by visit_date) as nextid2
FROM stadium
)

SELECT id,visit_date,people
from input
WHERE (people>=100 and prev1>=100 and prev2>=100 and previd1=id-1 and previd2=id-2)
OR (people>=100 and next1>=100 and next2>=100 and nextid1=id+1 and nextid2=id+2)
OR (people>=100 and prev1>=100 and next1>=100 and previd1=id-1 and nextid1=id+1)
ORDER BY visit_date;