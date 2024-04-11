package BaiThucHanhSo2;

import java.awt.*;
import javax.swing.*;
public class GridBagLayoutDemo extends JFrame {
	JLabel lb1 = new JLabel("Name");
	JTextField tf1 = new JTextField(50);
	JLabel lb2 = new JLabel("Address");
	JTextArea ta1 = new JTextArea(5, 50);
	JLabel lb3 = new JLabel("Sex");
	CheckboxGroup cb = new CheckboxGroup();
	Checkbox cb1 = new Checkbox("Male", cb, true);
	Checkbox cb2 = new Checkbox("Female", cb, true);
	JLabel lb4 = new JLabel("Hobbies");
	Checkbox cb3 = new Checkbox("Reading", true);
	Checkbox cb4 = new Checkbox("Sport", false);
	Checkbox cb5 = new Checkbox("Travelling", false);
	JLabel lb5 = new JLabel("Age Group");
	Choice ch1 = new Choice();
	JButton bt1 = new JButton("OK");
	JButton bt2 = new JButton("Cancel");
	GridBagLayout gb;
	GridBagConstraints gbc;
	private void addComponent(Component component, int gridx, int gridy, int gridwidth, int gridheight, int fill) {
        gbc.gridx = gridx;
        gbc.gridy = gridy;
        gbc.gridwidth = gridwidth;
        gbc.gridheight = gridheight;
        gbc.fill = fill;
        gb.setConstraints(component, gbc);
        add(component, gbc);
    }
	public GridBagLayoutDemo(String title) {
		super(title);
		gb = new GridBagLayout();
		setLayout(gb);
		ch1.addItem("--");
		ch1.addItem("0-10");
		ch1.addItem("10-20");
		ch1.addItem("20-30");
		ch1.addItem("30-40");
		ch1.addItem("above 40");
		gbc = new GridBagConstraints();
		addComponent(lb1, 0, 0, 1, 1, GridBagConstraints.HORIZONTAL);
		addComponent(tf1, 2, 0, 5, 1, GridBagConstraints.HORIZONTAL);
		addComponent(lb2, 0, 1, 1, 1, GridBagConstraints.HORIZONTAL);
		addComponent(ta1, 2, 1, 5, 1, GridBagConstraints.HORIZONTAL);
		addComponent(lb3, 0, 2, 1, 1, GridBagConstraints.HORIZONTAL);
		addComponent(cb1, 2, 2, 1, 1, GridBagConstraints.HORIZONTAL);
		addComponent(cb2, 2, 3, 1, 1, GridBagConstraints.HORIZONTAL);
		addComponent(lb4, 0, 4, 1, 1, GridBagConstraints.HORIZONTAL);
		addComponent(cb3, 2, 4, 1, 1, GridBagConstraints.HORIZONTAL);
		addComponent(cb4, 2, 5, 1, 1, GridBagConstraints.HORIZONTAL);
		addComponent(cb5, 2, 6, 1, 1, GridBagConstraints.HORIZONTAL);
		addComponent(lb5, 0, 7, 1, 1, GridBagConstraints.HORIZONTAL);
		addComponent(ch1, 2, 7, 1, 1, GridBagConstraints.HORIZONTAL);
		addComponent(bt1, 3, 9, 1, 1, GridBagConstraints.NONE);
		addComponent(bt2, 4, 9, 1, 1, GridBagConstraints.NONE);
	}
	public static void main(String[] args) {
		GridBagLayoutDemo gbl = new GridBagLayoutDemo("GridBagLayout Demo");
		gbl.setBounds(300, 300, 600, 300);
		gbl.setVisible(true);
	}
}
