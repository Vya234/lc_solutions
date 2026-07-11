# Write your MySQL query statement below
DELETE p
FROM Person p
JOIN Person s
    ON p.id>s.id
    AND p.email=s.email 


