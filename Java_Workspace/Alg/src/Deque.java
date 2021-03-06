import java.util.*;
import edu.princeton.cs.algs4.*;
public class Deque<Item> implements Iterable<Item>{
	private Node first;
	private Node last;
	private Node sentinel_first;
	private Node sentinel_last;
	private int N;
	
	private class Node{
		Item item;
		Node next;
		Node pre;
	}
	
	
	public Deque(){
		sentinel_first = new Node();
		sentinel_last = new Node();
		sentinel_first.next = sentinel_last;
		sentinel_first.pre = null;
		sentinel_last.next = null;
		sentinel_last.pre = sentinel_first;
		
		first = sentinel_first;
		last = sentinel_last;
		
		N = 0;
		
		assert check();
	}
	
	 // check internal invariants
    private boolean check() {

        // check a few properties of instance variable 'first'
        if (N < 0) {
            return false;
        }
        if (N == 0 ) {
            if (first.next != sentinel_last) return false;
            if (last.pre != sentinel_first) return false;
        }
        else if (N == 1) {
        	if (first.pre != sentinel_first) return false;
            if (last.next != sentinel_last) return false;
        }
        else {
            if (first == null)      return false;
            
        }

        // check internal consistency of instance variable N
        int numberOfNodes = 0;
        for (Node x = first; x != sentinel_last; x = x.next) {
            numberOfNodes++;
        }
        if (numberOfNodes != N) return false;

        return true; 
    }
	
	public boolean isEmpty(){
		return sentinel_first.next == sentinel_last;
	}
	
	public int size() {
		return N;
	}                       // return the number of items on the deque
	 
	public void addFirst(Item item){
		if(item == null) throw new java.lang.NullPointerException("Item is null");
		Node oldfirst = first.next;
		first = new Node();
		first.item = item;
		first.next = oldfirst;
		first.pre = sentinel_first;
		sentinel_first.next = first;
		oldfirst.pre = first;
		first = sentinel_first;
		N++;
		
		assert check();
	}          // add the item to the front
	
	public void addLast(Item item){
		if(item == null) throw new java.lang.NullPointerException("Item is null");
		Node oldlast = sentinel_last.pre;
		last = new Node();
		last.item = item;
		last.next = sentinel_last;
		last.pre = oldlast;
		sentinel_last.pre = last;
		oldlast.next = last;
		last = sentinel_last;
		N++;
		assert check();
	}           // add the item to the end
	
	public Item removeFirst(){
		if (isEmpty()) throw new NoSuchElementException("Stack underflow");
		if(first == last)
			last = sentinel_last;
		first = first.next;
		Node newfirst = first.next;
		Item item = first.item;
		sentinel_first.next = newfirst;
		newfirst.pre = sentinel_first;
		first.next = null;
		first.pre = null;
		first = sentinel_first;
		N--;
		return item;
	}//remove and return the item from the first
		
	public Item removeLast(){
		if (isEmpty()) throw new NoSuchElementException("Stack underflow");
		if(first == last)
			first = sentinel_first;
		last = last.pre;
		Node newlast = last.pre;
		Item item = last.item;
		sentinel_last.pre = newlast;
		newlast.next = sentinel_last;
		last.next = null;
		last.pre = null;
		last = sentinel_last;
		N--;
		return item;
	}                 // remove and return the item from the end
	
	public Iterator<Item> iterator(){
		return new ListIterator();
	}         // return an iterator over items in order from front to end
	
	private class ListIterator implements Iterator<Item>{
		private Node current = first.next;
		public boolean hasNext(){ return current.next != null;}
		public void remove() {throw new UnsupportedOperationException();}
		
		public Item next() {
            if (!hasNext()) throw new NoSuchElementException();
            Item item = current.item;
            current = current.next; 
            return item;
        }
	}
	
	public static void main(String[] args){
		Deque<String> deque = new Deque<String>();
		while(!StdIn.isEmpty()){
			String item = StdIn.readString();
			if(!item.equals("+") && !item.equals("-") && !item.equals("*") && !item.equals("/")) 
				deque.addFirst(item);
			else if(item.equals("+"))
				deque.addLast("+");
			else if(item.equals("-"))
				StdOut.println(deque.removeFirst());
			else if(item.equals("*"))
				StdOut.println(deque.removeLast());
		}
		//Iterator<String> i = deque.iterator();
		
		for(String s:deque){
			StdOut.println(s);
		}
		//StdOut.print(deque.first.next.item);
		//StdOut.print(deque.size());
	}   // unit testing
}
