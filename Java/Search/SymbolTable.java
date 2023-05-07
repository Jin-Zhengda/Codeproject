package Search;

import edu.princeton.cs.algs4.Queue;
/**
 * Symbol Table based on Arrays and Binary Search 
 */
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
    //put the key-val pair into the table
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
    //get the value corresponding to the key
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
    //delete the key-val pair
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
    //check if this table contains the key
    public boolean contains(Key key) {
        return get(key) != null;
    }

    //O(1)
    //check if this table is empty 
    public boolean isEmpty() {
        return N == 0;
    }

    //O(1)
    //get the current size of this table
    public int size() {
        return N;
    }

    //get the size in the table from lo to hi
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
    //get the min key
    public Key min() {
        return keys[0];
    }

    //O(1)
    //get the max key
    public Key max() {
        return keys[N - 1];
    }

    //O(logN)
    //get the max key which less than or equal to the key
    public Key floor(Key key) {
        if (key == max()) {
            return key;
        }
        int i = rank(key);
        return keys[i + 1];
    }

    //O(logN)
    //get the min key which larger than or equal to the key
    public Key ceiling(Key key) {
        int i = rank(key);
        return keys[i];
    }

    //O(logN)
    //get the amount of the keys which less than the key
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
    //get the kth key 
    public Key select(int k) {
        return keys[k];
    }

    //O(N)
    //delete the min key
    public void deleteMin() {
        delete(min());
    }

    //O(1)
    //delete the max key
    public void deleteMax() {
        delete(max());
    }

    //get the set of keys of this table from lo to hi
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

    //get the set of all the keys of this table
    public Iterable<Key> keys() {
        return keys(min(), max());
    }

}

