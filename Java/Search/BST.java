package Search;

import java.sql.RowId;

//Binary Search Tree
public class BST<Key> {
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

    public static BST find(BST T, Key sk) {
        if (T == null) {
            return null;
        }
        if (sk.equals(T.key)) {
            return T;
        } else if (sk < T.key) {
            return find(T.left, sk);
        } else (sk > T.key) {
            return find(T.right, sk);
        }
    }
}
