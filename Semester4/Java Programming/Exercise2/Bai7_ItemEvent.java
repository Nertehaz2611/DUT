package BaiThucHanhSo2;

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class Bai7_ItemEvent extends JFrame {
    JPanel pn1, pn2;
    JCheckBox cbMale, cbFemale;
    JComboBox cbb;
    List animal;
    JLabel lb;

    public void GUI() {
        setSize(350, 250);
        setLayout(new GridLayout(2, 1));


        cbMale = new JCheckBox("Male", false);
        cbMale.addItemListener(new ItemListener() {
            public void itemStateChanged(ItemEvent e) {
                String data = "";
                if (e.getStateChange() == 1) {
                    data += "Male";
                    cbFemale.setSelected(false);
                } else data = "";
                lb.setText(data);
            }
        });
        cbFemale = new JCheckBox("Female", false);
        cbFemale.addItemListener(new ItemListener() {
            public void itemStateChanged(ItemEvent e) {
                String data = "";
                if (e.getStateChange() == 1) {
                    data += "Female";
                    cbMale.setSelected(false);
                } else data = "";
                lb.setText(data);
            }
        });

        String hdh[] = {"MS DOS", "Window", "Linux", "MacOS"};
        cbb = new JComboBox<>(hdh);
        cbb.addItemListener(new ItemListener() {

            public void itemStateChanged(ItemEvent e) {
                lb.setText((e.getStateChange() == 1 ? cbb.getSelectedItem().toString() : ""));
            }

        });

        animal = new List();
        animal.add("Tiger");
        animal.add("Lion");
        animal.add("Elephant");
        animal.add("Cat");
        animal.add("Mouse");
        animal.add("Dog");
        animal.addItemListener(new ItemListener() {
            public void itemStateChanged(ItemEvent e) {
                lb.setText(e.getStateChange() == 1 ? animal.getSelectedItem().toString() : "");
            }
        });
        pn1 = new JPanel(new FlowLayout());
        pn1.add(cbMale);
        pn1.add(cbFemale);
        pn1.add(cbb);
        pn1.add(animal);

        lb = new JLabel("The event is displayed here");
        lb.setVerticalAlignment(JLabel.TOP);
        lb.setHorizontalAlignment(JLabel.CENTER);
        pn2 = new JPanel(new FlowLayout());
        pn2.add(lb);
        add(pn1);
        add(pn2);
        setVisible(true);
    }

    public Bai7_ItemEvent(String title) {
        super(title);
        GUI();
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                dispose();
            }
        });
    }

    public static void main(String[] args) {
        new Bai7_ItemEvent("Item Event");
    }
}
