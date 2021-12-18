#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

void part_one ()
{
	int limit;
	scanf ( "%d", &limit );
	int previous = -1, next = -1;
	int ans = 0;
	scanf ( "%d", &previous );
	for ( int i = 1 ; i < limit ; ++i ) {
		scanf ( "%d", &next );
		if ( next > previous )
			++ans;
		previous = next;
	}
	printf ( "Part One Ans is : %d\n", ans );
}

void part_two ()
{
	int limit;
	scanf ( "%d", &limit );
	int prev_a, prev_b, prev_c, next;
	int ans = 0;
	scanf ( "%d%d%d", &prev_a, &prev_b, &prev_c );
	for ( int i = 3 ; i < limit ; ++i ) {
		scanf ( "%d", &next );
		int up = prev_a + prev_b + prev_c;
		int down = prev_b + prev_c + next;
		if ( down > up ) ++ans;
		prev_a = prev_b;
		prev_b = prev_c;
		prev_c = next;
	}
	printf ( "Part Two Ans is : %d\n", ans );
}

int main ()
{
	part_one ();
	part_two ();

	return 0;
}

