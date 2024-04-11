package BaiThucHanhSo1;
import java.util.Scanner;

public class Bai16 {
	public static int reverse(int m) {
		int res = 0;
		while (m > 0) {
			res = res * 10 + (m % 10);
			m /= 10;
		}
		return res;
	}
	public static boolean isPalindrome(int m) {
		return (m == reverse(m));
	}
	public static void solve() {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Nhập M: ");
		int m = scanner.nextInt();
		if (isPalindrome(m)) {
			System.out.println(m + " là số đối xứng");
		} else {
			System.out.println(m + " không phải là số đối xứng");
		}
	}
	public static void main(String[] args) {
		Bai16 bai16 = new Bai16();
		bai16.solve();
	}
}
