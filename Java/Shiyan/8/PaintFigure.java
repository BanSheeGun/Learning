import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class PaintFigure extends JFrame implements ActionListener {
    JButton btnTriangle;
    JButton btnRectangle;
    JButton btnEllipse;
    JPanel jMainPanel = new JPanel();
    JPanel buttons = new JPanel();
    int i = 0;

    public PaintFigure() {
        super("working!");
        btnTriangle = new JButton("TRI");
        btnRectangle = new JButton("REC");
        btnEllipse = new JButton("ELL");
        btnTriangle.addActionListener(this);
        btnRectangle.addActionListener(this);
        btnEllipse.addActionListener(this);
        
        buttons.add(btnEllipse);
        buttons.add(btnRectangle);
        buttons.add(btnTriangle);

        jMainPanel.setLayout(new GridLayout(3, 3));

        this.getContentPane().add(buttons, BorderLayout.NORTH);
        this.getContentPane().add(buttons, BorderLayout.CENTER);

        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(500, 400);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent ae) {
        if (ae.getActionCommand().equals("TRI")) {
            if (i < 9) {
                jMainPanel.add(new Triangle());
                jMainPanel.repaint();
                jMainPanel.validate();
                i++;
            }
        }
        if (ae.getActionCommand().equals("REC")) {
            if (i < 9) {
                jMainPanel.add(new Rectangles());
                jMainPanel.repaint();
                jMainPanel.validate();
                i++;
            }
        }
        if (ae.getActionCommand().equals("ELL")) {
            if (i < 9) {
        System.out.println("add");
                jMainPanel.add(new Ellipse());
                jMainPanel.repaint();
                jMainPanel.validate();
                i++;
            }
        }
    }

    public static void main(String[] args) {
        new PaintFigure();
    }
}

class Triangle extends JPanel {
    int height, width;

    public void paintComponent(Graphics g) {
        height = this.getSize().height;
        width = this.getSize().width;
        g.setColor(Color.blue);
        Polygon p = new Polygon();
        p.addPoint(0, height);
        p.addPoint(width / 2, 0);
        p.addPoint(width, height);
        g.fillPolygon(p);
    }
}

class Rectangles extends JPanel {
    int height, width;

    public void paintComponent(Graphics g) {
        height = this.getSize().height;
        width = this.getSize().width;
        g.setColor(Color.red);
        g.fillRect(0, 0, width, height);
    }
}

class Ellipse extends JPanel {
    int height, width;

    public void paintComponent(Graphics g) {

        System.out.println("1");
        height = this.getSize().height;
        width = this.getSize().width;
        g.setColor(Color.yellow);
        g.fillOval(0, 0, width, height);
    }
}