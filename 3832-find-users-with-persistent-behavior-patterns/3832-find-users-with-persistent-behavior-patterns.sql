WITH vd AS (
    SELECT user_id, action_date
    FROM activity
    GROUP BY user_id, action_date
    HAVING COUNT(*) = 1
),
a AS (
    SELECT
        user_id,
        action,
        COUNT(*) AS streak_length,
        MIN(action_date) AS start_date,
        MAX(action_date) AS end_date
    FROM activity
    WHERE (user_id, action_date) IN (
        SELECT user_id, action_date
        FROM vd
    )
    GROUP BY user_id, action
    HAVING DATEDIFF(MAX(action_date), MIN(action_date)) + 1 = COUNT(*)
),
b AS (
    SELECT *,
        DENSE_RANK() OVER (
            PARTITION BY user_id
            ORDER BY streak_length DESC, action ASC
        ) AS ranking
    FROM a
)
SELECT user_id, action, streak_length, start_date, end_date
FROM b
WHERE ranking = 1 and streak_length >= 5
ORDER BY streak_length DESC, user_id ASC;