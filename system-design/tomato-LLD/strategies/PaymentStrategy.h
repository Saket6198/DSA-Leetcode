#ifndef PaymentStrategy_H
#define PaymentStrategy_H
#include<bits/stdc++.h>
using namespace std;

class PaymentStrategy {
public:
    virtual void pay(double amount) = 0;
    virtual ~PaymentStrategy() {
        // Virtual destructor for proper cleanup of derived classes
    }
};
#endif // PAYMENT_STRATEGY_H