select d.name as Department,e.name as Employee,Salary
from Employee e
join Department d on e.departmentId = d.id
WHERE(
    SELECT COUNT(DISTINCT salary)
    FROM Employee e2
    WHERE e2.departmentId = e.departmentId AND e2.salary >= e.salary) <= 3
order by Department,Salary desc;