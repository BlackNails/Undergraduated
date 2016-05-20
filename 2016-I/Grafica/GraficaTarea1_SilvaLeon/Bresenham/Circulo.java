import javax.swing.*;
import java.awt.*;

public class Circulo extends JApplet{
	
	Board b;
	
	public void init(){
	
		Container c = this.getContentPane();
		c.setLayout(null);
		c.setBackground(Color.BLACK);
		b = new Board();
		b.setBounds(50,50,500,500);
		c.add(b);
		setSize(600,600);
	}
	
	class Board extends Canvas{
		
		Board(){
			setBackground(Color.WHITE);
			setSize(500,500);
		}
		
		public void paint(Graphics g){
			super.paint(g);
			g.setColor(Color.ORANGE);
			circunferencia(g,200, 200, 100);
			
		}
		
		public void drawPoints(Graphics g ,int xc,int yc,int x,int y){
			g.drawRect(xc+x, yc+y, 1, 1);
			g.drawRect(xc-x, yc+y, 1, 1);
			g.drawRect(xc+x, yc-y, 1, 1);
			g.drawRect(xc-x, yc-y, 1, 1);
			g.drawRect(xc+y, yc+x, 1, 1);
			g.drawRect(xc-y, yc+x, 1, 1);
			g.drawRect(xc+y, yc-x, 1, 1);
			g.drawRect(xc-y, yc-x, 1, 1);

		}
		//circuenferencia de centro xc yc y radio r
		public void circunferencia(Graphics g,int xc , int yc , int r){
			int x = 0;
			int y = r;
			
			int p = 3 - 2*r;
						
			while(x < y){
				drawPoints(g,xc,yc,x,y);
				if(p < 0)
					p = p + 4*x + 6;
				else{
					p = p + 4*(x-y)+10;
					y = y - 1;
				}
				x = x + 1;
			}
			if(x == y)
				drawPoints(g,xc,yc,x,y);
			
		}
		
		
	}
	
}