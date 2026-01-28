#include <bits/stdc++.h>

using namespace std;



class Solution {
public:
    void reverseString(vector<char>& s) {
        int st = 0;
        int e = s.size()-1;

        while (st < e) {
            swap(s[st++] , s[e--]);
        }

     
    }
};




void reverse(char name[] , int n) {
    int s = 0;
    int e = n-1;
    
    while (s<e) {
        swap(name[s++] , name[e--]);
    }
}


int getLength(char name[]) {
    int count = 0;
    for (int i = 0 ; name[i]!= '\0'; i++) {
        count++;
    }
    return count;
}



int main() {
    
    char name[20];
    
    cout << "Enter your name" <<endl;
    
    cin>>name;
    
    cout << "Your Name is" <<endl;
    cout << name <<endl;
    
    
    cout << " Length: " << getLength(name) <<endl;
    reverse(name , getLength(name));
    cout << name << endl;
    
    
    return 0;
}
