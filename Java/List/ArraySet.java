package List;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

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
            T returnItem = items[pos];
            pos += 1;
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
        if (x == null) {
            throw new IllegalArgumentException("can not add null!");
        }
        if (contains(x)) {
            return;
        }
        items[size] = x;
        size += 1;
    }

    public boolean contains(T x) {
        for (int i = 0; i < size; i++) {
            if (x.equals(items[i])) {
                return true;
            }
        }
        return false;
    }

    public int size() {
        return size;
    }

    public static <Glerp> ArraySet<Glerp> of(Glerp...stuff) {
        ArraySet<Glerp> returnSet = new ArraySet<>();
        for (Glerp x : stuff) {
            returnSet.add(x);
        }
        return returnSet;
    }

    @Override
    public String toString() {
        List<String> stringOfSet = new ArrayList<>();
        for (T x : this) {
            stringOfSet.add(x.toString());
        }
        return "[" + String.join(", ", stringOfSet) + "]";
    }

    @Override
    public boolean equals(Object other) {
        if (other == null) {
            return false;
        }
        if (other == this) {
            return true;
        }
        if (other instanceof ArraySet oas) {
            if (oas.size() != this.size()) {
                return false;
            }
            for (T item : this) {
                if (!oas.contains(item)) {
                    return false;
                }
            }
        }
        return false;
    }

    public static void main(String[] args) {
        ArraySet<Integer> set = new ArraySet<>();
        set.add(11);
        set.add(63);
        set.add(63);
        set.add(2);
        System.out.println(set.contains(2));
        System.out.println(set);
        // for (int i : set) {
        // System.out.println(i);
        // }
    }
}
