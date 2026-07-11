# Write your MySQL query statement below
SELECT user_id, name, mail
FROM Users
WHERE BINARY RIGHT(mail, 13) = '@leetcode.com'
  AND LEFT(mail, LENGTH(mail) - 13)
      REGEXP '^[A-Za-z][A-Za-z0-9_.-]*$';