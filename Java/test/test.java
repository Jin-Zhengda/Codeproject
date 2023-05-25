package test;

import Sort.MergeTD;

public class test {
    public static void main(String args[]) {
        int[] a = {5, 4, 2, 6, 3, 1};
        MergeTD mergeTD = new MergeTD();
        mergeTD.sort(a);
        System.out.println(mergeTD.getCount());
        System.out.println(mergeTD.isSorted(a));
    }
}
