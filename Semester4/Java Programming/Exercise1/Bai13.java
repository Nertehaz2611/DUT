package BaiThucHanhSo1;
import java.util.Scanner;

public class Bai13 {
	public static int GCD(int a, int b) {
		return (b == 0)? a : GCD(b, a % b);
	}
	public static void solve() {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Nhập a, b: ");
		int a, b;
		a = scanner.nextInt();
		b = scanner.nextInt();
		System.out.println("UCLN(a, b) = " + GCD(a, b));
		System.out.println("BCNN(a, b) = " + a * b / GCD(a, b));
	}
	public static void main(String[] args) {
		Bai13 bai13 = new Bai13();
		bai13.solve();
	}
}
