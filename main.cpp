//Name : Ibrahim Talha ASAN
//Course:Programming for Engineers,64170019,Fall Semester,2020-2021.
//Purpose:The purpose of this problem is to classify the data from Data.txt
//correctly and assign it to variables, then write these assigned
//variables to the binary file.

#include <iostream>
#include<fstream>
#include <sstream>
using namespace std;

class Doctor{
    //variables related Doctor class
    string name;
    int age,socialSecurityNumber,officeNumber,experienceNumber,totalPatientNumber;
public:
    //set functions related Doctor class
    void setName(string newName){
        name=newName;
    }
    void setAge(int  newAge){
        age=newAge;
    }
    void setSocialSecurityNumber(int newSocialSecurityNumber){
        socialSecurityNumber=newSocialSecurityNumber;
    }
    void setOfficeNumber(int newOfficeNumber){
        officeNumber=newOfficeNumber;
    }
    void setExperienceNumber(int  newExperienceNumber){
        experienceNumber=newExperienceNumber;
    }
    void setTotalPatientNumber(int  newTotalPatientNumber){
        totalPatientNumber=newTotalPatientNumber;
    }
    //constructor method related Doctor class
    Doctor(){
    }
    //deconstructor method related Doctor class
    ~Doctor(){
    }
};

class Patient{
    //variables related Patient class
    string name;
    int age;
    int socialSecurityNumber;
public:
    //set functions related Patient class
    void setName(string newName){
        name=newName;
    }
    void setAge(int  newAge){
        age=newAge;
    }
    void setSocialSecurityNumber(int newSocialSecurityNumber){
        socialSecurityNumber=newSocialSecurityNumber;
    }
    //constructor method related Patient class
    Patient(){
    }
    //deconstructor method related Patient class
    ~Patient(){
    }
};

class PayingPatient{
    //variables related PayingPatient class
    string name;
    int age,numberOfDays,dailyCharge,treatmentCharge,socialSecurityNumber;
public:
    //set functions related PayingPatient class
    void setName(string newName){
        name=newName;
    }
    void setAge(int  newAge){
        age=newAge;
    }
    void setNumberOfDays(int  newNumberOfDays){
        numberOfDays=newNumberOfDays;
    }
    void setDailyCharge(int  newDailyCharge){
        dailyCharge=newDailyCharge;
    }
    void setTreatmentCharge(int  newTreatmentCharge){
        treatmentCharge=newTreatmentCharge;
    }
    void setSocialSecurityNumber(int newSocialSecurityNumber){
        socialSecurityNumber=newSocialSecurityNumber;
    }
    //constructor method related PayingPatient class
    PayingPatient(){
    }
    //deconstructor method related PayingPatient class
    ~PayingPatient(){
    }
    friend void calculate(int dailyCharge,int numberOfDays,int treatmentCharge);
};

void calculate(int dailyCharge,int numberOfDays,int treatmentCharge){
    treatmentCharge = dailyCharge * numberOfDays;
    cout << "This paying patient's treatment charge is " << treatmentCharge <<endl;
}

class Person{
    //set functions related Person class
    string name;
    int age;
    int socialSecurityNumber;
public:
    //set functions related Person class
    void setName(string newName){
        name=newName;
    }
    void setAge(int  newAge){
        age=newAge;
    }
    void setSocialSecurityNumber(int newSocialSecurityNumber){
        socialSecurityNumber=newSocialSecurityNumber;
    }
    //constructor method related Person class
    Person(){
    }
    //deconstructor method related Person class
    ~Person(){
    }
};

//reading datas from the Data.txt
int readingFile(Doctor d[3],Patient p[4],PayingPatient pp[2],Person person[3]) {
    fstream readingData;
    string line;
    int i;
    int temp;
    const char iteration =',';
    string S;
    readingData.open("C:\\src\\cpp_projects\\hw3\\Data.txt");

    if (!readingData) {
        cout << "Error, file couldn't be opened" << endl;
        return 1;
    }
    while (getline(readingData, line)) {
        //Performs the operations of the Doctor class.
        if (line == "Doctors") {
            i = 0;
            cout<<"Doctor's Data"<<endl;
            //It takes information line by line until it becomes Patients.
            while (getline(readingData, line) && line != "Patients") {
                istringstream ss(line);
                getline(ss, S, iteration);
                d[i].setName(S);
                cout << "Doctor's Name: " << S << endl;

                getline(ss, S, iteration);
                istringstream(S) >> temp;
                d[i].setAge(temp);
                cout << "Doctor's Age: " << S << endl;

                getline(ss, S, iteration);
                istringstream(S) >> temp;
                d[i].setSocialSecurityNumber(temp);
                cout << "Doctor's Social Security Number: " << S << endl;

                getline(ss, S, iteration);
                istringstream(S) >> temp;
                d[i].setOfficeNumber(temp);
                cout << "Doctor's Office Number: " << S << endl;

                getline(ss, S, iteration);
                istringstream(S) >> temp;
                d[i].setExperienceNumber(temp);
                cout << "Doctor's Experience Number: " << S << endl;

                getline(ss, S, iteration);
                istringstream(S) >> temp;
                d[i].setTotalPatientNumber(temp);
                cout << "Doctor's Total Patient Number: " << S << endl;
                i++;
                cout << endl;
            }
        }
        cout << "**********************************************"<< endl;
        //Performs the operations of the Patients class.
        if (line == "Patients") {
            i = 0;
            cout<<"Patient's Data"<<endl;
            //It takes information line by line until it becomes Paying Patients.
            while (getline(readingData, line) && line != "Paying Patients") {

                istringstream ss(line);
                getline(ss, S, iteration);
                p[i].setName(S);
                cout << "Patient's Name: " << S << endl;

                getline(ss, S, iteration);
                istringstream(S) >> temp;
                p[i].setAge(temp);
                cout << "Patient's age: " << S << endl;

                getline(ss, S, iteration);
                istringstream(S) >> temp;
                p[i].setSocialSecurityNumber(temp);
                cout << "Patient's Security Number: " << S << endl;
                i++;
                cout << endl;
            }
        }
        cout << "**********************************************"<< endl;
        //Performs the operations of the Paying Patients class
        if (line == "Paying Patients") {
            i = 0;
            cout<<"Person's Data"<<endl;
            //It takes information line by line until it becomes Person.
            while (getline(readingData, line) && line != "Person") {

                istringstream ss(line);
                getline(ss, S, iteration);
                pp[i].setName(S);
                cout << "Paying Patient's Name: " << S << endl;

                getline(ss, S, iteration);
                istringstream(S) >> temp;
                pp[i].setAge(temp);
                cout << "Paying Patient's Age: " << S << endl;

                getline(ss, S, iteration);
                istringstream(S) >> temp;
                pp[i].setNumberOfDays(temp);
                int numberOfDays = temp;
                cout << "Paying Patient's Number of Days: " << S << endl;

                getline(ss, S, iteration);
                istringstream(S) >> temp;
                pp[i].setDailyCharge(temp);
                int dailyCharge = temp;
                cout << "Paying Patient's Daily Charge: " << S << endl;

                getline(ss, S, iteration);
                istringstream(S) >> temp;
                pp[i].setTreatmentCharge(temp);
                int treatmentCharge = temp;
                cout << "Paying Patient's Treatment Charge: " << S << endl;

                getline(ss, S, iteration);
                istringstream(S) >> temp;
                pp[i].setSocialSecurityNumber(temp);
                cout << "Paying Patient's Security Number: " << S << endl;
                i++;
                calculate(dailyCharge,numberOfDays,treatmentCharge);
                cout << endl;
            }
        }
        cout << "**********************************************"<< endl;
        //Performs the operations of the Person class
        if (line == "Person") {
            i = 0;
            cout<<"Person's Data"<<endl;
            //It takes line by line until the last information.
            while (getline(readingData, line)) {
                istringstream ss(line);
                getline(ss, S, iteration);
                person[i].setName(S);
                cout << "Person's Name: " << S << endl;

                getline(ss, S, iteration);
                istringstream(S) >> temp;
                person[i].setAge(temp);
                cout << "Person's Age: " << S << endl;

                getline(ss, S, iteration);
                istringstream(S) >> temp;
                person[i].setSocialSecurityNumber(temp);
                cout << "Person's Security Number: " << S << endl;
                i++;
                cout << endl;
            }
        }
    }
    readingData.close();
}

//write Binary files from the reading Data.txt
void writeBinaryFile(Doctor d[3],Patient p[4],PayingPatient pp[2],Person person[3]){
    //create and write doctor.bin file.
    fstream file("C:\\src\\cpp_projects\\hw3\\doctor.bin",ios::binary | ios::out );
    for (int i =0;i<3;i++) {
        file.write((char *) &d[i], sizeof(d));
    }
    file.close();
    //create and write patient.bin file.
    fstream file1("C:\\src\\cpp_projects\\hw3\\patient.bin",ios::binary | ios::out );
    for (int i =0;i<4;i++) {
        file.write((char *) &p[i], sizeof(d));
    }
    file1.close();
    //create and write payingpatient.bin file.
    fstream file2("C:\\src\\cpp_projects\\hw3\\payingpatient.bin",ios::binary |  ios::out );
    for (int i =0;i<2;i++) {
        file.write((char *) &pp[i], sizeof(d));
    }
    file2.close();
    //create and write person.bin file.
    fstream file3("C:\\src\\cpp_projects\\hw3\\person.bin",ios::binary | ios::out );
    for (int i =0;i<3;i++) {
        file.write((char *) &person[i], sizeof(d));
    }
    file3.close();
}

int main(){
    //create objects
    Doctor doctorData[3];
    Patient patientData[4];
    PayingPatient payingPatientData[2];
    Person PersonData[3];
        
    //calling readingFile function
    readingFile(doctorData,patientData,payingPatientData,PersonData);
    //calling writeBinaryFile function
    writeBinaryFile(doctorData,patientData,payingPatientData,PersonData);

    return 0;
}