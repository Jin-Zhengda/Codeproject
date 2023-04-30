package Sort;
//三向切分的快速排序
public class QuickWithThreeWays implements Sort{
    public void sort(int[] a) {
        StdRandom.shuffle(a);
        sort(a, 0, a.length - 1);
     }
 
     private void sort(int[] a, int lo, int hi) {
        if (hi < lo) {
            return;
        }
        int lt = lo;
        int i = lo + 1;
        int gt = hi;
        int v = a[lo];
        while (i < gt) {
            int cmp = a[i].compareTo(v);
            if (cmp < 0) {
                exch(a, lt++, i++);
            }
            else if (cmp > 0) {
                exch(a, i, gt--);
            }
            else {
                i++;
            }
        }
        sort(a, lo, lt - 1);
        sort(a, gt + 1, hi);
     }
}
