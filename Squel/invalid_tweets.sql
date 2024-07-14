/*

1683. Invalid Tweets

SQL Schema
Create table If Not Exists Tweets(tweet_id int, content varchar(50))
Truncate table Tweets

insert into Tweets(tweet_id, content) values ('1', 'Vote for Biden')
insert into Tweets (tweet_id, content) values ('2', 'Let us make America great again!')

Pandas Schema
data = [[1, 'Vote for Biden'], [2, 'Let us make America Great Again!']]
tweets = pd.DataFrame(data, columns = ['tweet_id', 'content']).astype({'tweet_id':'Int64, 'content': 'object})

Table: Tweets

+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| tweet_id       | int     |
| content        | varchar |
+----------------+---------+
tweet_id is the primary key (column with unique values) for this table.
This table contains all the tweets in a social media app.
 

Write a solution to find the IDs of the invalid tweets. The tweet is invalid if the number of characters used in the content of the tweet is strictly greater than 15.

Return the result table in any order.

The result format is in the following example.

 

Example 1:

Input: 
Tweets table:
+----------+----------------------------------+
| tweet_id | content                          |
+----------+----------------------------------+
| 1        | Vote for Biden                   |
| 2        | Let us make America great again! |
+----------+----------------------------------+
Output: 
+----------+
| tweet_id |
+----------+
| 2        |
+----------+
Explanation: 
Tweet 1 has length = 14. It is a valid tweet.
Tweet 2 has length = 32. It is an invalid tweet.

*/

select distinct tweet_id
from Tweets
where length(content) > 15 ORDER BY tweet_id ASC;