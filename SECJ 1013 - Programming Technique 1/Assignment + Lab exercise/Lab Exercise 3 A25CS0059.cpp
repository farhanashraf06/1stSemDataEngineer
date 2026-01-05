// FARHAN ASHRAF BIN FAKHRUL ANWAR  A25CS0059   19/12/2025 
#include <iostream>
using namespace std;

void dispStatus (int x);
void getInput ( int &x , int &y , int &z ,int &w);
void dispOutput (int x);
float calcAverage (int x , int y);


int  main (){
    int activeCase , totalCases , totalDeath , totalRecovered , newCases, totalActiveCases=0 , numOfState=0 , highest=0;
    string stateName , highestStateName;
    float avg;
    char enterToContinue;

    do {
        cout << "----- DATA -----" << endl;
        cout << "State Name  : ";
        getline (cin , stateName);
        numOfState++;
        getInput (totalCases , newCases ,totalDeath , totalRecovered);
        activeCase = totalCases + newCases - totalDeath - totalRecovered;
        cout << endl;
        totalActiveCases += activeCase;
        if ( activeCase > highest ){
            highest = activeCase;
            highestStateName = stateName;
        }
        cout << "----- Summary -----" << endl;
        dispOutput ( activeCase );
        cout << endl;
        cin.ignore (1000 , '\n');
        cout << "Press <ENTER> to  continue...";
        cin.get (enterToContinue);
        cout << endl;
    } while (enterToContinue == '\n');

    cout << "----- Active Cases -----" << endl;
    cout << "Total : " << totalActiveCases << endl;
    cout << "Highest : " << highest << " ( " << highestStateName << " ) " << endl;
    avg = calcAverage (totalActiveCases , numOfState);
    cout << "Average for " << numOfState << " states : " << avg << endl;

    return 0;
}
void dispStatus (int x){
    if (x > 40){
        cout << "Status : Red Zone" << endl;
    }
    else if ( (x >= 21) && (x <= 40)){
        cout << "Status : Orange Zone" << endl;
    }
    else if ( (x >= 1) && (x <= 20)){
        cout << "Status : Yellow Zone" << endl;
    }
    else {
        cout << "Status : Green Zone" << endl;

    }
}
void getInput ( int &x , int &y , int &z ,int &w){
    cout << "Total Cases : " ;
    cin >> x;
    cout << "New Cases : " ;
    cin >> y;
    cout << "Total Death : " ;
    cin >> z;
    cout << "Total Recovered : " ;
    cin >> w;
}
void dispOutput (int x){
    cout << "Active Cases : " << x << endl;
    dispStatus(x);
}
float calcAverage (int x , int y){
    float avg = x / y;
    return avg; 
}


