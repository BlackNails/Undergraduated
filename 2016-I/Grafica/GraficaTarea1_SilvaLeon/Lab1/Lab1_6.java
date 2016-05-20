import javax.swing.*;
import java.awt.*;
import java.awt.geom.GeneralPath;

public class Lab1_6 extends JApplet{
		
	public void init(){
		setSize(400,400);
	}

	public void rombo(Graphics2D g , int x1 , int y1 , int width ){
		
		GeneralPath p;
		p = new GeneralPath();
		
		p.moveTo(x1, y1 + width/2);
		p.lineTo(x1 + width/2, y1);
		p.lineTo(x1 + width, y1 + width/2);
		p.lineTo(x1 + width/2, y1 + width);
		p.closePath();
		g.setColor(Color.RED);
		g.draw(p);
	}
	
	public void paint(Graphics g){
		
		Graphics2D g2 = (Graphics2D) g;
		
		for(int i = 0 ; i < 4 ; i++){
			g2.setColor(Color.CYAN);
			g2.drawRect(180 - 40*i, 180 - 40*i, 20 + 80*i, 20 + 80*i);
			rombo(g2,180-40*i,180-40*i,20+80*i);
		}
		
	}
	
}
