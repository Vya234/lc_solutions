# Write your MySQL query statement below
SELECT ROUND(AVG(
    CASE
        WHEN DATEDIFF(d.order_date,d.customer_pref_delivery_date)=0 THEN 1
        ELSE 0
    END
)*100,2) as immediate_percentage
FROM Delivery d
JOIN (
    SELECT customer_id,min(order_date) as order_date
    FROM Delivery
    GROUP BY customer_id
) as t
ON d.customer_id=t.customer_id AND d.order_date=t.order_date
