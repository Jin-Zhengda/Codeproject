package Search;

import edu.princeton.cs.algs4.Queue;
//Symbol Table based on Arrays and Binary Search 
public class SymbolTable<Key extends Comparable<Key>, Value> {
    private Key[] keys;
    private Value[] vals;
    private int N;


    public SymbolTable(int capacity) {
        N = 0;
        keys = (Key[]) new Comparable[capacity];
        vals = (Value[]) new Object[capacity];
    }

    private void resize(int capacity) {
        Key[] tempkeys = (Key[]) new Comparable[capacity];
        Value[] tempVals = (Value[]) new Object[capacity];
        for (int i = 0; i < keys.length; i++) {
            tempkeys[i] = keys[i];
            tempVals[i] = vals[i];
        }
        keys = tempkeys;
        vals = tempVals;
    }

    //O(N)
    public void put(Key key, Value val) {
        if (val == null) {
            delete(key);
            return;
        }
        if (N == keys.length) {
            resize(keys.length * 2);
        }
        int i = rank(key);
        if (i < N && keys[i].compareTo(key) == 0) {
            vals[i] = val;
            return;
        }
        for (int j = N; j > i; j--) {
            keys[j] = keys[j - 1];
            vals[j] = vals[j - 1];
            keys[i] = key;
            vals[i] = val;
        }
        N++;
    }

    //O(logN)
    public Value get(Key key) {
        if (isEmpty()) {
            return null;
        } 
        int i = rank(key);
        if (i < N && keys[i].compareTo(key) == 0) {
            return vals[i];
        } else {
            return null;
        }
    }

    //O(N)
    public void delete(Key key) {
        if (isEmpty()) {
            return;
        }
        int i = rank(key);
        for (int j = i; j < N - 1; j++) {
            keys[j] = keys[j + 1];
            vals[j] = vals[j + 1];
        }
        N--;
    }

    //O(logN)
    public boolean contains(Key key) {
        return get(key) != null;
    }

    //O(1)
    public boolean isEmpty() {
        return N == 0;
    }

    //O(1)
    public int size() {
        return N;
    }

    public int size(Key lo, Key hi) {
        if (hi.compareTo(lo) < 0) {
            return 0;
        } else if (contains(hi)) {
            return rank(hi) - rank(lo) - 1;
        } else {
            return rank(hi) - rank(lo);
        }
    }

    //O(1)
    public Key min() {
        return keys[0];
    }

    //O(1)
    public Key max() {
        return keys[N - 1];
    }

    //O(logN)
    public Key floor(Key key) {
        if (key == max()) {
            return key;
        }
        int i = rank(key);
        return keys[i + 1];
    }

    //O(logN)
    public Key ceiling(Key key) {
        int i = rank(key);
        return keys[i];
    }

    //O(logN)
    public int rank(Key key) {
        return rank(key, 0, N - 1);
    }

    private int rank(Key key, int lo, int hi) {
        if (hi < lo) {
            return lo;
        }
        int mid = lo + (hi - lo) / 2;
        int cmp = key.compareTo(keys[mid]);
        if (cmp < 0) {
            return rank(key, lo, mid - 1);
        } else if (cmp > 0) {
            return rank(key, mid + 1, hi);
        } else {
            return mid;
        }
    }

    //O(1)
    public Key select(int k) {
        return keys[k];
    }

    //O(N)
    public void deleteMin() {
        delete(min());
    }

    //O(1)
    public void deleteMax() {
        delete(max());
    }

    public Iterable<Key> keys(Key lo, Key hi) {
        Queue<Key> q = new Queue<Key>();
        for (int i = rank(lo); i < rank(hi); i++) {
            q.enqueue(keys[i]);
        }
        if (contains(hi)) {
            q.enqueue(keys[rank(hi)]);
        }
        return q;
    }

    public Iterable<Key> keys() {
        return keys(min(), max());
    }

}

