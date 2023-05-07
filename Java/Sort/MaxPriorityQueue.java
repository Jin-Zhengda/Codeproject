package Sort;
/**
 * Priority Queue based on Max Binary Heap
 * which can be used in Heap Sorting
 */
public class MaxPriorityQueue<Key extends Comparable<Key>> {
    private Key[] keys;
    private int size;

    public MaxPriorityQueue(int maxSize) {
        keys = (Key[]) new Comparable[maxSize + 1];
        size = 0;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int size() {
        return size;
    }

    //O(1)
    public Key getMax() {
        if (isEmpty()) {
            throw new NullPointerException();
        }
        return keys[1];
    }

    //O(logN)
    public void insert(Key key) {
        keys[size + 1] = key;
        size += 1;
        swim(size);

    }

    //O(logN)
    public Key removeMax() {
        Key max = keys[1];
        exch(1, size - 1);
        size -= 1;
        keys[size + 1] = null;
        sink(1);
        return max;
    }

    private void sink(int k) {
        while (2 * k <= size) {
            int j = 2 * k;
            if (j < size && keys[j].compareTo(keys[j + 1]) < 0) {
                j += 1;
            }
            if (keys[k].compareTo(keys[j]) >= 0) {
                break;
            }
            exch(k, j);
            k = j;
        }
    }

    private void swim(int k) {
        while (k > 1 && keys[k / 2].compareTo(keys[k]) < 0) {
            exch(k / 2, k);
            k = k / 2;
        }

    }

    private void exch(int i, int j) {
        Key t = keys[i];
        keys[i] = keys[j];
        keys[j] = t;
    }
}
