// Your code goes here

class Employee {
   private:
    double salary;

   public:
    string name;

   protected:
    int employeeId;

   public:
    Employee(string name, int employeeId ,double salary) {
        this->name = name;
        this->employeeId = employeeId;

        if (salary >= 0) {
            this->salary = salary;
        } else {
            this->salary = 0.0;
            cout << "Invalid salary" << endl;
        }
    }

    void setSalary(double salary) {
        if (salary < 0) {
            cout << "Invalid salary" << endl;
            this->salary = 0.0;
            return;
        }

        this->salary = salary;
    }

    double getSalary() { return this->salary; }

    void displayEmployeeDetails() {
        cout << "Name : " << this->name << endl;
        cout << "Employee Id : " << this->employeeId << endl;
        cout << fixed << setprecision(2);
        cout << "Salary : " << this->salary << endl;
    }

};

// Please Do not change anything below, It is only for your reference.
/*

This is the driver code that will execute and demonstrate the functionality of
your `Employee` class.

It creates an object of class `Employee`, the parameterized constructor sets the
values of `name`, `employeeId`, and `salary` attributes. It calls the
`getSalary()` method to display the salary set by the parameterized constructor.
It then calls the `setSalary()` method to set the `newSalary`.
Then finally `displayEmployeeDetails()` is called to print the details of the
employee in the specified format.


// Main function to demonstrate the functionality of the Employee class
int main() {

    // Create a variable for taking input from the user
    string name;
    int employeeId;
    double salary;
    double newSalary;

    // Create an Employee object
    Employee employee(name, employeeId, salary);

    // Get and print the salary
    cout << fixed << setprecision(2) << "Salary : " << employee.getSalary() <<
endl;

    // Update the salary
    employee.setSalary(newSalary);

    // Display employee details
    employee.displayEmployeeDetails();

    return 0;
}

*/

/*
// Below is the output format

cout << "Name : " << name << endl;
cout << "Employee Id : " << employeeId << endl;
cout << fixed << setprecision(2) << "Salary : " << salary << endl;

*/
