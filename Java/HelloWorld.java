package Java;

public class HelloWorld {
    public static void printIndexed(String str){
        int len = str.length();
        for(int i = len - 1; i >= 0; i--){
            System.out.print(str.charAt(len - i - 1));
            System.out.print(i);
            }
        }
    public static void main(String[] args) {
        // int x;
        // int sum;
        // sum = 0;
        // for (x = 1; x < 10; x++) {
        //     sum += x;
        //     System.out.println(sum);
        // }
       printIndexed("ZELDA");
    }
}