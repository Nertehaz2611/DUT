package BaiThucHanhSo2;
import javax.swing.*;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import java.awt.*;
import java.awt.event.*;

public class Bai6_ActionEvent extends Frame implements ActionListener {
    JLabel lb;
    JPanel pn, pn1, pn2;
    JButton ok;
    JTextField txt;
    List animal;

    public void GUI() {
        setSize(400, 250);
        setLayout(new GridLayout(2, 1));

        ok = new JButton("OK");
        ok.addActionListener(this);
        txt = new JTextField(10);
        txt.getDocument().addDocumentListener(new DocumentListener() {

            @Override//from  w  w  w .  j  av  a 2s.  com
            public void insertUpdate(DocumentEvent e) {
                lb.setText("Text changed");
            }
            @Override
            public void removeUpdate(DocumentEvent e) {
                lb.setText("Text changed");

            }

            @Override
            public void changedUpdate(DocumentEvent e) {
                lb.setText("Text changed");

            }

        });
        animal = new List();
        animal.add("Tiger");
        animal.add("Lion");
        animal.add("Elephant");
        JScrollPane sp = new JScrollPane(animal, JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
//        sb.add(animallist);
        JScrollBar sb = sp.getVerticalScrollBar();
        sb.setPreferredSize(new Dimension(10, 0));

        animal.addActionListener(this);
        pn1 = new JPanel(new FlowLayout());
        pn1.add(ok);
        pn1.add(txt);
        pn1.add(sp);

        lb = new JLabel("The event is displayed here");
        lb.setHorizontalAlignment(JLabel.CENTER);
        lb.setVerticalAlignment(JLabel.TOP);

        add(pn1);
        add(lb);
        setVisible(true);

    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == ok) {
            lb.setText("Button is clicked ");
        }
        if (e.getSource() == txt) {
            lb.setText("TextField is written: " + txt.getText());
        }
        if (e.getSource() == animal) {
            lb.setText("You double click on the" + e.getActionCommand());
        }
    }

    public Bai6_ActionEvent(String title) {
    	super(title);
        GUI();
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                dispose();
            }
        });
    }

    public static void main(String[] args) {
        new Bai6_ActionEvent("Action Event");
    }
}