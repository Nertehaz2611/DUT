package BaiThucHanhSo1;
import java.util.Scanner;

public class Bai8 {
	public static double res(int n) {
		double S = 0;
		for (int i = 1; i <= n; i++) {
			S += 1.0/i;
		}
		return S;
	}
	public static void solve() {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Nhập n: ");
		int n = scanner.nextInt();
		System.out.print("S = " + res(n));
	}
	public static void main(String[] args) {
		Bai8 bai8 = new Bai8();
		bai8.solve();
	}
}
