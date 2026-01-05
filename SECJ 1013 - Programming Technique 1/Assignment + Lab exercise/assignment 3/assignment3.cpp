#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int SIZE = 20;
void getInput(string uni[SIZE], int intake[SIZE], int enrollment[SIZE], int output[SIZE]);
void calTotal (int intake[SIZE], int enrollment[SIZE], int output[SIZE] , int &x , int &y, int &z);
void calAverage (int intake[SIZE], int enrollment[SIZE], int output[SIZE] , int &x , int &y, int &z , float &q , float &w, float &e);
void getLowest (int intake[SIZE], int enrollment[SIZE], int output[SIZE] , int &x , int &y , int &z , int &index , int &index2 , int &index3);
void getHighest (int intake[SIZE], int enrollment[SIZE], int output[SIZE] , int &x , int &y , int &z , int &index , int &index2 , int &index3);


int main(){
    string uni[SIZE];
    int intake[SIZE] , enrollment[SIZE], output[SIZE] , totalIntake , totalEnrollment , totalOutput,
    lowestIntake, lowestEnrollment , lowestOutput , highestIntake , highestEnrollment , highestOutput , ILI , ILE , ILO ,
    IHI , IHE , IHO;
    float avgIntake , avgEnrollment , avgOutput;

    getInput (uni , intake , enrollment , output);
    calTotal (intake , enrollment , output , totalIntake ,totalEnrollment , totalOutput);
    calAverage (intake , enrollment , output , totalIntake ,totalEnrollment , totalOutput ,avgIntake , avgEnrollment , avgOutput);
    getLowest (intake , enrollment , output , lowestIntake , lowestEnrollment , lowestOutput , ILI , ILE , ILO);
    getHighest (intake , enrollment , output , highestIntake , highestEnrollment , highestOutput , IHI , IHE , IHO);

    ofstream outFile;
    outFile.open ("output.txt");

    outFile << setw (67) <<"NUMBER OF STUUDENTS INTAKE , ENROLMENT AND OUTPUT"<< endl;
    outFile << setw(56) << "IN PUBLIC UNIVERSITIES (2015)" << endl;
    outFile << "________________________________________________________________________________" << endl << endl;
    outFile << setw(13) << "UNIVERSITY" << setw(20) <<"INTAKE" << setw(20) << "ENROLMENT" << setw(20) << "OUTPUT" << endl;
    outFile << "________________________________________________________________________________" << endl;
    for (int i=0; i < SIZE; i++){
        outFile << setw(8) <<  uni[i] << setw(25) << intake[i] << setw(18) << enrollment[i] << setw(22) << output[i] << endl;
    }
    outFile << "________________________________________________________________________________" << endl << endl;
    outFile <<setw(8) << "TOTAL" << setw(25) << totalIntake << setw(18) << totalEnrollment << setw(22) << totalOutput << endl;
    outFile << fixed << setprecision(2) << setw(8) << "AVERAGE" << setw(25) << avgIntake << setw(18) << avgEnrollment << setw(22) << avgOutput << endl;
    outFile << "________________________________________________________________________________" << endl << endl;

    outFile << "THE LOWEST NUMBER OF STUDENT INTAKE     = " << lowestIntake << " (" << uni[ILI] <<")" << endl;
    outFile << "THE LOWEST NUMBER OF STUDENT ENROLMENT  = " << lowestEnrollment << " (" << uni[ILE] <<")" << endl;
    outFile << "THE LOWEST NUMBER OF STUDENT OUTPUT     = " << lowestOutput << " (" << uni[ILO] <<")" << endl << endl;
    outFile << "THE HIGHEST NUMBER OF STUDENT INTAKE     = " << highestIntake << " (" << uni[IHI] <<")" << endl;
    outFile << "THE HIGHEST NUMBER OF STUDENT ENROLMENT  = " << highestEnrollment << " (" << uni[IHE] <<")" << endl;
    outFile << "THE HIGHEST NUMBER OF STUDENT OUTPUT     = " << highestOutput << " (" << uni[IHO] <<")" << endl << endl;
    outFile << "THE RANGE NUMBER OF STUDENT INTAKE     = " << highestIntake - lowestIntake << endl;
    outFile << "THE RANGE NUMBER OF STUDENT ENROLMENT  = " << highestEnrollment - lowestEnrollment << endl;
    outFile << "THE RANGE NUMBER OF STUDENT OUTPUT     = " << highestOutput - lowestOutput << endl;



    return 0;
}
void getInput(string uni[SIZE], int intake[SIZE], int enrollment[SIZE], int output[SIZE]){
    ifstream inFile;
    inFile.open("input.txt");
    if (!inFile.is_open()){
        cout << "Error on reading the file. Terminating the program...." << endl;
        exit(1);
    }
    cout << "Reading........" << endl;
    int i=0;
    while (inFile >> uni[i] >> intake[i] >> enrollment[i] >> output[i]){
        i++;
    }
}
void calTotal (int intake[SIZE], int enrollment[SIZE], int output[SIZE] , int &x , int &y, int &z){
    
    for (int i=0; i < SIZE; i++){
        x+=intake[i];
        y+= enrollment[i];
        z+= output[i];
    }
    
}
void calAverage (int intake[SIZE], int enrollment[SIZE], int output[SIZE] ,  int &x , int &y, int &z , float &q , float &w, float &e){
    q = x/SIZE;
    w = y/SIZE;
    e = z/SIZE;
}
void getLowest (int intake[SIZE], int enrollment[SIZE], int output[SIZE] , int &x , int &y , int &z , int &index , int &index2 , int &index3){
    x = intake[0];
    y = enrollment[0];
    z = output[0]; 
    for (int i=0; i < SIZE; i++){
        if (intake[i] < x){
            x = intake[i];
            index = i;
        }
        if (enrollment[i] < y){
            y = enrollment[i];
            index2 = i;
        }
        if (output[i] < z){
            z = output[i];
            index3 =i;
        }
    }
}
void getHighest (int intake[SIZE], int enrollment[SIZE], int output[SIZE] , int &x , int &y , int &z, int &index , int &index2 , int &index3){
    x = intake[0];
    y = enrollment[0];
    z = output[0]; 
    for (int i=0; i < SIZE; i++){
        if (intake[i] > x){
            x = intake[i];
            index = i;
        }
        if (enrollment[i] > y){
            y = enrollment[i];
            index2 = i;
        }
        if (output[i] > z){
            z = output[i];
            index3 = i;
        }
    }
}





