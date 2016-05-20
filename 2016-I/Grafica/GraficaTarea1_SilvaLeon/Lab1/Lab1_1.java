import javax.swing.*;
import java.awt.*;

public class Lab1_1 extends JApplet{
	public void init(){
		setSize(400,400);
	}
	
	public void paint(Graphics g){
		Graphics2D g2 = (Graphics2D) g;
		g2.setColor(Color.ORANGE);
		for(int i = 0 ; i < 10 ; i++)
			g2.drawLine(20	+ i*25, 20, 50 + i*25, 200);
		
	}
}
