#include<iostream>
#include<string>

using std::string;
using namespace std;

string ToMilitary(string Time) {
	string MilitaryTime = Time;
	if(Time[8] == 'P') {
		MilitaryTime[0] = Time[0] + 1;
		if(MilitaryTime[1] > '7') {
			MilitaryTime[1] = Time[1] - 8;
			MilitaryTime[0] = Time[0] + 2; 
		} else {
		MilitaryTime[1] = Time[1] + 2;
		}
	}
	MilitaryTime[8] = ' ';
	MilitaryTime[9] = ' ';
	cout << "MT0: " << MilitaryTime[0] << endl;
	return MilitaryTime;
}


int main() {
	string Time = "11:13:59PM";
	cout << Time << endl;
	string Converted = ToMilitary(Time);
	cout << Converted << endl;
}