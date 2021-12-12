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

sub pangrams {
	my $s = shift;
	$s = lc $s;
	my %letters_count;
	foreach (split //, $s) {
		$letters_count{$_} += 1;
	}
	foreach my $x ('a'..'z') {
		if (not exists $letters_count{$x}) {
			return "not pangram";
		}
	}
	return "pangram";
}

my @input_values = ( "We promptly judged antique ivory buckles for the next prize", "We promptly judged antique ivory buckles for the prize", );
my @input_checks = ( "pangram", "not pangram", );
assert (scalar(@input_values) == scalar(@input_checks));

for (my $i = 0; $i < scalar(@input_values); ++$i) {
	my $s = $input_values[$i];
	my $check = $input_checks[$i];
	say "s=($s)";

	my $result = pangrams $s;
	say "result=($result)";	

	assert ($result eq $check);
	say "";
}


