#include <iostream>
#include <iomanip>
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
void calculateTotals(int entryCount, string type[], double weight[], double &paperWeight, double &glassWeight, 
               double &metalWeight, double &plasticWeight, int &paperCount, int &glassCount, 
               int &metalCount, int &plasticCount, double &totalWeight)
{
    paperWeight = glassWeight = metalWeight = plasticWeight = 0;
    paperCount = glassCount = metalCount = plasticCount = 0;
    totalWeight = 0;

    for (int i = 0; i < entryCount; i++) {
        if (type[i] == "Paper") 
        {paperWeight += weight[i];
         paperCount++;
        }
        else if (type[i] == "Glass") 
        {
        glassWeight += weight[i];
        glassCount++;
        }
        else if (type[i] == "Metal")
        {
        metalWeight += weight[i];
        metalCount++;
        }
        else if (type[i] == "Plastic")
        {
        plasticWeight += weight[i];
        plasticCount++;
        }

        totalWeight += weight[i];
    }
}

void displayResults(int entryCount, string type[], double weight[], string date[],
                    double paperWeight, double glassWeight, double metalWeight, double plasticWeight,
                    double totalWeight,int paperCount, int glassCount, int metalCount, 
             int plasticCount) 
{
    cout << "\n---------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(8) << "Date" << setw(15) << "Material" << setw(23) << "Weight(kg)/Volume(L)" << setw(14) << "Category"<<setw(25)<<"Total materials"
         << setw(30) << "Total of each Category(kg)" << setw(29) << "Recycling Percentage(%)" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < entryCount; i++) {
        int categoryCount = 0;
        string category;
        double categoryTotal = 0;
        double recyclingPercentage = 0;

        if (type[i] == "Paper") 
        {
            category="Paper(Recyclable)";
            categoryCount = paperCount;
            categoryTotal = paperWeight;
            recyclingPercentage = (paperWeight / totalWeight) * 100;
        } 
        else if (type[i] == "Glass") 
        {
            category="Glass(Recyclable)";
            categoryCount = glassCount;
            categoryTotal = glassWeight;
            recyclingPercentage = (glassWeight / totalWeight) * 100;
        } 

        else if (type[i] == "Metal") 
        {
            category="Metal(Recyclable)";
            categoryCount = metalCount;
            categoryTotal = metalWeight;
            recyclingPercentage = (metalWeight / totalWeight) * 100;
        } 
        else if (type[i] == "Plastic") 
        {
            category="Plastic(Recyclable)";
            categoryCount = plasticCount;
            categoryTotal = plasticWeight;
            recyclingPercentage = (plasticWeight / totalWeight) * 100;
        }   

        cout << setw(10) << date[i] 
             << setw(12) << type[i]
             << setw(15) << fixed << setprecision(2) << weight[i]
             << setw(28) << category
             << setw(15) << fixed<<setprecision(2) << categoryCount
             << setw(18) << categoryTotal
             << setw(35) << fixed<<setprecision(2) << recyclingPercentage<< endl;
    }
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Total Weight of All Materials: " << totalWeight << " kg\n";
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
    cout << "2. Recycling Calculation." << endl;
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
    int entryCount = 8;
    double paperWeight,glassWeight,metalWeight,plasticWeight,totalWeight=0.0;
    int paperCount, glassCount, metalCount, plasticCount=0;
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
                    calculateTotals(entryCount, entryType, entryWeight, paperWeight, glassWeight, metalWeight, plasticWeight,paperCount, glassCount, metalCount, plasticCount, totalWeight);
                   displayResults(entryCount, entryType, entryWeight, entryDate, paperWeight, glassWeight, metalWeight, plasticWeight, totalWeight,paperCount, glassCount, metalCount, plasticCount);

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
