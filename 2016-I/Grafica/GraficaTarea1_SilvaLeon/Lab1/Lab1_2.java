import javax.swing.*;
import java.awt.*;

public class Lab1_2 extends JApplet{

	public void init(){
		
		setSize(400,400);
	
	}
	
	public void paint(Graphics g){
		
		Graphics2D g2 = (Graphics2D) g;		
		
		for(int i = 0 ; i < 10 ; i++){
			g2.setColor(Color.ORANGE);
			g2.drawLine(20 + i*25, 20, 170 + i*25, 200);
			g2.setColor(Color.CYAN);
			g2.drawLine(20 + i*25, 200, 170 + i*25 , 20);
		}
	}
}
