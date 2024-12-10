#include <iostream>
#include <string>

using namespace std;

// *******************************************************************
//          Function 1 -                                             *
//          Student Name: Tang Yu Shan                               *
//          Matrik Number: A24CS0199                                 *
// *******************************************************************

void wasteInput(int entry,string type[],double weight[],string date[])
{
    for(int i=0;i<entry;i++)
    {
        cout<<"Enter material type (paper/glass/metal/plastic): ";
        cin >>type[i];
        while(type[i]!="paper" && type[i]!="glass" && type[i]!="metal" && type[i]!="plastic")
        {
            cout<<"Invalid material type! Please enter again! "<<endl;
            cout<<"Enter material type (paper/glass/metal/plastic): ";
            cin>>type[i];
        }
        cout<<"Enter weight(kg)/volume(L): ";
        cin>> weight[i];
        cout<<"Enter date(YYYY-MM-DD):";
        cin >>date[i];

        string uniqueID;
        uniqueID = type[i] + "_" + to_string(weight[i])+ "_" +date[i];
        cout<< "ID: "<<uniqueID<<endl;
    }
    cout<<"Entry sucessfully saved!"<<endl;


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
    cout << "1. " << endl;
    cout << "2. " << endl;
    cout << "3. " << endl;
    cout << "4. Exit" << endl;
    cout << "Choose an option (1-4): ";
}

int main() {

    // Dummy Data
    int entry;
    cout<<"How mant enrty you want?"<<endl;
    cin>>entry;
    string entryType[entry];
    string entryDate[entry];
    double entryWeight[entry];

    int choice;

    do{
        displayMenu();
        cin >> choice;
        
        switch(choice) {
            
            case 1: cout << "\n***** Module 1 ******" << endl;
                    wasteInput(entry,entryType,entryWeight,entryDate);
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
