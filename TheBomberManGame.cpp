#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> bomberMan(int n, vector<string> grid) {
	vector<string> NewGrid;
	for(unsigned int row = 0; row < grid.size(); row++) {
		string NewLine = "";
		for(unsigned int col = 0; col < grid.at(row).length(); col++) {
			if(grid.at(row)[col] == '0') {
				NewLine[col] = '.';
				if(col > 0) {
					NewLine[col-1] = '.';
				}
				if(col < grid.at(row).length()) {
					NewLine[col+1] = '.';
					col += 1;
				}
			} else {
				NewLine[col] = '0';
		}
	}
		NewGrid.push_back(NewLine);
	}
	for(unsigned int i = 0; i < NewGrid.size(); i++) {
		cout << NewGrid.at(i) << endl;
	}
	return grid;
}

int main() {
	vector<string> grid;
	string line1 = ".......";
	string line2 = "...0...";
	string line3 = "....0..";
	string line4 = ".......";
	string line5 = "00.....";
	string line6 = "00.....";
	grid.push_back(line1);
	grid.push_back(line2);
	grid.push_back(line3);
	grid.push_back(line4);
	grid.push_back(line5);
	grid.push_back(line6);
	grid = bomberMan(3, grid);
}
