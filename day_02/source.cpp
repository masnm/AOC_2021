#include <bits/stdc++.h>
using namespace std;

void part_one () {
	string command;
	long x_axis = 0, y_axis = 0, temp;
	int count;
	cin >> count;
	for ( int i = 0 ; i < count ; ++i ) {
		cin >> command >> temp;
		switch ( command.length() ) {
			case 7 : { x_axis += temp; break; }
			case 4 : { y_axis += temp; break; }
			case 2 : { y_axis -= temp; break; }
			default : assert ( false );
		}
	}
	cout << "Part One ans is : " << (x_axis * y_axis) << endl;
}

void part_two () {
	string command;
	long horizontal = 0, aim = 0, depth = 0;
	long temp;
	int count;
	cin >> count;
	for ( int i = 0 ; i < count ; ++i ) {
		cin >> command >> temp;
		switch ( command.length() ) {
			case 7 : { horizontal += temp; depth += ( aim * temp ); break; }
			case 4 : { aim += temp; break; }
			case 2 : { aim -= temp; break; }
			default : assert ( false );
		}
	}
	cout << "Part two ans is : " << (depth * horizontal) << endl;
}

int main ()
{
	part_one ();
	part_two ();

	return 0;
}
