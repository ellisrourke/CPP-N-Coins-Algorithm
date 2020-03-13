#include <iostream>
#include <vector>
#include<numeric>




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
/*
for(int i=0;i<solutions.size();i++){
    for(int j=0;j<solutions[i].size();j++){
        std::cout << solutions[i][j] << " ";
    } std::cout << std::endl;
}
 */
}