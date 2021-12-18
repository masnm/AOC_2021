#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

void part_one () {
	char command[105];
	long x_axis = 0, y_axis = 0, temp;
	int count;
	scanf ( "%d", &count );
	for ( int i = 0 ; i < count ; ++i ) {
		scanf ( "%s%ld", command, &temp );
		switch ( strlen(command) ) {
			case 7 : { x_axis += temp; break; }
			case 4 : { y_axis += temp; break; }
			case 2 : { y_axis -= temp; break; }
			default : assert ( false );
		}
	}
	printf ( "Part One ans is : %ld\n", (x_axis * y_axis) );
}

void part_two () {
	char command[105];
	long horizontal = 0, aim = 0, depth = 0;
	long temp;
	int count;
	scanf ( "%d", &count );
	for ( int i = 0 ; i < count ; ++i ) {
		scanf ( "%s%ld", command, &temp );
		switch ( strlen(command) ) {
			case 7 : { horizontal += temp; depth += ( aim * temp ); break; }
			case 4 : { aim += temp; break; }
			case 2 : { aim -= temp; break; }
			default : assert ( false );
		}
	}
	printf ( "Part two ans is : %ld\n", (depth * horizontal) );
}

int main ()
{
	part_one ();
	part_two ();

	return 0;
}

