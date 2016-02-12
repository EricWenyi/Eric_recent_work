import edu.princeton.cs.algs4.*;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {
	private boolean[] open;
	private static int  n;
	private WeightedQuickUnionUF uf;
	
	private int mapto1D(int i, int j){
		if(i  == 0) i++;
		if(i == n+1) i--;
		if(j == 0) j++;
		if(j == n+1) j--;
		int num = (i - 1) * n + j - 1;
		return num;
	}
	
	private void valid(int i, int j){
		if(i > n || j > n || i < 1 || j < 1)
			throw new java.lang.IndexOutOfBoundsException("row index i out of bounds");
	}
	
	public Percolation(int N){// create N-by-N grid, with all sites blocked
		
		if (N < 0) throw new IllegalArgumentException("row index i out of bounds");
		open = new boolean[N*N + 2];
		for(int i = 0; i < N*N + 2; i++){//initialize open[]
			open[i] = false;
		}
		//open[n*n] = true;
		//open[n*n+1] = true;
		n = N;//initialize n
		uf = new WeightedQuickUnionUF(N*N + 2);//initialize uf
		
		for(int i= 0; i< N; i++){//initialize the virtual site
			uf.union(n*n,i);
			uf.union(n*n+1 , n*n - n + i );
		}	
	}
	
	public void open(int i, int j){// open site (row i, column j) if it is not open already
		valid(i,j);
		int num = mapto1D(i,j);
		if(isOpen(i,j))
			return;
		else{
			open[num] = true;
			int check1 = mapto1D(i - 1,j);
			int check2 = mapto1D(i + 1,j);
			int check3 = mapto1D(i ,j - 1);
			int check4 = mapto1D(i ,j + 1); 
			if(open[check1]) uf.union(check1,num);
			if(open[check2]) uf.union(check2,num);
			if(open[check3]) uf.union(check3,num);
			if(open[check4]) uf.union(check4,num);
		}
		//StdOut.println("THe point(" + i + "," + j + ") has opened");
		
	}
	
	public boolean isOpen(int i, int j){ // is site (row i, column j) open?
		valid(i,j);
		int num = mapto1D(i,j);
		if(open[num])
			return true;
		else
			return false;
	}
	
	public boolean isFull(int i, int j){// is site (row i, column j) full?
		valid(i,j);
		
		int num = mapto1D(i,j);
		if(uf.connected(n*n,num)){
			//StdOut.println("This site is full");
			return true;
		}
		else
			return false;
	}
	
	public boolean percolates(){// does the system percolate?
		if(uf.connected(n*n, n*n+1))
			return true;
		else 
			return false;

			
	}

	public static void main(String[] args){ // test client (optional)
		int N = StdIn.readInt();
		Percolation pe = new Percolation(N);
		//StdOut.println(pe.n);
		while(!StdIn.isEmpty()){
			int i = StdIn.readInt();
			int j = StdIn.readInt();
			//StdOut.println(i + "  " + j);
			pe.open(i,j);
			//pe.isFull(i, j);
		}
		//int f1 = pe.uf.find(N*N);
		//int f2 = pe.uf.find(N*N + 1);
		//StdOut.println(f1 + "  " + f2);
		if(pe.percolates())
			StdOut.println("The system percolates");
		else
			StdOut.println("The system fail to percolate");
		
	}

}
