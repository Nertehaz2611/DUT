package BaiThucHanhSo1;
import java.util.Scanner;

public class Bai7 {
	public static int namNhuan(int year) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) return 1;
		return 0;
	}
	public static int soNgay(int month, int year) {
		int x = 0;
		switch (month) {
			case 1, 3, 5, 7, 8, 10, 12:
				x = 31;
				break;
			case 4, 6, 9, 11:
				x = 30;
				break;
			case 2:
				x = 28 + namNhuan(year);
		}
		return x;
	}
	public static void solve() {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Nhập tháng, năm: ");
		int month = scanner.nextInt();
		int year = scanner.nextInt();
		System.out.println("Tháng " + month + "/" + year + " có " + soNgay(month, year) + " ngày.");
	}
	public static void main(String[] args) {
		Bai7 bai7 = new Bai7();
		bai7.solve();
	}
}
