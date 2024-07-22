/*
1075. Project Employees I

SQL Schema
Create table If Not Exists Project (project_id int, employee_id int)
Create table If Not Exists Employee (employee_id int, name varchar(10), experience_years int)
Truncate table Project
insert into Project (project_id, employee_id) values ('1', '1')
insert into Project (project_id, employee_id) values ('1', '2')
insert into Project (project_id, employee_id) values ('1', '3')
insert into Project (project_id, employee_id) values ('2', '1')
insert into Project (project_id, employee_id) values ('2', '4')
Truncate table Employee
insert into Employee (employee_id, name, experience_years) values ('1', 'Khaled', '3')
insert into Employee (employee_id, name, experience_years) values ('2', 'Ali', '2')
insert into Employee (employee_id, name, experience_years) values ('3', 'John', '1')
insert into Employee (employee_id, name, experience_years) values ('4', 'Doe', '2')

Pandas Schema
data = [[1, 1], [1, 2], [1, 3], [2, 1], [2, 4]]
project = pd.DataFrame(data, columns=['project_id', 'employee_id']).astype({'project_id':'Int64', 'employee_id':'Int64'})
data = [[1, 'Khaled', 3], [2, 'Ali', 2], [3, 'John', 1], [4, 'Doe', 2]]
employee = pd.DataFrame(data, columns=['employee_id', 'name', 'experience_years']).astype({'employee_id':'Int64', 'name':'object', 'experience_years':'Int64'})

Table: Project

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| project_id  | int     |
| employee_id | int     |
+-------------+---------+
(project_id, employee_id) is the primary key of this table.
employee_id is a foreign key to Employee table.
Each row of this table indicates that the employee with employee_id is working on the project with project_id.
 

Table: Employee

+------------------+---------+
| Column Name      | Type    |
+------------------+---------+
| employee_id      | int     |
| name             | varchar |
| experience_years | int     |
+------------------+---------+
employee_id is the primary key of this table. It's guaranteed that experience_years is not NULL.
Each row of this table contains information about one employee.
 

Write an SQL query that reports the average experience years of all the employees for each project, rounded to 2 digits.

Return the result table in any order.

The query result format is in the following example.

 

Example 1:

Input: 
Project table:
+-------------+-------------+
| project_id  | employee_id |
+-------------+-------------+
| 1           | 1           |
| 1           | 2           |
| 1           | 3           |
| 2           | 1           |
| 2           | 4           |
+-------------+-------------+
Employee table:
+-------------+--------+------------------+
| employee_id | name   | experience_years |
+-------------+--------+------------------+
| 1           | Khaled | 3                |
| 2           | Ali    | 2                |
| 3           | John   | 1                |
| 4           | Doe    | 2                |
+-------------+--------+------------------+
Output: 
+-------------+---------------+
| project_id  | average_years |
+-------------+---------------+
| 1           | 2.00          |
| 2           | 2.50          |
+-------------+---------------+
Explanation: The average experience years for the first project is (3 + 2 + 1) / 3 = 2.00 and for the second project is (3 + 2) / 2 = 2.50

*/

# Write your MySQL query statement below
select project_id, ifnull(round(avg(experience_years), 2), 0) as average_years
from Project
inner join Employee
on Project.employee_id = Employee.employee_id
group by project_id 
order by project_id asc;

/* Using Pandas  1*/

import pandas as pd
import numpy as np
def project_employees_i(project: pd.DataFrame, employee: pd.DataFrame) -> pd.DataFrame:
    merged_df = project.merge(employee, on = 'employee_id', how='left')
    def calcavg(x):
        if(np.sum(x['experience_years']) < 0):
            average = 0
        else:
            average = np.round(np.average(x['experience_years']), 2)
        return pd.Series({'average_years': average})
    
    result_df = merged_df.groupby('project_id').apply(calcavg).reset_index()
    return result_df

/* Using pandas 2 */
import pandas as pd
import numpy as np
def project_employees_i(project: pd.DataFrame, employee: pd.DataFrame) -> pd.DataFrame:
    merged_df = project.merge(employee, on = 'employee_id', how='left')
    def calcavg(x):
        if(np.sum(x['experience_years']) < 0):
            average = 0
        else:
            average = np.round(np.average(x['experience_years']), 2)
        return average
    
    result_df = merged_df.groupby('project_id').apply(calcavg).reset_index(name="average_years")
    return result_df