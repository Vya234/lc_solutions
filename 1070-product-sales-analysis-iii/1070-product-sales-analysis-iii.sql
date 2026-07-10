# Write your MySQL query statement below
SELECT S.product_id, S.year AS first_year, S.quantity, S.price
FROM Sales S
JOIN (
    SELECT product_id, MIN(year) AS year
    FROM Sales
    GROUP BY product_id
) T
ON  S.product_id=T.product_id AND S.year=T.year