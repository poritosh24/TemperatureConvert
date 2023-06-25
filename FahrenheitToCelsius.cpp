#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to convert Fahrenheit to Celsius
double convertToFahrenheit(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

int main() {
    ifstream inputFile("FahrenheitTemperature.txt"); // Open the input file

    if (!inputFile) {
        cerr << "Failed to open the input file." << endl;
        return 1;
    }

    ofstream outputFile("CelsiusTemperature.txt"); // Open the output file

    if (!outputFile) {
        cerr << "Failed to create the output file." << endl;
        return 1;
    }

    string city;
    double temperature;

    while (inputFile >> city >> temperature) {
        double celsius = convertToFahrenheit(temperature);
        outputFile << city << " " << celsius << endl;
    }

    inputFile.close(); // Close the input file
    outputFile.close(); // Close the output file

    return 0;
}
