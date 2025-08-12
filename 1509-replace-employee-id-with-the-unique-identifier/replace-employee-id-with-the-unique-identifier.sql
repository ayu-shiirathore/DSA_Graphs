# Write your MySQL query statement below
SELECT unique_id,name 
FROM EMployees e LEFT JOIN EmployeeUNI u 
ON u.id = e.id; 