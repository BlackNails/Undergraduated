/*Julio Silva Leon*/
import x10.io.Console;

public class Fibonacci(input:Long) {
	
	var output:Long;
	
	def this(input:Long){
		property(input);
	}
	def fib(n:Long){
		if(n <= 2) return 1;
		val f1:Long;
		val f2:Long;
		f1 = fib(n - 1);
		f2 = fib(n - 2);
		//Console.OUT.println(f1+f2);
		return f1 + f2;
	}
	
	public static def main(args:Rail[String]){
		val fib10 = new Fibonacci(10);
		var i:Long;
		i = 1;
		finish{
			async{
		while(i <= fib10.input){
				Console.OUT.println("fib(" + i +")"
					+"="+fib10.fib(i));
		i = i + 1;}
				}
		}
		
	}
}
