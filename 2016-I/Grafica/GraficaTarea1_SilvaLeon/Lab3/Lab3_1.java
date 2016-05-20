import javax.swing.*;
import java.awt.*;

public class Lab3_1 extends JApplet{
	
	public void init(){
		setSize(400,400);
	}
	
	public void paint(Graphics g){
		
		for(int i = 0 ; i < 4 ; i++)
			if(i%2 == 0){
				g.setColor(Color.GREEN);
				g.fillArc(50, 50, 200, 150, 90*i, 90);
			}
			else{
				g.setColor(Color.RED);
				g.fillArc(50, 50, 200, 150, 90*i, 90);
			}
		}		
}
