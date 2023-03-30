import java.util.Iterator;

//可迭代集合
public class ArraySet<T> implements Iterable<T> {

    private T[] items;
    private int size;

    private class ArraySetIterator implements Iterator<T> {
        private int pos;

        public ArraySetIterator() {
            pos = 0;
        }

        public boolean hasNext() {
            return pos < size;
        }

        public T next() {
            T returnItem = items[size - 1];
            size += 1;
            return returnItem;
        }
    }

    public ArraySet() {
        items = (T[]) new Object[100];
        size = 0;
    }

    public Iterator<T> iterator() {
        return new ArraySetIterator();
    }

    public void add(T x) {
        if (contains(x)) {
            return;
        }
        items[size] = x;
        size += 1;
    }

    public boolean contains(T x) {
        for (int i = 0; i < size; i++) {
            if (items[i] == null) {
                if (x == null) {
                    return true;
                }
            }
            if (x.equals(items[i])) {
                return true;
            }
        }
        return false;
    }

    public int size() {
        return size;
    }

    public static void main(String[] args) {

    }
}
