package Sort;

//O(N**2)
//对于部分有序的数组效率较高
public class Insertion implements Sort {
    @Override
    public void sort(int[] a) {
        int N = a.length;
        for (int i = 1; i < N; i++) {
            for (int j = i; j > 0; j--) {
                if (less(a[j], a[j - 1])) {
                    exch(a, j, j - 1);
                }
            }
        }
    }
}
