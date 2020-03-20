#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <string>

int countWays(std::vector<int> const &coins,int index, int n, int const &lowerLimit,int const &upperLimit,int count,int const &amtCoins){
    if(n <= 0){
        if(n < 0){
            return 0;
        }
            if(count <= upperLimit && count >= lowerLimit)
                return 1;
            return 0;
    }
    if(index == amtCoins){
        return 0;
    }
    return countWays(coins, index, n - coins[index],lowerLimit,upperLimit,count+1,amtCoins) + countWays(coins, index + 1, n,lowerLimit,upperLimit,count,amtCoins);
}

int runCountWays(int n, int lowerLimit,int upperLimit){
    auto t1 = std::chrono::high_resolution_clock::now();
    int index = 0;
    int count = 0;
    std::vector<int> coins = {1,2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};//151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293};
    int amtCoins = coins.size();

    std::cout << n << " " << lowerLimit << " " << upperLimit << " //  "  << countWays(coins,index,n,lowerLimit,upperLimit,count,amtCoins);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>( t2 - t1 ).count();
    std::cout << " solutions found in " << duration << " second(s)" << std::endl;


}

int main() {
    std::ifstream infile;
    infile.open("input.txt");
    std::string inLine;
    std::vector<int> inputs;

    if(!infile.is_open()){
        std::cerr << "file error" << std::endl;
    }
    int x;

    while(std::getline(infile,inLine)){
        inputs.clear();
        std::istringstream in(inLine);
        std::copy(std::istream_iterator<int>(in),
                std::istream_iterator<int>(),
                std::back_inserter(inputs));

        if(inputs.size() == 1){
            runCountWays(inputs[0],0,inputs[0]);
        }
        else if (inputs.size() == 2){
            runCountWays(inputs[0],0,inputs[1]);
        } else if (inputs.size() == 3){
            runCountWays(inputs[0],inputs[1],inputs[2]);
        } else {
            std::cerr << "invalid input" << std::endl;
        }

    }




}




