package List;
public class IntList {
    int first;
    IntList rest;

    public IntList(int f, IntList r) {
        first = f;
        rest = r;
    }

    public int size() {
        if (rest == null) {
            return 1;
        }
        return 1 + rest.size();
    }

    public int iterativrSize() {
        IntList p = this;
        int totalSize = 0;
        while (p != null) {
            p = p.rest;
            totalSize++;
        }
        return totalSize;
    }

    public int get(int i) {
        if (i == 0) {
            return first;
        }
        return rest.get(i - 1);
    }

    public void incrList() {
        IntList p = this;
        while (p.rest != null) {
            if (p.first > p.rest.first) {
                int t = p.first;
                p.first = p.rest.first;
                p.rest.first = t;
            }
            p = p.rest;
        }
    }

    public static void main(String[] args) {
        IntList L = new IntList(3, null);
        L = new IntList(1, L);
        L = new IntList(2, L);
        L = new IntList(0, L);
        L.incrList();
        System.out.println(L.get(2));
    }
}
