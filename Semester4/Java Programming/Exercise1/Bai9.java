package BaiThucHanhSo1;
import java.util.Scanner;
import java.math.*;

public class Bai9 {
	public static double res(int n) {
		double S = 15;
		int gt = 1;
		for (int i = 1; i <= n; i++) {
			gt *= i;
			S += Math.pow(-1, i)*(1.0/gt);
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
		Bai9 bai9 = new Bai9();
		bai9.solve();
	}
}
