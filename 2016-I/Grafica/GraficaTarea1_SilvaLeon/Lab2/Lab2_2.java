import javax.swing.*;
import java.awt.*;

public class Lab2_2 extends JApplet{
	public void init(){
		setSize(400,400);
	}
	
	public void paint(Graphics g){
		Graphics2D g2 = (Graphics2D)g;
		
		for(int i = 0 ; i < 8 ; i++){
				g2.setColor(Color.BLUE);
				g2.drawLine(40 + 40*i, 40, 360 - 40*i, 360);
				g2.drawLine(40, 360-40*i, 360, 40+40*i);			
				g2.setColor(Color.RED);
				g2.drawLine(40, 340-40*i, 360, 60+40*i);
				g2.drawLine(60 + 40*i,40,340-40*i,360);

		}
	}
}
