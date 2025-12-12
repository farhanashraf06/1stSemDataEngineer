// FARHAN ASHRAF BIN FAKHRUL ANWAR     A25CS0059   11/11/2025   SET 3
#include <iostream>
using namespace std;

int main (){
    int num,digit;
    int product = 1;
    string multiplies;
    cout << " Please enter your desired integer. "<< endl;
    cin >> num;
    if (num == 0){
        product =0;
    }
    else {
        num = abs(num);
        while (num > 0){
        digit = num % 10;
        product *= digit;
        num /= 10;
        }
    }
    if ( (product % 4 == 0) && (product % 5 == 0) && (product % 7 == 0)){
        multiplies = "is a multiplies of 4 , 5 and 7";
    }
    else if ((product % 4 == 0) && (product % 5 == 0)){
        multiplies = "is a multiplies of 4 and 5";
    }
    else if ((product % 4 == 0) && (product % 7 == 0)){
        multiplies = "is a multiplies of 4 and 7";
    }
    else if ((product % 5 == 0) && (product % 7 == 0)){
        multiplies = "is a multiplies of 5 and 7";
    }
    else if ((product % 5 == 0) && (product % 7 == 0)){
        multiplies = "is a multiplies of 5 and 7";
    }
    else if (product % 4 == 0){
        multiplies = "is a multiplies of 4";
    }
    else if (product % 5 == 0){
        multiplies = "is a multiplies of 5";
    }
    else if (product % 7 == 0){
        multiplies = "is a multiplies of 7";
    }
    cout << " The product of the digits is : "<< product << " which " << multiplies << endl;

    return 0;
}