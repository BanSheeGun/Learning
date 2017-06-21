package game;

import java.io.*;
import java.util.Scanner;

public class Cell {
	public int ID, xl, gj, fy, jq;
	
	public static String SName[];
	public static int sz[][];
	public static void initcell () {
		SName = new String[100];
		sz = new int[100][4];
		try {
			FileReader ini = new FileReader("ini/2.ini");
			Scanner inireader = new Scanner(ini);
			for (int i = 0; i < 51; ++i) {
				SName[i] = inireader.next();
				sz[i][0] = inireader.nextInt();
				sz[i][1] = inireader.nextInt();
				sz[i][2] = inireader.nextInt();
				sz[i][3] = inireader.nextInt();
				System.out.println(SName[i]);
			}
			sz[99][0] = 0;
			sz[99][1] = 0;
			sz[99][2] = 0;
			sz[99][3] = 0;
			SName[99] = "公主";
			inireader.close();
		} catch (IOException e) {
			System.out.println(e + "初始化cell失败");
		}
	}
	
	public Cell(int id, int a, int b, int c, int d) {
		// TODO Auto-generated constructor stub
		ID = id;
		xl = a;
		gj = b;
		fy = c;
		jq = d;
	}
	
	public Cell(int id) {
		ID = id;
		xl = sz[id][0];
		gj = sz[id][0];
		fy = sz[id][0];
		jq = sz[id][0];
	}
}
