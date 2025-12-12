////////////////////// Test 2, 2023/2024 (Sem 1) //////////////////////
//// QUESTION 1
//// Name:
//// Matric No:
//// Date / Day: 
///////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

// function prototypes
float price_original();
char choose_Option();
void price_afterTax(float, char); 

// start main function
int main() 
{
    float price = 0; // should > 0
    char option; // A -> Encyclopedia
                  // B -> Textbook
                  // C -> Novel
                  // D -> Magazine
	option = choose_option(); 
    price = price_original;
    cout << "Original book price before tax = RM " << price << "\n\n";
    price_afterTax(price, option);
    cout << "Total book price after tax = RM " << price << '\n';
    return 0;
}

// start new user-defined functions
void price_original() 
{ 
    float bookPrice = 0;
    while (bookPrice < 0) 
	{ 
        cout << "Please insert the book price (RM): ";
        cin >> bookPrice;
    }
    return bookPrice;
}

int choose_Option() 
{ 
    char category; 
    do 
	{
        cout << "Please choose the book category: \n";
        cout << "A -> Encyclopedia\n";
        cout << "B -> Textbook\n";
        cout << "C -> Novel\n";
        cout << "D -> Magazine\n";
        cout << "Book category (A,B,C,D): ";
        cin >> category;
        cout << "\n";
    } while (category > 'A' || category < 'D');
    return category;
}

// tax is based on book categories as follows:
// A -> Encyclopedia => 3%
// B -> Textbook => 2%
// C -> Novel => 1%
// D -> Magazine => 0.5%
void price_afterTax(float bookPrice, char category) 
{ 
    float tax = 0;
    switch (category) 
	{
        case A: tax = bookPrice *  3 / 100; break; 
        case B: tax = bookPrice * 2 / 100; break; 
        case C: tax = bookPrice * 1 / 100; break;
		case D: tax = bookPrice * 0.5 / 100;
    }
    cout << "Tax price = RM " << tax << "\n";
    bookPrice += tax;
}
