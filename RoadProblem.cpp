#include <iostream>

#include<vector>

using std::vector;
using namespace std;

/*
 * Complete the hackerCountry function below.
 */
string hackerCountry(vector<vector<int>> tolls) {
    int Cost = 0;
    int CurrentCity = 0;
    int NumCities = 0;
    vector<int> ShortestTo;
    int DikstraCost[tolls.size()];
    int DikstraCity[tolls.size()];
    int MinCityCost;
    int MinCityIndex;
    while(NumCities < 2 || CurrentCity != 0) {
        MinCityCost = tolls.at(CurrentCity).at(0);
        MinCityIndex = 0;
        cout << "CurrentCity: " << CurrentCity << endl;
        cout << "MinCityCost: " << MinCityCost << endl;
        cout << "MinCityIndex: " << MinCityIndex << endl;
        for(unsigned int i = 0; i < tolls.at(CurrentCity).size(); i++) {
            if(MinCityCost == 0 || (MinCityCost > tolls.at(CurrentCity).at(i) && tolls.at(CurrentCity).at(i) != 0)) {
                MinCityCost = tolls.at(CurrentCity).at(i);
                MinCityIndex = i;
            }
        }
        Cost += MinCityCost;
        NumCities++;
        DikstraCost[MinCityIndex] = Cost;
        DikstraCity[MinCityIndex] = NumCities+1;
        cout << "Shortest Path to " << MinCityIndex << ": " << DikstraCost[MinCityIndex] << endl;
        
        CurrentCity = MinCityIndex;
        cout << "Cost: " << Cost << endl;;
        cout << "CurrentCity: " << CurrentCity << endl;
        cout << "NumCities: " << NumCities << endl;
}
for(unsigned int i = 0; i < tolls.size(); i++) {
    cout << "Dik: " << DikstraCost[i] + tolls.at(i).at(0) << endl;
    if(DikstraCost[i] + tolls.at(i).at(0) < Cost) {
        Cost = DikstraCost[i] + tolls.at(i).at(0);
        NumCities = DikstraCity[i];
        }
    }

    string Answer = to_string(Cost) + '/' + to_string(NumCities);
    return Answer;

}

int main()
{
    vector<int> a = {0, 1, 5, 100};
    vector<int> b = {100, 0, 2, 100};
    vector<int> c = {6, 100, 0, 3};
    vector<int> d = {4, 100, 100, 0};
    vector<vector<int>> InputVector;
    InputVector.push_back(a);
    InputVector.push_back(b);
    InputVector.push_back(c);
    InputVector.push_back(d);
    string Answer = hackerCountry(InputVector);
    cout << Answer << endl;

    return 0;
}