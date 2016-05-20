import javax.swing.*;
import java.awt.*;

public class P2 extends JApplet{
	
	
	public void init(){
	
		setSize(400,400);
	}
	
		
		public void paint(Graphics g){
			int xc = 200 , yc = 200,r=200;
			double[] a = {0.8*Math.PI,0.6*Math.PI,0.4*Math.PI,0.2*Math.PI};
			double[] ang = new double[4];
			ang[0]= a[0];
			for(int i = 1 ; i < 4 ; i++)
				ang[i] = a[i-1]+a[i];
			//super.paint(g);
			g.setColor(Color.ORANGE);
			circunferencia(g,xc, yc, r);
			g.drawLine(200,200,200,0);
			
			linea(g,xc,yc,xc - (int)Math.round((r*Math.cos(ang[0]-Math.PI/2.0)))
			,yc + (int)Math.round((r*Math.sin(ang[0]-Math.PI/2.0))));
			
			linea(g,xc,yc,xc + (int)Math.round((r*Math.cos(3*Math.PI/2-ang[1])))
			,yc + (int)Math.round((r*Math.sin(3*Math.PI/2-ang[1]))));  
			     
			linea(g,xc,yc,xc + (int)Math.round((r*1.0*Math.cos(a[3])))
			,yc - (int)Math.round((r*1.0*Math.sin(a[3])))); 
			
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
		
		public void linea(Graphics g,int x1 , int y1 , int x2 , int y2){
			int dx = x2 - x1 ;
			int dy = y2 - y1 ;
			int p = 2*(dy) - (dx);
			int j=1;
			int d = Math.abs(x2 - x1);
			float m = (float) dy / (float) dx;

			
			if(m > 0){// lineas de este tipo en 2 sentidos \\
				if(dx < 0)// linea \ de derecha a izquierda
					for(int i = 0 ; i < d ; i++){
						p = p + (2*dy) -((2*dx)*j) ;
						if(p < 0){
							g.drawLine(x1, y1, x1-1, y1-1);
							x1 = x1 - 1;
							y1 = y1 - 1;
							j = 1;
						}
						else{
							g.drawLine(x1, y1, x1 - 1, y1);
							x1 = x1 - 1;
							j=0;
						}
					}
					
				else // linea \ de izquierda a derecha
					for(int i = 0 ; i < d ; i++){
						
						p = p + (2*dy) -((2*dx)*j) ;
						if(p > 0){
							g.drawLine(x1, y1, x1+1, y1+1);
							x1 = x1 + 1;
							y1 = y1 + 1;
							j = 1;
						}
						else{
							g.drawLine(x1, y1, x1 + 1, y1);
							x1 = x1 + 1;
							j=0;
						}
					}
				
			}
			
			else// lineas de este tipo en 2 sentidos//
				if(dx > 0)// linea / de izquierda a derecha
					for(int i = 0 ; i < d ; i++){
						p = p + (2*dy) -((2*dx)*j) ;
						if(p < 0){
							g.drawLine(x1, y1, x1-1, y1+1);
							x1 = x1 + 1;
							y1 = y1 - 1;
							j = 1;
						}
						else{
							g.drawLine(x1, y1, x1 - 1, y1);
							x1 = x1 + 1;
							j=0;
						}
					}
					
				else// linea / de derecha a izquieda
					for(int i = 0 ; i < d ; i++){
						
						p = p + (2*dy) -((2*dx)*j) ;
						if(p > 0){
							g.drawLine(x1, y1, x1+1, y1-1);
							x1 = x1 - 1;
							y1 = y1 + 1;
							j = 1;
						}
						else{
							g.drawLine(x1, y1, x1 + 1, y1);
							x1 = x1 - 1;
							j=0;
						}
			}				
			
		}
		
		
	//}
	
}
