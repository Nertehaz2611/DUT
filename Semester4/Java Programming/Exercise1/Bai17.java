package BaiThucHanhSo1;
import java.util.Scanner;

public class Bai17 {
	static boolean isPrime[] = new boolean[10001];
	public static void sieve() {
		for (int i = 0; i <= 10000; i++) {
			isPrime[i] = true;
		}
		isPrime[0] = isPrime[1] = false;
		for (int i = 2; i <= 10000; i++) {
			if (isPrime[i]) {
				for (int j = i*i; j <= 10000; j+=i) {
					isPrime[j] = false;
				}
			}
		}
	}
	public static void solve() {
		sieve();
		Scanner scanner = new Scanner(System.in);
		System.out.print("Nhập n: ");
		int n = scanner.nextInt();
		System.out.print("Các số nguyên tố nhỏ hơn hoặc bằng n: ");
		for (int i = 0; i <= n; i++) {
			if (isPrime[i]) System.out.print(i + " ");
		}
	}
	public static void main(String[] args) {
		Bai17 bai17 = new Bai17();
		bai17.solve();
	}
}
