package BaiThucHanhSo1;
import java.util.Scanner;

public class Bai14 {
	public static boolean isPrime(int m) {
		for (int i = 2; i*i <= m; i++) {
			if (m % i == 0) {
				return false;
			}
		}
		return true;
	}
	public static void solve() {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Nhập m: ");
		int m = scanner.nextInt();
		if (isPrime(m)) {
			System.out.println(m + " là số nguyên tố");
		}
		else System.out.println(m + " không phải là số nguyên tố");
	}
	public static void main(String[] args) {
		Bai14 bai14 = new Bai14();
		bai14.solve();
	}
}
