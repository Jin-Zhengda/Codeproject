package Sort;

//插入排序的改进，对大数组效率较高
//O(N**x), 1 < x < 2
public class Shell implements Sort {
    @Override
    public void sort(int[] a) {
        int N = a.length;
        int h = 1;
        while (h < N / 3) {
            h = h * 3 + 1;
        }
        while (h > 1) {
            for (int i = h; i < N; i++) {
                for (int j = i; j >= h; j -= h) {
                    if (less(a[j], a[j - h])) {
                        exch(a, j, j - h);
                    }
                }
            }
        }
    }

}
