
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
  ifstream file("advent_day_2_input.txt");
  string string_in,direction,temp;
  int distance=0,horiz = 0, vert=0,aim=0;
  while(getline(file, string_in)){
    direction = string_in[0];
    temp = string_in[string_in.length()-1];
    distance = stoi(temp);
    cout<<direction<<" "<<distance<<endl;
    if (direction == "f"){
      horiz += distance;
      if(aim != 0){
        vert += distance * aim;
      }
    }
    else if (direction == "u"){
      aim += distance *-1;

    }
    else if (direction == "d"){
      aim+=distance;
    }
    else{
      cout<<"oops"<<endl;
    }
  }
  cout<<"Total Vertical Distance: "<<vert<<endl;
  cout<<"Total Horizontal Distance: "<<horiz<<endl;
  cout<<"Multiplied together: "<< vert*horiz<<endl;
}
