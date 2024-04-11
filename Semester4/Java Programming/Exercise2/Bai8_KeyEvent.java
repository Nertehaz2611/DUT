package BaiThucHanhSo2;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class Bai8_KeyEvent extends JFrame implements KeyListener {
    JLabel lb;
    JPanel pn;
    public void GUI() {
    	
        pn = new JPanel(new GridLayout(1,1));
        lb = new JLabel("A", lb.CENTER);
        addKeyListener(this);

        pn.add(lb);
        add(pn);
        setSize(400,300);
        setVisible(true);
    }
    public void keyTyped(KeyEvent e) {
        lb.setText(String.valueOf(e.getKeyChar()));

    }
    public void keyPressed(KeyEvent e) {
        // TODO Auto-generated method stub

    }
    public void keyReleased(KeyEvent e) {
        // TODO Auto-generated method stub

    }

    public Bai8_KeyEvent(String title) {
        super(title);
        GUI();
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                dispose();
            }
        });
    }
    public static void main(String[] args) {
        new Bai8_KeyEvent("Key Event");
    }

}
