/*


1164. Product Price at a Given Date

SQL Schema
Create table If Not Exists Products (product_id int, new_price int, change_date date)
Truncate table Products
insert into Products (product_id, new_price, change_date) values ('1', '20', '2019-08-14')
insert into Products (product_id, new_price, change_date) values ('2', '50', '2019-08-14')
insert into Products (product_id, new_price, change_date) values ('1', '30', '2019-08-15')
insert into Products (product_id, new_price, change_date) values ('1', '35', '2019-08-16')
insert into Products (product_id, new_price, change_date) values ('2', '65', '2019-08-17')
insert into Products (product_id, new_price, change_date) values ('3', '20', '2019-08-18')

Pandas Schema
data = [[1, 20, '2019-08-14'], [2, 50, '2019-08-14'], [1, 30, '2019-08-15'], [1, 35, '2019-08-16'], [2, 65, '2019-08-17'], [3, 20, '2019-08-18']]
products = pd.DataFrame(data, columns=['product_id', 'new_price', 'change_date']).astype({'product_id':'Int64', 'new_price':'Int64', 'change_date':'datetime64[ns]'})

Table: Products

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| new_price     | int     |
| change_date   | date    |
+---------------+---------+
(product_id, change_date) is the primary key (combination of columns with unique values) of this table.
Each row of this table indicates that the price of some product was changed to a new price at some date.
 

Write a solution to find the prices of all products on 2019-08-16. Assume the price of all products before any change is 10.

Return the result table in any order.

The result format is in the following example.

 

Example 1:

Input: 
Products table:
+------------+-----------+-------------+
| product_id | new_price | change_date |
+------------+-----------+-------------+
| 1          | 20        | 2019-08-14  |
| 2          | 50        | 2019-08-14  |
| 1          | 30        | 2019-08-15  |
| 1          | 35        | 2019-08-16  |
| 2          | 65        | 2019-08-17  |
| 3          | 20        | 2019-08-18  |
+------------+-----------+-------------+
Output: 
+------------+-------+
| product_id | price |
+------------+-------+
| 2          | 50    |
| 1          | 35    |
| 3          | 10    |
+------------+-------+

*/

select product_id, new_price as price 
from Products 
where (product_id,change_date) in 
    (select product_id , max(change_date) as date 
    from Products 
    where change_date <='2019-08-16' 
    group by product_id
    )
union
select distinct product_id, 10 as price 
from Products 
where product_id not in
    (select distinct product_id 
    from Products 
    where change_date <='2019-08-16' 
    );