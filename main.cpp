#include <iostream>
#include <string>

using namespace std;

// *******************************************************************
//          Function 1 -                                             *
//          Student Name: Tang Yu Shan                               *
//          Matrik Number: A24CS0199                                 *
// *******************************************************************

void wasteInput(string type[],double weight[],string date[], int &entryCount)
{
    while(true)
    {
        cout<<"Enter material type (paper/glass/metal/plastic): ";
        cin >> type[entryCount];
        while(type[entryCount]!="paper" && type[entryCount]!="glass" && type[entryCount]!="metal" && type[entryCount]!="plastic")
        {
            cout<<"Invalid material type! Please enter again! "<<endl;
            cout<<"Enter material type (paper/glass/metal/plastic): ";
            cin>>type[entryCount];
        }
        cout<<"Enter weight(kg)/volume(L): ";
        cin>> weight[entryCount];
        cout<<"Enter date(YYYY-MM-DD): ";
        cin>>date[entryCount];

        cout<<"Entry " << entryCount << " sucessfully saved!"<<endl;
        string uniqueID;
        uniqueID = type[entryCount] + "_" + to_string(weight[entryCount])+ "_" +date[entryCount];
        cout<< "ID: "<<uniqueID<<endl;

        entryCount += 1;

        char input=' ';

        while (input!='Y' && input!='N') {
            cout << "Do you wish to add another entry? (Y/N): ";
            cin >> input;
        }
        if (input=='N') {
            break;
        }
    }
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

void function3(string entryType[], double entryWeight[], string entryDate[]) { // change the name and datta type of function
    for (int i=0; i<8; i++) {
        cout << entryType[i] << " " << entryWeight[i] << " " << entryDate[i] << endl;
    }
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
    cout << "1. Create an entry." << endl;
    cout << "2. " << endl;
    cout << "3. " << endl;
    cout << "4. Exit" << endl;
    cout << "Choose an option (1-4): ";
}

int main() {

    // Dummy Data
    const int MAX_ENTRIES = 1024;
    string entryType[MAX_ENTRIES] = {"Plastic", "Glass", "Glass", "Plastic", "Paper", "Paper", "Metal", "Glass"};
    double entryWeight[MAX_ENTRIES] = {0.5, 2.2, 1.6, 0.8, 0.4, 0.7, 2.3, 0.8};
    string entryDate[MAX_ENTRIES] = {"2024-12-01", "2024-12-02", "2024-12-02", "2024-12-03", "2024-12-04", "2024-12-04", "2024-12-06", "2024-12-07"};
    int entryCount = 1;

    int choice;

    do{
        displayMenu();
        cin >> choice;
        
        switch(choice) {
            
            case 1: cout << "\n***** Module 1 ******" << endl;
                    wasteInput(entryType, entryWeight, entryDate, entryCount);
                    cout << "***** Module 1 ******\n" << endl;
                    break;

            case 2: cout << "\n***** Module 2 ******" << endl;
                    function2();
                    function3(entryType, entryWeight, entryDate);
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
