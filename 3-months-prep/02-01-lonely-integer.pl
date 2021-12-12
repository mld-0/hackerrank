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

sub lonelyinteger {
	my @a = @{$_[0]};
	my %c;
	foreach (@a) {
		$c{$_} += 1;
	}
	while (my ($k,$v) = each(%c)) {
		if ($v == 1) {
			return $k;
		}
	}
	return -1;
}


my @input_values = ( [1], [1,1,2], [0,0,1,2,1], );
my @input_checks = ( 1, 2, 2, );
assert (scalar(@input_values) == scalar(@input_checks));

for (my $i = 0; $i < scalar(@input_values); ++$i) {
	my @a = @{$input_values[$i]};
	say "a=(@a)";
	my $check = $input_checks[$i];

	my $result = lonelyinteger \@a;
	say "result=($result)";

	assert ($result == $check);
	say "";
}

