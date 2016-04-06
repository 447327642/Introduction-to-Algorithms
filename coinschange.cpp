/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/
class Solution {

public:

    int coinChange(vector<int>& coins, int amount) {

    int len=coins.size();

    if(len<=0 || amount<=0)return 0;

    sort(coins.begin(),coins.end());

    vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,amount+1)); 

    for(int i=0;i<len;i++)

    {

        dp[i][0]=0;

        if(coins[0]==1)

        dp[i][1]=1;

    }

    for(int j=1;j<=amount;j++)

    {

        if(j%coins[0]==0)

        dp[0][j]=j/coins[0];

    }

    for(int i=1;i<len;i++)

    {

        for(int j=1;j<=amount;j++)

        {

            if(coins[i]>j)dp[i][j]=dp[i-1][j];

            else

            {

              dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i]]+1);

            }

        

        }

    }

    return dp[len-1][amount]>amount?-1:dp[len-1][amount];

    }

};

method2
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int j = 0; j < coins.size(); ++j) {
            for (int i = coins[j]; i <= amount; ++i)
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
