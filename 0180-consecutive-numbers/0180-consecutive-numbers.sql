# Write your MySQL query statement below
SELECT DISTINCT L1.num as ConsecutiveNums
From Logs L1
JOIN Logs L2
    ON L1.num=L2.num 
    AND L1.id+1=L2.id
JOIN Logs L3
    ON L2.num=L3.num 
    AND L2.id+1=L3.id
