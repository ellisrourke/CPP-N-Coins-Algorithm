#include <iostream>
#include <vector>
int countWays(std::vector<int> &coins,int index, int n){
    if(n == 0){
        return 1;
    }
    else if(n < 0){
        return 0;
    }

    int combinations = 0

    for(int i=0;i<coins.size();i++)
        combinations += countWays(coins,index,n - coins[index]) + countWays(coins, index+1,n);

}
int main() {
    std::vector<int> coins = {1,2,3,5,7,11};
    int index = 0;
    int lowerLimit = 1;
    int recursionLimit = 5
    std::cout << countWays(coins,0,5) << std::endl;
}

/*
int calculateChange(int &n,std::vector<int>&availableCoins, std::vector<int>&usedCoins,int &up, int &low,std::vector<std::vector<int>> solutions){
    if((std::accumulate(usedCoins.begin(),usedCoins.end(),0) == n) and low <usedCoins.size() > up) {
        solutions.emplace_back(usedCoins);
        return 1;
        }
    else if (usedCoins.size() > up){
        return 0;
    }
    else if((std::accumulate(usedCoins.begin(),usedCoins.end(),0) == n) > n){
        return 0;
    }
    else if(availableCoins.empty()){
        return 0;
    }
    int combinations = 0;

        std::vector<int>usedCoinsCopy(usedCoins);
        usedCoinsCopy.push_back(availableCoins[0]);
        combinations += calculateChange(n,availableCoins,usedCoinsCopy,low,up,solutions);
        availableCoins = std::vector<int>(availableCoins.begin()+1,availableCoins.end());
        combinations += calculateChange(n,availableCoins,usedCoins,low,up,solutions);
        return combinations;

}
int main() {
int n = 5;
int lowerLimit = 0;
int upperLimit = 10;
std::vector<int> coins = {1,2,3,5,7};
std::vector<int> usedCoins = {};
std::vector<std::vector<int>> solutions;
std::cout << calculateChange(n,coins,usedCoins,lowerLimit,upperLimit,solutions);

for(int i=0;i<solutions.size();i++){
    for(int j=0;j<solutions[i].size();j++){
        std::cout << solutions[i][j] << " ";
    } std::cout << std::endl;
}

}
*/