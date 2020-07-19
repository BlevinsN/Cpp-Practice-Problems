#include<iostream>
#include<vector>

using namespace std;

bool checkA(vector<int> a, int value) {
    for(unsigned int i = 0; i < a.size(); i++) {
        if(value %a.at(i) != 0) {
            return false;
        }
    }
    return true;
}
bool checkB(vector<int> b, int value) {
    for(unsigned int i = 0; i < b.size(); i++) {
        if(b.at(i) %value != 0) {
            return false;
        }
    }
    return true;
}
int getTotalX(vector<int> a, vector<int> b) {
    int Total = 0;
    for(int i = a.at(a.size()-1); i <= b.at(b.size()-1); i++) {
        if(checkA(a, i) && checkB(b, i)) {
            cout << i << endl;
            Total++;
        }
    }
    return Total;
}


int main() {
    vector<int> a = {1};
    vector<int> b = {100};
    int Answer = getTotalX(a, b);
    cout << Answer << endl;
}