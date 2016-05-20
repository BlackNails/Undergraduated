import javax.swing.*;
import java.awt.*;

public class Lab1_4 extends JApplet{
	
	public void init(){
		setSize(400,400);
	}
	
	public void paint(Graphics g){
		
		Graphics2D g2 = (Graphics2D) g;
				
		for(int i = 0 ; i < 31 ; i++){
		
		g2.setColor(Color.RED);
			if( i < 16)
				g2.drawLine(50, 50, 50 + 20*i, 350);
			else
				g2.drawLine(50, 50, 350, 50 + 20*(i-16));
		
		g2.setColor(Color.CYAN);
			if(i < 16)
				g2.drawLine(350, 350, 50,350 - 20*i);
			else
				g2.drawLine(350, 350, 50+(20*(i-16)), 50);
		}
	}
}
