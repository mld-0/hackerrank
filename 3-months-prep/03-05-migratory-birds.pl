#!/usr/bin/env perl
use strict;
use warnings;
use v5.026;
use Carp::Assert;


sub migratoryBirds {
	my @arr = @{$_[0]};
	my $result_value = -2**64+1;
	my $result_index = undef;
	my %counts;
	foreach my $x (@arr) {
		$counts{$x} += 1;
	}
	foreach my $k (sort {$a<=>$b} keys %counts) {
		my $v = $counts{$k};
		if ($v > $result_value) {
			$result_index = $k;
			$result_value = $v;
		}
	}
	return $result_index;
}

my @input_values = ( [1,4,4,4,5,3], [1,2,3,4,5,4,3,2,1,3,4], );
my @input_checks = ( 4, 3, );
assert (scalar(@input_values) == scalar(@input_checks));

for (my $i = 0; $i < scalar(@input_values); ++$i) {
	my @arr = @{$input_values[$i]};
	my $check = $input_checks[$i];
	say "arr=(@arr)";
	my $result = migratoryBirds \@arr;
	say "result=($result)";
	assert ($result == $check);
	say "";
}

