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

sub countingValleys {
	my $steps = $_[0];
	my $path = $_[1];
	my $count_valleys = 0;
	my $current_height = 0;
	my $previous_height = 0;
	foreach my $x (split //, $path) {
		$previous_height = $current_height;
		if ($x eq 'D') {
			$current_height -= 1;
		} elsif ($x eq 'U') {
			$current_height += 1;
		}
		if ($previous_height == 0 and $current_height < 0) {
			$count_valleys += 1;
		}
	}
	return $count_valleys;
}


my @input_values = ( [8,"UDDDUDUU"], [12,"DDUUDDUDUUUD"], );
my @input_checks = ( 1, 2, );
assert (scalar(@input_values) == scalar(@input_checks));

for (my $i = 0; $i < scalar(@input_values); ++$i) { 
	my $steps = $input_values[$i]->[0];
	my $path = $input_values[$i]->[1];
	say "steps=($steps), path=($path)";

	my $check = $input_checks[$i];

	my $result = countingValleys $steps, $path;
	say "result=($result)";

	assert ($result == $check);
	say "";
}


