#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>
#include <iterator>
#include <sstream>
//sieve of eratosthenes to caluclate primes upto the value specifies
std::vector<int> sieveOfEratosthnes(const int max){

    std::vector<int> sieve(max+1); // vector of max numbers, initialized to default value 0
    std::vector<int> primes = {};

    for (int i = 2; i < sieve.size(); i++)//run sieve for every number upto max
    {
        for (int j = i * i; j < sieve.size(); j +=i) //mark values as not prime that are multiples of i
            sieve[j] = 1;  // make number as not prime in sieve
    }

    for (int i = 1; i < sieve.size(); i++)
        if (sieve[i] == 0)  //push marked values from sieve array marked as prime to the prime array
            primes.push_back(i);

    return primes;
}

//recursive funtion to count check if a combination is valid
int countWays(std::vector<int> const &coins,int index, int n, int const &lowerLimit,int const &upperLimit,int count,int const &amtCoins){
    if(n <= 0){ //solution found or amount of of bounds
        if(n < 0){ //amount out of bounds
            return 0; //signifies solution not found
        }
            if(count <= upperLimit && count >= lowerLimit) //if the number of coins is within the range allows from user
                return 1; //add 1 to number of solutions
            return 0; //solution out of bounds
    }
    if(index == amtCoins){ //if the index has reached the end of the coins, no more solutions can exist, return
        return 0;
    }
    //returning result if (result if the coin at the current index is chosen and index not incremented) + (go to next available coin and run the previous statment in next recurive call)
    return countWays(coins, index, n - coins[index],lowerLimit,upperLimit,count+1,amtCoins)+countWays(coins, index + 1, n,lowerLimit,upperLimit,count,amtCoins);
}

//function to run program for each line of input file
int runCountWays(int n, int lowerLimit,int upperLimit){
    auto t1 = std::chrono::high_resolution_clock::now();
    std::vector<int> coins = sieveOfEratosthnes(n);
    int index = 0;
    int count = 0;
    int amtCoins = coins.size();
    //run program for current parameters
    std::cout << n << " " << lowerLimit << " " << upperLimit << " //  "  << countWays(coins,index,n,lowerLimit,upperLimit,count,amtCoins);
    auto t2 = std::chrono::high_resolution_clock::now();
    double duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
    //output the amount of time taken for program to run
    std::cout << " solutions found in " << duration/1000 << " second(s)" << std::endl;


}

int main(int argc, char *argv[]) {
    //open file passed on the command line
    std::ifstream infile;
    infile.open(argv[1]);
    std::string inLine;
    std::vector<int> inputs;

    //validate if the file has opened correctly
    if(!infile.is_open()){
        std::cerr << "file error" << std::endl;
    }

    //get values from file line by line
    while(std::getline(infile,inLine)){
        inputs.clear();
        std::istringstream in(inLine);
        std::copy(std::istream_iterator<int>(in),
                std::istream_iterator<int>(),
                std::back_inserter(inputs));

        //different parameterization of program arguments based on mode (if bounds have been given)
        if(inputs.size() == 1){
            runCountWays(inputs[0],0,inputs[0]);
        }
        else if (inputs.size() == 2){
            runCountWays(inputs[0],inputs[1],inputs[1]);
        } else if (inputs.size() == 3){
            runCountWays(inputs[0],inputs[1],inputs[2]);
        } else {
            std::cerr << "invalid input" << std::endl;
        }

    }
}




