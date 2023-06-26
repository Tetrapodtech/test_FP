#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

vector<string> split_comma(string str) {
    int prev = 0;
    int next = str.find_first_of(',');

    vector<string> datum;

    while (prev < str.size()) {
        string subStr(str, prev, next-prev);
        datum.push_back(subStr);

        prev = next + 1;
        next = str.find_first_of(',', prev);

        if (next == string::npos) next = str.size();
    }

    return datum;
}

vector<vector<string> > function_question1(vector<vector<string>> data) {

    string search;
    string period1;
    string period2;
    vector<string> datum_result {};
    vector<vector<string>> data_result {};
    
    for (int i = 0; i < data.size(); i++) {

        if (data[i][2] == "-") {
            search = data[i][1];
            period1 = data[i][0];

            for (int j = i+1; j < data.size(); j++) {
                if ((search == data[j][1]) && (data[j][2] != "-")) {
                    period2 = data[j][0];
                    break;
                }
            }

            datum_result.push_back(search);
            datum_result.push_back(period1);
            datum_result.push_back(period2);

            data_result.push_back(datum_result);
            datum_result.erase(datum_result.begin(), datum_result.end());
        }
    }

    return data_result;
}



int main(void) {
    vector<vector<string>> data;
    string str;
    vector<vector<string>> answer1;

    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());

    while (getline(cin, str) && !str.empty()) {
        data.push_back(split_comma(str));
    }

    cout << "--------------------" << endl;
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data[i].size(); j++) {
            cout << data[i][j] << " ";
        }
        cout << "" << endl;
    }
    cout << "--------------------" << endl;

    answer1 = function_question1(data);

    cout << "--------------------" << endl;
    cout << "answer for question1" << endl;
    for (int i = 0; i < answer1.size(); i++) {
        for (int j = 0; j < answer1[i].size(); j++) {
            cout << answer1[i][j] << " ";
        }
        cout << "" << endl;
    }
    cout << "--------------------" << endl;

    return(0);
}