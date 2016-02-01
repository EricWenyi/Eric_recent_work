package test_io;

import edu.princeton.cs.algs4.*;

public class IntegerToBinary {
	public static void main(String[] args){
		StdOut.print("Please enter an integer: ");
		int n = StdIn.readInt();
		String s = "";
		for (int N = n; n > 0; n /= 2){
			s = (n % 2) + s;
		}
		
		StdOut.print(s);
	}
}
