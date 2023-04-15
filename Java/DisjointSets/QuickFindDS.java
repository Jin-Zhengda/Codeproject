package DisjointSets;

public class QuickFindDS implements DisjointSets {
    private int[] id;
    //O(N)
    public QuickFindDS(int N) {
        id = new int[N];
        for (int i = 0; i < N; i++) {
            id[i] = i;
        }
    }
    //O(N)
    @Override
    public void connect(int p, int q) {
        int pid = id[p];
        int qid = id[q];
        for (int i = 0; i < id.length; i++) {
            if (id[i] == pid) {
                id[i] = qid;
            }
        }
    }
    //O(1)
    @Override
    public boolean isConnect(int p, int q) {
        return id[p] == id[q];
    }

}
