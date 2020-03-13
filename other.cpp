//
// Created by Ellis on 13/03/2020.
//

#include <iostream>
#include <vector>


int countWays(std::vector<int> &coins,int index, int n){
    if(n == 0){
        return 1;
    }
    else if(n < 0){
        return 0;
    } else if (n > 0 && index == coins.size()){
        return 0;
    }

    return countWays(coins,index,n - coins[index]) + countWays(coins, index+1,n);

}
int main() {

    std::vector<int> coins = {1,2,3,5,7,11};
    std::cout << countWays(coins,0,5) << std::endl;
}