package test;

public class Runner {
    private final String name;
    private final int speed;
    private final int perFiveSleep;
    private int distanceCovered;

    public Runner(String name, int speed, int perFiveSleep) {
        this.name = name;
        this.speed = speed;
        this.perFiveSleep = perFiveSleep;
        this.distanceCovered = 0;
    }

    public int speed() {
        return speed;
    }

    public String name() {
        return name;
    }

    public int perFiveSleep() {
        return perFiveSleep;
    }

    public int distanceCovered() {
        return distanceCovered;
    }

    public void increaseDistanceCovered(int increase) {
        this.distanceCovered += increase;
    }

}
