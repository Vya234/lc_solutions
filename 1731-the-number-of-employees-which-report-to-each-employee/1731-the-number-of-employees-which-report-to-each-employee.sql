# Write your MySQL query statement below
SELECT e.employee_id, e.name, COUNT(t.reports_to) as reports_count, ROUND(AVG(t.age)) as average_age 
FROM Employees e
JOIN Employees t
ON t.reports_to=e.employee_id
GROUP BY e.employee_id, e.name
ORDER BY e.employee_id