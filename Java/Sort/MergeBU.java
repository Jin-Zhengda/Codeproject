package Sort;

//自底向上的归并排序
//O(N*logN)
public class MergeBU implements Sort {
    private int[] aux;

    private void merge(int[] a, int lo, int mid, int hi) {
        int i = lo;
        int j = hi;

        for (int k = lo; k <= hi; k++) {
            aux[k] = a[k];
        }

        for (int k = lo; k <= hi; k++) {
            if (i > mid) {
                a[k] = aux[j++];
            } else if (j > hi) {
                a[k] = aux[i++];
            } else if (less(aux[j], aux[i])) {
                a[k] = aux[j++];
            } else {
                a[k] = aux[i++];
            }
        }
    }

    @Override
    public void sort(int[] a) {
        int N = a.length;
        aux = new int[N];
        for (int sz = 1; sz < N; sz *= 2) {
            for (int lo = 0; lo < N - sz; lo += sz * 2) {
                merge(a, lo, lo + sz - 1, Math.min(lo, lo + sz - 1));
            }
        }
    }

}
