package game;

import java.io.*;
import java.util.Scanner;

public class GameMap {
	public Cell[][] map;
	public static String[] IDtoPic = new String[100];
	int bornx, borny;
	int bornx1, borny1;
	
	public static void initgamemap() {
		try {
			FileReader ini = new FileReader("ini/1.ini");
			Scanner inireader = new Scanner(ini);
			for (int i = 0; i < 51; ++i) {
				IDtoPic[i] = inireader.next();
			}
			IDtoPic[99] = "pic/role/en.jpg";
			inireader.close();
		} catch (IOException e) {
			System.out.println("读入配置失败");
		}	
	}
	
	public GameMap() {
		// TODO Auto-generated constructor stub
		map = new Cell[13][13];
	}
}


