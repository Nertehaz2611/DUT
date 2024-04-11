package BaiThucHanhSo1;

public class Bai18 {
	static boolean isPerfect[] = new boolean[1001];
	public static void perfect() {
		isPerfect[0] = isPerfect[1] = false;
		for (int i = 2; i <= 1000; i++) {
			int s = 0;
			for (int j = 1; j <= i / 2; j++) {
				if (i % j == 0) {
					s += j;
				}
				if (s > i) break;
			}
			if (s == i) isPerfect[i] = true;
			else isPerfect[i] = false;
		}
	}
	public static void solve() {
		perfect();
		System.out.println("Các số hoàn hảo trong phạm vi 1000: ");
		for (int i = 0; i <= 1000; i++) {
			if (isPerfect[i]) System.out.print(i + " ");
		}
	}
	public static void main(String[] args) {
		Bai18 bai18 = new Bai18();
		bai18.solve();
	}
}
