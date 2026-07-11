# Write your MySQL query statement below
SELECT e.employee_id
FROM Employees e
LEFT JOIN Employees t
ON e.manager_id=t.employee_id
WHERE e.salary<30000 AND t.employee_id is NULL AND e.manager_id is NOT NULL
ORDER BY e.employee_id
