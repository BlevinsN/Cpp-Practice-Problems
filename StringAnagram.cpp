#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> stringAnagram(vector<string> dictionary, vector<string> query) {
    vector<int> QueryMatches;
    for(unsigned int i = 0; i < query.size(); i++) {
        int CurrQueryMatch = 0;
        for(unsigned int j = 0; j < dictionary.size(); j++) {
            if(query.at(i).length() == dictionary.at(j).length()) {
                int Match = 0;
                for(unsigned long Qletter = 0; Qletter < query.at(i).length(); Qletter++) {
                    for(unsigned long Dletter = 0; Dletter < dictionary.at(j).length(); Dletter++) {
                    	cout << "Check: " << query.at(i)[Qletter] << " and " << dictionary.at(j)[Dletter] << endl;
                        if(query.at(i)[Qletter] == dictionary.at(j)[Dletter]) {
                        	cout << "Match Found: " << dictionary.at(j) << " and " << query.at(i) << endl;
                            Match++;
                            break;
                        }
                    }
                    if(Match == query.at(i).length()) {
                        CurrQueryMatch++;
                    }
                }
            }
        }
        QueryMatches.push_back(CurrQueryMatch);
        CurrQueryMatch = 0;
    }
    return QueryMatches;
}

int main() {
	vector<string> dictionary= {"heater", "cold", "clod", "reheat", "docl"};
	vector<string> query= {"codl", "heater", "abcd"};

	vector<int> Answer = stringAnagram(dictionary, query);
	for(unsigned int i = 0; i < Answer.size(); i++) {
		cout << Answer.at(i) << " ";
	}
	cout << endl;
}