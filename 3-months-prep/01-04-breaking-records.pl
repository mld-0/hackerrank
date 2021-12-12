#!/usr/bin/env perl
use strict;
use warnings;
use v5.026;
use Carp::Assert;

sub breakingRecords {
	my $scores = shift;
	my $record_min = $scores->[0];
	my $updateRecordMin = 0;
	my $record_max = $scores->[0];
	my $updateRecordMax = 0;
	foreach my $s (@{$scores}[1..$#{$scores}]) {
		if ($s < $record_min) {
			$record_min = $s;
			$updateRecordMin += 1;
		}
		if ($s > $record_max) {
			$record_max = $s;
			$updateRecordMax += 1;
		}
	}
	return ( $updateRecordMax, $updateRecordMin );
}


my $input_values = [ [10, 5, 20, 20, 4, 5, 2, 25, 1], [3, 4, 21, 36, 10, 28, 35, 5, 24, 42], ];
my $input_checks = [ [2, 4], [4, 0], ];
assert (scalar(@{$input_values}) == scalar(@{$input_checks}));

for (my $i = 0; $i < scalar(@{$input_values}); ++$i) {
	my $scores = $input_values->[$i];
	say "scores=(@{$scores})";
	my @check = @{$input_checks->[$i]};

	my @result = breakingRecords $scores;
	say "result=(@result)";
	assert ("@result" eq "@check");

	say STDERR "";
}

