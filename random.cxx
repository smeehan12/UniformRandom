//////////////////////////////////////////////////
//
// Author : Sam Meehan, samuel.meehan@cern.ch
//
// Description : This is a program that explores generating uniformly distributed random numbers
//               distributed between 0 and 1
// References : http://www.cplusplus.com/reference/cstdlib/rand/
//
//////////////////////////////////////////////////

#include <iostream>     /* cout */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
#include <string>
#include <map>

int main(){

  std::cout<<"Starting Random"<<std::cout;


  // RAND_MAD is a built in variable defined in the standard library
  std::cout<<"Rand Max : "<<RAND_MAX<<std::endl;
  
  // we need to define the seed of the generator
  // what happens if you take this line away?
  srand (time(NULL)*100000000);

  // get one of the random numbers from our generator
  int gen = rand();
  
  // calculate a random number stored as an integer
  int rand_int = gen/RAND_MAX;
  std::cout<<"rand_int : "<<rand_int<<std::endl;
  
  // calculate a random number after casting the generated number to be a float
  float rand_float = ((float)gen)/RAND_MAX;
  std::cout<<"rand_float : "<<rand_float<<std::endl;
  
  // generate a bunch of these and store in a vector
  std::vector<float> rand_numbers;
  
  int nGen=1000000;  // CHANGE me if you want to increase the stats
  
  for(int iGen=0; iGen<nGen; iGen++){
    float gen_rand_float = ((float)rand())/RAND_MAX;
    rand_numbers.push_back(gen_rand_float);
    
    // use the modulo operator to only print out every 100th time through our loop
    if(iGen%100==0){
      std::cout<<"iGen : "<<iGen<<"  "<<gen_rand_float<<std::endl;
    }
  }
  
  // count the number of occurrences of a range of numbers in our vector
  // we will use a map to form categories but there are many ways to keep track of this
  std::map<std::string,int> rand_dist;

  rand_dist["under"]    =0;
  rand_dist["[0.0,0.1)"]=0;
  rand_dist["[0.1,0.2)"]=0;
  rand_dist["[0.2,0.3)"]=0;
  rand_dist["[0.3,0.4)"]=0;
  rand_dist["[0.4,0.5)"]=0;
  rand_dist["[0.5,0.6)"]=0;
  rand_dist["[0.6,0.7)"]=0;
  rand_dist["[0.7,0.8)"]=0;
  rand_dist["[0.8,0.9)"]=0;
  rand_dist["[0.9,1.0)"]=0;
  rand_dist["over"]     =0;
  
  for(int iGen=0; iGen<nGen; iGen++){
  
    if(rand_numbers.at(iGen)<0.0)
      rand_dist["under"] +=1;
    else if(rand_numbers.at(iGen)>=0.0 && rand_numbers.at(iGen)<0.1)
      rand_dist["[0.0,0.1)"] +=1;
    else if(rand_numbers.at(iGen)>=0.1 && rand_numbers.at(iGen)<0.2)
      rand_dist["[0.1,0.2)"] +=1;
    else if(rand_numbers.at(iGen)>=0.2 && rand_numbers.at(iGen)<0.3)
      rand_dist["[0.2,0.3)"] +=1;
    else if(rand_numbers.at(iGen)>=0.3 && rand_numbers.at(iGen)<0.4)
      rand_dist["[0.3,0.4)"] +=1;
    else if(rand_numbers.at(iGen)>=0.4 && rand_numbers.at(iGen)<0.5)
      rand_dist["[0.4,0.5)"] +=1;
    else if(rand_numbers.at(iGen)>=0.5 && rand_numbers.at(iGen)<0.6)
      rand_dist["[0.5,0.6)"] +=1;
    else if(rand_numbers.at(iGen)>=0.6 && rand_numbers.at(iGen)<0.7)
      rand_dist["[0.6,0.7)"] +=1;
    else if(rand_numbers.at(iGen)>=0.7 && rand_numbers.at(iGen)<0.8)
      rand_dist["[0.7,0.8)"] +=1;
    else if(rand_numbers.at(iGen)>=0.8 && rand_numbers.at(iGen)<0.9)
      rand_dist["[0.8,0.9)"] +=1;
    else if(rand_numbers.at(iGen)>=0.9 && rand_numbers.at(iGen)<1.0)
      rand_dist["[0.9,1.0)"] +=1;
    else if(rand_numbers.at(iGen)>=1.0 )
      rand_dist["over"] +=1;
  
  }

  // show content of the raw counts
  std::cout << "\n\nDistribution of numbers : ";
  for (std::map<std::string,int>::iterator it=rand_dist.begin(); it!=rand_dist.end(); ++it){
    std::cout << it->first << " => " << it->second << '\n';
  }


  // show contents of the fractional distribution
  std::cout << "\n\nFractional distribution of numbers : ";
  for (std::map<std::string,int>::iterator it=rand_dist.begin(); it!=rand_dist.end(); ++it){
    std::cout << it->first 
              << " => " 
              << (float)it->second/nGen << '\n';
              
  }

  return 34;
}