package BaiThucHanhSo2;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
import java.security.PublicKey;

class Bai2_ArithOpe extends JFrame implements ActionListener {	
	JLabel lb, lb1, lb2, lb3;
	JTextField txt1, txt2, txtres;
	JButton add, sub, mul, div, reset, exit;
	JPanel pn, pn1, pn2, pn3, pn4;
	
	public void GUI() {
		lb = new JLabel("Basic Arithmetic Operations");
		lb1 = new JLabel("Number 1:");
		lb2 = new JLabel("Number 2:");
		lb3 = new JLabel("Result:");
		
		txt1 = new JTextField(7);
		txt2 = new JTextField(7);
		txtres = new JTextField(7);
		
		add = new JButton("Addition");
		sub = new JButton("Subtraction");
		mul = new JButton("Multiplication");
		div = new JButton("Division");
		reset = new JButton("Reset");
		exit = new JButton("Exit");
		
		add.addActionListener(this);
		sub.addActionListener(this);
		mul.addActionListener(this);
		div.addActionListener(this);
		reset.addActionListener(this);
		exit.addActionListener(this);
		
		pn = new JPanel(new GridLayout(4, 1));
		pn1 = new JPanel(new FlowLayout());
		pn2 = new JPanel(new GridLayout(3, 2));
		pn3 = new JPanel(new FlowLayout());
		pn4 = new JPanel(new FlowLayout());
		
		pn1.add(lb);
		
		pn2.add(lb1);
		pn2.add(txt1);
		pn2.add(lb2);
		pn2.add(txt2);
		pn2.add(lb3);
		pn2.add(txtres);
		
		pn3.add(add);
		pn3.add(sub);
		pn3.add(mul);
		pn3.add(div);
		
		pn4.add(reset);
		pn4.add(exit);
		
		pn.add(pn1);
		pn.add(pn2);
		pn.add(pn3);
		pn.add(pn4);
		
		add(pn);
		setSize(500, 300);
		setVisible(true);
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == add) {
			Double a = Double.parseDouble(txt1.getText());
			Double b = Double.parseDouble(txt2.getText());
			txtres.setText(Double.toString(a+b));
		} else if (e.getSource() == sub) {
			Double a = Double.parseDouble(txt1.getText());
			Double b = Double.parseDouble(txt2.getText());
			txtres.setText(Double.toString(a-b));
		} else if (e.getSource() == mul) {
			Double a = Double.parseDouble(txt1.getText());
			Double b = Double.parseDouble(txt2.getText());
			txtres.setText(Double.toString(a*b));
		} else if (e.getSource() == div) {
			Double a = Double.parseDouble(txt1.getText());
			Double b = Double.parseDouble(txt2.getText());
			if (b == 0) {
				txtres.setText("Undefined");
			}
			else txtres.setText(Double.toString(a/b));
		} else if (e.getSource() == reset) {
			txt1.setText("");
			txt2.setText("");
			txtres.setText("");
		} else if (e.getSource() == exit) {
			System.exit(0);
		}
	}
	
	public Bai2_ArithOpe(String title) {
		super(title);
		GUI();
	}
	
	public static void main(String[] args) {
		new Bai2_ArithOpe("Arithmetic Operations");
	}
}
