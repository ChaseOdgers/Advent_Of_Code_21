#include <iostream>
#include <fstream>
#include <queue>

int part1(){
  //Load data into queue
  int lineIn, cur, next, incCount = 0;
  std::queue<int> RawQueue;
  std::ifstream infile("advent_day_1_input.txt");
  while (infile >> lineIn){ RawQueue.push(lineIn); }

  //Evaluate data
  cur = RawQueue.front();
  while (!RawQueue.empty()){
    RawQueue.pop();
    next = RawQueue.front();
    if (next > cur){  incCount++; }
    cur = next;
  }

  return incCount;
}

int part2(){
  //Load data into vector
  int lineIn, cur, next, incCount = 0, i=0;
  std::queue<int> RawQueue;
  std::ifstream infile("advent_day_1_input.txt");
  std::vector<int> RawVect;
  while (infile >> lineIn){ RawVect.push_back(lineIn); }

  //Evaluate Data
  while (i < RawVect.size()-3){
    cur = RawVect[i] + RawVect[i+1] + RawVect[i+2];
    next = RawVect[i+1] + RawVect[i+2] + RawVect[i+3];
    if (cur < next){
      incCount++;
    }
    i++;
  }

  return incCount;
}


int main(){
  std::cout<<"Total increases: "<<part1()<<std::endl;
  std::cout<<"Total window increases: "<<part2()<<std::endl;
}
