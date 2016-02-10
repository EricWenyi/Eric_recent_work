package test_io;

import edu.princeton.cs.algs4.StdOut;

public class exe1_2_7 {
	public static String mystery(String s){
		int N = s.length();
		if(N<=1) return s;
		String a = s.substring(0, N/2);
		String b = s.substring(N/2, N);
		return mystery(a) + mystery(b);
	}
	
	public static void main(String[] args){
		String s = "that is amazing";
		String test = mystery(s);
		StdOut.println(test);
	}
}
