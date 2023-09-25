import java.util.Scanner;

public class NumsMedian {
    private static int kNum(int[] nums1, int[] nums2, int k) {
        int length1 = nums1.length;
        int length2 = nums2.length;
        int index1 = 0; 
        int index2 = 0;
        while (true) {
            if (index1 == length1) {
                return nums2[index2 + k - 1];
            }
            if (index2 == length2) {
                return nums1[index1 + k - 1];
            }
            if (k == 1) {
                return Math.min(nums1[index1], nums2[index2]);
            }
            int newIndex1 = Math.min(index1 + k / 2, length1) - 1;
            int newIndex2 = Math.min(index2 + k / 2, length2) - 1;
            if (nums1[newIndex1] <= nums2[newIndex2]) {
                k = k - (newIndex1 - index1 + 1);
                index1 = newIndex1 + 1;
            } else {
                k = k - (newIndex2 - index2 + 1);
                index2 = newIndex2 + 1;
            }
        }
    }

    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int totalLength = nums1.length + nums2.length;
        if (totalLength % 2 == 1) {
            return kNum(nums1, nums2, totalLength / 2 + 1);
        } else {
            return (kNum(nums1, nums2, totalLength / 2) + kNum(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int m = Integer.parseInt(in.nextLine());
        int n = Integer.parseInt(in.nextLine());
        int[] nums1 = new int[m];
        int[] nums2 = new int[n];
        for (int i = 0; i < m; i++) {
            nums1[i] = Integer.parseInt(in.nextLine());
        }
        for (int i = 0; i < n; i++) {
            nums2[i] = Integer.parseInt(in.nextLine());
        }
        double median = findMedianSortedArrays(nums1, nums2);
        System.out.print(String.format("%.1f", median));
    }
}
