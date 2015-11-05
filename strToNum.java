import java.util.*;

public class strToNum{
	private static int strToNum(String[] arr){
		int total = 0;
		int temp = 0;
		for(int i = 0; i < arr.length; i++){
			int num = getNum(arr[i]);
			if(num < 100){
				temp += num;
			}
			else if(num > 100){
				temp *= num;
				total += temp;
				temp = 0;
			}
			else{
				temp *= num;
			}
		}

		total += temp;
		return total;
	}

	// Must be a better way to do this
	// Maps words of numbers to their integer equivalents
	private static int getNum(String str){
		if(str.equals("one"))
			return 1;
		else if(str.equals("two"))
			return 2;
		else if(str.equals("three"))
			return 3;
		else if(str.equals("four"))
			return 4;
		else if(str.equals("five"))
			return 5;
		else if(str.equals("six"))
			return 6;
		else if(str.equals("seven"))
			return 7;
		else if(str.equals("eight"))
			return 8;
		else if(str.equals("nine"))
			return 9;
		else if(str.equals("ten"))
			return 10;
		else if(str.equals("eleven"))
			return 11;
		else if(str.equals("twelve"))
			return 12;
		else if(str.equals("thirteen"))
			return 13;
		else if(str.equals("fourteen"))
			return 14;
		else if(str.equals("fifteen"))
			return 15;
		else if(str.equals("sixteen"))
			return 16;
		else if(str.equals("seventeen"))
			return 17;
		else if(str.equals("eighteen"))
			return 18;
		else if(str.equals("nineteen"))
			return 19;
		else if(str.equals("twenty"))
			return 20;
		else if(str.equals("thirty"))
			return 30;
		else if(str.equals("fourty"))
			return 40;
		else if(str.equals("fifty"))
			return 50;
		else if(str.equals("sixty"))
			return 60;
		else if(str.equals("seventy"))
			return 70;
		else if(str.equals("eighty"))
			return 80;
		else if(str.equals("ninety"))
			return 90;
		else if(str.equals("hundred"))
			return 100;
		else if(str.equals("thousand"))
			return 1000;
		else if(str.equals("million"))
			return 1000000;
		else if(str.equals("billion"))
			return 1000000000;
		
		return -1;
	}

	/**
	 *	Takes in a number as a word (ie. one hundred fifty million) and outputs the corresponding number
	 */
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		System.out.print("Please enter a number in word format (ie. two thousand fifty three): ");
		String[] str = in.nextLine().split(" ");

		System.out.println(strToNum(str));
	}
}