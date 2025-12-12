#include <iostream>
#include <iomanip>
using namespace std;

float calculateLateFees ( int days );
void displayMenu ();
void displayLibraryInfo ();
int getUserInput (int &days);

int main () {
    int action , days;
    float lateFee;
    do {
        displayMenu();
        cin >> action;
        cout << endl;
        switch (action){
            case 1 : 
                getUserInput (days);
                lateFee = calculateLateFees (days);
                cout << "Your late fee is : RM " << setprecision (2) << fixed << lateFee << endl;
                break;
            case 2 :
                displayLibraryInfo ();
                cout << endl;
                break;
            case 3 :
                cout << "Thank you for using this system ! " << endl;
        }

    }while (action != 3);
    return 0;
}
void displayMenu (){
    cout << "----- Library Book Checkout System -----" << endl;
    cout << "Actions : " << endl;
    cout << "1. Calculate Late Fees" << endl  << "2. Display Library Information" << endl << "3. Quit" << endl;
}
void  displayLibraryInfo (){
    cout << "Name  : Farhan International Library " << endl;
    cout << "Address  : Pusat Pentadbiran Universiti Teknologi Malaysia, 80990 Skudai , Johor Darul Ta'zim " << endl;
    cout << "Contact Us  : 60+ 3892474  " << endl;

}
int getUserInput (int &days){
    cout << "How many days has your book overdue ? : ";
    cin >> days;
    return days;
}
float calculateLateFees (int days){
    float totalFees=0;
    if ( days <= 7){
        totalFees += (0.5*days);
    }
    else if ( days <= 14 ){
        totalFees += ((7 * 0.5 )+((days - 7) * 1.00));
    }
    else if (days > 14){
        totalFees += ((7 * 0.5 ) + (7 * 1.0 ) + (2.00 *(days - 14)));
    }
    return totalFees;
}