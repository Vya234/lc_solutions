# Write your MySQL query statement below
SELECT MAX(num) as num
FROM ( SELECT num AS num
    FROM MyNumbers
    GROUP BY num
    HAVING count(num)=1 
    ) as unique_nums