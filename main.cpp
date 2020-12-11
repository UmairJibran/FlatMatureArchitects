#include <iostream>

using namespace std;

struct Patient{
  string name,gender;
  int age;
  bool hasSugar, hasHeartDisease, hasCovid;

  Patient(string name, string gender, int age, bool hasSugar, bool hasHeartDisease, bool hasCovid){
    this->name = name;
    this->gender = gender;
    this->age = age;
    this->hasHeartDisease = hasHeartDisease;
    this->hasCovid = hasCovid;
    this->hasSugar = hasSugar;
  }

};

int main() {
  Patient patients[10] = {{"","",0,false,false,false},{"","",0,false,false,false},{"","",0,false,false,false},{"","",0,false,false,false},{"","",0,false,false,false},{"","",0,false,false,false},{"","",0,false,false,false},{"","",0,false,false,false},{"","",0,false,false,false},{"","",0,false,false,false}};

  char op = 'y';
  int counter = 0;
  int females = 0, males = 0, binary = 0,children = 0, critical = 0, covidPositive = 0, old = 0, sugarPositive = 0, heartPatients = 0;
  while(op != 'n'){
    char yn;
    cout << "Enter Patient Name: ";
    cin >> patients[counter].name;
    cout << "Enter Patient Age: ";
    cin >> patients[counter].age;
    cout << "Enter Patient Gender: ";
    cin >> patients[counter].gender;
    cout << "Is COVID Positive? ";
    cin >> yn;
    if(yn == 'y') patients[counter].hasCovid = true;
    cout << "Is BLood Sugar Positive? ";
    cin >> yn;
    if(yn == 'y') patients[counter].hasSugar = true;
    cout << "Does Patient have heart Disease? ";
    cin >> yn;
    if(yn == 'y') patients[counter].hasHeartDisease = true;
    if(patients[counter].gender == "m") males += 1; else if(patients[counter].gender == "f") females += 1; else binary += 1;
    if(patients[counter].age < 15) children +=1;
    if(patients[counter].hasSugar) sugarPositive += 1;
    if(patients[counter].hasCovid) covidPositive += 1;
    if(patients[counter].hasHeartDisease) heartPatients += 1;
    if(patients[counter].hasCovid && (patients[counter].hasSugar || patients[counter].hasHeartDisease)) critical += 1;
    counter += 1;

    cout << "Do you want to add another record? ";
    cin >> op;
  }
  for(int i = 0; i < counter; i+=1){
    cout << "Name " << patients[i].name << endl;
    cout << "Age " << patients[i].age << endl;
    cout << "Gender " << patients[i].gender << endl;
    cout << "hasCovid " << patients[i].hasCovid << endl;
    cout << "hasSugar " << patients[i].hasSugar << endl;
    cout << "hasHeartDisease " << patients[i].hasHeartDisease << endl << endl;
  }
  cout << "Total Patients: " << counter << endl;
  cout << "Total males: " << males << endl;
  cout << "Total females: " << females << endl;
  cout << "Total Binary: " << binary << endl;
  cout << "Total children: " << children << endl;
  cout << "Total patients with blood sugar: " << sugarPositive << endl;
  cout << "Total patients with heart disease: " << heartPatients << endl;
  cout << "Total patients with covid Positive: " << covidPositive << endl;
  cout << "Total Critical patients: " << critical << endl; 
 }