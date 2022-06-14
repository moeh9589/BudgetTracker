#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main () {
    cout<<"Test"<<endl;
    int monthly_income, money, amount;
    string searching_category, myline;

    ifstream budget_file;
    budget_file.open("budget.txt");

    map<string, float> budget;


    if (budget_file.is_open()) {

        while (budget_file) {
            getline(budget_file, myline);
            if (myline != "") {
                size_t colon_pos = myline.find('=');
                string newstr = myline.substr(0, colon_pos);
                float f = stof(myline.substr(colon_pos + 1));
                cout << newstr << endl;    
                budget.insert({newstr, f});   
                money += f;
            }
        }
        
    }
    monthly_income = budget["Monthly_Income"];
    money= budget["Total_Money"];
    
    budget.erase("Monthly_Income");
    budget.erase("Total_Money");

    cout << "Your monthly income: $" << monthly_income << endl;
    cout << "Money left:" << money << endl;

    for (auto itr = budget.begin(); itr != budget.end(); ++itr) {
        cout << itr->first << '\t' << itr->second << '\n';
    }

    cout << endl << "Enter the number of the category of which money was spent:";
    cin >> searching_category;
    cout << "How much money was spent on " << searching_category << "? ";
    cin >> amount;

    for (auto itr = budget.begin(); itr != budget.end(); ++itr) {
        if (itr->first == searching_category) {
            itr->second -= amount;
            money -= amount;
            cout << "You now have " << itr->second << " left for " << itr->first << endl;

        }
    }

    cout << endl << "Money left: $" << money << endl;

    for (auto itr = budget.begin(); itr != budget.end(); ++itr) {
        cout << itr->first << ':' << itr->second << '\n';
    }
    budget_file.close();
    ofstream testFile ("budget.txt");

    testFile << "Monthly_Income= " << monthly_income << "\n";
    testFile << "Total_Money= " << money << "\n";
    for (auto itr = budget.begin(); itr != budget.end(); ++itr) {
        testFile << itr->first << "= " << itr->second << '\n';
    }
    testFile.close();

    return 0;
}


