#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
    string employeeId;
    string employeeName;
    double baseSalary;

public:
    Employee(string id, string name, double salary)
    {
        employeeId = id;
        employeeName = name;
        baseSalary = salary;
    }

    virtual double calculateSalary() const
    {
        return baseSalary;
    }

    virtual string getRole() const
    {
        return "Employee";
    }

    string getProfile() const
    {
        return employeeName + " (" + employeeId + ") - " + getRole();
    }

    virtual ~Employee() {}
};

class Manager : public Employee
{
private:
    double performanceBonus;

public:
    Manager(string id, string name, double salary, double bonus)
        : Employee(id, name, salary)
    {
        performanceBonus = bonus;
    }

    double calculateSalary() const override
    {
        return baseSalary + performanceBonus;
    }

    string getRole() const override
    {
        return "Manager";
    }
};

class Engineer : public Employee
{
private:
    int overtimeHours;
    double overtimeRate;

public:
    Engineer(string id, string name, double salary, int hours, double rate)
        : Employee(id, name, salary)
    {
        overtimeHours = hours;
        overtimeRate = rate;
    }

    double calculateSalary() const override
    {
        return baseSalary + (overtimeHours * overtimeRate);
    }

    string getRole() const override
    {
        return "Engineer";
    }
};

int main()
{
    Employee* staff[2];

    staff[0] = new Manager("EMP001", "Ali Khan", 80000, 20000);
    staff[1] = new Engineer("EMP002", "Sara Ahmed", 60000, 15, 1500);

    for (int i = 0; i < 2; i++)
    {
        cout << staff[i]->getProfile() << "\n";
        cout << "Salary: " << staff[i]->calculateSalary() << "\n\n";
        delete staff[i];
    }

    return 0;
}
