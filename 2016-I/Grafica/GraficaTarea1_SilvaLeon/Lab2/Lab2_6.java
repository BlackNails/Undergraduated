import javax.swing.*;
import java.awt.*;

public class Lab2_6 extends JApplet{
	public void init(){
		setSize(400,400);
	}
	
	public void paint(Graphics g){
		Graphics2D g2 = (Graphics2D)g;
		g2.setColor(Color.BLUE);
		int x1 = this.getWidth();
		int y1 = this.getHeight();
		g2.drawOval(x1/4, y1/4,x1/2 , x1/2);
		g2.drawArc(0, 0, x1/2, x1/2, 270, 90);
		g2.drawArc(x1/2, 0, x1/2, x1/2, 180, 90);
		g2.drawArc(0, y1/2, x1/2, x1/2, 0, 90);
		g2.drawArc(x1/2, y1/2, x1/2, x1/2, 90, 90);
	}
}
