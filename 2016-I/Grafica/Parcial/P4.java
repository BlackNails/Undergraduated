import javax.swing.*;
import java.awt.*;

public class P4 extends JApplet{
	public void init(){
		setSize(400,400);
	}
	
	public void paint(Graphics g){
		Graphics2D g2 = (Graphics2D)g;
		
		for(int i = 0 ; i < 2 ; i++){
			g2.setColor(Color.RED);
			g2.fillRect(40+80*i, 40+80*i, 320-160*i, 320-160*i);
			g2.setColor(Color.CYAN);
			g2.fillRect(80+80*i, 80+80*i, 240-160*i, 240-160*i);
		}
		g2.setColor(Color.WHITE);
		for(int i = 0 ; i < 4 ; i++)
		g2.fillArc(0,0,400,400,60+90*i,60);
	}
}
