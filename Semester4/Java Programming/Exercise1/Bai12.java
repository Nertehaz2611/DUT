package BaiThucHanhSo1;
import java.util.Scanner;

public class Bai12 {
	public static long S(int m) {
		long res = 0;
		while (m > 0) {
			res += m % 10;
			m /= 10;
		}
		return res;
	}
	public static long P(int m) {
		long res = 1;
		while (m > 0) {
			res *= m % 10;
			m /= 10;
		}
		return res;
	}
	public static void solve() {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Nhập m: ");
		int m = scanner.nextInt();
		System.out.println("S = " + S(m));
		System.out.println("P = " + P(m));
	}
	public static void main(String[] args) {
		Bai12 bai12 = new Bai12();
		bai12.solve();
	}
}
