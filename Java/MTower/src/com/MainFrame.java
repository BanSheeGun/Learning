package com;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

import game.*;

public class MainFrame extends JFrame implements KeyListener{
	private static final long serialVersionUID = -2748685992144471445L;
	JPanel gamefield, buttonfield, infofield, infow[];
	JButton newgame, savegame, loadgame;
	Pic RK, YK, BK, HX;
	JLabel SM, FY, GJ, LV;
	JLabel RKN, YKN, BKN, CS;
	Game nowgame;
	int infoi;
	
	public MainFrame(String title) {
		// TODO Auto-generated constructor stub
		super(title);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(920, 665);
		setLocation(30, 20);
		setLayout(null);
		InitButtonField();
		InitInfoField();
		InitGameField();
		setVisible(true);
		this.addKeyListener(this);
	}
	
	private void InitButtonField() {
		newgame = new JButton("新游戏");
		savegame = new JButton("保存游戏");
		loadgame = new JButton("加载游戏");
		gamefield = new JPanel();
		gamefield.setLayout(null);
		this.add(gamefield);
		gamefield.setBounds(0, 0, 300, 30);
		gamefield.add(newgame);
		gamefield.add(savegame);
		gamefield.add(loadgame);
		newgame.setBounds(1, 0, 98, 30);
		savegame.setBounds(101, 0, 98, 30);
		loadgame.setBounds(201, 0, 98, 30);
		
		newgame.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				nowgame = new Game("rec/base.txt");
				freshinfofield();
				freshgamefield(nowgame.gp[nowgame.nowfloor]);
				returnfoucs();
			}
		});

		savegame.addActionListener(new ActionListener() {
			JFrame tmp;
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				tmp = new JFrame("");
				tmp.setSize(100, 200);
				tmp.setLocation(300, 300);
				tmp.setVisible(true);
				tmp.setLayout(new FlowLayout(FlowLayout.LEFT, 20, 20));
				JButton jb1, jb2, jb3;
				jb1 = new JButton("存档 1");
				jb2 = new JButton("存档 2");
				jb3 = new JButton("存档 3");
				tmp.add(jb1);
				tmp.add(jb2);
				tmp.add(jb3);

				jb1.addActionListener(new ActionListener() {
					@Override
					public void actionPerformed(ActionEvent e) {
						// TODO Auto-generated method stub
						nowgame.Savegame("rec/1.txt");
						System.out.println("保存到存档1");
						returnfoucs();
						returna();
					}
				});
				jb2.addActionListener(new ActionListener() {
					@Override
					public void actionPerformed(ActionEvent e) {
						// TODO Auto-generated method stub
						nowgame.Savegame("rec/2.txt");
						System.out.println("保存到存档2");
						returnfoucs();
						returna();
					}
				});
				jb3.addActionListener(new ActionListener() {
					@Override
					public void actionPerformed(ActionEvent e) {
						// TODO Auto-generated method stub
						nowgame.Savegame("rec/3.txt");
						System.out.println("保存到存档3");
						returnfoucs();
						returna();
					}
				});
			}
			public void returna() {
				tmp.dispose();
			}
		});
		
		loadgame.addActionListener(new ActionListener() {
			JFrame tmp;
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				tmp = new JFrame("");
				tmp.setSize(100, 200);
				tmp.setLocation(300, 300);
				tmp.setVisible(true);
				tmp.setLayout(new FlowLayout(FlowLayout.LEFT, 20, 20));
				JButton jb1, jb2, jb3;
				jb1 = new JButton("存档 1");
				jb2 = new JButton("存档 2");
				jb3 = new JButton("存档 3");
				tmp.add(jb1);
				tmp.add(jb2);
				tmp.add(jb3);

				jb1.addActionListener(new ActionListener() {
					@Override
					public void actionPerformed(ActionEvent e) {
						// TODO Auto-generated method stub
						nowgame = new Game("rec/1.txt");
						System.out.println("读取存档 1");
						freshinfofield();
						freshgamefield(nowgame.gp[nowgame.nowfloor]);
						returnfoucs();
						returna();
					}
				});
				jb2.addActionListener(new ActionListener() {
					@Override
					public void actionPerformed(ActionEvent e) {
						// TODO Auto-generated method stub
						nowgame = new Game("rec/2.txt");
						System.out.println("读取存档 2");
						freshinfofield();
						freshgamefield(nowgame.gp[nowgame.nowfloor]);
						returnfoucs();
						returna();
					}
				});
				jb3.addActionListener(new ActionListener() {
					@Override
					public void actionPerformed(ActionEvent e) {
						// TODO Auto-generated method stub
						nowgame = new Game("rec/3.txt");
						System.out.println("读取存档 3");
						freshinfofield();
						freshgamefield(nowgame.gp[nowgame.nowfloor]);
						returnfoucs();
						returna();
					}
				});
			}
			
			public void returna() {
				tmp.dispose();
			}
		});
	}
	
	private void InitInfoField() {
		infofield = new JPanel();
		this.add(infofield);
		infofield.setBounds(0, 30, 320, 600);
		infofield.setLayout(null);
		SM = new JLabel("生命： ");
		FY= new JLabel("防御： ");
		GJ = new JLabel("攻击：");
		LV = new JLabel("等级： ");
		HX = new Pic("pic/role/main.jpg");
		infofield.add(SM);
		infofield.add(FY);
		infofield.add(GJ);
		infofield.add(HX);
		infofield.add(LV);
		SM.setBounds(120, 15, 200, 30);
		FY.setBounds(120, 50, 200, 30);
		GJ.setBounds(120, 85, 200, 30);
		HX.setBounds(10, 15, 100, 100);
		LV.setBounds(10, 115, 300, 30);

		RK = new Pic("pic/key/redkey.jpg");
		YK = new Pic("pic/key/yellowkey.jpg");
		BK = new Pic("pic/key/bluekey.jpg");
		RKN = new JLabel("1  个");
		YKN = new JLabel("1  个");
		BKN = new JLabel("1  个");
		CS = new JLabel("第 1 层");
		infofield.add(RK);
		infofield.add(YK);
		infofield.add(BK);
		infofield.add(CS);
		infofield.add(RKN);
		infofield.add(YKN);
		infofield.add(BKN);
		YK.setBounds(5, 175, 50, 50);
		BK.setBounds(115, 175, 50, 50);
		RK.setBounds(225, 175, 50, 50);
		YKN.setBounds(60, 175, 40, 40);
		BKN.setBounds(170, 175, 40, 40);
		RKN.setBounds(280, 175, 40, 40);
		CS.setBounds(60, 225, 250, 30);
		infofield.setBackground(Color.gray);
		infoi = 0;
		infow = new JPanel[5];
	}
	
	private void InitGameField () {
		gamefield = new JPanel();
		this.add(gamefield);
		gamefield.setVisible(false);
		gamefield.setBounds(360, 40, 520, 520);
		gamefield.setLayout(new GridLayout(13, 13, 0, 0));
		gamefield.setVisible(true);
	}
	
	public void freshgamefield(GameMap now) {
		gamefield.setVisible(false);
		gamefield.removeAll();
		for (int i = 0; i < 13; ++i) 
			for (int j = 0; j < 13; ++j) {
				gamefield.add(new Pic(GameMap.IDtoPic[now.map[i][j].ID]));
			}
		gamefield.setVisible(true);
	}
	
	public void freshinfofield() {
		infofield.setVisible(false);
		SM.setText("生命： " + nowgame.sxl);
		FY.setText("防御： " + nowgame.sfy);
		GJ.setText("攻击： " + nowgame.sgj);
		LV.setText("等级：  " + nowgame.lv + "           金钱： " + nowgame.sjq);
		YKN.setText(nowgame.sy + " 个 ");
		BKN.setText(nowgame.sb + " 个 ");
		RKN.setText(nowgame.sr + " 个 ");
		CS.setText("第 " + nowgame.nowfloor + " 层");
		for (int i = 1; i <= infoi; ++i)
			infofield.remove(infow[i]);
		infoi = 0;
		int tmp = nowgame.gp[nowgame.nowfloor].map[nowgame.nowx+1][nowgame.nowy].ID;
		if (tmp >= 15) {
			++infoi;
			info(tmp);
		}
		tmp = nowgame.gp[nowgame.nowfloor].map[nowgame.nowx-1][nowgame.nowy].ID;
		if (tmp >= 15) {
			++infoi;
			info(tmp);
		}
		tmp = nowgame.gp[nowgame.nowfloor].map[nowgame.nowx][nowgame.nowy+1].ID;
		if (tmp >= 15) {
			++infoi;
			info(tmp);
		}
		tmp = nowgame.gp[nowgame.nowfloor].map[nowgame.nowx][nowgame.nowy-1].ID;
		if (tmp >= 15) {
			++infoi;
			info(tmp);
		}
		infofield.repaint();
		infofield.setVisible(true);
	}
	
	public void info(int id) {
		 infow[infoi] = new JPanel();
		 infow[infoi].setLayout(null);
		 infow[infoi].setBounds(10 , 285 + (infoi-1) * 75, 300, 75);
		 infow[infoi].setBackground(Color.WHITE);
		 Pic infopic = new Pic(GameMap.IDtoPic[id]);
		 JTextArea infotext = new JTextArea();
		 infotext.setText(Cell.SName[id]);
		 if (id >= 30 && id != 99) {
			 int tmp = nowgame.duizhan(id);
			 String tmp1 = "";
			 tmp1 = Cell.SName[id] + "\r\n";
			 tmp1 += "生命： " + Cell.sz[id][0] + " 攻击： "+ Cell.sz[id][1] + " 防御： "+ Cell.sz[id][2] + " 金币："+ Cell.sz[id][3] + "\r\n";
			 if (tmp != -1)
				 tmp1 += "伤害： " + tmp;
			 else 
				 tmp1 += "伤害： ????";
			 infotext.setText(tmp1);
		 }
		 infow[infoi].add(infopic);
		 infow[infoi].add(infotext);
		 infopic.setBounds(0, 0, 75, 75);
		 infotext.setBounds(75, 0, 225, 75);
		 infofield.add(infow[infoi]);
	}
	
	@Override
	public void keyPressed(KeyEvent e) {
		int x = nowgame.nowx;
		int y = nowgame.nowy;
		String presskey = KeyEvent.getKeyText(e.getKeyCode());
		switch (presskey) {
		case "W":
			nowgame.gp[nowgame.nowfloor].map[x][y] = new Cell(14);
			x -= 1;
			break;
		case "S":
			nowgame.gp[nowgame.nowfloor].map[x][y] = new  Cell(11);
			x += 1;
			break;
		case "A":
			nowgame.gp[nowgame.nowfloor].map[x][y] = new  Cell(12);
			y -= 1;
			break;
		case "D":
			nowgame.gp[nowgame.nowfloor].map[x][y] = new  Cell(13);
			y += 1;
			break;
		default:
			return;
		}
		nowgame.Work(nowgame.gp[nowgame.nowfloor].map[x][y].ID, x, y);
		freshgamefield(nowgame.gp[nowgame.nowfloor]);
		freshinfofield();
	}
	
	@Override
	public void keyTyped(KeyEvent e) {
	}

	@Override
	public void keyReleased(KeyEvent arg0) {
		// TODO Auto-generated method stub
	}
	
	public void returnfoucs() {
		requestFocus();
	}
}
