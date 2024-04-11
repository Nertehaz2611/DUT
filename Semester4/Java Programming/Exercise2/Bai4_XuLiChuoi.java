package BaiThucHanhSo2;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
public class Bai4_XuLiChuoi extends JFrame implements ActionListener {
	JLabel lb0, lb1, lb2, lb3, lb4, lb5;
	JTextField txt0, txt1, txt2, txt3, txt4, txt5;
	JButton ok, reset, exit;
	JPanel pn1, pn2, pn;
	
	public void GUI() {
		lb0 = new JLabel("");
		lb1 = new JLabel("Enter a string");
		lb2 = new JLabel("To UpperCase");
		lb3 = new JLabel("To LowerCase");
		lb4 = new JLabel("To LowerUpper");
		lb5 = new JLabel("Number of word");
		
		txt0 = new JTextField(25);
		txt0.setVisible(false);
		txt1 = new JTextField(25);
		txt2 = new JTextField(25);
		txt2.setEditable(false);
		txt3 = new JTextField(25);
		txt3.setEditable(false);
		txt4 = new JTextField(25);
		txt4.setEditable(false);
		txt5 = new JTextField(25);
		txt5.setEditable(false);
		
		ok = new JButton("OK");
		reset = new JButton("Reset");
		exit = new JButton("Exit");
		
		ok.addActionListener(this);
		reset.addActionListener(this);
		exit.addActionListener(this);
		
		pn1 = new JPanel(new GridLayout(6, 2, 10, 15));
		pn2 = new JPanel(new FlowLayout(FlowLayout.CENTER, 120, 15));
		pn = new JPanel(new FlowLayout());
		
		pn1.add(lb0);
		pn1.add(txt0);
		pn1.add(lb1);
		pn1.add(txt1);
		pn1.add(lb2);
		pn1.add(txt2);
		pn1.add(lb3);
		pn1.add(txt3);
		pn1.add(lb4);
		pn1.add(txt4);
		pn1.add(lb5);
		pn1.add(txt5);
		
		pn2.add(ok);
		pn2.add(reset);
		pn2.add(exit);
		
		pn.add(pn1);
		pn.add(pn2);
		
		add(pn);
		setSize(550, 290);
		setVisible(true);
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	public char toUpper(char c) {
		if (c >= 97 && c <= 122) c -= 32;
		return c;
	}
	
	public char toLower(char c) {
		if (c >= 65 && c <= 90) c += 32;
		return c;
	}
	
	public String toLowerUpper(String s) {
		String str = "";
		str += toLower(s.charAt(0));
		for (int i = 1; i < s.length(); i++) {
			if (s.charAt(i-1) == ' ' && s.charAt(i) != ' ') {
				str += toLower(s.charAt(i));
			}
			else str += toUpper(s.charAt(i));
		}
		return str;
	}
	
	public String toUppercase(String s) {
		String str = "";
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) >= 97 && s.charAt(i) <= 122) {
				str += toUpper(s.charAt(i));
			}
			else str += s.charAt(i);
		}
		return str;
	}
	
	public String toLowercase(String s) {
		String str = "";
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) >= 65 && s.charAt(i) <= 90) {
				str += toLower(s.charAt(i));
			}
			else str += s.charAt(i);
		}
		return str;
	}
	
	public int count(String s) {
		int c = 1;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == ' ' && s.charAt(i+1) != ' ') c++;
		}
		return c;
	}

	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == ok) {
			String s = txt1.getText();
			txt2.setText(toUppercase(s));
			txt3.setText(toLowercase(s));
			txt4.setText(toLowerUpper(s));
			txt5.setText(Integer.toString(count(s)));
		} else if (e.getSource() == reset) {
			txt1.setText("");
			txt2.setText("");
			txt3.setText("");
			txt4.setText("");
			txt5.setText("");
		} else if (e.getSource() == exit) {
			System.exit(0);
		}
	}
	public Bai4_XuLiChuoi(String title) {
		super(title);
		GUI();
	}
	public static void main(String[] args) {
		new Bai4_XuLiChuoi("String processing");
	}
}