/**
 * LeetCode 322.零钱兑换1
 * 动态规划
 */
package LeetCode;
import java.util.*;

public class coinChange {
    //类似无限背包问题
    //使用二维数组，dp[i][j]为前i个硬币兑换j大小面值所需的最少硬币数
    public static int minCoinNums1(int[] coins, int amount) {
        Arrays.sort(coins);
        int[][] dp = new int[coins.length][amount + 1];

        for (int j = 0; j < amount + 1; j ++) {
            if (j % coins[0] == 0) {
                dp[0][j] = j / coins[0];
            } else {
                dp[0][j] = amount + 1; // 无法兑换设置一个较大值
            }
        }

        for (int i = 1; i < coins.length; i ++) {
            for(int j = 0; j < amount + 1; j++) {
                if (j < coins[i]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - coins[i]] + 1);
                }
            }
        }

        int result = dp[coins.length - 1][amount];
        if (result <= amount) {
            return result;
        } else {
            return -1;
        }
    }

    //使用一维数组，dp[i]表示兑换j大小面值所需的最少硬币数
    public static int minCoinNums2(int[] coins, int amount) {
        Arrays.sort(coins);
        int[] dp = new int[amount + 1];

        Arrays.fill(dp, amount + 1);
        dp[0] = 0;
        for (int i = 1; i < amount + 1; i ++) {
            for (int j = 0; j < coins.length; j ++) {
                if (i - coins[j] >= 0) {
                    dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        if (dp[amount] <= amount) {
            return dp[amount];
        } else {
            return -1;
        }
    }

    public static void main(String[] args) {
        int[] coins = {2, 5};
        int amount = 13;
        System.out.println(minCoinNums1(coins, amount));
    }
    
}