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

sub marsExploration {
	my $s = shift;
	my $result = 0;
	my $expected = "SOS" x int(length($s) / 3);
	assert (length($s) == length($expected));
	for (my $i = 0; $i < length($s); ++$i) {
		my $c = substr $s, $i, 1;
		my $x = substr $expected, $i, 1;
		if ($c ne $x) {
			$result += 1;
		}
	}
	return $result;
}


my @input_values = ( "SOSSPSSQSSOR", "SOSSOT", "SOSSOSSOS", );
my @input_checks = ( 3, 1, 0, );
assert (scalar(@input_values) == scalar(@input_checks));

for (my $i = 0; $i < scalar(@input_values); ++$i) {
	my $s = $input_values[$i];
	say "s=($s)";
	my $check = $input_checks[$i];

	my $result = marsExploration $s;
	say "result=($result)";

	assert ($result eq $check);
	say "";
}



