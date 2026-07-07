# Write your MySQL query statement below
SELECT p.product_id, ROUND(IFNULL(SUM(p.price*u.units)/SUM(u.units),0),2) as average_price
FROM Prices p
LEFT JOIN UnitsSold u
ON p.product_id=u.product_id AND DATEDIFF(p.end_date,u.purchase_date)>=0 AND DATEDIFF(u.purchase_date,p.start_date)>=0
GROUP BY p.product_id