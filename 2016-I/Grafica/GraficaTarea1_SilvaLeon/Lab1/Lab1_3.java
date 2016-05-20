import javax.swing.*;
import java.awt.*;

public class Lab1_3 extends JApplet{
	
	public void init(){
		setSize(400,400);
	}
	
	public void paint(Graphics g){
		
		Graphics2D g2 = (Graphics2D) g;
		g2.setColor(Color.RED);
		
		for(int i = 0 ; i < 31 ; i++)
			if( i < 16)
				g2.drawLine(50, 50, 50 + 20*i, 350);
			else
				g2.drawLine(50, 50, 350, 50 + 20*(i-16));
	}
}
