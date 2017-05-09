import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class SimpleLogin extends JFrame implements ActionListener {
    private JLabel lblName, lblPassword;
    private JButton btnOk, btnCancel;
    private JTextField jtfName;
    private JPasswordField jtfpassword;
    private JPanel jpbtn, jpMain;

    public SimpleLogin() {
        super("Login!");

        //button
        jpbtn = new JPanel();
        btnOk = new JButton("OK");
        btnCancel = new JButton("Cancel");
        jpbtn.add(btnOk);
        jpbtn.add(btnCancel);

        //information
        jpMain = new JPanel();
        lblName = new JLabel("user name: ");
        lblPassword = new JLabel("password: ");
        jtfName = new JTextField(15);
        jtfpassword = new JPasswordField(15);
        jpMain.add(lblName);
        jpMain.add(lblPassword);
        jpMain.add(jtfName);
        jpMain.add(jtfpassword);

        btnOk.addActionListener(this);
        btnCancel.addActionListener(this);

        Container con = this.getContentPane();
        con.add(jpbtn, BorderLayout.SOUTH);
        con.add(jpMain, BorderLayout.CENTER);

        this.setSize(250, 150);
        this.setLocation(500, 300);
        this.setResizable(false);
        this.setVisible(true);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {
        SimpleLogin sl = new SimpleLogin();
    }


    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == btnOk) {
            if (jtfName.getText().equals("aa") && new String(jtfpassword.getPassword()).equals("123")) {
                this.dispose();
                JOptionPane.showMessageDialog(null, "Success!");
            } else {
                JOptionPane.showMessageDialog(null, "Fail!");
                jtfName.setText("");
                jtfpassword.setText("");
            }
        }
        if (e.getSource() == btnCancel) {
            System.exit(0);
        }
    }
}