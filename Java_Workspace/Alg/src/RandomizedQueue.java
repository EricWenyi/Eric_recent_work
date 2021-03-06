import java.util.*;
import edu.princeton.cs.algs4.*;

public class RandomizedQueue<Item> implements Iterable<Item> {
	private Node first;
	private Node last;
	private Node randompre;
	private int N;

	private class Node {
		Item item;
		Node next;
	}

	public RandomizedQueue() {
		first = null;
		last = null;
		randompre = null;
		N = 0;
	}
	// construct an empty randomized queue

	public boolean isEmpty() {
		return first == null;
	}
	// is the queue empty?

	public int size() {
		return N;
	}
	// return the number of items on the queue

	public void enqueue(Item item) {
		if(item == null) throw new java.lang.NullPointerException("The item inserted is null");
		Node oldlast = last;
		last = new Node();
		last.item = item;
		last.next = null;
		if (isEmpty())
			first = last;
		else
			oldlast.next = last;
		N++;
	}
	// add the item

	public Item dequeue() {
		
		randompre = first;
		int ran;
		Item item;
		
		if(isEmpty())
			throw new java.util.NoSuchElementException("The queue is empty");
		
		ran = StdRandom.uniform(N);
		if(ran == 0){
			item = first.item;
			first = first.next;
			if(isEmpty())
				last = null;
			N--;
			return item;
		}
		else{
			for(int i = 0; i< ran - 1; i++){
				randompre = randompre.next;
			}
			item = randompre.next.item;
			
			if(randompre.next == last)
				last = randompre;
			
			randompre.next = randompre.next.next;
			N--;
			return item;
		}
		
		
		
	}
	// remove and return a random item

	public Item sample() {
		randompre = first;
		int ran;
		Item item;
		
		if(isEmpty())
			throw new java.util.NoSuchElementException("The queue is empty");
		
		ran = StdRandom.uniform(N);
		if(ran == 0)
			return first.item;
		else{
			for(int i = 0; i < ran - 1; i++){
				randompre = randompre.next;
			}
			item = randompre.next.item;
			return item;
		}
	}
	// return (but do not remove) a random item

	public Iterator<Item> iterator() {
		return new QueueIterator();
	}
	
	private class QueueIterator implements Iterator<Item>{
		private Node current = first;
		public boolean hasNext(){ return current != null;}
		public void remove() {throw new UnsupportedOperationException();}
		
		public Item next() {
            if (!hasNext()) throw new NoSuchElementException();
            Item item = current.item;
            current = current.next; 
            return item;
        }
	} 
	// return an independent iterator over items in random order

	public static void main(String[] args) {
		RandomizedQueue<String> queue = new RandomizedQueue<String>();
		while(!StdIn.isEmpty()){
			String item = StdIn.readString();
			if(!item.equals("*"))
				queue.enqueue(item);
			else{
				StdOut.println(queue.sample());
				StdOut.println(queue.N);
			}
		}
//		for(String s:queue){
//			StdOut.println(s);
//		}
		StdOut.println(queue.N);
	}
	// unit testing

}