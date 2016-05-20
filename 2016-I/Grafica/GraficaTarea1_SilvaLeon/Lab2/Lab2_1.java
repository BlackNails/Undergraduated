import javax.swing.*;
import java.awt.*;

public class Lab2_1 extends JApplet{
	public void init(){
		setSize(400,400);
	}
	
	public void paint(Graphics g){
		Graphics2D g2 = (Graphics2D)g;
		
		for(int i = 0 ; i < 8 ; i++){
				g2.setColor(Color.BLUE);
				g2.drawLine(40 + 20*i, 40, 360 - 20*i, 360);
				g2.drawLine(40, 360-20*i, 360, 40+20*i);			
				g2.setColor(Color.RED);
				g2.drawLine(200 + 20*i, 40, 200-20*i, 360);
				g2.drawLine(40,200-20*i,360,200+20*i);

		}
	}
}
