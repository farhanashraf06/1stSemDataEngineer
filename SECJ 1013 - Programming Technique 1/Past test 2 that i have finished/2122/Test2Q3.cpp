#include <iostream>
#include <iomanip>
using namespace std;

void getInput(string &x , float &y ,int &z , string &q);
float deterAmountAssist (float y , int z);
int main (){
    string IC;
    float gross , x;
    int numofchildren;
    string eligibility;
    char choice;
    cout << "----- Eligibility Check for Malaysian Family Assistance -----" << endl;
    do {
        getInput (IC , gross , numofchildren , eligibility);
        x = deterAmountAssist (gross , numofchildren);
        cout << "Amount of family assistance = RM " << x << endl;
        cout << "Enter 'Y' or 'y' to enter other data : ";
        cin >> choice;
        choice = toupper (choice);
        if ( choice != 'Y'){return 0;}

    } while (choice == 'Y');
}
void getInput(string &x , float &y ,int &z , string &q){
    cout << "Please enter your IC number : ";
    cin >> x;
    cout << "Please enter your monthly gross income : ";
    cin >> y;
    if ( y > 5000){
        q= "NOT ELIGIBLE";
        cout << "Status : " << q << endl;
        return;
    }
    else {
        q = "ELIGIBLE";
        cout << "Please enter the number of children : ";
        cin >> z;
        cout << "Status : " << q << endl;
    }
}
float deterAmountAssist (float y , int z){
    float moneyassist;
    if  ( (y >= 2501 ) && ( y <= 5000)){
        if (z ==0){
            moneyassist= 400;
        }
        if ((z == 1 )|| (z == 2)){
            moneyassist = 600;
        }
        if (z >= 3){
            moneyassist = 800;
        }

    }
    if (y <= 2500){
         if (z ==0){
            moneyassist= 1000;
        }
        if ((z ==1 )|| (z == 2)){
            moneyassist = 1500;
        }
        if (z >= 3){
            moneyassist = 2000;
        }

    }
    return moneyassist;

}