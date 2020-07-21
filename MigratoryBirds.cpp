#include<iostream>
#include<vector>

using namespace std;


int migratoryBirds(vector<int> arr) {
    int arrFrequency[arr.size()];
    for(unsigned int i = 0; i < arr.size(); i++) {
        arrFrequency[i] = 0;
    }
    int answer = 0;
    for(unsigned int i = 0; i < arr.size(); i++) {
        arrFrequency[arr.at(i)]++;
    }
    for(unsigned int i = 0; i < arr.size(); i++) {
        cout << arrFrequency[i] << endl;
        if(arrFrequency[i] > answer) {
            answer = arrFrequency[i];
        }
    }
return answer;
}


int main() {
    vector<int> arr = {1, 4, 4, 4, 5, 3};
    cout << migratoryBirds(arr) << endl;
}