#include "bits/stdc++.h"
#include <iostream>
using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

#define F first
#define S second
#define eb emplace_back

using ll = long long int;

struct points {
	ll x1, y1, x2, y2;
	points () : x1(0), y1(0), x2(0), y2(0) { }
	points ( ll _x1, ll _y1, ll _x2, ll _y2 ) :
		x1(_x1), y1(_y1), x2(_x2), y2(_y2)
	{ }
};
debug & operator << (debug & dd, points p) {
	dd << "(" << p.x1 << ", " << p.y1 << ", " << p.x2 << ", " << p.y2 << ")"; return dd;
}

const int nax = 1005;
vector<points> vvi;
vector<vector<ll>> arr ( nax, vector<ll>(nax) );

ll get_input ()
{
	vvi.clear();
	ll mx = 0;
	ll _x1, _y1, _x2, _y2;
	while ( scanf("%lld,%lld -> %lld,%lld", &_x1, &_y1, &_x2, &_y2 ) != EOF ) {
		mx = max ( mx, max ( max ( _x1, _y1 ), max ( _x2, _y2 ) ) );
		vvi.emplace_back( _x1, _y1, _x2, _y2 );
	}
	return mx;
}

void clear_array ()
{
	for ( int i = 0 ; i < nax ; ++i )
		for ( int j = 0 ; j < nax ; ++j )
			arr[i][j] = 0LL;
}

void part_one ()
{
	for ( const points& i : vvi ) {
		if ( i.x1 == i.x2 ) {
			for ( ll col = min(i.y1,i.y2) ; col <= max(i.y1,i.y2) ; ++col )
				++ arr[col][i.x1];
		} else if ( i.y1 == i.y2 ) {
			for ( ll row = min(i.x1,i.x2) ; row <= max(i.x1,i.x2) ; ++row )
				++ arr[i.y1][row];
		} else {
			// debug() << imie(i);
		}
	}
	ll count = 0;
	for ( const vector<ll>& vl : arr )
		for ( const ll& x : vl )
			if ( x > 1 )
				++count;
	printf ( "Part one ans is : %lld\n", count );
}

void part_two ()
{
	for ( points& i : vvi ) {
		if ( i.x1 == i.x2 ) {
			for ( ll col = min(i.y1,i.y2) ; col <= max(i.y1,i.y2) ; ++col )
				++ arr[col][i.x1];
		} else if ( i.y1 == i.y2 ) {
			for ( ll row = min(i.x1,i.x2) ; row <= max(i.x1,i.x2) ; ++row )
				++ arr[i.y1][row];
		} else {
			if ( (i.x1 > i.x2) && (i.y1 > i.y2) ) {
				while ( i.x1 >= i.x2 )
					++ arr[i.y1--][i.x1--];
			} else if ( (i.x1 < i.x2) && (i.y1 < i.y2) ) {
				while ( i.x1 <= i.x2 )
					++ arr[i.y1++][i.x1++];
			} else if ( (i.x1 > i.x2) && (i.y1 < i.y2) ) {
				while ( i.x1 >= i.x2 )
					++ arr[i.y1++][i.x1--];
			} else if ( (i.x1 < i.x2) && (i.y1 > i.y2) ) {
				while ( i.x1 <= i.x2 )
					++ arr[i.y1--][i.x1++];
			} else {
				assert ( false );
			}
		}
	}
	ll count = 0;
	for ( const vector<ll>& vl : arr )
		for ( const ll& x : vl )
			if ( x > 1 )
				++count;
	printf ( "Part one ans is : %lld\n", count );
}

int main ()
{
	ll mx = get_input ();
	assert ( mx < nax );
	clear_array ();
	part_one ();
	clear_array ();
	part_two ();

	return 0;
}
