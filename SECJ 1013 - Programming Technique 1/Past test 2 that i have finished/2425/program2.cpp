#include <iostream>
#include <cmath>
#include <iomanip>
#include <cctype>
using namespace std;


char function1 (float amount);
float function2 (char x);
int main (){
    int count , temp;
    char code, code2;
    float amount, banknoteValue;
    cout << "-----Money Currency Exchange Program-----"<< endl;
    cout << " Pick a currency to convert from : " << endl;
    cout << " I - Indonesian Rupiah , B - Bangladeshi , C - Chinese Yuan" << endl;


while (true){
    cin >> code;
    code = toupper (code);
    if ((cin.fail()) || ((code != 'I') && (code != 'B') && (code != 'C'))){
    cout << "Invalid Code ! Enter again : " << endl;
    continue;  
}
    cout << "Enter the amount you want to change in your original currency : ";
    cin >> amount;
        switch (code){
        case 'I' :
            amount *=0.000286;
            cout << "Your conversion money is : MYR " << amount << endl;
            amount = ceil (amount);
            cout << "You will get : MYR " << amount << endl;
            break;
        case 'B' :
            amount *=0.0378;
            cout << "Your conversion money is : MYR " << amount << endl;
            amount = ceil (amount);
            cout << "You will get : MYR " << amount << endl;
            break;
        case 'C' :
            amount *=0.62;
            cout << "Your conversion money is : MYR " << amount << endl;
            amount = ceil (amount);
            cout << "You will get : MYR " << amount << endl;
            break;             
    }
    break;
}
    
    while (amount !=0){
        code2=function1(amount);
        banknoteValue = function2 (code2);
        count = amount / banknoteValue;
        temp = count * banknoteValue;
        cout << "Your money in bank note MYR " << banknoteValue<< " : " << banknoteValue << " x " << count << " = " << temp << endl;
        amount -= temp; 
        cout <<  "Your balance is : MYR " << amount << endl;
    }

    return 0;
}
char function1 (float amount){
    float bankNoteA = 100 ,bankNoteB = 50,  bankNoteC = 20 , bankNoteD = 10 , bankNoteE = 5 , bankNoteF = 1;
    char bankNote;
    cout << "How would you like your money ? : " << endl;
    if (amount  >= bankNoteA){
        cout << " A - MYR " << bankNoteA << endl;
    }
    if (amount  >= bankNoteB){
        cout << " B - MYR  " << bankNoteB << endl;
    }
    if (amount  >= bankNoteC){
        cout << " C - MYR " << bankNoteC << endl;
    }
    if (amount  >= bankNoteD){
        cout << " D - MYR " << bankNoteD << endl;
    }
    if (amount  >= bankNoteE){
        cout << " E - MYR " << bankNoteE << endl;
    }
    if (amount  >= bankNoteF){
        cout << " F - MYR " << bankNoteF << endl;
    }
    while (true){
    cin >> bankNote;
    bankNote = toupper(bankNote);
    if ((cin.fail()) || ( (bankNote != 'A') && (bankNote != 'B') && (bankNote != 'C') && (bankNote != 'D') && (bankNote != 'E') && (bankNote != 'F') ) ){
        cin.clear ();
        cin.ignore (1000, '\n');
        cout << "Invalid Bank Note ! Try again : ";
        continue;
    }
    else {break;}
}
    return bankNote;
}
float function2 (char x){
    switch (x){
        case 'A' : return 100.00;break;
        case 'B' : return 50.00;break;
        case 'C' : return 20.00;break;
        case 'D' : return 10.00;break;
        case 'E' : return 5.00;break;
        case 'F' : return 1.00;break;
        default : return 0.00;break;
    }
}
