package game;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.*;
import javax.swing.*;

public class Game {
	public GameMap gp[];
	public static String cd;
	public int nowx, nowy, nowfloor;
	public int sxl, sgj, sfy, sjq, sy, sb, sr, lv;
	public int sfloor;
	
	public Game(String cdd) {
		// TODO Auto-generated constructor stub
		cd = cdd;
		System.out.println("读取游戏 " + cdd);
		try {
			FileReader gameinfo = new FileReader(cdd);
			Scanner gf = new Scanner(gameinfo);
			nowx = gf.nextInt();
			nowy = gf.nextInt();
			nowfloor = gf.nextInt();
			sxl = gf.nextInt();
			sgj = gf.nextInt();
			sfy = gf.nextInt();
			sjq = gf.nextInt();
			sy = gf.nextInt();
			sb = gf.nextInt();
			sr = gf.nextInt();
			lv = gf.nextInt();
			sfloor = gf.nextInt();
			
			gp = new GameMap[sfloor];
			for (int i = 0; i < sfloor; ++i) {
				gp[i] = new GameMap();
				gp[i].bornx = gf.nextInt();
				gp[i].borny = gf.nextInt();
				gp[i].bornx1 = gf.nextInt();
				gp[i].borny1 = gf.nextInt();
				for (int ii = 0; ii < 13; ++ii)
					for (int jj = 0; jj < 13; ++jj) {
						int idd = gf.nextInt();
						gp[i].map[ii][jj] = new Cell(idd);
					}
			}
			gp[nowfloor].map[nowx][nowy] = new Cell(11);
			
			gf.close();
			gameinfo.close();
		} catch (Exception e) {
			// TODO: handle exception
			System.out.println(e+"\n游戏信息失败");
		}
		
	}
	
	public void Work(int nid, int x, int y) {
		if (nid == 0) {
			gp[nowfloor].map[x][y] = gp[nowfloor].map[nowx][nowy];
			gp[nowfloor].map[nowx][nowy] = new Cell(0);
			nowx = x;
			nowy = y;
			return;
		}
		if (nid == 1 || nid == 4 || nid == 5)
			return;
		if (nid == 3) {
			x = gp[nowfloor+1].bornx;
			y = gp[nowfloor+1].borny;
			gp[nowfloor+1].map[x][y] = new Cell(11);
			gp[nowfloor].map[nowx][nowy] = new Cell(0);
			nowx = x;
			nowy = y;
			nowfloor++;
			return;
		}
		if (nid == 2) {
			x = gp[nowfloor-1].bornx1;
			y = gp[nowfloor-1].borny1;
			gp[nowfloor-1].map[x][y] = new Cell(11);
			gp[nowfloor].map[nowx][nowy] = new Cell(0);
			nowx = x;
			nowy = y;
			nowfloor--;
			return;
		}
		if (nid == 15) {
			if (sy >= 1) {
				sy--;
				gp[nowfloor].map[x][y] = new Cell(0);
			} 
			return;
		} 
		if (nid == 16) {
			if (sb >= 1) {
				sb--;
				gp[nowfloor].map[x][y] = new Cell(0);
			} 
			return;
		} 
		if (nid == 17) {
			if (sr >= 1) {
				sr--;
				gp[nowfloor].map[x][y] = new Cell(0);
			} 
			return;
		}
		
		if (nid == 8 || nid == 9 || nid == 10) {
			sd3();
			return;
		}
		switch (nid) {
		case 18:
			sxl += 200;
			Work(0, x, y);
			break;
		case 19:
			sxl += 500;
			Work(0, x, y);
			break;
		case 20:
			sgj += 3;
			Work(0, x, y);
			break;
		case 21:
			sfy += 3;
			Work(0, x, y);
			break;
		case 22:
			sgj += 10;
			Work(0, x, y);
			break;
		case 23:
			lv += 1;
			sxl += 1000;
			sgj += 7;
			sfy += 7;
			Work(0, x, y);
			break;
		case 24:
			sfy += 10;
			Work(0, x, y);
			break;
		case 25:
			sjq += 300;
			Work(0, x, y);
			break;
		case 26:
			sy += 1;
			sb += 1;
			sr += 1;
			Work(0, x, y);
			break;
		case 27:
			sy += 1;
			Work(0, x, y);
			break;
		case 28:
			sb += 1;
			Work(0, x, y);
			break;
		case 29:
			sr += 1;
			Work(0, x, y);
			break;
		case 6:
			sd1();
			break;
		case 7:
			sd2();
			break;
		case 99:
			tongguan();
			break;
		default:
			int diaoxue = duizhan(nid);
			if (diaoxue < sxl && diaoxue != -1) {
				sxl -= diaoxue;
				gp[nowfloor].map[x][y] = gp[nowfloor].map[nowx][nowy];
				gp[nowfloor].map[nowx][nowy] = new Cell(0);
				nowx = x;
				nowy = y;
				sjq += Cell.sz[nid][3];
			}
			break;
		}
	}
	
	public void Savegame(String OB) {
		try {
			FileWriter fw = new FileWriter(OB);
			fw.write(nowx + " " + nowy + " " + nowfloor + "\r\n");
			fw.write(sxl + " " + sgj + " " + sfy + " " + sjq + "\r\n");
			fw.write(sy + " " + sb + " " + sr + "\r\n");
			fw.write(lv + "\r\n\r\n" + sfloor + "\r\n");
			
			for (int i = 0; i < sfloor; ++i) {
				fw.write(gp[i].bornx + " " + gp[i].borny + " " + gp[i].bornx1 + " " + gp[i].borny1 + "\r\n");
				for (int x = 0; x < 13; ++x) {
					for (int y = 0; y < 13; ++y)
						fw.write(gp[i].map[x][y].ID + " ");
					fw.write("\r\n");
				}
				fw.write("\r\n");
			}
			
			fw.close();
		} catch (Exception e) {
			// TODO: handle exception
			System.out.println(e + "\n存档失败");
		}
	}
	
	JFrame tanchuang;
	JLabel jingqian;
	void sd1() {
		tanchuang = new JFrame("等级商店");
		tanchuang.setSize(240, 200);
		tanchuang.setLocation(300, 200);
		tanchuang.setVisible(true);
		jingqian = new JLabel("金币: " + sjq);
		JButton a1, a2;
		a1 = new JButton("100金币升一级");
		a2 = new JButton("返回");
		tanchuang.setLayout(new FlowLayout(FlowLayout.LEFT, 50, 20));
		tanchuang.add(jingqian);
		tanchuang.add(a1);
		tanchuang.add(a2);
		
		a1.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				System.out.println(sjq);
				if (sjq < 100)
					return;
				else {
					System.out.println(sjq);
					sjq -= 100;
					lv += 1;
					sxl += 100;
					sgj += 7;
					sfy += 7;
				}
				jingqian.setText("金币: " + sjq);
				tanchuang.repaint();
			}
		});
		
		a2.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				tanchuang.dispose();
			}
		});
	}
	
	void sd2() {
		tanchuang = new JFrame("钥匙商店");
		tanchuang.setSize(240, 400);
		tanchuang.setLocation(300, 200);
		tanchuang.setVisible(true);
		jingqian = new JLabel("金币: " + sjq);
		JButton a1, a2, a3, a4;
		a1 = new JButton("25金币 黄钥匙");
		a2 = new JButton("50金币 蓝钥匙");
		a3 = new JButton("100金币 红钥匙");
		a4 = new JButton("返回");
		tanchuang.setLayout(new FlowLayout(FlowLayout.LEFT, 50, 20));
		tanchuang.add(jingqian);
		tanchuang.add(a1);
		tanchuang.add(a2);
		tanchuang.add(a3);
		tanchuang.add(a4);

		a1.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				System.out.println(sjq);
				if (sjq < 25)
					return;
				else {
					System.out.println(sjq);
					sjq -= 25;
					sy += 1;
				}
				jingqian.setText("金币： " + sjq);
				tanchuang.repaint();
			}
		});

		a2.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				System.out.println(sjq);
				if (sjq < 50)
					return;
				else {
					System.out.println(sjq);
					sjq -= 50;
					sb += 1;
				}
				jingqian.setText("金币： " + sjq);
				tanchuang.repaint();
			}
		});

		a3.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				System.out.println(sjq);
				if (sjq < 100)
					return;
				else {
					System.out.println(sjq);
					sjq -= 100;
					sr += 1;
				}
				jingqian.setText("金币： " + sjq);
				tanchuang.repaint();
			}
		});
		
		a4.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				tanchuang.dispose();
			}
		});
	}	
	
	void sd3() {
		tanchuang = new JFrame("商店");
		tanchuang.setSize(240, 400);
		tanchuang.setLocation(300, 200);
		tanchuang.setVisible(true);
		jingqian = new JLabel("金币： " + sjq);
		JButton a1, a2, a3, a4;
		a1 = new JButton("25金币 800生命");
		a2 = new JButton("25金币 4点攻击");
		a3 = new JButton("25金币 4点防御");
		a4 = new JButton("返回");
		tanchuang.setLayout(new FlowLayout(FlowLayout.LEFT, 50, 20));
		tanchuang.add(jingqian);
		tanchuang.add(a1);
		tanchuang.add(a2);
		tanchuang.add(a3);
		tanchuang.add(a4);

		a1.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				System.out.println(sjq);
				if (sjq < 25)
					return;
				else {
					System.out.println(sjq);
					sjq -= 25;
					sxl += 800;
				}
				jingqian.setText("金币： " + sjq);
				tanchuang.repaint();
			}
		});

		a2.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				System.out.println(sjq);
				if (sjq < 25)
					return;
				else {
					System.out.println(sjq);
					sjq -= 25;
					sgj += 4;
				}
				jingqian.setText("金币： " + sjq);
				tanchuang.repaint();
			}
		});

		a3.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				System.out.println(sjq);
				if (sjq < 25)
					return;
				else {
					System.out.println(sjq);
					sjq -= 25;
					sfy += 4;
				}
				jingqian.setText("金币： " + sjq);
				tanchuang.repaint();
			}
		});
		
		a4.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				tanchuang.dispose();
			}
		});
	}
	
	void tongguan() {
		tanchuang = new JFrame("通关");
		tanchuang.setSize(240, 200);
		tanchuang.setLocation(300, 200);
		tanchuang.setVisible(true);
		jingqian = new JLabel("游戏结束     ");
		JButton a1, a2;
		a1 = new JButton("    继续闲逛   ");
		a2 = new JButton("退出游戏");
		tanchuang.setLayout(new FlowLayout(FlowLayout.LEFT, 50, 20));
		tanchuang.add(jingqian);
		tanchuang.add(a1);
		tanchuang.add(a2);

		a1.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				tanchuang.dispose();
			}
		});

		a2.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				System.exit(0);
			}
		});
	}
	
	public int duizhan (int id) {
		int sh = sgj - Cell.sz[id][2];
		if (sh <= 0)
			return -1;
		int cishu = (Cell.sz[id][0] + sh - 1) / sh - 1;
		int diaoxue = (sfy - Cell.sz[id][1]) * cishu;
		if (diaoxue < 0)
			diaoxue = 0;
		return diaoxue;
	}
}
