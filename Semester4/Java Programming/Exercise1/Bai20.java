package BaiThucHanhSo1;
import java.util.Scanner;
import java.math.*;

public class Bai20 {
	public static boolean isPerfectSquare(int x) {
		int s = (int)Math.sqrt(x);
		return s*s == x;
	}
	public static boolean isFibonacci(int k) {
		return (isPerfectSquare(5 * k * k + 4) || isPerfectSquare(5 * k * k - 4)) && k >= 0;
	}
	public static int fiboIndex(int k) {
		if (k == 0) return 0;
		if (k == 1) return 1;
		int index = 1;
		int a = 0, b = 1;
		while (b < k) {
			int temp = a;
			a = b;
			b = temp + b;
			index++;
		}
		return index;
	}
	public static void solve() {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Nhập k: ");
		int k = scanner.nextInt();
		if (isFibonacci(k)) {
			System.out.println(k + " là phần tử thứ " + fiboIndex(k) + " trong dãy Fibonacci");
		} else {
			System.out.println(k + " không thuộc dãy Fibonacci");
		}
	}
	public static void main(String[] args){
		Bai20 bai20 = new Bai20();
		bai20.solve();
	}
}
