#include<iostream>
#include<vector>
using namespace std;

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    int AppleHit = 0;
    int OrangeHit = 0;
    for(unsigned int i = 0; i < apples.size(); i++) {
        if(a + apples.at(i) >= s && a + apples.at(i) <= t) {
            AppleHit++;
        }
    }
    for(unsigned int i = 0; i < oranges.size(); i++) {
        if(b + oranges.at(i) >= s && b + oranges.at(i) <= t) {
            OrangeHit++;
        }
    }
    cout << AppleHit << endl << OrangeHit << endl;
}


int main() {
	vector<int> Apple = {-2, 2, 1};
	vector<int> Orange = {5, -6};

	countApplesAndOranges(7, 11, 5, 15, Apple, Orange);
}