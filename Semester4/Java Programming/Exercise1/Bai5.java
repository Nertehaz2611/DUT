package BaiThucHanhSo1;
import java.util.Scanner;

public class Bai5 {
	public static double stg(double a, double b, double c) {
		if (a <= b && b <= c) {
			return b;
		}
		else if (b <= a && a <= c) {
			return a;
		}
		else return c;
	}
	public static void solve() {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Nhập a, b, c: ");
		double a, b, c;
		a = scanner.nextDouble();
		b = scanner.nextDouble();
		c = scanner.nextDouble();
		System.out.print("Số trung gian: " + stg(a, b, c));
	}
	public static void main(String[] args) {
		Bai5 bai5 = new Bai5();
		bai5.solve();
	}
}
