/*
1251. Average Selling Price
Solved
Easy
Topics
Companies
SQL Schema
Pandas Schema
Table: Prices

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| start_date    | date    |
| end_date      | date    |
| price         | int     |
+---------------+---------+
(product_id, start_date, end_date) is the primary key (combination of columns with unique values) for this table.
Each row of this table indicates the price of the product_id in the period from start_date to end_date.
For each product_id there will be no two overlapping periods. That means there will be no two intersecting periods for the same product_id.
 

Table: UnitsSold

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| purchase_date | date    |
| units         | int     |
+---------------+---------+
This table may contain duplicate rows.
Each row of this table indicates the date, units, and product_id of each product sold. 
 

Write a solution to find the average selling price for each product. average_price should be rounded to 2 decimal places.

Return the result table in any order.

The result format is in the following example.

 

Example 1:

Input: 
Prices table:
+------------+------------+------------+--------+
| product_id | start_date | end_date   | price  |
+------------+------------+------------+--------+
| 1          | 2019-02-17 | 2019-02-28 | 5      |
| 1          | 2019-03-01 | 2019-03-22 | 20     |
| 2          | 2019-02-01 | 2019-02-20 | 15     |
| 2          | 2019-02-21 | 2019-03-31 | 30     |
+------------+------------+------------+--------+
UnitsSold table:
+------------+---------------+-------+
| product_id | purchase_date | units |
+------------+---------------+-------+
| 1          | 2019-02-25    | 100   |
| 1          | 2019-03-01    | 15    |
| 2          | 2019-02-10    | 200   |
| 2          | 2019-03-22    | 30    |
+------------+---------------+-------+
Output: 
+------------+---------------+
| product_id | average_price |
+------------+---------------+
| 1          | 6.96          |
| 2          | 16.96         |
+------------+---------------+
Explanation: 
Average selling price = Total Price of Product / Number of products sold.
Average selling price for product 1 = ((100 * 5) + (15 * 20)) / 115 = 6.96
Average selling price for product 2 = ((200 * 15) + (30 * 30)) / 230 = 16.96

*/

/* MYSQL using aggregate function and left join */

# Write your MySQL query statement below
select e1.product_id, ifnull(round((sum(e2.units * e1.price) / sum(e2.units)), 2), 0) as average_price # since we want to get round value upto 2 and if that whole value is NULL we want the output as 0
from Prices e1
left join UnitsSold e2
using(product_id)
where e2.product_id is null or e2.purchase_date between e1.start_date and e1.end_date
group by e1.product_id;

/* Panda */

import pandas as pd
import numpy as np

def average_selling_price(prices: pd.DataFrame, units_sold: pd.DataFrame) -> pd.DataFrame:
    # Left joining prices and units sold table 
    merged_df = prices.merge(units_sold, on = 'product_id', how = 'left')
    # defining the where clause to get the required data between the dates
    filtered_df = merged_df[(merged_df['purchase_date'].isnull() | merged_df['purchase_date'].between(merged_df['start_date'], merged_df['end_date']))]
    
    #defining a function which calculates average if total units are != 0
    def calculateAvg(group):
        total_units = np.sum(group['units'])
        if(total_units > 0):
            average_price = np.round((np.sum(group['units'] * group['price']) / np.sum(group['units'])),2)
        else:
            average_price = 0
        return average_price

    # renaming the column and getting the output of required columns
    result_df = filtered_df.groupby('product_id').apply(calculateAvg).reset_index(name='average_price')
    return result_df

/* Method - 2: */

import pandas as pd
import numpy as np

def average_selling_price(prices: pd.DataFrame, units_sold: pd.DataFrame) -> pd.DataFrame:
    /* Left joining prices and units sold table */
    merged_df = prices.merge(units_sold, on = 'product_id', how = 'left')
    
    /* defining the where clause to get the required data between the dates */
    filtered_df = merged_df[(merged_df['purchase_date'].isnull() | merged_df['purchase_date'].between(merged_df['start_date'], merged_df['end_date']))]
    
    /* defining a function which calculates average if total units are != 0 */
    def calculateAvg(group):
        total_units = np.sum(group['units'])
        if(total_units > 0):
            average_price = np.round((np.sum(group['units'] * group['price']) / np.sum(group['units'])),2)
        else:
            average_price = 0
        return pd.Series({'average_price': average_price})

    /* renaming the column and getting the output of required columns */

    result_df = filtered_df.groupby('product_id').apply(calculateAvg).reset_index() # Resetting index to make 'product_id' a column again

    return result_df

