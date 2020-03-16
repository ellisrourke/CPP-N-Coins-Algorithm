#include <iostream>
#include <vector>
int countWays(std::vector<int> &coins,int index, int n, int lowerLimit,int upperLimit,int recursiveDepth){
    if(n == 0){
        if((recursiveDepth + coins[index-1]) <= 0 && recursiveDepth + lowerLimit >= index-1){
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
    return countWays(coins, index, n - coins[index],lowerLimit,upperLimit,recursiveDepth-1) + countWays(coins, index + 1, n,lowerLimit,upperLimit,recursiveDepth-1);

}
int main() {
    std::vector<int> coins = {1,2,3,5,7};
    int index = 0;
    int n = 8;
    int lowerLimit = 5;
    int upperLimit = 5;
    std::cout << countWays(coins,index,n,lowerLimit,upperLimit,upperLimit) << " ways to make change" << std::endl;
}