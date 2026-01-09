// FARHAN ASHRAF BIN FAKHRUL ANWAR  A25CS0059   9/1/2026
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int MAXSIZE=10;
void readFile (string fileName , float tempF[] , int &size);
void computeC (float tempF[] , float tempC[] , int size);
float average (float tempC[] , int size);
void Grade (float tempC[] , char grade[], int gradeAmount[], int size);
void writeFile (float tempF[] , float tempC[] , char grade[] , int size);

int main (){
    string name;
    int size=0 , gradeAmount[3] = {0,0,0};
    float tempF[MAXSIZE] , tempC[MAXSIZE] , avg;
    char grade[MAXSIZE];

    cout << "Enter the name of the file to be read from :";//inputLE4.txt
    cin >> name;

    readFile (name , tempF , size);
    computeC (tempF , tempC , size);
    avg = average (tempC , size);
    Grade(tempC , grade , gradeAmount , size);
    writeFile ( tempF , tempC , grade , size);
    
    //WRITE OUTPUT TO SCREEN
    cout << fixed << setprecision (2);
    cout << "Average of the temperature in Celcius : " << avg << endl;
    cout << "Number of high temperature : " << gradeAmount[0] << endl;
    cout << "Number of medium temperature : " << gradeAmount[1] << endl;
    cout << "Number of low temperature : " << gradeAmount[2] << endl;

    return 0;
}
void readFile (string fileName , float tempF[] , int &size){
    ifstream inFile;
    inFile.open (fileName);
        if (!inFile.is_open()){
            cout << "Error to find the file ! Exiting the program...." << endl;
            exit(1);
        }
    cout << "Reading......" << endl;
    while ( inFile >> tempF[size]){
            size++;
        }
        inFile.close();
}

void computeC (float tempF[] , float tempC[] , int size){
    for ( int i = 0 ; i < size; i++){
        tempC[i] = (5.0/9.0) * (tempF[i] - 32);
    }
}

float average (float tempC[] , int size){
    float sum=0;
    for ( int i = 0; i < size; i++){
        sum += tempC[i];
    }
    return sum/size;
    
}

void Grade (float tempC[] , char grade[] , int gradeAmount[] , int size){
    for (int i = 0; i < size ; i++){
        if (tempC[i] >= 35){
            grade[i] = 'H';
            gradeAmount[0]++;
        }
        else if ((tempC[i] < 35) && (tempC[i] >= 20)){
            grade[i] = 'M';
            gradeAmount[1]++;
        }
        else{
            grade[i] = 'L';
            gradeAmount[2]++;
        }
    }
}

void writeFile (float tempF[] , float tempC[] , char grade[] , int size){
    ofstream outFile;
    outFile.open ("outputLE4.txt");
    outFile << fixed << setprecision(2);
    outFile << setw(21) << "C (Celcius)" << setw(23) << "F (Farenheit)" << setw(22) << "Description" << endl;
    outFile << setw(21) << "===========" << setw(23) << "=============" << setw(22) << "=============" << endl;
    for ( int i = 0; i < size; i++){
    outFile << setw (18) << tempC[i] << setw(22) << tempF[i] << setw(20) << grade[i] << endl;
    }
    outFile.close();
}

