#include<iostream>

#include<vector>

using namespace std;


int FindIndex(vector<int> scores, int left, int right, int Value) {
    int mid = left + (right-left) / 2;
    cout << "Looking for: " << Value << endl;
    cout << "mid: " << mid << endl;
    cout << "left: " << left << endl;
    cout << "right: " << right << endl;
    if(right >= left) {
        if(Value == scores.at(mid)) {
            return mid;
        } else if(Value > scores.at(mid)) {
            return FindIndex(scores, left, mid - 1, Value);
        } else {
            return FindIndex(scores, mid+1, right, Value);
        }
    }
    return -1;
}

vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    vector<int>AlicePos;
    for(unsigned int i = 1; i < scores.size(); i++) {
        if(scores.at(i) == scores.at(i-1)) {
            scores.erase(scores.begin()+i);
        }
    }
    for(unsigned int j = 0; j < alice.size(); j++) {
        cout << "Looking for: " << alice.at(j) << endl;
        if(alice.at(j) > scores.at(0)) {
            AlicePos.push_back(1);
        } else if(alice.at(j) < scores.at(scores.size()-1)) {
            AlicePos.push_back(scores.size()+1);
        } else {
            int Offset = 0;
            while(FindIndex(scores, 0, scores.size(), alice.at(j)+Offset) == -1) {
                Offset--;
            }
            AlicePos.push_back(FindIndex(scores, 0, scores.size(), alice.at(j)+Offset)+1);
            cout << "Pushed: " << FindIndex(scores, 0, scores.size(), alice.at(j)+Offset) << endl;
        }
    }
    return AlicePos;
}

int main() {
    vector<int>Scores = {100, 100, 50, 40, 40, 20, 10};
    vector<int>Alice = {5, 25, 50, 120};
    vector<int>Answer = climbingLeaderboard(Scores, Alice);
    for(unsigned int i = 0; i < Answer.size(); i++) {
        cout << Answer.at(i) << std::endl;
    }
}