# Write your MySQL query statement below
SELECT T.unique_id , S.name
FROM Employees S
LEFT JOIN EmployeeUNI T
ON S.id=T.id

