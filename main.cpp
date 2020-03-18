#include <iostream>
#include <vector>
int countWays(std::vector<int> &coins,int index, int n, int lowerLimit,int upperLimit,int recursiveDepth,int count){
    if(n == 0){
        std::cout << "steps = " << (count) << std::endl;
        //if((recursiveDepth + coins[index-1])>=0){
        if(count <= upperLimit && count >= lowerLimit){
            return 1;
        } else
            return 0;
    }
    else if(n < 0){
        return 0;
    }
    else if(index == coins.size() && n > 0){

        return 0;
    }

    return countWays(coins, index, n - coins[index],lowerLimit,upperLimit,recursiveDepth-1,count+1) + countWays(coins, index + 1, n,lowerLimit,upperLimit,recursiveDepth-1,count);
}
int main() {
    std::vector<int> coins = {1,2,3,5};
    int index = 0;
    int n = 6;
    int lowerLimit = 5;
    int upperLimit = 6;
    int count = 0;
    std::cout << countWays(coins,index,n,lowerLimit,upperLimit,upperLimit,count) << " ways to make change" << std::endl;
}