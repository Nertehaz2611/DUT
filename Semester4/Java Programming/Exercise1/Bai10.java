package BaiThucHanhSo1;
import java.util.Scanner;
import java.math.*;

public class Bai10 {
	public static double res(int n) {
		double S = 1;
		int gt = 1;
		for (int i = 2; i <= n; i++) {
			gt *= (2*i - 2)*(2*i - 1);
			S += 1.0/gt;
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
		Bai10 bai10 = new Bai10();
		bai10.solve();
	}
}
