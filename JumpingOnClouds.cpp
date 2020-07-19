#include<iostream>

#include<vector>

using namespace std;

int jumpingOnClouds(vector<int> c, int k) {
    int CurCloud = 0;
    int Energy = 100;
    cout << Energy << endl;
    while((CurCloud + k) % c.size() != 0) {
    	cout << Energy << endl;
        if(c.at(CurCloud) == 0) {
            Energy -= 1;
        } else if(c.at(CurCloud) == 1) {
            Energy -= 3;
        }
        CurCloud = (CurCloud + k) % c.size();
    }
    if(c.at(CurCloud) == 0) {
            Energy -= 1;
        } else if(c.at(CurCloud) == 1) {
            Energy -= 3;
        }
    return Energy;
}


int main() {
	vector<int> c = {0, 0, 1, 0, 0, 1, 1, 0};
	int k = 2;
	cout << jumpingOnClouds(c, k) << endl;
}