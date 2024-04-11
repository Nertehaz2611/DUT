package BaiThucHanhSo2;

import java.awt.*;
import javax.swing.*;
public class GridLayoutDemo extends JFrame {
	public static void main(String[] args) {
		GridLayoutDemo gl = new GridLayoutDemo();
		gl.setTitle("GridLayout Demo");
		gl.setLayout(new GridLayout());
		gl.setBounds(250, 250, 300, 300);
		JLabel xLabel = new JLabel("X coordinate: ");
		JLabel yLabel = new JLabel("Y coordinate: ");
		JTextField xInput = new JTextField(5);
		JTextField yInput = new JTextField(5);
		gl.setLayout(new GridLayout(2, 2));
		gl.add(xLabel); gl.add(xInput);
		gl.add(yLabel); gl.add(yInput);
		gl.setVisible(true);
	}
}
