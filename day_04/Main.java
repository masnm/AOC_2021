import java.util.*;

class Pair {
	public boolean mark;
	public int data;
	Pair () { mark = false; data = -1; }
	Pair ( boolean _mark, int _data ) { mark = _mark; data = _data; }
	public void mark_true ( int value ) { if ( data==value ) mark = true; }
	public String toString () {
		String ret;
		ret = (mark?"{ T, ":"{ F, ");
		ret += Integer.toString(data) + " }";
		return ret;
	}
}

class Grid {
	public Pair pair[][];
	Grid () {
		pair = new Pair[5][5];
		for ( int i = 0 ; i < 5 ; ++i )
			for ( int j = 0 ; j < 5 ; ++j )
				pair[i][j] = new Pair();
	}
	public void mark_true ( int value ) {
		for ( int i = 0 ; i < 5 ; ++i )
			for ( int j = 0 ; j < 5 ; ++j )
				pair[i][j].mark_true (value);
	}
	public boolean wins () {
		int top[] = new int[5];
		int left[] = new int[5];
		for ( int i = 0 ; i < 5 ; ++i ) top[i] = left[i] = 0;
		for ( int i = 0 ; i < 5 ; ++i )
			for ( int j = 0 ; j < 5 ; ++j )
				if ( pair[i][j].mark ) {
					++left[i];
					++top[j];
				}
		for ( int i = 0 ; i < 5 ; ++i )
			if ( top[i] == 5 || left[i] == 5 )
				return true;
		return false;
	}
	public String toString () {
		String ret="{";
		for ( int i = 0 ; i < 5 ; ++i ) {
			for ( int j = 0 ; j < 5 ; ++j ) {
				ret += pair[i][j].toString();
			}
			if ( i < 4 ) ret += ",\n";
			if ( i == 4 ) ret += "}\n";
		}
		return ret;
	}
}

public class Main {

	public static Scanner scan;
	public static int arrCount;
	public static int arr[];
	public static int gridCount;
	public static Grid grid[];

	public static void main(String[] args) {
		scan = new Scanner ( System.in );
		initialize ();
		get_array ();
		get_grids ();
		part_one ();
		part_two ();
	}
	public static void initialize () {
		arrCount = 0;
		gridCount = 0;
		arr = new int[10005];
		grid = new Grid[1005];
		for ( int i = 0 ; i < 1005 ; ++i )
			grid[i] = new Grid();
	}
	public static void get_array () {
		String str = scan.next();
		int num = 0;
		for ( char s : str.toCharArray() ) {
			if ( s == ',' ) { arr[arrCount++] = num; num = 0; }
			else { int t = Character.getNumericValue(s); num *= 10; num += t; }
		}
		arr[arrCount++] = num;
	}
	public static void get_grids () {
		assert ( gridCount == 0 );
		while ( scan.hasNext() ) {
			for ( int i = 0 ; i < 5 ; ++i ) {
				for ( int j = 0 ; j < 5 ; ++j ) {
					int t = scan.nextInt();
					grid[gridCount].pair[i][j].mark = false;
					grid[gridCount].pair[i][j].data = t;
				}
			}
			++gridCount;
		}
	}
	public static void part_one () {
		boolean found = false;
		int ind = -1, num = -1;
		for ( int index = 0 ; index < arrCount && !found ; ++index ) {
			for ( int gi = 0 ; gi < gridCount ; ++gi )
				grid[gi].mark_true ( arr[index] );
			for ( int gi = 0 ; gi < gridCount ; ++gi )
				if ( grid[gi].wins() ) {
					found = true;
					ind = gi;
					num = arr[index];
					break;
				}
		}
		Grid wg = grid[ind];
		long unmarked = 0, marked = 0;
		for ( int i = 0 ; i < 5 ; ++i )
			for ( int j = 0 ; j < 5 ; ++j ) {
				if ( wg.pair[i][j].mark )
					marked += wg.pair[i][j].data;
				else
					unmarked += wg.pair[i][j].data;
			}
		System.out.println ( "Unmarked : " + unmarked );
		System.out.println ( "Marked : " + marked );
		System.out.println ( "Number : " + num );
		System.out.println ( "Part one ans is : " + (num * unmarked) );
	}
	public static void part_two () {
		int ind = -1, num = -1;
		int wincount = 0;
		boolean isWined[] = new boolean[gridCount+5];
		for ( int i = 0 ; i < gridCount+5 ; ++i ) isWined[i] = false;
		for ( int index = 0 ; (index < arrCount) && (wincount < gridCount) ; ++index ) {
			for ( int gi = 0 ; gi < gridCount ; ++gi )
				grid[gi].mark_true ( arr[index] );
			for ( int gi = 0 ; gi < gridCount ; ++gi )
				if ( grid[gi].wins() ) {
					if ( !isWined[gi] ) {
						++wincount;
						isWined[gi] = true;
						ind = gi;
						num = arr[index];
					}
				}
		}
		Grid wg = grid[ind];
		long unmarked = 0, marked = 0;
		for ( int i = 0 ; i < 5 ; ++i )
			for ( int j = 0 ; j < 5 ; ++j ) {
				if ( wg.pair[i][j].mark )
					marked += wg.pair[i][j].data;
				else
					unmarked += wg.pair[i][j].data;
			}
		System.out.println ( "Unmarked : " + unmarked );
		System.out.println ( "Marked : " + marked );
		System.out.println ( "Number : " + num );
		System.out.println ( "Part two ans is : " + (num * unmarked) );
	}
}
