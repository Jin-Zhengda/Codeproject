/*
 * LeetCode LCR 090.打家劫舍2
 * 贪心算法
 */

package LeetCode;

public class rob2 {
    //路径为环状，通过切割，取2~n的一段和1~n-1的一段分别求最优解，最后在两个解中取最大值
    public int maxRobMoney(int[] nums) {
        int n = nums.length;
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return Math.max(nums[0], nums[1]);
        }
        int[] arr1 = new int[n - 1];
        int[] arr2 = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            arr1[i] = nums[i];
            arr2[i] = nums[i + 1];
        }
        int[] m1 = new int[n - 1];
        int[] m2 = new int[n - 1];
        m1[0] = arr1[0];
        m2[0] = arr2[0];
        m1[1] = Math.max(arr1[0], arr1[1]);
        m2[1] = Math.max(arr2[0], arr2[1]);
        for (int i = 2; i < n - 1; i++) {
            m1[i] = Math.max(m1[i - 2] + arr1[i], m1[i - 1]);
            m2[i] = Math.max(m2[i - 2] + arr2[i], m2[i - 1]);
        }
        return Math.max(m1[n - 2], m2[n - 2]);
    }
}
