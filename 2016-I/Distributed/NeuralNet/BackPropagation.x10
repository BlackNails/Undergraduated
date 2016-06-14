import x10.array.*;
import x10.util.Random;
import x10.io.File;

public class BackPropagation{
	
	public static def f(n:Double){
		val e:Double = 2.7182;
		var d1:Double = Math.pow(e,n);
		var d2:Double = Math.pow(e,-n);
		
		return (d1 - d2) / (d1 + d2); 
	}

	public static def main(args:Rail[String]){
		
		val w1 = new Array_1[Double](2);
		val b1 = new Array_1[Double](2);
		val w2 = new Array_1[Double](2);
		var b2:Double;
		val a1 = new Array_1[Double](2);
		var a2:Double;
		val p2 = new Array_1[Double](2);
		var p1:Double;
		var eu:Double = 1; val eo = new Array_1[Double](2);
		var alpha:Double = 0.1;
		val t = new Array_1[Double](6);
		val p = new Array_1[Double](6);
		p(0)=-2;p(1)=-1.2;p(2)=-0.4;p(3)=0.4;p(4)=1.2;p(5)=2;
		t(0)=-1;t(1)=-0.81;t(2)=-0.31;t(3)=0.309;t(4)=0.809;t(5)=1;
		w1(0) = -0.2; w1(1) = 0.5;
		w2(0) = 0.1; w2(1) = 0.3;
		b1(0) = 0.7; b1(1) = -0.2;
		b2    = 0.8; 
		//p1    = -2;
		//p2(0) = 0.8; p2(1) = -0.83;
		
		for(var j:Long = 0 ; j < 30 ; j++)	
			for(var i:Long = 0 ; i < 6 ; i++){
				
				while(eu > 0.00001){
				/*Primera capa*/
				a1(0) = w1(0)*p(i) + b1(0);
				a1(1) = w1(1)*p(i) + b1(1);
				
				// funcion tangh
				a1(0) = f(a1(0));
				a1(1) = f(a1(1));
				
				// Con la identidad
				a2 = w2(0)*a1(0) + w2(1)*a1(1) + b2;
				//Console.OUT.println(a2);
				//a2 = f(a2);
				
				Console.OUT.println("Primera capa a1 : " + a1(0) + " " + a1(1) + 
						" a2: " +a2 );

				
				/*Error Ultima capa*/
				eu = -2*(t(i) - a2);
				/*Error Capa oculta*/
				eo(0) = (1 - a1(0)*a1(0))*w2(0)*eu;
				eo(1) = (1 - a1(1)*a1(1))*w2(1)*eu;
				//eo = eo * eu;
				
				Console.OUT.println("Error Ultima capa: " + eu);
				//Console.OUT.println("Capa oculta: "+ eo);
				
				/*Actualizando los w*/
				w2(0) = w2(0) - alpha*eu*a1(0);
				w2(1) = w2(1) - alpha*eu*a1(1);
				
				b2 = b2 - alpha*eu;
				
				w1(0) = w1(0) - alpha*eo(0)*p(i);
				w1(1) = w1(1) - alpha*eo(1)*p(i);
				
				b1(0) = b1(0) - alpha*eo(0);
				b1(1) = b1(1) - alpha*eo(1);
				
				a1(0) = w1(0)*p(i) + b1(0);
				a1(1) = w1(1)*p(i) + b1(1);
				a1(0) = f(a1(0));
				a1(1) = f(a1(1));
				
				a2 = w2(0)*a1(0) + w2(1)*a1(1) + b2;

			}
			eu = 1;
			
		}
			
			
		Console.OUT.println("w1 : " + w1);
		Console.OUT.println("w2 : " + w2);
		Console.OUT.println("b1 : " + b1);
		Console.OUT.println("b2 : " + b2);
			
	}
}
