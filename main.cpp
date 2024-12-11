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

        cout<<"Entry " << entryCount << " sucessfully saved! "<<endl;
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
void calculateTotals(int entryCount, string type[], double weight[], double materialWeights[], int materialCounts[], double &totalWeight) 
{
    for (int i=0;i<4;i++) 
    {
        materialWeights[i]=0;
        materialCounts[i]=0;
    }
    totalWeight=0;

    for (int i=0;i<entryCount;i++) 
    {
        if (type[i]=="Paper") 
        {
            materialWeights[0]+=weight[i];
            materialCounts[0]++;
        } 
        else if (type[i]=="Glass") 
        {
            materialWeights[1]+=weight[i];
            materialCounts[1]++;
        } 
        else if (type[i]=="Metal") 
        {
            materialWeights[2]+=weight[i];
            materialCounts[2]++;
        } 
        else if (type[i]=="Plastic") 
        {
            materialWeights[3]+=weight[i];
            materialCounts[3]++;
        }

        totalWeight+=weight[i];
    }
}

void displayResults(int entryCount, string type[], double weight[], string date[], double materialWeights[], int materialCounts[], double totalWeight) 
{
    cout<<"----------------------------------------------------------------------------------------"<<endl;
    cout<<setw(8)<<"Date"<<setw(20)<<"Material"<<setw(37)<<"Weight(kg)/Volume(L)"<<endl;
    cout<<"----------------------------------------------------------------------------------------"<<endl;

   for (int i=0;i<entryCount;i++) 
   {
        double recyclingPercentage=0;
        if (type[i]=="Paper") 
        {
            recyclingPercentage=(materialWeights[0]/totalWeight)*100;
        } 
        else if (type[i]=="Glass") 
        {
            recyclingPercentage=(materialWeights[1]/totalWeight)*100;
        } 
        else if (type[i]=="Metal") 
        {
            recyclingPercentage=(materialWeights[2]/totalWeight)*100;
        } 
        else if (type[i]=="Plastic") 
        {
            recyclingPercentage=(materialWeights[3]/totalWeight)*100;
        }

        cout << setw(10)<<date[i]
             << setw(16)<<type[i]
             << setw(25)<<fixed<<setprecision(2)<<weight[i]<<endl;
    }

    string categories[]={"Paper","Glass","Metal","Plastic"};
    string categoryNames[]={"Paper (Recyclable)","Glass (Recyclable)","Metal (Recyclable)","Plastic (Recyclable)"};
    double recyclingPercentages[4];

    for (int i=0;i<4;i++) 
    {
        if(totalWeight>0)
        recyclingPercentages[i]=(materialWeights[i]/totalWeight)*100; 
        else
        recyclingPercentages[i] = 0;
    }

    cout << "---------------------------------------------------------------------------------------------" << endl;
    cout << "Category Summary (Total): " << endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;

    for (int i=0; i<4;i++) 
    {
        cout <<categoryNames[i]<<": "
             <<materialCounts[i]<<" materials, "
             <<fixed<<setprecision(2) << materialWeights[i]<<" kg/L, "
             <<"Recycling Percentage : "<<fixed<<setprecision(2)<<recyclingPercentages[i]<<"%"<<endl;
    }

    cout << "---------------------------------------------------------------------------------------------" << endl;
    cout << "Total Weight of All Materials: " << totalWeight <<" kg/L"<<endl;
    
    int totalMaterials=0;
    for (int i=0; i<4; i++) 
    {
        totalMaterials += materialCounts[i];
    }
    cout<<"Total Materials Regardless of Category: "<<totalMaterials<<endl;
    cout<<"---------------------------------------------------------------------------------------------"<<endl;
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
    double materialWeights[4] = {0, 0, 0, 0}; 
    int materialCounts[4] = {0, 0, 0, 0};
    double totalWeight = 0;
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
                    calculateTotals(entryCount, entryType, entryWeight, materialWeights, materialCounts, totalWeight);
                    displayResults(entryCount, entryType, entryWeight, entryDate, materialWeights, materialCounts, totalWeight);

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
