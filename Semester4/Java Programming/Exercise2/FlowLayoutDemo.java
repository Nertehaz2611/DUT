package BaiThucHanhSo2;

import java.awt.*;
import javax.swing.*;
public class FlowLayoutDemo extends JFrame {
	public static void main(String arg[]) {
		FlowLayoutDemo f = new FlowLayoutDemo();
		f.setTitle("FlowLayout Demo");
		f.setBounds(200, 500, 350, 350);
		f.setLayout(new FlowLayout());
		f.add(new JButton("OK"));
		f.add(new JButton("Cancel"));
		
		f.add(new JLabel("This is the Label"));
		f.add(new JTextField(7));
		f.add(new JTextArea(5, 30));
		
		f.add(new Checkbox("Sport"));
		f.add(new Checkbox("Music"));
		f.add(new Checkbox("Travel"));
		
		CheckboxGroup cg = new CheckboxGroup();
		f.add(new Checkbox("Female", cg, true));
		f.add(new Checkbox("Male", cg, true));
		
		Choice ch = new Choice();
		ch.addItem("Sport");
		ch.addItem("Music");
		ch.addItem("Travel");
		f.add(ch);
		List list = new List(3, false);
		list.add("Music");
		list.add("Travel");
		list.add("Game");
		list.add("Telen");
		f.add(list);
		f.setVisible(true);
	}
}
