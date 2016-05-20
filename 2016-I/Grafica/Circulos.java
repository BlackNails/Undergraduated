import javax.swing.*;
import java.awt.*;

public class Circulos extends JApplet{
	int w = this.getWidth();
	int h = this.getHeight();
	int dec = w/20;
	public void init(){
		setSize(400,400);
	}
	
	public void paint(Graphics g){
		
		for(int i = 0 ; i < 5 ; i++){
			//Negros
			g.setColor(Color.BLACK);
			for(int j = 0 ; j < 12 ; j++){
				g.fillArc(dec*(2*i),dec*(2*i),180 -dec*(2*i),
						180-dec*(2*i),90+30*j, 15);
				g.fillArc(dec*(2*i), dec*(2*i),180 -dec*(2*i),
						180-dec*(2*i),270+30*j, 15);
			}
			g.setColor(Color.CYAN);
			for(int j = 0 ; j < 12 ; j++){
				
				g.fillArc(dec*(2*i),dec*(2*i),180 -dec*(2*i),
						180-dec*(2*i),105+30*j, 15);
				g.fillArc(dec*(2*i),dec*(2*i),180 -dec*(2*i),
						180-dec*(2*i),285+30*j, 15);
			}
			/*g.setColor(Color.YELLOW);
			g.fillOval(20,20,160-dec*(2*i),160-dec*(2*i));*/
		
			
		}
	}

}
