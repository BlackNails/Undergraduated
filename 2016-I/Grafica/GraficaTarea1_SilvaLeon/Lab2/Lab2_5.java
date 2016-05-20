import javax.swing.*;
import java.awt.*;

public class Lab2_5 extends JApplet{
	public void init(){
		setSize(400,400);
	}
	
	public void paint(Graphics g){
		Graphics2D g2 = (Graphics2D)g;
		g2.setColor(Color.RED);
		
		for(int i = 0 ; i < 4 ; i++){
			g2.drawArc(100+25*i, 40+50*i, 200-50*i,200-50*i, 180, 180);
			g2.drawArc(100+25*i, 240, 200-50*i, 200-50*i, 0, 180);
		
			g2.drawArc(0+50*i, 140+25*i, 200-50*i, 200-50*i, 90, -180);
			g2.drawArc(200, 140+25*i, 200-50*i, 200-50*i, 90, 180);
		}
	}
}
