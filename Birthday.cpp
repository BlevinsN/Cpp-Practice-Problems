#include<iostream>
#include<vector>

using namespace std;


int birthday(vector<int> s, int d, int m) {
    int Total = 0;
    for(unsigned int i = 0; i < s.size()-m+1; i++) {
        int Sum = 0;
        for(unsigned int j = i; j < m+i; j++) {
            Sum += s.at(j);
        }
        if(Sum == d) {
            Total++;
        }
    }
    return Total;
}

int main() {
    vector<int> s = {1, 2, 1, 3, 2};
    int d = 3;
    int m = 2;
    cout << "Answer: " << birthday(s, d, m) << endl;
}