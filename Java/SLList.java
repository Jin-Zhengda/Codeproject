package Java;
//单向链表
public class SLList<DataType> {
    public class Node {
        public DataType item;
        public Node next;
    
        public Node(DataType i, Node n) {
            item = i;
            next = n;
        }
    }
    
    private Node sentinel;
    private Node last;
    private int size;

    public SLList() {
        sentinel = new Node(null, null);
        size = 0;
    }

    public SLList(DataType x) {
        sentinel = new Node(null, null);
        sentinel.next = new Node(x, null);
        last = sentinel.next;
        size = 1;
    }

    public void addFirst(DataType x) {
        size ++;
        sentinel.next = new Node(x, sentinel.next);
    }

    public DataType getFirst() {
        return sentinel.next.item;
    }

    public void addLast(DataType x) {
        size++;
        last.next = new Node(x, null);
        last = last.next;
    }

    public DataType getLast() {
        return last.item;
    }

    public int size() {
        return size;
    }

    public static void main(String[] args) {
        SLList<Integer> L = new SLList<>(3);
        L.addFirst(2);
        L.addFirst(1);
        L.addLast(0);
        System.out.print(L.getLast());
    }
}