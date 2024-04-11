package BaiThucHanhSo1;
import java.util.Scanner;
import java.math.*;

public class Bai3 {
	
	public static void ptbh(double a, double b, double c) {
		double delta = Math.pow(b, 2) - 4*a*c;
		if (delta > 0) {
			double x1 = (-b + Math.sqrt(delta)) / (2*a);
			double x2 = (-b - Math.sqrt(delta)) / (2*a);
			System.out.println("Phương trình có 2 nghiệm phân biệt: ");
			System.out.println("x1 = " + x1);
			System.out.println("x2 = " + x2);
		} else if (delta == 0) {
			double x = -b / (2*a);
			System.out.println("Phương trình có nghiệm kép: ");
			System.out.println("x = " + x);
		} else {
			System.out.println("Phương trình vô nghiệm");
		}
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
		System.out.print("Nhập hệ số c: ");
		double c = scanner.nextDouble();
		System.out.println("Phương trình bậc hai: " + a + "x^2" + " + " + b + "x" + " + " + c + " = 0");
		ptbh(a, b, c);
	}
	
	public static void main(String[] args) {
		Bai3 bai3 = new Bai3();
		bai3.solve();
	}
}
