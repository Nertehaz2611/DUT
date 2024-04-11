package BaiThucHanhSo1;
import java.util.Scanner;
import java.math.*;

public class Bai11 {
	public static long res(int n) {
		long S = 1;
		for (int i = n; i >= 1; i-=2) {
			S *= i;
		}
		return S;
	}
	public static void solve() {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Nhập n: ");
		int n = scanner.nextInt();
		System.out.print("n!! = " + res(n));
	}
	public static void main(String[] args) {
		Bai11 bai11 = new Bai11();
		bai11.solve();
	}
}
