import javax.swing.*;
import java.awt.*;
import java.awt.geom.GeneralPath;

public class Lab3_3 extends JApplet{
	public void init(){
		setSize(400,400);
	}
	
	public void paint(Graphics g){
		int x1 = this.getWidth();
		int y1 = this.getHeight();
		
		Graphics2D g2 = (Graphics2D)g;
		drawSomething(g2,x1/2,y1/2);
		
	}
	public void drawSomething(Graphics2D g,int x1 , int y1){
		GeneralPath p = new GeneralPath();
		GeneralPath p2 = new GeneralPath();
		int base = 180;
		Color[] colors = new Color[3];
		colors[1] = new Color(255,60,50);
		colors[0] = new Color(255,255,0);
		colors[2] = new Color(100,255,10);
		
		for(int i = 8, j = 0 ; i >=0 ; i--,j++){
			g.setColor(colors[j%3]);
			p.moveTo(x1, y1);
			
			p.lineTo(x1-10*i, y1-base/2);
			p.lineTo(x1-10*i, y1 + base/2);
			p.closePath();
			g.fill(p);
			p.reset();

			p.moveTo(x1, y1);
			p.lineTo(x1+10*i, y1-base/2);
			p.lineTo(x1+10*i, y1 + base/2);
			p.closePath();
			g.fill(p);
			p.reset();
			
			
			//g.draw(p);
		}
	}
}
