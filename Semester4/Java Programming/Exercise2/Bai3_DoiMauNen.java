package BaiThucHanhSo2;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
public class Bai3_DoiMauNen extends JFrame implements ActionListener {
	JButton red, green, blue, exit;
	JPanel pn, pn1;
	
	public void GUI() {
		
		red = new JButton("RED");
		green = new JButton("GREEN");
		blue = new JButton("BLUE");
		exit = new JButton("Thoát");
		
		red.addActionListener(this);
		green.addActionListener(this);
		blue.addActionListener(this);
		exit.addActionListener(this);
		
		pn = new JPanel(new BorderLayout());
		pn1 = new JPanel(new FlowLayout());
		
		pn1.add(red);
		pn1.add(green);
		pn1.add(blue);
		pn1.add(exit);
		
		pn.add(pn1, BorderLayout.SOUTH);
		pn.setBackground(Color.GREEN);
		pn1.setBackground(pn.getBackground());
		
		add(pn);
		setSize(400, 300);
		setVisible(true);
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

	public void actionPerformed(ActionEvent e) {
		if (e.getSource() != exit) {
			if (e.getSource() == red) {
				pn.setBackground(Color.RED);
			} else if (e.getSource() == green) {
				pn.setBackground(Color.GREEN);
			} else if (e.getSource() == blue) {
				pn.setBackground(Color.BLUE);
			}
			pn1.setBackground(pn.getBackground());
		} else if (e.getSource() == exit) {
			System.exit(0);
		}
	}
	
	public Bai3_DoiMauNen(String title) {
		super(title);
		GUI();
	}
	
	public static void main(String[] args) {
		new Bai3_DoiMauNen("Đổi màu nền");
	}
}
