package DisjointSets;
/* 
 */
public class WQUwithPathCompressionDS implements DisjointSets {
    private int[] id;

    // O(N)
    public WQUwithPathCompressionDS(int N) {
        id = new int[N];
        for (int i = 0; i < N; i++) {
            id[i] = -1;
        }
    }

    private int findRoot(int p) {
        int q = p;
        while (id[q] >= 0) {
            q = id[q];
        }
        while (id[p] >= 0) {
            int t = p;
            p = id[p];
            id[t] = q;
            id[q] -= 1;
        }
        return q;
    }

    // O(lg*N)
    @Override
    public void connect(int p, int q) {
        int i = findRoot(p);
        int j = findRoot(q);
        if (id[i] < id[j]) {
            id[i] += id[j];
            id[j] = i;
        } else {
            id[j] += id[i];
            id[i] = j;
        }
    }

    // O(lg*N)
    @Override
    public boolean isConnect(int p, int q) {
        return findRoot(p) == findRoot(q);
    }

}
