/* 1907. Count Salary Categories
Solved
Medium
Topics
premium lock icon
Companies
SQL Schema
Pandas Schema
Table: Accounts

+-------------+------+
| Column Name | Type |
+-------------+------+
| account_id  | int  |
| income      | int  |
+-------------+------+
account_id is the primary key (column with unique values) for this table.
Each row contains information about the monthly income for one bank account.
 

Write a solution to calculate the number of bank accounts for each salary category. The salary categories are:

"Low Salary": All the salaries strictly less than $20000.
"Average Salary": All the salaries in the inclusive range [$20000, $50000].
"High Salary": All the salaries strictly greater than $50000.
The result table must contain all three categories. If there are no accounts in a category, return 0.

Return the result table in any order.

The result format is in the following example.

 

Example 1:

Input: 
Accounts table:
+------------+--------+
| account_id | income |
+------------+--------+
| 3          | 108939 |
| 2          | 12747  |
| 8          | 87709  |
| 6          | 91796  |
+------------+--------+
Output: 
+----------------+----------------+
| category       | accounts_count |
+----------------+----------------+
| Low Salary     | 1              |
| Average Salary | 0              |
| High Salary    | 3              |
+----------------+----------------+
Explanation: 
Low Salary: Account 2.
Average Salary: No accounts.
High Salary: Accounts 3, 6, and 8.
*/

SELECT 
  'Low Salary' AS category,
  COUNT(*) AS accounts_count
FROM Accounts
WHERE income < 20000

UNION ALL

SELECT 
  'Average Salary',
  COUNT(*)
FROM Accounts
WHERE income BETWEEN 20000 AND 50000

UNION ALL

SELECT 
  'High Salary',
  COUNT(*)
FROM Accounts
WHERE income > 50000;

-- This query uses UNION ALL to combine the results of three separate SELECT statements, each counting the number of accounts in a specific salary category.
-- The first SELECT counts accounts with income less than 20000, the second counts those with income between 20000 and 50000, and the third counts those with income greater than 50000.
-- Each SELECT statement includes a hardcoded category name to label the results.
-- The final result will contain three rows, one for each salary category, with the corresponding count of accounts.
-- The use of UNION ALL ensures that all results are included, even if some categories have a count of zero.