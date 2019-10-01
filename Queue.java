import java.util.Scanner;
class Node {
    int val;
    Node next;
  
    Node(int x) {
        val = x;
        next = null;
    }
}

class Queue {
    Node first, last;
  
    public void enqueue(Node n) {
        if(first == null) {
            first = n;
            last = first;
        }
        else {
            last.next = n;
            last = n;
        }
    }
  
    public Node dequeue() {
        if(first == null) {
            return null;
        }
        else {
            Node temp = new Node(first.val);
            first = first.next;
            return temp;
        }   
    }

    public void traverse() {
    		Node n=first;
    	if(first == last && first == null) {
    		System.out.println("Empty Queue");
    	}
    	else if(first == last) {
    		System.out.println(first.val);
    	}
    	else {
    		while(n!=null) {
    			System.out.print(n.val + "->");
    			n=n.next;
    		}
    	}
    }
}

class queue_main {
	public static void main(String[] args) {
		Queue que =new Queue();
		Scanner sc = new Scanner(System.in);
		int ch, data;
		char ch1='Y';
		while(ch1 =='Y' || ch1 == 'y') {
			System.out.println("Menu\n1.Enqueue\n2.Dequeue\n3.Traversal");
			ch = sc.nextInt();
			switch(ch) {
				case 1:
					System.out.println("Enter the data you want to insert");
					data = sc.nextInt();
					que.enqueue(new Node(data));
					break;

				case 2:
					que.dequeue();
					break;

				case 3:
					System.out.println("The queue is");
					que.traverse();
					break;

				default:
					System.out.println("Enter the a correct value");
					break;
			}
			System.out.println("Do you wish to continue");
			ch1=sc.next().charAt(0);
		}
	}
}
