#include<iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

string encryption(string s) {
    for(size_t i = 0; i < s.length(); i++) {
        if(s[i] == ' ') {
            for(size_t j = i; j < s.length()-1; j++) {
                s[j] = s[j+1];
            }
            s.resize(s.length()-1);
        }
    }
    string encrypted;
    int StringLength = s.length();
    int rows = floor(sqrt(s.length()));
    int cols = ceil(sqrt(s.length()));
    cout << s.length() << endl;
    while((rows * cols) < StringLength) {
    	rows += 1;
    }
    int index = 0;
    vector<string> RowVector;
    for(int i = 0; i < rows; i++) {
    	string temp;
    	for(int RowIndex = 0; RowIndex < cols; RowIndex++) { 
    		temp+= s[index];
    		index++;
    	}
	    RowVector.push_back(temp); 
	    temp = "";       
      }
      for(unsigned int i = 0; i < RowVector.at(0).length(); i++) {
      	for(unsigned int j = 0; j < RowVector.size(); j++) {
      		if(RowVector.at(j)[i]) {
      			encrypted += RowVector.at(j)[i];
      		} 
      	}
      	encrypted += ' ';
      }
      while(encrypted[encrypted.length()-1] == ' ') {
		encrypted.pop_back();
      }
return encrypted;
}

int main() {
	string s = "roqfqeylxuyxjfyqterizzkhgvngapvudnztsxeprfp";
	s = "chillout";
	//s = "haveaniceday";
	cout << encryption(s) << endl;
}