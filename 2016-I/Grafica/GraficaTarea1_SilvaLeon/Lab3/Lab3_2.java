import javax.swing.*;
import java.awt.*;

public class Lab3_2 extends JApplet{
	public void init(){
		setSize(400,400);
	}
	
	public void paint(Graphics g){
		for(int i = 0 ; i < 9 ; i++){
			g.setColor(Color.RED);
			g.fillOval(20+20*i, 20+20*i,360-40*i, 360-40*i);
			g.setColor(Color.BLUE);
			g.fillRect(40+20*i,40+20*i,320-40*i,320-40*i);
		}	
	}

}
