package DisjointSets;

public class WeightedQuickUnionDS implements DisjointSets{
    private int[] id;
    //O(N)
    public WeightedQuickUnionDS(int N) {
        id = new int[N];
        for (int i = 0; i < N; i++) {
            id[i] = -1;
        } 
    }

    private int findRoot(int p) {
        while (id[p] >= 0) {
            p = id[p];
        }
        return p;
    }
    //O(logN)
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
    //O(logN)
    @Override
    public boolean isConnect(int p, int q) {
        return findRoot(p) == findRoot(q);
    }
}
