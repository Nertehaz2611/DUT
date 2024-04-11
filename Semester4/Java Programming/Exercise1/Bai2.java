package BaiThucHanhSo1;
import java.util.Scanner;

public class Bai2 {
	public static double ptbn(double a, double b){
		double res = -b/a;
		return res;
	}
	public static void solve() {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Nhập hệ số a: ");
		double a = scanner.nextDouble();
		while (a == 0) {
			System.out.println("Hệ số a phải khác 0, vui lòng nhập lại!");
			System.out.print("Nhập lại hệ số a: ");
			a = scanner.nextDouble();
		}
		System.out.print("Nhập hệ số b: ");
		double b = scanner.nextDouble();
		System.out.println("Phương trình bậc nhất: " + a + "x" + " + " + b + " = 0");
		System.out.println("x = " + ptbn(a, b));
	}
	public static void main(String[] args) {
		Bai2 bai2 = new Bai2();
		bai2.solve();
	}
}
