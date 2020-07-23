#include<iostream>
#include<vector>
using namespace std;

int sockMerchant(int n, vector<int> ar) {
    int NumPairs = 0;
    for(unsigned int i = 0; i < n-1; i++) {
    	for(unsigned int j = i+1; j < ar.size(); j++) {
    		if(ar.at(i) == ar.at(j)) {
    			NumPairs++;
    			ar.erase(ar.begin()+j);
    			break;
    		}
    	}
    }
    return NumPairs;

}


int main() {
	vector<int> ar = {10, 20, 20, 10, 10, 30, 50, 10, 20};
	cout << sockMerchant(9, ar) << endl;
}
