package BaiThucHanhSo2;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
import java.util.Stack;
public class Bai5_Calculator extends JFrame implements ActionListener {
	JTextField txt;
	JButton num[], dot, add, sub, mul, div, clr, res;
	JPanel pn, pn1;
	String s = "";
	
	public void GUI() {
		txt = new JTextField(22);
		txt.setHorizontalAlignment(JTextField.RIGHT);
		txt.setEditable(false);
		txt.setPreferredSize(new Dimension(200, 50));
        txt.setFont(new Font("Roboto", Font.PLAIN, 20));
		
		num = new JButton[10];
		for (int i = 0; i <= 9; i++) {
			num[i] = new JButton(Integer.toString(i));
			num[i].addActionListener(this);
		}
		dot = new JButton(".");
		add = new JButton("+");
		sub = new JButton("-");
		mul = new JButton("*");
		div = new JButton("/");
		clr = new JButton("C");
		res = new JButton("=");
		res.setPreferredSize(new Dimension(45, 104));
		
		dot.addActionListener(this);
		add.addActionListener(this);
		sub.addActionListener(this);
		mul.addActionListener(this);
		div.addActionListener(this);
		clr.addActionListener(this);
		res.addActionListener(this);
		
		pn1 = new JPanel(new GridLayout(4, 4));
		pn = new JPanel(new BorderLayout());
		
		pn1.add(num[7]);
		pn1.add(num[8]);
		pn1.add(num[9]);
		pn1.add(div);
		pn1.add(num[4]);
		pn1.add(num[5]);
		pn1.add(num[6]);
		pn1.add(mul);
		pn1.add(num[1]);
		pn1.add(num[2]);
		pn1.add(num[3]);
		pn1.add(sub);
		pn1.add(num[0]);
		pn1.add(dot);
		pn1.add(clr);
		pn1.add(add);
		
		
		pn.add(txt, BorderLayout.NORTH);
        pn.add(pn1, BorderLayout.CENTER);
        pn.add(res, BorderLayout.EAST);
        add(pn);
        setSize(500,300);
        setVisible(true);
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
    public boolean isOperator(char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }

    public int precedence(char op) {
        switch (op) {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            default:
                return -1;
        }
    }

    public String infixToPostfix(String infix) {
        StringBuilder postfix = new StringBuilder();
        Stack<Character> stack = new Stack<>();

        for (char ch : infix.toCharArray()) {
            if (Character.isDigit(ch) || ch == '.') {
                postfix.append(ch);
            } else if (isOperator(ch)) {
                postfix.append(' ');
                while (!stack.isEmpty() && precedence(ch) <= precedence(stack.peek())) {
                    postfix.append(stack.pop()).append(' ');
                }
                stack.push(ch);
            }
        }
        while (!stack.isEmpty()) {
            postfix.append(' ').append(stack.pop());
        }

        return postfix.toString();
    }

    public double evaluatePostfix(String postfix) {
        Stack<Double> stack = new Stack<>();

        for (String token : postfix.split("\\s+")) {
            if (Character.isDigit(token.charAt(0)) || token.length() > 1) {
                stack.push(Double.parseDouble(token));
            } else if (isOperator(token.charAt(0))) {
                double operand2 = stack.pop();
                double operand1 = stack.pop();
                double result;
                switch (token) {
                    case "+":
                        result = operand1 + operand2;
                        break;
                    case "-":
                        result = operand1 - operand2;
                        break;
                    case "*":
                        result = operand1 * operand2;
                        break;
                    case "/":
                        result = operand1 / operand2;
                        break;
                    default:
                        throw new IllegalArgumentException("Invalid operator: " + token);
                }
                stack.push(result);
            }
        }
        return stack.pop();
    }
	
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() != null && s == "Infinity") {
			s = "";
		}
		if (e.getSource() == num[0]) {
			s += "0";
			txt.setText(s);
		}
		if (e.getSource() == num[1]) {
			s += "1";
			txt.setText(s);
		}
		if (e.getSource() == num[2]) {
			s += "2";
			txt.setText(s);
		}
		if (e.getSource() == num[3]) {
			s += "3";
			txt.setText(s);
		}
		if (e.getSource() == num[4]) {
			s += "4";
			txt.setText(s);
		}
		if (e.getSource() == num[5]) {
			s += "5";
			txt.setText(s);
		}
		if (e.getSource() == num[6]) {
			s += "6";
			txt.setText(s);
		}
		if (e.getSource() == num[7]) {
			s += "7";
			txt.setText(s);
		}
		if (e.getSource() == num[8]) {
			s += "8";
			txt.setText(s);
		}
		if (e.getSource() == num[9]) {
			s += "9";
			txt.setText(s);
		}
		if (e.getSource() == dot) {
			s += ".";
			txt.setText(s);
		}
		if (e.getSource() == clr) {
			s = "";
			txt.setText(s);
		}
		if (e.getSource() == add) {
			s += "+";
			txt.setText(s);
		}
		if (e.getSource() == sub) {
			s += "-";
			txt.setText(s);
		}
		if (e.getSource() == mul) {
			s += "*";
			txt.setText(s);
		}
		if (e.getSource() == div) {
			s += "/";
			txt.setText(s);
		}
		if (e.getSource() == res) {
			String post = infixToPostfix(s);
			Double ans = evaluatePostfix(post);
			s = Double.toString(ans);
			txt.setText(s);
		}
	}
	
	public Bai5_Calculator(String title) {
		super(title);
		GUI();
	}
	
	public static void main(String[] args) {
		new Bai5_Calculator("Calculator");
	}

	
}
