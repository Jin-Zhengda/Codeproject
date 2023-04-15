package DisjointSets;

public class QuickUnionDS implements DisjointSets {
    private int[] id;
    //O(N)
    public QuickUnionDS(int N) {
        id = new int[N];
        // use -1 to represent the root of a tree
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
    //O(N)
    @Override
    public void connect(int p, int q) {
        int i = findRoot(p);
        int j = findRoot(q);
        id[j] = i;
    }
    //O(N)
    @Override
    public boolean isConnect(int p, int q) {
        return findRoot(p) == findRoot(q);
    }

}
