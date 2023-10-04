#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <random>

// a macro that says that x can be displayed w/ a fixed ammount
// of integers, while the precision is at 2
#define FIXED_FLOAT(x) fixed<<setprecision(2)<<(x)

using namespace std;

const string FILE_NAME = "names.txt";

void getNames(string fileName, vector<string> &nameList);
void displayChecks(int iterator);
string generateDate();
double generateAmmount();

int main(){
  vector<string> nameList;
  getNames(FILE_NAME, nameList);
  

  return 0;
}

void getNames(string fileName, vector<string> &nameList) {
  fstream file;
  file.open(fileName, fstream::in); //file will only be readable
  if(file.is_open()) {
    string line;
    while  (getline(file, line)) { //for every line in file
      nameList.push_back(line);
    }
    file.close();
  }
  else {
    cout << "File is not loading, closing program...\n";
    exit(1);
  }
}

string generateDate() { //choose a random date out of the 365 days of the year
  default_random_engine generator(time(0));
  uniform_real_distribution<double> distribution(0, 360);
  string month = "";
  string day = "";
  string year = "23";
  int randomNumber = distribution(generator); 
  if (randomNumber <= 31){
    month = "1";
    day = to_string(randomNumber);
  } else if (randomNumber > 31 && randomNumber <= 59){
    month = "2";
    day = to_string(randomNumber - 31);
  } else if (randomNumber > 59 && randomNumber <= 90){
    month = "3";
    day = to_string(randomNumber - 59);
  } else if (randomNumber > 90 && randomNumber <= 120){
    month = "4";
    day = to_string(randomNumber - 90);
  } else if (randomNumber > 120 && randomNumber <= 151){
    month = "5";
    day = to_string(randomNumber - 120);
  } else if (randomNumber > 151 && randomNumber <= 181) {
    month = "6";
    day = to_string(randomNumber - 151);
  } else if (randomNumber > 181 && randomNumber <= 212) {
    month = "7";
    day = to_string(randomNumber - 181);
  } else if (randomNumber > 212 && randomNumber <= 243) {
    month = "8";
    day = to_string(randomNumber - 212);
  } else if (randomNumber > 243 && randomNumber <= 273){
    month = "9";
    day = to_string(randomNumber - 243);
  } else if (randomNumber > 273 && randomNumber <= 304) {
    month = "10";
    day = to_string(randomNumber - 273);
  } else if (randomNumber > 304 && randomNumber <= 334){
    month = "11";
    day = to_string(randomNumber - 304);
  } else if (randomNumber > 335 && randomNumber <= 365) {
    month = "12";
    day = to_string(randomNumber -335);
  }
  return month + '/' + day + "/" + year;
}

double generateAmmount() {
  default_random_engine generator(time(0));
  uniform_real_distribution<double> distribution(0.00, 10000.00);
  return distribution(generator);
}

