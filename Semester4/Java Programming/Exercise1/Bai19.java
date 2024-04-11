package BaiThucHanhSo1;
import java.util.Scanner;

public class Bai19 {
	static long fibo[] = new long[1001];
	public static void fibonacci() {
		fibo[0] = 0;
		fibo[1] = 1;
		for (int i = 2; i <= 1000; i++) {
			fibo[i] = fibo[i-1] + fibo[i-2];
		}
	}
	public static void solve() {
		fibonacci();
		int n;
		Scanner scanner = new Scanner(System.in);
		System.out.print("Nhập n: ");
		n = scanner.nextInt();
		System.out.print("Dãy fibonacci: ");
		for (int i = 1; i <= n; i++) {
			System.out.print(fibo[i] + " ");
		}
	}
	public static void main(String[] args) {
		Bai19 bai19 = new Bai19();
		bai19.solve();
	}
}
