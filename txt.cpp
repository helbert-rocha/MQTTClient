#include "txt.h"
#include <fstream>
#include <iostream>
using namespace std;
TXT::TXT(){}
TXT::~TXT(){}
void TXT::save(){

    char data[100];

   // open a file in write mode.
   ofstream outfile;
   outfile.open("meuprimeirotestc++.txt");

   cout << "Writing to the file" << endl;
   cout << "Enter your name: ";
   cin.getline(data, 100);

   // write inputted data into the file.
   outfile << data << endl;

   cout << "Enter your age: ";
   cin >> data;
   cin.ignore();

   // again write inputted data into the file.
   outfile << data << endl;

   // close the opened file.
   outfile.close();
}
