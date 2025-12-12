#include <iostream>
using namespace std;

float getAmount();
void times(float &x , float &y);
bool validTime(float time);
void mealAllowance (float &a , float &b , float &c);
const float bAllowance = 5;
const float lAllowance = 7;
const float dAllowance = 7;

int main(){
    int days;
    float E=0 , GA =0 , AA=0 , EA , AS;
    cout << "Please enter the number of working days :";
    cin >> days;
    for ( int i = 1 ; i <= days ; i++){
    cout << endl << "Day "<< i << ":" << endl;
    mealAllowance (E , GA , AA);
    }
    cout << "Total Expenses :RM " << E << endl;
    cout << "Total given allowance :RM " << GA << endl;
    cout << "Total allowable allowance:RM " << AA << endl;
    EA = E - AA;
    AS = GA - AA;
    cout << "Extra amount paid by employee :RM " << EA << endl;
    cout << "Total amount saved by employer :RM " << AS << endl; 

    return 0;
}
float getAmount(){
    float spend;
    cout << "How much did you spent on your meal ? : ";
    do {
    cin >> spend;
    if ( spend <= 0){
    cout << "Invalid value ! Enter again :";
    cin.ignore (1000 ,'\n');
    }
    }while (spend <= 0);
    return spend;
}
void times ( float &x , float &y){
    do{
        cout << "Please enter Punch In (HH.MM) : ";
        cin >> x;
        if (!validTime(x)){
            cout << "Invalid time system! ";
        }
    } while (!(validTime(x)));
    do {
        cout << "Please enter Punch Out (HH.MM) : ";
        cin >> y;
        if (!validTime(y)){
            cout << "Invalid time system! ";
        }
        if ((x > y)){
            cout << "Punch out time cannot be smaller than Punch in time ! ";
        }
    } while ( (!(validTime(y))) || (x > y) );
}
bool validTime (float time){
    int hour = static_cast <int>(time);
    int minute = static_cast <int>((time - hour)*100);
    if (((hour < 0) || (hour > 23)) || (minute < 0) || (minute > 59)){
        return false;
    }
    else {
        return true;
    }
}
void mealAllowance (float &a , float &b , float &c){
    float PI, PO , bspend , lspend , dspend;
    times (PI , PO);
    if (PI < 7.00){
        cout << "Breakfast : " << endl ;
        bspend = getAmount ();
        a += bspend;
        b += bAllowance;
        if (bspend > bAllowance){
            c += bAllowance;
        }
        else {
            c += bspend;
        }
    }
    if (PO > 12.00){
        cout << "Lunch : "<< endl ;
        lspend = getAmount ();
        a += lspend;
        b += lAllowance;
         if (lspend > lAllowance){
            c += lAllowance;
        }
        else {
            c += lspend;
        }
    }
    if (PO > 18.00){
        cout << "Dinner : " << endl ;
        dspend = getAmount ();
        a += dspend;
        b += dAllowance;
         if (dspend > dAllowance){
            c += dAllowance;
        }
        else {
            c += dspend;
        }
    }
}