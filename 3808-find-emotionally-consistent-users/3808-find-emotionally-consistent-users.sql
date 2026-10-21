# Write your MySQL query statement below
with a as (
    select user_id, count(distinct content_id) as total_rec
    from reactions 
    group by user_id
),
b as (
    select user_id, reaction , count(*) as rec_count,
    dense_rank() over (partition by user_id order by count(*) desc) as ranking
    from reactions 
    group by user_id, reaction
)
select a.user_id,reaction as dominant_reaction , round(rec_count / total_rec, 2) as reaction_ratio
from a join b 
on a.user_id = b.user_id and b.ranking = 1 and a.total_rec >= 5
where round(rec_count/ total_rec, 2) >= 0.60
order by reaction_ratio desc, user_id asc;