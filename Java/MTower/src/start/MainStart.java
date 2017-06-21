package start;

import com.*;
import game.*;

public class MainStart {
	public static void main(String[] args) {
		MainFrame mf = new MainFrame("魔塔");
		mf.setVisible(true);
		Cell.initcell();
		GameMap.initgamemap();
	}
}
