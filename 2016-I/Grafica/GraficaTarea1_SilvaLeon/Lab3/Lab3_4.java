import javax.swing.*;
import java.awt.*;
import java.awt.geom.GeneralPath;

public class Lab3_4 extends JApplet{
	public void init(){
		setSize(400,400);
	}
	
	public void paint(Graphics g){
		
		Graphics2D g2 = (Graphics2D)g;
		drawStar(g2,200,200,150);
		
	}
	public void drawStar(Graphics2D g,int x1 , int y1 , int r){
		GeneralPath p = new GeneralPath();
		Color[] colors = new Color[3];
		colors[0] = new Color(154,255,50);
		colors[1] = new Color(255,60,0);
		colors[2] = new Color(255,255,10);
		for(int i = 0 ; i < 3 ; i++){
			g.setColor(colors[i]);
			p.moveTo(x1, y1 -(r-50*i));
			
			p.lineTo(x1 - ((r-50*i)*Math.sin(2*Math.PI/10))
					, y1 + (r-50*i)*Math.cos(2*Math.PI/10));
			
			p.lineTo(x1 + (r-50*i)*Math.sin(2*Math.PI/5)
					, y1 - (r-50*i)*Math.cos(2*Math.PI/5) );
			
			p.lineTo(x1 - (r-50*i)*Math.sin(2*Math.PI/5)
					, y1 - (r-50*i)*Math.cos(2*Math.PI/5) );
			
			p.lineTo(x1 + (r-50*i)*Math.sin(2*Math.PI/10)
					, y1 + (r-50*i)*Math.cos(2*Math.PI/10));
			p.closePath();
			g.fill(p);
			p.reset();
			//g.draw(p);
		}
	}
}
