#include<iostream>
#include<string>
using namespace std;


string biggerIsGreater(string w) {
	string Bigger = w;
	if(w.length() < 2) {
		return "no answer";
	}
	int index = w.length()-2;
	while(Bigger[index] >= Bigger[index+1]) {
		index--;
		if(index == -1) {
			return "no answer";
		}
	}
	int MinIndex = index;
	int MaxIndex = index+1;
	for(unsigned long i = index; i < w.length(); i++) {
		//cout << " Min: " << Bigger[MinIndex] << " Max: " << Bigger[MaxIndex] << endl;
		if(Bigger[i] > Bigger[MinIndex] && Bigger[i] < Bigger[MaxIndex]) {
			MaxIndex = i;
		}
	}
	char temp = Bigger[MaxIndex];
	Bigger[MaxIndex] = Bigger[MinIndex];
	Bigger[MinIndex] = temp;
	index++;
	//cout << Bigger << endl;
	for(unsigned long i = index; i < Bigger.length()-1; i++) {
		for(unsigned long j = i; j < Bigger.length(); j++) {
			if(Bigger[j] <= Bigger[i]) {
				//cout << "B[" << j << "]: " << Bigger[j] << " B[" << i << "]: " << Bigger[i] << endl;
				temp = Bigger[j];
				Bigger[j] = Bigger[i];
				//cout << Bigger << endl;
				Bigger[i] = temp;
				//cout << Bigger << endl;
			}
		}
	}
	return Bigger;
}



int main() {
	string Test1 = "zyyyvvvvvuttsrqqokjjheedccb";
	string Test2 = "dcba";
	string Test3 = "dcbb";
	string Test4 = "abdc";
	string Test5 = "abcd";

	cout << biggerIsGreater(Test1) << endl;
	cout << biggerIsGreater(Test2) << endl;
	cout << biggerIsGreater(Test3) << endl;
	cout << biggerIsGreater(Test4) << endl;
	cout << biggerIsGreater(Test5) << endl;
}










