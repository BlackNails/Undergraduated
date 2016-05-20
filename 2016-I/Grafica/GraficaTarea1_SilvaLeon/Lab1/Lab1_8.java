import javax.swing.*;
import java.awt.*;
import java.awt.geom.GeneralPath;

public class Lab1_8 extends JApplet{
	public void init(){
		setSize(400,400);
	}
	
	public void paint(Graphics g){
		Graphics2D g2 = (Graphics2D)g;
		
		GeneralPath p;
		p = new GeneralPath();
		
		p.moveTo(40, 280);
		p.lineTo(160, 40);
		p.lineTo(280, 280);
		p.lineTo(160,280);
		p.lineTo(100, 160);
		p.lineTo(220, 160);
		p.lineTo(160, 280);
		p.closePath();
		
		g2.draw(p);
		
		
	}
}
