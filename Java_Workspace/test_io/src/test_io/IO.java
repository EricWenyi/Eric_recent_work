package test_io;

import java.util.Scanner;
public class IO{
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		System.out.println("Please enter a number: ");
		char array[] = new char[3];
		for(int i = 0; i<3; i++){
			char a = scanner.next("").charAt(0);
			array[i] = a;
		}
		
		
		System.out.println("The number you have entered is composed of "+array[0]+" and " +array[2]);
	}
}