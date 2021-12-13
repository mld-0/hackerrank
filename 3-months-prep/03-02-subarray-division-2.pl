#!/usr/bin/env perl
use strict;
use warnings;
use v5.026;
use Carp::Assert;
use List::Util qw(sum);

sub birthday_i {
	my @s = @{$_[0]};
	my $d = $_[1];
	my $m = $_[2];
	my @results = ();
	for (my $k = 0; $k < scalar(@s)-$m+1; ++$k) {
		my @loop_group = @s[$k..$k+$m-1];
		if (sum(@loop_group) == $d) {
			push @results, \@loop_group;
		}
	}
	#say "results=([" . ( join '], [', map { join ',', @{$_} } @results ) . "])";
	return scalar(@results);
}

sub birthday_ii {
	my @s = @{$_[0]};
	my $d = $_[1];
	my $m = $_[2];
	my @results = map { [ @s[$_..$_+$m-1] ] } grep { sum( @s[$_..$_+$m-1] ) == $d } ( 0..(scalar(@s)-$m) ) ;
	#say "results=([" . ( join '], [', map { join ',', @{$_} } @results ) . "])";
	return scalar(@results);
}


my @test_functions = ( \&birthday_i, \&birthday_ii, );
my @test_functions_names = ( "birthday_i", "birthday_ii", );
assert (scalar(@test_functions) == scalar(@test_functions_names));

my @input_values = ( [[1,2,1,3,2], 3,2], [[1,1,1,1,1,1], 3,2], [[4], 4,1], [[2,5,1,3,4,4,3,5,1,1,2,1,4,1,3,3,4,2,1], 18,7], );
my @input_checks = ( 2, 0, 1, 3, );
assert (scalar(@input_values) == scalar(@input_checks));

for (my $test_func_i = 0; $test_func_i < scalar(@test_functions); ++$test_func_i) {

	my $test_func = $test_functions[$test_func_i];
	say $test_functions_names[$test_func_i];

	for (my $i = 0; $i < scalar(@input_values); ++$i) {
		my @s = @{$input_values[$i]->[0]};
		my $d = $input_values[$i]->[1];
		my $m = $input_values[$i]->[2];
		say "s=(@s), d=($d), m=($m)";

		my $check = $input_checks[$i];

		my $result = $test_func->(\@s, $d, $m);
		say "result=($result)";

		assert ($result == $check);
	}

	say "";
}

