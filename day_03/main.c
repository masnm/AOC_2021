#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

void make_zero ( long* arr, int limit )
{
	for ( int i = 0 ; i < limit ; ++i )
		arr[i] = 0;
}

long bit_to_long ( char* bits, int len )
{
	long start = 1;
	long ans = 0;
	for ( int i = len - 1 ; i > -1 ; --i ) {
		if ( bits[i] == '1' )
			ans += start;
		start <<= 1;
	}
	return ans;
}

void part_one ()
{
	const int binary_limit = 15;
	char bits [binary_limit];
	int bits_len = -1;
	long count_one [binary_limit];
	long count_zero [binary_limit];
	make_zero ( count_one, binary_limit );
	make_zero ( count_zero, binary_limit );
	while ( scanf ( "%s", bits ) != EOF ) {
		int bit_len = strlen ( bits );
		assert ( bit_len < binary_limit );
		if ( bits_len == -1 ) bits_len = bit_len;
		else assert ( bits_len == bit_len );
		for ( int i = 0 ; i < bit_len ; ++i ) {
			if ( bits[i] == '0' ) count_zero[i]++;
			else count_one[i]++;
		}
	}
	for ( int i = 0 ; i < bits_len ; ++i ) {
		assert ( count_one[i] != count_zero[i] );
		bits[i] = (count_one[i] > count_zero[i] ? '1' : '0');
	}
	long gamma_rate = bit_to_long ( bits, bits_len );
	for ( int i = 0 ; i < bits_len ; ++i ) {
		assert ( count_one[i] != count_zero[i] );
		bits[i] = (count_one[i] < count_zero[i] ? '1' : '0');
	}
	long epsilon_rate = bit_to_long ( bits, bits_len );
	printf ( "Part One Power consumptin is : %ld\n", (gamma_rate * epsilon_rate) );
}

#define bit_lim 15
#define input_lim 2050
char bit[input_lim][bit_lim];
bool available[input_lim];

bool one_available ( int limit )
{
	int count = 0;
	for ( int i = 0 ; i < limit ; ++i ) {
		if ( available[i] ) {
			++count;
		}
	}
	return count == 1;
}

char* get_one ( int limit )
{
	for ( int i = 0 ; i < limit ; ++i )
		if ( available[i] )
			return bit[i];
	assert ( false );
}

void part_two ()
{
	for ( int i = 0 ; i < input_lim ; ++i ) available[i] = true;
	int count = 0;
	for ( count = 0 ;  ; )
		if ( scanf ( "%s", bit[count++] ) == EOF )
			break;
	--count; // its a bug
	int current_bit = 0;
	while ( true ) {
		if ( one_available ( count ) ) break;
		if ( current_bit >= count ) assert(false);
		int one_count = 0;
		int zero_count = 0;
		for ( int i = 0 ; i < count ; ++i ) {
			if ( available[i] && bit[i][current_bit] == '0' ) zero_count++;
			else if ( available[i] ) one_count++;
		}
		for ( int i = 0 ; i < count ; ++i ) {
			if ( one_count == zero_count ) {
				for ( int j = 0 ; j < count ; ++j ) {
					if ( available[j] && bit[j][current_bit] == '0' )
						available[j] = false;
				}
			} else {
				for ( int j = 0 ; j < count ; ++j ) {
					if ( available[j] ) {
						if ( one_count > zero_count ) {
							if ( bit[j][current_bit] == '0' )
								available[j] = false;
						} else if ( zero_count > one_count ) {
							if ( bit[j][current_bit] == '1' )
								available[j] = false;
						}
					}
				}
			}
		}
		current_bit++;
	}
	char* poin = get_one ( count );
	long oxygen_generator_rating = bit_to_long ( poin, strlen(bit[0]) );
	for ( int i = 0 ; i < input_lim ; ++i ) available[i] = true;
	current_bit = 0;
	while ( true ) {
		if ( one_available ( count ) ) break;
		if ( current_bit >= count ) assert(false);
		int one_count = 0;
		int zero_count = 0;
		for ( int i = 0 ; i < count ; ++i ) {
			if ( available[i] && bit[i][current_bit] == '0' ) zero_count++;
			else if ( available[i] ) one_count++;
		}
		for ( int i = 0 ; i < count ; ++i ) {
			if ( one_count == zero_count ) {
				for ( int j = 0 ; j < count ; ++j ) {
					if ( available[j] && bit[j][current_bit] == '1' )
						available[j] = false;
				}
			} else {
				for ( int j = 0 ; j < count ; ++j ) {
					if ( available[j] ) {
						if ( one_count > zero_count ) {
							if ( bit[j][current_bit] == '1' )
								available[j] = false;
						} else if ( zero_count > one_count ) {
							if ( bit[j][current_bit] == '0' )
								available[j] = false;
						}
					}
				}
			}
		}
		current_bit++;
	}
	poin = get_one ( count );
	long CO2_scrubber_rating = bit_to_long ( poin, strlen(bit[0]) );
	printf ( "Part Two life support rating is : %ld\n", (oxygen_generator_rating * CO2_scrubber_rating) );
}

int main ()
{
	// part_one ();
	part_two ();

	return 0;
}

