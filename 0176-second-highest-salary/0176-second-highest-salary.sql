# Write your MySQL query statement below
/*
SELECT max(salary) as SecondHighestSalary
FROM Employee
WHERE salary < (
    SELECT max(salary) 
    FROM Employee
)
*/
SELECT (
    SELECT DISTINCT salary FROM Employee ORDER BY salary DESC LIMIT 1 OFFSET 1 
    ) 
as SecondHighestSalary
