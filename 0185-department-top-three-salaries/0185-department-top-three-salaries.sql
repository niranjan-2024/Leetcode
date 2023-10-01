SELECT D.name AS Department, E1.name AS Employee, E1.salary AS Salary
FROM Department D, Employee E1, Employee E2
WHERE D.id = E1.departmentId AND E1.departmentId = E2.departmentId AND E1.salary <= E2.salary
GROUP BY D.id, E1.name HAVING COUNT(DISTINCT E2.salary) <= 3
ORDER BY E1.salary DESC