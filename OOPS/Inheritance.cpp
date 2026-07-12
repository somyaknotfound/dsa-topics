// Your code goes here

class Employee {
    protected: 
    string name;
    int id;

    public:
    Employee(string name , int id) {
        this->name = name;
        this->id = id;
    }

    virtual void displayDetails() {
        cout << "Name : "<<name << endl;
        cout << "Id : "<<id << endl; 
    }

};


class Manager : public Employee {
    private:
        int teamSize;
    public:
        Manager(string name , int id, int teamSize) : Employee(name , id) {
            this->teamSize = teamSize;
        }

        void displayDetails() override {
            Employee::displayDetails();
            cout << "Team Size : " << teamSize << endl;
        }
};

class Engineer : public Employee{
    private:
        string specialization;
    public:
        Engineer(string name, int id , string specialization) : Employee(name, id) {
            this->specialization = specialization;
        }

        void displayDetails() override {
            Employee::displayDetails();
            cout << "Specialization : "<<specialization<<endl;
        }
};



// Please Do not change anything below, It is only for your reference.
/*

This is the driver code that will execute and demonstrate the functionality of your base class `Employee`, 
and derived classes `Manager` and `Engineer`.

It creates an object of class `Manager`, and uses the parameterized constructor to initialize 
the attributes of both Manager and the inherited attributes from the Employee class.
It then prints a line with the text message "Manager Details".
Then it calls the displayDetails() method of the Manager class which prints details of the manager.

It creates an object of class `Engineer`, and uses the parameterized constructor to initialize 
the attributes of both Engineer and the inherited attributes from the Employee class.
It then prints a line with the text message "Engineer Details".
Then it calls the displayDetails() method of the Engineer class which prints details of the engineer.


int main() {

    string M_name, E_name, E_specialization;
    int M_id, E_id, M_teamSize;

    // Create Manager instance
    Manager manager(M_name, M_id, M_teamSize);
    cout << "Manager Details" << endl;
    manager.displayDetails();

    // Create Engineer instance
    Engineer engineer(E_name, E_id, E_specialization);
    cout << "\nEngineer Details" << endl;
    engineer.displayDetails();

    return 0;
}

*/

/*
// Below are the output statements

cout << "Name : " << name << endl;
cout << "Id : " << id << endl;
cout << "Team Size : " << teamSize << endl;
cout << "Specialization : " << specialization << endl;
*/
