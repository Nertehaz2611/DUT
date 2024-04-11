package BaiThucHanhSo1;
import java.util.Scanner;

public class Bai1 {
	public static double Max(double a, double b, double c) {
		if (a >= b && a >= c) {
			return a;
		} else if (b >= a && b >= c) {
			return b;
		} else return c;
	}
	public static void solve() {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Nhập a: ");
		double a = scanner.nextDouble();
		System.out.print("Nhập b: ");
		double b = scanner.nextDouble();
		System.out.print("Nhập c: ");
		double c = scanner.nextDouble();
		System.out.println("Giá trị lớn nhất là: " + Max(a, b, c));
		scanner.close();
	}
	public static void main(String[] args) {
		Bai1 bai1 = new Bai1();
		bai1.solve();
	}
}
