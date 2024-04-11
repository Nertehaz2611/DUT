package BaiThucHanhSo1;
import java.util.Scanner;

public class Bai6 {
	public static boolean check(int a, int b) {
		if (0 <= a && a <= b && b <= 24) return true;
		return false;
	}
	public static int res(int a, int b) {
		if (b < 18) {
			return 45000 * (b - a);
		} else if (a > 18) {
			return 60000 * (b - a);
		} else {
			return 45000 * (18 - a) + 60000 * (b - 18);
		}
	}
	public static void solve() {
		Scanner scanner = new Scanner(System.in);
		System.out.print(" Nhập a, b (0 <= a <= b <= 24): ");
		int a, b;
		a = scanner.nextInt();
		b = scanner.nextInt();
		boolean c = check(a, b);
		while (!c) {
			System.out.println("Không hợp lệ!");
			System.out.print(" Nhập a, b (0 <= a <= b <= 24): ");
			a = scanner.nextInt();
			b = scanner.nextInt();
			c = check(a, b);
		}
		System.out.print("Tổng giá tiền: " + res(a, b));
	}
	public static void main(String[] args) {
		Bai6 bai6 = new Bai6();
		bai6.solve();
	}
}
