import javax.swing.*;
import java.awt.*;

public class Lab2_4 extends JApplet{
	public void init(){
		setSize(400,400);
	}
	
	public void paint(Graphics g){
		Graphics2D g2 = (Graphics2D)g;
		g2.setColor(Color.RED);
		for(int i = 0 ; i < 8 ; i++){
			g2.drawOval(180-20*i, 180-20*i, 40+40*i, 40+40*i);
		}
	}
}
