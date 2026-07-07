# Write your MySQL query statement below
SELECT s.user_id, ROUND(
    (CASE WHEN COUNT(c.action)=0 THEN 0 ELSE AVG(c.action='confirmed') END),2)  as confirmation_rate
FROM Signups s
LEFT JOIN Confirmations c
ON s.user_id=c.user_id
GROUP BY s.user_id;