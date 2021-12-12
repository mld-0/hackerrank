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
use Data::Dumper;
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

sub diagonalDifference {
	my @arr = @{$_[0]};
	my $LR = 0;
	my $RL = 0;
	for (my $i = 0; $i < scalar(@arr); ++$i) {
		$RL += $arr[$i]->[$i];
		$LR += $arr[scalar(@arr)-$i-1]->[$i];
	}
	return abs($RL - $LR);
}


my @input_values = ( [[11,2,4],[4,5,6],[10,8,-12]], [[-1,1,-7,-8],[-10,-8,-5,-2],[0,9,7,-1],[4,4,-2,1]], );
my @input_checks = ( 15, 1, );
assert (scalar(@input_values) == scalar(@input_checks));

for (my $i = 0; $i < scalar(@input_values); ++$i) {
	my @arr = @{$input_values[$i]};
	say "arr=([" . ( join '], [', map { join ',', @{$_} } @arr ) . "])";
	my $check = $input_checks[$i];

	my $result = diagonalDifference \@arr;
	say "result=($result)";

	assert ($result == $check);
	say "";
}

