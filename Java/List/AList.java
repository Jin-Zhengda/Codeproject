package List;
//可变数组
public class AList<Item> {
    private Item[] items;
    private int size;

    public AList() {
        items = (Item[]) new Object[100];
        size = 0;
    }

    private void reszie(int capacity) {
        Item[] temItems = (Item[]) new Object[capacity];
        System.arraycopy(items, 0, temItems, 0, size);
        items = temItems;
    }

    public void addLast(Item x) {
        if (size == items.length) {
            reszie(size * 2);
        }
        items[size] = x;
        size++;
    }

    public Item getLast() {
        return items[size - 1];
    }

    public Item get(int i) {
        return items[i];
    }

    public int size() {
        return size;
    }

    public void insert(Item x, int index) {
        if (size == items.length) {
            reszie(size * 2);
        }
        Item[] temItems = (Item[]) new Object[size*2];
        System.arraycopy(items, 0, temItems, 0, index - 1);
        temItems[index] = x;
        System.arraycopy(items, index, temItems, index + 1, size - index);
        items = temItems;
    }

    public Item removeLast() {
        Item last = getLast();
        items[size - 1] = null;
        size--;
        return last;
    }

    public static void main(String args[]) {
        
    }
}
