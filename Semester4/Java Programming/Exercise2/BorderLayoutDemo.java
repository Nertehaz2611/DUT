package BaiThucHanhSo2;

import java.awt.*;
import javax.swing.*;
public class BorderLayoutDemo extends JFrame {
	public static void main(String[] args) {
		BorderLayoutDemo b = new BorderLayoutDemo();
		b.setTitle("BorderLayout Demo");
		b.setBounds(200, 500, 350, 350);
		JTextField msg = new JTextField("Hien thi thong bao");
		msg.setEditable(false);
		JButton nutVe = new JButton("Ve");
		Canvas vungVe = new Canvas();
		vungVe.setSize(150, 150);
		vungVe.setBackground(Color.white);
		Scrollbar sb1 = new Scrollbar(Scrollbar.VERTICAL, 0, 10, 30, 100);
		Scrollbar sb2 = new Scrollbar(Scrollbar.VERTICAL, 0, 10, 30, 100);
		b.setLayout(new BorderLayout());
		b.add(nutVe, BorderLayout.NORTH);
		b.add(msg, BorderLayout.SOUTH);
		b.add(vungVe, BorderLayout.CENTER);
		b.add(sb1, BorderLayout.WEST);
		b.add(sb2, BorderLayout.EAST);
		b.setVisible(true);
	}
}
