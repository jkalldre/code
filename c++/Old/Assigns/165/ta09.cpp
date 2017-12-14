#include <iostream>
#include <string>

using namespace std;

class Employee
{
  protected:
   string name;
   
  public:
   Employee() {}
   Employee(string n) {setName(n); }
   string getName()       { return name; }
   void setName(string s) { name = s; }
   virtual void display()
   {
   
   }
   virtual float getPayCheck() = 0;
      
};

class HourlyEmployee : public Employee
{
   private:
    int hourlyWage;
    int numHours;
    
   public:
    HourlyEmployee(string n, int i)
    {
        numHours = 40;
        name = n;
        hourlyWage = i;
    }
    int getHourlyWage() { return hourlyWage; }
    void setHourlyWage(int i) { hourlyWage = i; }
    virtual void display()
    {
       cout << name << " - $" << hourlyWage << "/hour\n"; 
    }
    virtual float getPayCheck()
    {
       return (numHours * hourlyWage);
    }
};

class SalaryEmployee : public Employee
{
  private:
   int salary;
   
  public:
    SalaryEmployee(string n, int i)
    {
        name = n;
        salary = i;
    }
   int getSalary() { return salary; }
   void setSalaray(int i) { salary = i; }
   virtual void display()
    {
       cout << name << " - $" << salary << "/year\n"; 
    }
    virtual float getPayCheck()
    {
       return (salary / 24);
    }
};

void displayEmployeeData(Employee *e)
{
   e.display();
       cout << "Your Paycheck is " << e.getPayCheck();
       cout << endl;
}

int main()
{
   Employee *employees[3];
   char type;
   
   for (int i = 0; i < 3; i++)
   {
     cout << "Is the employee an hourly(h) or salaray(s) employee? ";
     cin >> type;
     if (type == 'h')
     {
        string name;
        int hWage;
        cout << "What is the name? ";
        cin >> name;
        cout << "What is their hourly wage? ";
        cin >> hWage;
        employees[i] = new HourlyEmployee(name, hWage);
     }
     if (type == 's')
     {
        string name;
        int salary;
        cout << "What is the name? ";
        cin >> name;
        cout << "What is their salary? ";
        cin >> salary;
        employees[i] = new SalaryEmployee(name, salary);
     }
    }
    
    for (int i = 0; i < 3; i++)
    {
      displayEmployeeData(employees[i]);
    }
    
    delete employees[0];
    delete employees[1];
    delete employees[2];
}