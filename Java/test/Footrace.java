package test;

public class Footrace {
    private final int distance;
    private boolean gameover;

    public Footrace(int distance) {
        this.distance = distance;
        this.gameover = false;
    }

    public void setGameOver() {
        this.gameover = true;
    }

    public boolean isNotGameOver() {
        return !this.gameover;
    }

    public void runnerStartTrace(Runner runner) {
        try {
            while (runner.distanceCovered() <= this.distance && this.isNotGameOver()) {
                Thread.sleep(1000);
                runner.increaseDistanceCovered(1);
                System.out.println(runner.name() + " covered " + runner.distanceCovered() + " meters");
                if (runner.distanceCovered() == this.distance) {
                    this.setGameOver();
                    System.out.println(runner.name() + " won!");
                    break;
                }
                if (runner.distanceCovered() % 5 == 0 && runner.distanceCovered() > 0 && runner.distanceCovered() < this.distance) {
                    Thread.sleep(runner.perFiveSleep() * 1000L);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        Footrace footrace = new Footrace(20);
        Runner rabit = new Runner("Rabit", 5, 10);
        Runner turtle = new Runner("Turtle", 1, 1);

        System.out.println("Footrace started! Distance: " + footrace.distance);
        Thread rabitThread = new Thread(
                () -> {
                   footrace.runnerStartTrace(rabit);
                }
        );


        Thread turtleThread = new Thread(
                () -> {
                    footrace.runnerStartTrace(turtle);
                }
        );

        rabitThread.start();
        turtleThread.start();
    }
}
