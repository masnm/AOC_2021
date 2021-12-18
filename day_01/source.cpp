#include "bits/stdc++.h"
using namespace std;

void part_one ()
{
	int limit;
	cin >> limit;
	int previous = -1, next = -1;
	int ans = 0;
	cin >> previous;
	for ( int i = 1 ; i < limit ; ++i ) {
		cin >> next;
		if ( next > previous )
			++ans;
		previous = next;
	}
	cout << "Part One Ans is : " << ans << endl;
}

void part_two ()
{
	int limit;
	cin >> limit;
	int prev_a, prev_b, prev_c, next;
	int ans = 0;
	cin >> prev_a >> prev_b >> prev_c;
	for ( int i = 3 ; i < limit ; ++i ) {
		cin >> next;
		int up = prev_a + prev_b + prev_c;
		int down = prev_b + prev_c + next;
		if ( down > up ) ++ans;
		prev_a = prev_b;
		prev_b = prev_c;
		prev_c = next;
	}
	cout << "Part Two Ans is : " << ans << endl;
}

int main ()
{
	part_one ();
	part_two ();

	return 0;
}

