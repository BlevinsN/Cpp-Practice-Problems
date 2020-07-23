#include<iostream>
#include<vector>
using namespace std;

int FindSecondNumber(int index, vector<int> arr) {
    int SecondIndex = index + 1;
    while((arr.at(index) - arr.at(SecondIndex) != 1 || arr.at(index) - arr.at(SecondIndex) != -1) && (SecondIndex < arr.size()-1)) {
        SecondIndex++;
        cout << SecondIndex << endl;
    }
    return SecondIndex;
}

int longestSubarray(vector<int> arr) {
    int LongestSubarray = 0;
    int CurrentSubarray = 0;
    int StartIndex = 0;
    int SecondNumber = FindSecondNumber(StartIndex, arr);
    for(unsigned int i = 0; i < arr.size(); i++) {
        if(arr.at(i) == arr.at(StartIndex) || arr.at(i) == arr.at(SecondNumber)) {
            if(CurrentSubarray > LongestSubarray ) {
                LongestSubarray = CurrentSubarray;
            }
        } else {
            cout << CurrentSubarray << " starting at " << StartIndex << endl;
            i = ++StartIndex;
            CurrentSubarray = 0;
            SecondNumber = FindSecondNumber(StartIndex, arr);
        }
    }
    return LongestSubarray;
}

int main()
{
    vector<int> Input;
    int NumInput = 0;
    cin >> NumInput;
    for(int i = 0; i < NumInput; i++) {
        int CurrentValue = 0;
        cin >> CurrentValue;
        Input.push_back(CurrentValue);
    }
    longestSubarray(Input);
}