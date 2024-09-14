package test;

public class IntMax {
	public static int max(int a, int b) {
		return (a > b) ? a: b;
	}

	public static int max(int a, int b, int c) {
		int max1 = max(a, b);
		int max2 = max(a, c);
		return max(max1, max2);
	}

	public static void main(String[] args) {
		int max1 = IntMax.max(2, 6);
		System.out.println(max1);

		int max2 = IntMax.max(1, 2, 3);
		System.out.println(max2);
	}
}