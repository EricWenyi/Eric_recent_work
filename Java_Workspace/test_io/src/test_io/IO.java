package test_io;

import java.util.Scanner;
public class IO{
	public static void main(String[] args){
		/*Scanner scanner = new Scanner(System.in);
		System.out.println("Please enter a number: ");
		char array[] = new char[3];
		for(int i = 0; i<3; i++){
			char a = scanner.next("").charAt(0);
			array[i] = a;
		}*/
		
		int N = 5;
		String s = "";
		for (int n = N; n > 0; n/=2)
			s = (n % 2) + s; 
		
		
		
		System.out.println(s);
	}
}