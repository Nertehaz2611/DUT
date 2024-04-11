package BaiThucHanhSo1;
import java.util.Scanner;
import java.math.*;

public class Bai15 {
	public static boolean chinhPhuong(double m) {
		if (Math.sqrt(m) == (int)Math.sqrt(m)) return true;
		else return false;
	}
	public static void solve() {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Nhập P: ");
		double P = scanner.nextDouble();
		if (chinhPhuong(P)) {
			System.out.println((int)P + " là số chính phương");
		} else {
			System.out.println((int)P + " không phải là số chính phương");
		}
	}
	public static void main(String[] args) {
		Bai15 bai15 = new Bai15();
		bai15.solve();
	}
}
