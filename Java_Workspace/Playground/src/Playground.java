
public class Playground {
	public static void main(){
		int[][] p = new int[2][2];
		markship(p, 5);
		System.out.println(p[0][0]);
	}
	
	private static void markship(int [][] p, int N){
		p[0][0] = N;
	}
	
	
}
