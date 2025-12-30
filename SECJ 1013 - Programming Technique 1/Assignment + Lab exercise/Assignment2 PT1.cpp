#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

const string Model[3] = {"X50" , "Exora" , "Persona"};
const string Variants[2] = {"1.6L Standard CVT" , "1.6L Premium CVT" };
const string Region[2] = {"Peninsular Malaysia" , "East Malaysia" };

void getInput ( int &x , int &y , int &z);
bool inputValidationForModel ( int x );
bool inputValidation ( int x );
void dispCarInfo (int x , int y , int z, float &price);
float calcMonthly (float x , float y , float z);

int main (){
    cout << fixed << setprecision(2);
    int model , variant , region , repaymentPeriod;
    float price , downpayment , interestRate , monthlyInstallment, total = 0;
    char choice;
    do {
            cout << "Proton Loan Calculator" << endl;
            getInput ( model , variant  , region);
            dispCarInfo ( model , variant , region , price );
            while (true){
                cout << endl << "\nDown Payment (MYR) : ";
                cin >> downpayment;
                if (downpayment < 0){
                    cout << "Invalid Input\n" << endl;
                    continue;  
                }
                break;
            }
            while (true){
                cout << endl << "Interest Rate (%) : ";
                cin >> interestRate;
                if ( (interestRate < 0) || (interestRate > 100) ){
                    cout << "Invalid Input\n" << endl;
                    continue;  
                }
                break;
            }
            while (true){
                cout << endl << "Repayment Period ( in years ) : ";
                cin >> repaymentPeriod;
                if  (repaymentPeriod < 0 ){
                    cout << "Invalid Input\n" << endl;
                    continue;  
                }
                break;
            }
            price -= downpayment;
            monthlyInstallment = calcMonthly (price , interestRate , repaymentPeriod);
            total += monthlyInstallment;
            cout << "Monthly Installment (MYR) : " << monthlyInstallment << endl;
            cout << "Do you want to enter other data? [Y @ N] : ";
            cin >> choice;
            choice = toupper(choice);
        } while ((choice == 'Y'));
        
        cout << "\nTotal monthly payment (MYR): " << total << endl;
    
    return 0;
}
 void getInput ( int &x , int &y , int &z){
        do{
            cout << "\nModel [1 - X50 , 2 - Exora , 3 - Persona] : ";
            cin >> x;
        }while (!inputValidationForModel (x));
        do {
            cout << "Variants [1 - 1.6L Standard CVT , 2 - 1.6L Premium CVT ] : ";
            cin >> y;
        }while (!inputValidation(y));
        do {
            cout << "Region [1 - Peninsular Malaysia , 2 - East Malaysia ] : ";
            cin >> z;
        }while (!inputValidation (z));
    
}
bool inputValidationForModel ( int x ){
        if ( (cin.fail()) || ((x != 1) && (x != 2) && (x != 3))){
        cin.clear();
        cin.ignore (1000 , '\n');
        cout << "Invalid Input ! " << endl;
        return false;
    }
        return true;
}
bool inputValidation ( int x ){
   
        if ( (cin.fail()) || ((x != 1) && (x != 2))){
        cin.clear();
        cin.ignore (1000 , '\n');
        cout << "Invalid Input ! " << endl;
        return false;
    }
        return true;
}
void dispCarInfo (int x , int y , int z , float &price){
    cout << "\nCar Info" << endl;
    cout << "Model : " << Model[x-1] << endl;
    cout << "Variant : " << Variants[y-1] << endl;
    cout << "Region : " << Region[z-1] << endl;
    cout << "Paint Type : Metallic " << endl;
    switch (x){
        case 1 :
            if ((y==1) && (z==1)){price = 30600;}
            if ((y==2) && (z==1)){price = 34600;}
            if ((y==1) && (z==2)){price = 32600;}
            if ((y==2) && (z==2)){price = 36600;}
            break;

        case 2 :
            if ((y==1) && (z==1)){price = 40600;}
            if ((y==2) && (z==1)){price = 44600;}
            if ((y==1) && (z==2)){price = 42600;}
            if ((y==2) && (z==2)){price = 46600;}
            break;
        case 3 :
            if ((y==1) && (z==1)){price = 50600;}
            if ((y==2) && (z==1)){price = 54600;}
            if ((y==1) && (z==2)){price = 52600;}
            if ((y==2) && (z==2)){price = 56600;}
            break;
        default : price = 0;
                break;
    }
    cout << "Price (MYR) : " << price << endl;

}
float calcMonthly (float x , float y , float z){
    double h;
    h = x * (y / 100) * z;
    float monthly = (x + h) / (z * 12);
    return monthly;
}
