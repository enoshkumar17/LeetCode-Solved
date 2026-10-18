# Write your MySQL query statement below
SELECT FirstName, LastName, City, State FROM person LEFT JOIN Address on person.personid = address.personId