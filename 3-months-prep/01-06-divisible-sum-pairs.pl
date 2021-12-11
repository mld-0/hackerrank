#!/usr/bin/env perl
#   VIM SETTINGS: {{{3
#   vim: set tabstop=4 modeline modelines=10 foldmethod=marker:
#   vim: set foldlevel=2 foldcolumn=2:
#   }}}1
use strict; 
use warnings;
use v5.026;
use Carp::Assert;
use Capture::Tiny 'capture_stdout';
#	{{{2
sub ltrim {
	#	{{{
    my $str = shift;
    $str =~ s/^\s+//;
    return $str;
}
	#	}}}
sub rtrim {
	#	{{{
    my $str = shift;
    $str =~ s/\s+$//;
    return $str;
}
	#	}}}


sub divisibleSumPairs {
	my $n = $_[0];
	my $k = $_[1];
	my @ar = @{$_[2]};
	my $result_count = 0;
	for (my $l = 0; $l < scalar(@ar)-1; ++$l) {
		for (my $r = $l+1; $r < scalar(@ar); ++$r) {
			my $a = $ar[$l];
			my $b = $ar[$r];
			my $sum = $a + $b;
			my $mod = $sum % $k;
			if ($mod == 0) {
				$result_count++;
			}
		}
	}
	return $result_count;
}


my @input_values = ( [3, [1,3,2,6,1,2]], [2, [5,9,10,7,4]], [2, [8,10]], );
my @input_checks = ( 5, 4, 1, );
assert (scalar(@input_values) == scalar(@input_checks));

for (my $i = 0; $i < scalar(@input_values); ++$i) {
	my $k = $input_values[$i]->[0];
	my @ar = @{$input_values[$i]->[1]};
	say "k=($k), ar=(@ar)";

	my $check = $input_checks[$i];

	my $result = divisbleSumPairs 0, $k, \@ar;
	say "result=($result)";

	assert ($result == $check);
	say "";
}


