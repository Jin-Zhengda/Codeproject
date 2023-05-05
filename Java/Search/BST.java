package Search;

//Binary Search Tree
public class BST<Key extends Comparable<Key>> {
    private Key key;
    private BST<Key> left;
    private BST<Key> right;

    public BST(Key key, BST<Key> left, BST<Key> right) {
        this.key = key;
        this.left = left;
        this.right = right;
    }

    public BST(Key key) {
        this.key = key;
    }

    public BST<Key> find(BST<Key> T, Key sk) {
        if (T == null) {
            return null;
        }
        if (sk.equals(T.key)) {
            return T;
        } else if (sk.compareTo(T.key) < 0) {
            return find(T.left, sk);
        } else {
            return find(T.right, sk);
        }
    }
}
