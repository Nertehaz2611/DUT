package BaiThucHanhSo1;
import java.util.Scanner;

public class Bai4 {
	public static void hpt(double a, double b, double c, double d, double e, double f) {
		double x = (b*f - e*c) / (b*d - e*a);
		double y = (c - a*x) / b;
		System.out.println("x = " + x);
		System.out.println("y = " + y);
	}
	public static void solve() {
		Scanner scanner = new Scanner(System.in);
		double a, b, c, d, e, f;
		System.out.println("Nhập a, b, c: ");
		a = scanner.nextDouble();
		b = scanner.nextDouble();
		c = scanner.nextDouble();
		System.out.println("Nhập d, e, f: ");
		d = scanner.nextDouble();
		e = scanner.nextDouble();
		f = scanner.nextDouble();
		System.out.println("Hệ phương trình: ");
		System.out.println(a + "x + " + b + "y = " + c);
		System.out.println(d + "x + " + e + "y = " + f);
		hpt(a, b, c, d, e, f);
	}
	public static void main(String[] args) {
		Bai4 bai4 = new Bai4();
		bai4.solve();
	}
}
