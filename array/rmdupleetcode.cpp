#include<iostream>
#include<vector>
using namespace std;

int removeduplicates(vector<int> &a) {
    int writeIndex = 2;
    for (int readIndex = 2 ; readIndex< a.size(); readIndex++) {
        if (a[writeIndex-2]!=a[readIndex]) {
            a[writeIndex] = a[readIndex];
            writeIndex++;
        }
    }
}
// comparing with two elements back as we know tha array is already sorted


int remdupvalues(vector<int> &v , int val) {
    int writeIndex = 0;
    for(int readIndex = 0 ; readIndex <v.size(); readIndex++) {
        if (v[readIndex]!= val) {
            v[writeIndex] = v[readIndex];
            writeIndex++;
        }
    }
}


int main()
{

return 0;
}