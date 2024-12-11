#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// *******************************************************************
//          Function 1 - Recycling Entry                             *
//          Student Name: Tang Yu Shan                               *
//          Matrik Number: A24CS0199                                 *
// *******************************************************************

void wasteInput(string type[],double weight[],string date[], int &entryCount)
{
    while(true)
    {
        cout<<"Enter material type (Paper/Glass/Metal/Plastic): ";
        cin >> type[entryCount];
        while(type[entryCount]!="Paper" && type[entryCount]!="Glass" && type[entryCount]!="Metal" && type[entryCount]!="Plastic")
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
//          Function 2 - Calculate Statistics                        *
//          Student Name: Bong Zi Shan                               *
//          Matrik Number: A24CS0231                                 *
// *******************************************************************
void calculateTotals(int entryCount, string type[], double weight[], string date[], double materialWeights[], int materialCounts[], double &totalWeight,string categories[]) 
{
    totalWeight=0;
    double recyclingPercentages[4];
    int totalMaterials=0;

    for (int i=0;i<4;i++) 
    {
        materialWeights[i]=0;
        materialCounts[i]=0;
    }
    
    for (int i=0;i<entryCount;i++) 
    {
        if(type[i]=="Paper") 
        {
            materialWeights[0]+=weight[i];
            materialCounts[0]++;
        } 
        else if(type[i]=="Glass") 
        {
            materialWeights[1]+=weight[i];
            materialCounts[1]++;
        } 
        else if(type[i]=="Metal") 
        {
            materialWeights[2]+=weight[i];
            materialCounts[2]++;
        } 
        else 
        {
            materialWeights[3]+=weight[i];
            materialCounts[3]++;
        }

        totalWeight+=weight[i];
    }
    cout<<"----------------------------------------------------------------------------------------"<<endl;
    cout<<setw(7)<<"Date"<<setw(20)<<"Material"<<setw(30)<<"Weight(kg)/Volume(L)"<<endl;
    cout<<"----------------------------------------------------------------------------------------"<<endl;

   for (int i=0;i<entryCount;i++) 
    {
        cout << setw(10)<<date[i]
             << setw(16)<<type[i]
             << setw(20)<<fixed<<setprecision(2)<<weight[i]<<endl;
    }

    for (int i=0;i<4;i++) 
    {
        if(totalWeight>0)
        {
        recyclingPercentages[i]=(materialWeights[i]/totalWeight)*100; 
        totalMaterials += materialCounts[i];
        }
        else
        recyclingPercentages[i] = 0;
    }

    cout << "---------------------------------------------------------------------------------------------"<<endl;
    cout << "Category Summary (Total): " << endl;
    cout << "---------------------------------------------------------------------------------------------"<<endl;

    for (int i=0; i<4;i++) 
    {
        cout<<setw(10)<<left<<categories[i]               
            <<": "
            <<setw(2)<<right<<materialCounts[i]<<" materials, "          
            <<setw(4)<<fixed<<setprecision(2)<<materialWeights[i]<<"kg/L, "  
            <<fixed<<setprecision(2)<<"Recycling Percentage: "<<recyclingPercentages[i]<<"%"<<endl;
    }

    cout<<"---------------------------------------------------------------------------------------------"<<endl;
    cout<<"Total Weight of All Materials: "<<totalWeight<<" kg/L"<<endl;
    cout<<"Total Materials Regardless of Category: "<<totalMaterials<<endl;
    cout<<"---------------------------------------------------------------------------------------------"<<endl;
}

// *******************************************************************
//          Function 3 - Environmental Impact Assessment             *
//          Student Name: Hoe Zhi Wan                                *
//          Matrik Number: A24CS0082                                 *
// *******************************************************************

void environmentalImpact(double materialWeights[], string categories[], double impactValue[], double &totalTreesSaved, double &totalEnergySaved) {
    double impactFactors[] = {0.079, 3.96, 2.33, 0.17};

    // sources for impactFactors: 
    // https://www.drugplastics.com/resource-hub/blog/choose-plastic-over-glass-for-better-sustainability 
    // https://www.quora.com/How-much-CO2-is-produced-per-KWH-of-electricity
    // https://www.encon.eu/en/calculation-co2
    // https://www.milgro.eu/en/blog/co2-impact-of-paper-use-three-strategies-to-reduce-it
    // https://8billiontrees.com/carbon-offsets-credits/carbon-footprint-of-steel
    // https://sustainability.um.edu.my/ghg-um-2023

    totalTreesSaved = 0; // plastic & paper tree per kg
    totalEnergySaved = 0; // glass & metal kwh per kg

    cout << "\n---------------------------------------------------------------------------------------------" << endl;
    cout << "                               Environmental Impact Assessment                               " << endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;
    cout << "Categories \t Total Trees/Energy Saved" << endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;

    for (int i=0; i<4; i++) {
        impactValue[i] = 0;

        if (categories[i] == "Paper" || categories[i] == "Plastic") {
            impactValue[i] = materialWeights[i] * impactFactors[i];

            cout << categories[i]
                << "\t\t  " << fixed << setprecision(2) << impactValue[i]
                << "\t trees" << endl;

            totalTreesSaved += impactValue[i];
        } else if (categories[i] == "Glass" || categories[i] == "Metal") {
            impactValue[i] = materialWeights[i] * impactFactors[i];
            
            cout << categories[i]
                << "\t\t  " << fixed << setprecision(2) << impactValue[i]
                << "\t kwh of energy" << endl;

            totalEnergySaved += impactValue[i];
        }
    }

    cout << "---------------------------------------------------------------------------------------------" << endl;
    cout << "Total trees saved\t: " << totalTreesSaved << " trees" << endl;
    cout << "Total energy saved\t: " << totalEnergySaved << "kwh" << endl;
    cout << "---------------------------------------------------------------------------------------------\n" << endl;
}

// *******************************************************************
//          Function 4 -  Generate a Report                          *
//          Student Name: Md Abdullah                                *
//          Matrik Number: A24CS4022                                 *
// *******************************************************************
 
void generateRecyclingReport(int entryCount, double totalWeight, double materialWeight[], string categories[])
{
    cout << "\n***** Recycling Report *****" << endl;

    if (entryCount == 0 || totalWeight == 0) {
        cout << "No data available to generate the report.\n";
        cout << "***** End of Report *****\n" << endl;
        return;
    }   

    cout << "Total Entries: " << entryCount << endl;
    cout << "Total Weight Processed: " << totalWeight << " kg" << endl;
    cout << "Recyclable Material Weights:" << endl;
    for (int i=0; i<4; i++) {
        cout << categories[i] << "\t: " << materialWeight[i] << "kg" << endl;
    }
    
    // Identify the material with the highest contribution
    string highestCategory = categories[0];
    double highestWeight = materialWeight[0];

    for (int i=1; i<4; i++) {
        if (materialWeight[i] > highestWeight) {
            highestCategory = categories[i];
            highestWeight = materialWeight[i];
        }
    }

    cout << "The material with the highest contribution is: " << highestCategory << " (" << highestWeight << " kg).\n";

    // Proportions of each material
    cout << "Material Proportions (as % of total waste):\n";

    for (int i=0; i<4; i++) {
        cout << categories[i] << "\t: " << fixed << setprecision(2) << (materialWeight[i]/totalWeight) * 100 << "%\n";
    }
   // Recommendations
    cout << "\nRecommendations:\n";
    cout << "- Reduce plastic usage by opting for reusable items.\n";
    cout << "- Promote glass recycling through awareness campaigns.\n";
    cout << "- Encourage proper recycling of metals with accessible bins.\n";
    cout << "- Organize community events to improve paper recycling.\n";

    cout << "\n***** End of Report *****\n" << endl;
}

// *******************************************************************
//                                                                   *
//                         Main Function                             *
//                                                                   *
// *******************************************************************


void displayMenu() {
    cout << "1. Add Recycling Entry" << endl;
    cout << "2. View Recycling Statistics" << endl;
    cout << "3. Enviromnetal Impact Assessment" << endl;
    cout << "4. Generate a Report" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option (1-5): ";
}

int main() {

    // Dummy Data
    const int MAX_ENTRIES = 1024;
    
    string entryType[MAX_ENTRIES] = {"Plastic", "Glass", "Glass", "Plastic", "Paper", "Paper", "Metal", "Glass"};
    double entryWeight[MAX_ENTRIES] = {0.5, 2.2, 1.6, 0.8, 0.4, 0.7, 2.3, 0.8};
    string entryDate[MAX_ENTRIES] = {"2024-12-01", "2024-12-02", "2024-12-02", "2024-12-03", "2024-12-04", "2024-12-04", "2024-12-06", "2024-12-07"};
    int entryCount = 8;
    
    const int MATERIAL_TYPE = 4;

    string categories[MATERIAL_TYPE]={"Paper","Glass","Metal","Plastic"};
    double materialWeights[MATERIAL_TYPE] = {0.0, 0.0, 0.0, 0.0}; 
    int materialCounts[MATERIAL_TYPE] = {0, 0, 0, 0};
    double totalWeight=0;

    double impactValue[MATERIAL_TYPE]= {0.0, 0.0, 0.0, 0.0};
    double totalTreesSaved = 0, totalEnergySaved = 0; 

    int choice;

    do{
        displayMenu();
        cin >> choice;
        
        switch(choice) {
            
            case 1: cout << "\n***** Add an entry ******" << endl;
                    wasteInput(entryType, entryWeight, entryDate, entryCount);
                    cout << "***** Add an entry ******\n" << endl;
                    break;

            case 2: calculateTotals(entryCount, entryType, entryWeight, entryDate,materialWeights, materialCounts, totalWeight, categories); 
                    break;

            case 3: environmentalImpact(materialWeights, categories, impactValue, totalTreesSaved, totalEnergySaved);
                    break;

            case 4: calculateTotals(entryCount, entryType, entryWeight, entryDate,materialWeights, materialCounts, totalWeight, categories);
                    environmentalImpact(materialWeights, categories, impactValue, totalTreesSaved, totalEnergySaved);
                    generateRecyclingReport(entryCount, totalWeight, materialWeights, categories);
                    break;
            
            case 5: cout << "Exiting program...";
                    break;

            default: cout << "Invalid Option! Please enter a number between 1 and 5.\n" << endl;
        }
    } while(choice!=5);

    system("pause");

    return 0;
}



