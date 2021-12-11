#!/usr/bin/env perl
use strict;
use warnings;
use v5.026;
use Carp::Assert;

sub timeConversion {
	my $s = shift @_;

	my $time_range = substr $s, length($s)-2;

	my $time_H = substr $s, 0, 2;
	my $time_M = substr $s, 3, 2;
	my $time_S = substr $s, 6, 2;

	if ($time_range eq "PM" and $time_H != 12) {
		$time_H = $time_H + 12;
	} elsif ($time_range eq "AM" and $time_H == 12) {
		$time_H = 0;
	}

	my $result_str = sprintf("%02i:%02i:%02i", $time_H, $time_M, $time_S);
	return $result_str;
}

my @input_values = ( "07:05:45PM", "12:40:22AM", "06:40:03AM", "12:05:39AM", );
my @input_checks = ( "19:05:45", "00:40:22", "06:40:03", "00:05:39", );
assert (scalar(@input_values) == scalar(@input_checks));

for (my $i = 0; $i < scalar(@input_values); ++$i) {
	my $s = $input_values[$i];
	say "s=($s)";
	my $check = $input_checks[$i];

	my $result = timeConversion($s);
	
	assert ($result eq $check);
	say "";
}

