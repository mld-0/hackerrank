#!/usr/bin/env perl
#   VIM SETTINGS: {{{3
#   vim: set tabstop=4 modeline modelines=10 foldmethod=marker:
#   vim: set foldlevel=2 foldcolumn=2:
#   }}}1
use strict; 
use warnings;
use Carp::Assert;
use Capture::Tiny 'capture_stdout';
use v5.032;
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

sub plusMinus {
	my @arr = @{$_[0]};
	my $count_positive = 0;
	my $count_negative = 0;
	foreach my $x (@arr) {
		if ($x > 0) {
			$count_positive++;
		} elsif ($x < 0) {
			$count_negative++;
		}
	}
	my $count_zero = scalar(@arr) - ($count_positive + $count_negative);
	my $ratio_positive = $count_positive / scalar(@arr);
	my $ratio_negative = $count_negative / scalar(@arr);
	my $ratio_zero = $count_zero / scalar(@arr);
	printf("%.6f\n%.6f\n%.6f\n", $ratio_positive, $ratio_negative, $ratio_zero);
}


my @input_values = ( "6\n-4 3 -9 0 4 1\n", "8\n1 2 3 -1 -2 -3 0 0\n", );
my @input_checks = ( "0.500000\n0.333333\n0.166667\n", "0.375000\n0.375000\n0.250000\n", );
assert (scalar(@input_values) == scalar(@input_checks));

for (my $i = 0; $i <= $#input_values; ++$i) {
	my @loop_value_lines = split /\n/, $input_values[$i];
	my $check = $input_checks[$i];

	my $n = $loop_value_lines[0];
	my @arr = split / /, $loop_value_lines[1];
	say "arr=(@arr)";

	my $result = capture_stdout { plusMinus \@arr };
	say "result=($result)";

	assert ($result eq $check);
	say "";
}

