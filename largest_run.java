import java.util.*;

public class largest_run{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		// Try: 1 -1 -12 -9 2 98 -45 2 9 2 0 0 -24 7 6 2 99 -99 99 12 -42 4 18 6 -1 -200 150
		System.out.print("Enter space deliniated run: ");
		String[] temp = in.nextLine().split(" ");

		int[] arr = new int[temp.length];
		for(int i = 0; i < arr.length; i++){
			arr[i] = Integer.parseInt(temp[i]);
		}

		System.out.println("sum=" + sum(arr, 0, arr.length));

		int[] soln = getLargestRun(arr, 0, arr.length);
		System.out.println("start=" + soln[0] + "   end=" + soln[1]);

		for(int i = soln[0]; i < soln[1]; i++){
			System.out.print(arr[i] + " ");
		}

		System.out.println();
		System.out.println("sum=" + sum(arr, soln[0], soln[1]));
	}

	private static int[] getLargestRun(int[] arr, int begin, int end){
		int sum = sum(arr, begin, end);
		int pivot = findMinIndex(arr, begin, end);

		// TODO: Don't return immediately, keep recursion going til -1 is hit.
		//       Then compare values from getLargestRun, return largest value.
		//       Bubble up until largest value reachest top of stack.  Return.
		if(sum(arr, begin, pivot) > sum){
			return getLargestRun(arr, begin, pivot);
		}
		else if(sum(arr, pivot + 1, end) > sum){
			return getLargestRun(arr, pivot, end);
		}
		else{
			int[] soln = new int[2];
			soln[0] = begin;
			soln[1] = end;

			return soln;
		}
	}

	private static int sum(int[] arr, int begin, int end){
		int sum = 0;
		for(int i = begin; i < end; i++){
			sum += arr[i];
		}

		return sum;
	}

	private static int findMinIndex(int[] arr, int begin, int end){
		int min = arr[begin];
		int index = begin;
		for(int i = begin + 1; i < end; i++){
			if(arr[i] < min){
				min = arr[i];
				index = i;
			}
		}

		if(min > 0)
			return -1;

		return index;
	}
}
