import javax.swing.*;
import java.awt.*;

public class Bresenham extends JApplet{
	
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
			
			g.setColor(Color.BLACK);// \ de izq a derecha
			linea(g,100,30,250,180);
			g.setColor(Color.BLUE);// \ de derecha a izq
			linea(g,270,180,120,30);
			
			g.setColor(Color.GREEN);
			linea(g,100,180,250,30);// / de izq a derecha 
			g.setColor(Color.ORANGE);
			linea(g,270, 30, 120, 180);// / de derecha a izq
			
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
		
		
	}
	
}