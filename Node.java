// Jason Zhao - November 2, 2015
// Traverse a tree in a zig-zag.  So in a full binary tree with nodes numbered 
// in ascending order from left to right, top to bottom, a zig-zag traversal
// would be 0 2 1 3 4 5 6 14 13 12...

import java.util.*;

public class Node{
	public int value;
	public int level;

	public Node(int val, int lev){
		value = val;
		level = lev;
	}

	public static String flipflopTraversal(List<Node> arr){
		String str = "";
		boolean right = true;
		int level = 0;
		int i = 0;
		while(arr.size() != 0){
			if(right){
				while(i < arr.size()){
					if(level == arr.get(i).level){
						str += arr.get(i).value + " ";
						arr.remove(i);
					}
					else{
						i++;
					}
				}

				right = false;
				level++;
			}
			else{
				i--;
				while(i >= 0){
					if(level == arr.get(i).level){
						str += arr.get(i).value + " ";
						arr.remove(i);
					}
					
					i--;
				}

				right = true;
				level++;
				i++;
			}
		}

		str = str.substring(0, str.length() - 1);
		return str;
	}

	/**
	 *	Input a inorder traversed tree with corresponding node depths
	 *	Output a zig-zag traversal of that tree
	 *	
	 *	Try this input: 4 2,8 3,2 1,9 3,5 2,10 3,1 0,6 2,7 3,3 1
	 *	Output should be: 1 3 2 4 5 6 7 10 9 8
	 */
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		System.out.print("Inorder traversal of tree (<value> <level>,<value> <level>,...): ");
		String str = in.nextLine();

		List<Node> arr = new ArrayList<Node>();
		String[] nodes = str.split(",");
		for(int i = 0; i < nodes.length; i++){
			String[] data = nodes[i].split(" ");
			arr.add(new Node(Integer.parseInt(data[0]), Integer.parseInt(data[1])));
		}

		// Begin traversal algorithm
		System.out.println(flipflopTraversal(arr));
	}
}
