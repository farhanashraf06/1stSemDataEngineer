#include <iostream>
#include <iomanip>
using namespace std;

float calcAverage (int x , int y , int z);
float calcPrice(float q);
void getInput (int &x , int &y , int &z);
void dispRentalSummary (float x, float y , int mv1 , int mv2 , int mv3);
int main(){
    string name;
    int moviet1 , moviet2 , moviet3;
    float totalrate, finalprice ;
    char choice;
    do {
    cout << "----- Movie Rental Service - Data -----" << endl;
    cout << "Renter's name : ";
    cin.ignore (1000 , '\n');
    getline (cin , name);
    getInput (moviet1 , moviet2 , moviet3);
    totalrate = (moviet1 * 2) + (moviet2 * 5) + (moviet3 * 3.5);
    finalprice = calcPrice(totalrate);
    cout << "----- Summary -----" << endl;
    dispRentalSummary (totalrate , finalprice ,moviet1 , moviet2 , moviet3);
    cout << "Enter N to stop the program : ";
    cin >> choice;
    choice = toupper (choice);
    if (choice == 'N'){return 0;}
    }while (choice != 'N');
    
}
void getInput(int &x , int &y , int &z){
    cout << "Movie Type 1 : ";
    cin >> x;
    cout << "Movie Type 2 : ";
    cin >> y;
    cout << "Movie Type 3 : ";
    cin >> z;
}
float calcAverage (int x , int y , int z){
    float avg;
    avg = (x+y+z) / 3.0;
    return avg;
}
float calcPrice (float q){
    float disc=0;
    float finalprice;
    if (q < 35){
        disc += 0.1;
    }
    if ( (q >= 35) && (q <= 60)){
        disc +=0.15;
    }
    if (q > 60){
        disc += 0.25;
    }
    finalprice = q - (q*disc);
    return finalprice;
}
void dispRentalSummary (float x, float y , int mv1 , int mv2 , int mv3){
    float avg;
    string max;
    cout << "The total rate is : RM " << setprecision(2) << fixed<< x << endl;
    cout << "The final price is : RM " << setprecision (2) << fixed << y << endl;
    avg = calcAverage (mv1 , mv2 , mv3);
    cout << "Average : " << setprecision (2) << fixed << avg << endl;
    if (mv1>mv2){
        if (mv1 > mv3){
            max = "Movie Type 1";
        }
    }
    if (mv2>mv1){
        if (mv2 > mv3){
            max = "Movie Type 2";
        }
    }
    if (mv3>mv1){
        if (mv3 > mv2){
            max = "Movie Type 3";
        }
    }
    cout << "The highest rented movie type is : " << max << endl;
}