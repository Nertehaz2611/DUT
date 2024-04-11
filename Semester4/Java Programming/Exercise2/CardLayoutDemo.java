package BaiThucHanhSo2;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class CardLayoutDemo extends Frame implements ActionListener {
	Button order = new Button("Order");
	Button products = new Button("Products");
	CardLayoutDemo(String title){
		super(title);
		setBounds(200, 200, 200, 200);
		setLayout(new CardLayout());
		Panel p = new Panel();
		p.add(new Label("Product 1"));
		p.add(new Label("Product 2"));
		p.add(order);
		order.addActionListener(this);
		products.addActionListener(this);
		add("products", p);
		Panel p1 = new Panel();
		p1.add(new TextField("Name: ", 20));
		p1.add(new TextField("Address: ", 20));
		p1.add(new TextField("Phone: ", 20));
		p1.add(new Button("Order"));
		p1.add(products);
		add("order", p1);
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent we) {
				System.exit(0);
			}
		});
		show();
	}
	public void actionPerformed(ActionEvent e) {
		CardLayout cl = (CardLayout) getLayout();
		if (e.getSource() == order) {
			cl.show(this, "order");
		}
		if (e.getSource() == products) {
			cl.show(this, "products");
		}
	}
	public static void main(String[] args) {
		CardLayoutDemo cl = new CardLayoutDemo("CardLayout Demo");
	}
}
