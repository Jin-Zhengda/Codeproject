package test;

public class College implements Student {
    private String name;
    private String id;

    College(String name, String id) {
        this.name = name;
        this.id = id;
    }

    public void printMessage() {
        System.out.println(id + name);
    }
}
