import java.util.*;

public class Main {

	public static Scanner s;

	public static void part_one () {
		int ans = 0, temp = -1, prev = -1;
		int n = s.nextInt();
		prev = s.nextInt();
		for ( int i = 1 ; i < n ; ++i ) {
			temp = s.nextInt();
			if ( temp > prev ) ++ans;
			prev = temp;
		}
		System.out.println ( "Part One Ans is : " + ans );
	}

	public static void part_two () {
		int ans = 0;
		int ta, tb, tc, temp; 
		int n = s.nextInt ();
		ta = s.nextInt ();
		tb = s.nextInt ();
		tc = s.nextInt ();
		for ( int i = 3 ; i < n ; ++i ) {
			temp = s.nextInt();
			if ( (ta+tb+tc) < (tb+tc+temp) ) ++ans;
			ta = tb; tb = tc; tc = temp;
		}
		System.out.println ( "Part Two Ans is : " + ans );
	}

	public static void main ( String[] args ) {
		s = new Scanner( System.in );
		part_one ();
		part_two ();
	}
}
