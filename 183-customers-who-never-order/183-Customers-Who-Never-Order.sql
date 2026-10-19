# Write your MySQL query statement below
SELECT c.name AS Customers 
FROM 
    Customers c 
    LEFT JOIN 
    (SELECT DISTINCT customerId FROM Orders) o
ON
c.id=o.customerId
WHERE customerId IS NULL