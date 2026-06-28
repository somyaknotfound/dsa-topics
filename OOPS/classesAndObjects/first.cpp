//Your code goes here

class Student {
    private:
    string name;
    int rollNumber;

    public:

    void setDetails(string name, int rollNumber) {
        this->name = name;
        this->rollNumber = rollNumber;
    }

    void displayDetails() {
        cout << "Name : " << this->name << endl;
        cout << "Roll Number : " << this->rollNumber << endl;
        
    }
    


};


//Please Do not change anything below, It is only for your reference.
/*

This is the driver code that will execute and demonstrate the functionality of your `Student` class.

It creates a `Student` object, initializes its details using user input, and displays the details using the provided methods.

// Main function to demonstrate the functionality of the Student class
int main() {
    
    // Create variables for input
    string name;
    int rollNumber;

    // Read the name as a string input
    getline(cin, name);

    // Read the roll number as an integer input
    cin >> rollNumber;

    // Create an object of the Student class
    Student student;

    // Set the details of the student using the setDetails() method
    student.setDetails(name, rollNumber);

    // Display the student's details using the displayDetails() method
    student.displayDetails();

    return 0;
}

*/

/*
//Below are the output statements

cout << "Name : " << this->name << endl;
cout << "Roll Number : " << this->rollNumber << endl;

*/
