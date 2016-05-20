import javax.swing.*;
import java.awt.*;
import java.awt.geom.GeneralPath;

public class Lab1_7 extends JApplet{
	public void init(){
		setSize(400,400);
	}
	
	public void paint(Graphics g){
		Graphics2D g2 = (Graphics2D)g;
		
		GeneralPath p;
		p = new GeneralPath();
		
		p.moveTo(50, 50);
		p.lineTo(250, 250);
		p.lineTo(250, 50);
		p.lineTo(50,250);
		p.closePath();
		
		g2.draw(p);
		
		
	}
}
