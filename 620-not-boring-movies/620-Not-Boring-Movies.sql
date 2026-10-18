# Write your MySQL query statement below
SELECT * FROM Cinema WHERE id%2!=0 GROUP BY description HAVING description!="boring" or description IS NULL ORDER BY rating desc