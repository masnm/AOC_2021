import java.util.*;

public class Main {

	public static Scanner s;

	public static void part_one_exception () {
		// this function don't need the input count
		// explained in readme.txt file
		String command;
		long x_axis = 0, y_axis = 0, temp;
		boolean done = false;
		while ( true ) {
			if ( done ) break;
			try {
				command = s.next();
				temp = s.nextLong();
				switch ( command.length() ) {
					case 7 : { x_axis += temp; break; }
					case 4 : { y_axis += temp; break; }
					case 2 : { y_axis -= temp; break; }
					default : assert ( false );
				}
			} catch ( Exception e ) {
				done = true;
			}
		}
		System.out.println ( "Part One ans is : " + (x_axis * y_axis) );
	}

	public static void part_one () {
		String command;
		long x_axis = 0, y_axis = 0, temp;
		boolean done = false;
		int count = s.nextInt();
		for ( int i = 0 ; i < count ; ++i ) {
			command = s.next();
			temp = s.nextLong();
			switch ( command.length() ) {
				case 7 : { x_axis += temp; break; }
				case 4 : { y_axis += temp; break; }
				case 2 : { y_axis -= temp; break; }
				default : assert ( false );
			}
		}
		System.out.println ( "Part One ans is : " + (x_axis * y_axis) );
	}

	public static void part_two () {
		String command;
		long aim = 0, depth = 0, horizontal = 0;
		long x_axis = 0, y_axis = 0;
		long temp;
		boolean done = false;
		int count = s.nextInt();
		for ( int i = 0 ; i < count ; ++i ) {
			command = s.next();
			temp = s.nextLong();
			switch ( command.length() ) {
				case 7 : { horizontal += temp; depth += ( aim * temp ); break; }
				case 4 : { aim += temp; break; }
				case 2 : { aim -= temp; break; }
				default : assert ( false );
			}
		}
		System.out.println ( "Part two ans is : " + (depth * horizontal) );
	}

	public static void main ( String[] args ) {
		s = new Scanner ( System.in );
		part_one ();
		part_one_exception ();
		part_two ();
	}
}
