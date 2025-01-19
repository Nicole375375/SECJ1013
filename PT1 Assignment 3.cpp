//Nicole Lee A24CS0287
//Sam Wei Leng A24CS0295
// 10 JAN 2025
//PT1 ASSIGNMENT 3

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void getInput(string universities[], int intake[], int enrolment[], int output[], int &count);
int calTotal(int arr[], int size);
int getLowest(int arr[], int size);
int getHighest(int arr[], int size);
const int MAX_UNIVERSITIES = 20;

int main() {
    string universities[MAX_UNIVERSITIES];
    int intake[MAX_UNIVERSITIES], enrolment[MAX_UNIVERSITIES], output[MAX_UNIVERSITIES];
    int count = 0;

    ifstream inputFile("input.txt");

    if (!inputFile) {
        cout << "Error opening input file!" << endl;
        return 1;
    }

    getInput(universities, intake, enrolment, output, count);

    ofstream outputFile("output.txt");
    if (!outputFile) {
        cout << "Error opening output file!" << endl;
        return 1;
    }

    outputFile << setw(57) << "NUMBER OF STUDENTS' INTAKE, ENROLMENT AND OUTPUT\n";
    outputFile << setw(46) << "IN PUBLIC UNIVERSITIES (2023)\n\n";
    outputFile << "---------------------------------------------------------------\n";
    outputFile << "  UNIVERSITY" << setw(18) << "INTAKE" << setw(17) << "ENROLMENT" << setw(13) << "OUTPUT\n";
    outputFile << "---------------------------------------------------------------\n";

    for (int i = 0; i < count; i++) {
        outputFile << setw(5) << "";
        outputFile << left << setw(10) << universities[i];
        outputFile << right << setw(15) << intake[i] << setw(15) << enrolment[i] << setw(15) << output[i] << endl;
    }

    int totalIntake = calTotal(intake, count);
    int totalEnrolment = calTotal(enrolment, count);
    int totalOutput = calTotal(output, count);

    float avgIntake = totalIntake / static_cast<float>(count);
    float avgEnrolment = totalEnrolment / static_cast<float>(count);
    float avgOutput = totalOutput / static_cast<float>(count);

    outputFile << "---------------------------------------------------------------\n";
    outputFile << setw(5) <<"";
    outputFile << left << setw(10) << "TOTAL ";
    outputFile << right << setw(15) << totalIntake << setw(15) << totalEnrolment << setw(15) << totalOutput << "\n";

    outputFile << setw(5) <<"";
    outputFile << left << setw(10) << "AVERAGE "; 
    outputFile << fixed << setprecision(2);
    outputFile << right << setw(15) << avgIntake << setw(15) << avgEnrolment << setw(15) << avgOutput << "\n";

    // Get the lowest and highest for intake, enrolment, and output separately
    int lowestIntakeIndex = getLowest(intake, count);
    int highestIntakeIndex = getHighest(intake, count);

    int lowestEnrolmentIndex = getLowest(enrolment, count);
    int highestEnrolmentIndex = getHighest(enrolment, count);

    int lowestOutputIndex = getLowest(output, count);
    int highestOutputIndex = getHighest(output, count);

    // Output the results
    outputFile << "---------------------------------------------------------------\n";
    outputFile << "THE LOWEST NUMBER OF STUDENTS' INTAKE    = " << intake[lowestIntakeIndex] << " (" << universities[lowestIntakeIndex] << ")\n";
    outputFile << "THE LOWEST NUMBER OF STUDENTS' ENROLMENT = " << enrolment[lowestEnrolmentIndex] << " (" << universities[lowestEnrolmentIndex] << ")\n";
    outputFile << "THE LOWEST NUMBER OF STUDENTS' OUTPUT    = " << output[lowestOutputIndex] << " (" << universities[lowestOutputIndex] << ")\n\n";
    
    outputFile << "THE HIGHEST NUMBER OF STUDENTS' INTAKE    = " << intake[highestIntakeIndex] << " (" << universities[highestIntakeIndex] << ")\n";
    outputFile << "THE HIGHEST NUMBER OF STUDENTS' ENROLMENT = " << enrolment[highestEnrolmentIndex] << " (" << universities[highestEnrolmentIndex] << ")\n";
    outputFile << "THE HIGHEST NUMBER OF STUDENTS' OUTPUT    = " << output[highestOutputIndex] << " (" << universities[highestOutputIndex] << ")\n\n";

    outputFile << "THE RANGE OF NUMBER OF STUDENTS' INTAKE    = " << intake[highestIntakeIndex] - intake[lowestIntakeIndex] << "\n";
    outputFile << "THE RANGE OF NUMBER OF STUDENTS' ENROLMENT = " << enrolment[highestEnrolmentIndex] - enrolment[lowestEnrolmentIndex] << "\n";
    outputFile << "THE RANGE OF NUMBER OF STUDENTS' OUTPUT    = " << output[highestOutputIndex] - output[lowestOutputIndex] << "\n";
    outputFile << "---------------------------------------------------------------\n";

    cout << "Done writing results to output.txt!" << endl;
    inputFile.close();
    outputFile.close();

    return 0;
}

// Task 1
void getInput(string universities[], int intake[], int enrolment[], int output[], int &count) {
    ifstream inputFile("input.txt");
    string universityName;
    int i = 0;

    while (inputFile >> universityName >> intake[i] >> enrolment[i] >> output[i]) {
        universities[i] = universityName;
        i++;
        count++;
    }
}

// Task 2
int calTotal(int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

// Task 3
int getLowest(int arr[], int size) {
    int lowest = arr[0];
    int lowestIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < lowest) {
            lowest = arr[i];
            lowestIndex = i;
        }
    }
    return lowestIndex;
}

// Task 4
int getHighest(int arr[], int size) {
    int highest = arr[0];
    int highestIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > highest) {
            highest = arr[i];
            highestIndex = i;
        }
    }
    return highestIndex;
}


