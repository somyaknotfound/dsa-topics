// Your code goes here

class Book{
    private:
        vector <bool> isAvailable;
    public:
        vector<string> title;
        vector<string> author;

        Book(vector <string> title, vector<string> author , vector <bool> isAvailable ) {
            this->title = title;
            this->author = author;
            this->isAvailable = isAvailable;
        }

        void borrowBook(string bookName) {
            for (int i =  0 ; i < title.size() ; i++) {
                if (title[i] == bookName) {
                    if (isAvailable[i]) {
                        isAvailable[i] = false;
                        return;
                    } else {
                        cout <<  "Book is not available." << endl;
                        return;
                    }
                }
            }
        }

        void returnBook(string bookName) {
            for (int i = 0 ;i < title.size() ; i++) {
                if (title[i] == bookName) {
                    if (!isAvailable[i]) {
                        isAvailable[i] = true;
                        return;
                    }
                }
            }
        }

        void getAvailability(string bookName) {
            for (int i = 0 ; i < title.size() ; i++) {
                if (title[i] == bookName) {
                    if (isAvailable[i]) {
                        cout <<  "true" << endl;
                        return;
                    } 
                }

            }
            cout << "false" << endl;
        }
};


// Please Do not change anything below, It is only for your reference.
/*

This is the driver code that will execute and demonstrate the functionality of your `Book` class.

It creates an object of class `Book`, the parameterized constructor sets the values of `titles`, `authors`, and `isAvailable` attributes.
It iterates over the `methodCalls` vector and calls methods corresponding to the operation type.


// Main function to demonstrate the functionality of the Book class
int main() {

    // Create vectors for storing book details
    vector<string> titles, authors;
    vector<bool> isAvailable;
    vector<vector<string>> methodCalls;

    // Create book object using parameterized constructor to initialize the attributes
    Book book(titles, authors, isAvailable);

    // Iterate over the methodCalls
    for (const auto& methodCall : methodCalls) {
        string operation = methodCall[0];
        string bookName = methodCall[1];

        if (operation == "1") {
            // If the operation is of type 1 then call borrowBook
            book.borrowBook(bookName);
        } 
        else if (operation == "2") {
            // If the operation is of type 2 then call returnBook
            book.returnBook(bookName);
        } 
        else if (operation == "3") {
            // If the operation is of type 3 then call getAvailability
            book.getAvailability(bookName);
        }
    }

    return 0;
}

*/

/*
// Below are the output statements

cout << "false" << endl;
cout << "true" << endl;
cout << "Book is not available." << endl;

*/
