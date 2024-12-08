#include <iostream>

using namespace std;

// *******************************************************************
//          Function 1 -                                             *
//          Student Name: Tang Yu Shan                               *
//          Matrik Number: A24CS0199                                 *
// *******************************************************************

void function1() { // change the name and datta type of function
    cout << "Function 1" << endl;
}

// *******************************************************************
//          Function 2 -                                             *
//          Student Name: Bong Zi Shan                               *
//          Matrik Number: A24CS0231                                 *
// *******************************************************************

void function2() { // change the name and datta type of function
    cout << "Function 2" << endl;
}

// *******************************************************************
//          Function 3 -                                             *
//          Student Name: Hoe Zhi Wan                                *
//          Matrik Number: A24CS0082                                 *
// *******************************************************************

void function3() { // change the name and datta type of function
    cout << "Function 3" << endl;
}

// *******************************************************************
//          Function 4 -                                             *
//          Student Name: Md Abdullah                                *
//          Matrik Number: A24CS4022                                 *
// *******************************************************************

void function4() { // change the name and datta type of function
    cout << "Function 4" << endl;
}

// *******************************************************************
//                                                                   *
//                         Main Function                             *
//                                                                   *
// *******************************************************************

void displayMenu() {
    cout << "1. " << endl;
    cout << "2. " << endl;
    cout << "3. " << endl;
    cout << "4. Exit" << endl;
    cout << "Choose an option (1-4): ";
}

int main() {
    int choice;

    do{
        displayMenu();
        cin >> choice;
        
        switch(choice) {
            
            case 1: cout << "\n***** Module 1 ******" << endl;
                    function1();
                    cout << "***** Module 1 ******\n" << endl;
                    break;

            case 2: cout << "\n***** Module 2 ******" << endl;
                    function2();
                    function3();
                    cout << "***** Module 2 ******\n" << endl;
                    break;

            case 3: cout << "\n***** Module 3 ******" << endl;
                    function4();
                    cout << "***** Module 3 ******\n" << endl;
                    break;
            
            case 4: cout << "Exiting program...";
                    break;

            default: cout << "Invalid Option! Please enter a number between 1 and 4.\n" << endl;
        }
    } while(choice!=4);

    return 0;
}