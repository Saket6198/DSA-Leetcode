/*1116. Print Zero Even Odd
Solved
Medium
Topics
premium lock icon
Companies
You have a function printNumber that can be called with an integer parameter and prints it to the console.

For example, calling printNumber(7) prints 7 to the console.
You are given an instance of the class ZeroEvenOdd that has three functions: zero, even, and odd. The same instance of ZeroEvenOdd will be passed to three different threads:

Thread A: calls zero() that should only output 0's.
Thread B: calls even() that should only output even numbers.
Thread C: calls odd() that should only output odd numbers.
Modify the given class to output the series "010203040506..." where the length of the series must be 2n.

Implement the ZeroEvenOdd class:

ZeroEvenOdd(int n) Initializes the object with the number n that represents the numbers that should be printed.
void zero(printNumber) Calls printNumber to output one zero.
void even(printNumber) Calls printNumber to output one even number.
void odd(printNumber) Calls printNumber to output one odd number.
 

Example 1:

Input: n = 2
Output: "0102"
Explanation: There are three threads being fired asynchronously.
One of them calls zero(), the other calls even(), and the last one calls odd().
"0102" is the correct output.
Example 2:

Input: n = 5
Output: "0102030405"
 

Constraints:

1 <= n <= 1000
*/

#include <mutex>
#include <semaphore.h>

class ZeroEvenOdd {
private:
  int n;
  sem_t sem_zero, sem_even, sem_odd;

public:
  ZeroEvenOdd(int n) {
    this->n = n;
    sem_init(&sem_zero, 0, 1);
    sem_init(&sem_even, 0, 0);
    sem_init(&sem_odd, 0, 0);
  }

  // printNumber(x) outputs "x", where x is an integer.
  void zero(function<void(int)> printNumber) {
    for (int i = 0; i < n; i++) {
      sem_wait(&sem_zero);
      printNumber(0);
      if (i % 2 == 0)
        sem_post(&sem_odd);
      else
        sem_post(&sem_even);
    }
  }

  void even(function<void(int)> printNumber) {
    for (int i = 2; i <= n; i += 2) {
      sem_wait(&sem_even);
      printNumber(i);
      sem_post(&sem_zero);
    }
  }

  void odd(function<void(int)> printNumber) {
    for (int i = 1; i <= n; i += 2) {
      sem_wait(&sem_odd);
      printNumber(i);
      sem_post(&sem_zero);
    }
  }
};