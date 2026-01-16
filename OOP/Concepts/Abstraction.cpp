#include <iostream>
using namespace std;

class PaymentMethod
{
public:
    virtual double calculateFee(double amount) = 0;
    virtual void processPayment(double amount) = 0;
    virtual ~PaymentMethod() {}
};

class CreditCardPayment : public PaymentMethod
{
public:
    double calculateFee(double amount)
    {
        return amount * 0.03;
    }

    void processPayment(double amount)
    {
        double fee = calculateFee(amount);
        cout << "Credit Card Payment Processed\n";
        cout << "Amount: " << amount << "\n";
        cout << "Fee: " << fee << "\n";
        cout << "Total: " << amount + fee << "\n\n";
    }
};

class CashPayment : public PaymentMethod
{
public:
    double calculateFee(double amount)
    {
        return 0.0;
    }

    void processPayment(double amount)
    {
        cout << "Cash Payment Processed\n";
        cout << "Amount: " << amount << "\n";
        cout << "Fee: 0\n";
        cout << "Total: " << amount << "\n\n";
    }
};

int main()
{
    PaymentMethod* payment1 = new CreditCardPayment();
    PaymentMethod* payment2 = new CashPayment();

    payment1->processPayment(5000);
    payment2->processPayment(5000);

    delete payment1;
    delete payment2;

    return 0;
}
