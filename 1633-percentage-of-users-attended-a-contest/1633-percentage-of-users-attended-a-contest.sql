WITH totalusers AS (
    SELECT COUNT(*) AS total
    FROM Users
)
SELECT
    contest_id,
    ROUND(COUNT(user_id) * 100.0 / totalusers.total, 2) AS percentage
FROM Register
CROSS JOIN totalusers
GROUP BY contest_id
ORDER BY percentage DESC, contest_id ASC;