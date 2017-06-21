package com;

import java.awt.*;
import javax.swing.*;

public class Pic extends JPanel {
	private static final long serialVersionUID = 4655333955420264333L;
	Image a;
	
	public Pic(String imgs) {
		try {
			a=new ImageIcon(imgs).getImage();
		} catch (Exception e) {
			System.out.println(e);
		}
	}
	
	public void paintComponent(Graphics g){
		g.drawImage(a, 0, 0, this.getWidth(), this.getHeight(), this);  
	}
}
