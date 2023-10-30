/*
 * LeetCode 122.买卖股票的最佳时机2
 * 贪心算法
 */

package LeetCode;

public class maxStockProfit2 {
    public int maxProfit(int[] prices) {
        int[] S = new int[prices.length + 1];
        S[0] = 0;
        for (int i = 1; i < prices.length + 1; i++) {
            if (prices[i - 1] < prices[i - 2]) {
                S[i] = S[i - 1] + prices[i - 1] - prices[i - 2];
            } else {
                S[i] = S[i - 1];
            }
        }
        return S[S.length - 1];
    }
}
