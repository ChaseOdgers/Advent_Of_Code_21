#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> finder(vector<string> strVect, int pos, string gamma){
  cout<<"New Size: "<<strVect.size()<<endl;
  cout<<"POS: "<<pos<<endl;
  vector<string> newStrVect;
  for(int i=0; i<strVect.size(); i++){
    string curString = strVect[i];
    if (curString[pos] == gamma[pos]){
      newStrVect.push_back(strVect[i]);
    }
  }
  // for (auto i : newStrVect){
  //   cout<<i<<endl;
  // }
  cout<<"Incrementing position tracker"<<endl;
  pos += 1;
  if((strVect.size()<3)||(pos > 11)){
    cout<<"Returning vector of size: "<<newStrVect.size()<<endl;
    return newStrVect;
  }
  else{
    cout<<"Recursing"<<endl;
    finder(newStrVect,pos,gamma);
  }
}

int main(){
  ifstream file("advent_day_3_input.txt");
  string string_in;
  int gamma[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
  while(getline(file, string_in)){
    for(int i=0; i<12;i++){
      if(string_in[i]== '0'){
        gamma[i]++;
      }
      if(string_in[i] == '1'){
        gamma[i]--;
      }
    }
  }
  file.close();
  ifstream file2("advent_day_3_input.txt");
  for (int i=0; i<12; i++){
    if(gamma[i]<0){
      gamma[i] = 0;
    }
    if(gamma[i]>0){
      gamma[i] = 1;
    }
  }
  string gammaOut;
  for(int i=0; i<12; i++){
    gammaOut = gammaOut + to_string(gamma[i]);
  }
  cout<<"Gamma is: "<<gammaOut<<endl;
  vector<string> strVect;
  while(getline(file2, string_in)){
      if (string_in[0] == gammaOut[0]){
        //list of all strings where first bit is the most common bit
        strVect.push_back(string_in);
      }
    }
  cout<<strVect.size()<<endl;
  vector<string> results;
  results = finder(strVect, 1, gammaOut);
}
