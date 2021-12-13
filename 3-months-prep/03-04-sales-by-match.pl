#!/usr/bin/env perl
use strict;
use warnings;
use v5.026;
use Carp::Assert;

sub sockMerchant {
	my $n = $_[0];
	my @arr = @{$_[1]};
	my $result = 0;
	my %counts;
	foreach my $x (@arr) {
		$counts{$x} += 1;
	}
	while (my ($k,$v) = each %counts) {
		$result += int($v / 2);
	}
	return $result;
}


my @input_values = ( [10,20,20,10,10,30,50,10,20], [1,1,3,1,2,1,3,3,3,3], );
my @input_checks = ( 3, 4, );
assert (scalar(@input_values) == scalar(@input_checks));

for (my $i = 0; $i < scalar(@input_values); ++$i) {
	my @arr = @{$input_values[$i]};
	my $check = $input_checks[$i];
	say "arr=(@arr)";
	my $result = sockMerchant scalar(@arr), \@arr;
	say "result=($result)";
	assert ($result == $check);
	say "";
}

