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

sub flippingBits {
	my $n = shift;
	my $VAL = 2 ** 32 - 1;
	return ($n ^ $VAL);
}

my @input_values = ( [2147483647, 1, 0], [4,123456], [0,802743475,35601423], );
my @input_checks = ( [2147483648, 4294967294, 4294967295], [4294967291, 4294843839], [4294967295,3492223820,4259365872], );
assert (scalar(@input_values) == scalar(@input_checks));

for (my $i = 0; $i < scalar(@input_values); ++$i) {
	my @loop_values = @{$input_values[$i]};
	my @loop_checks = @{$input_checks[$i]};
	assert (scalar(@loop_values) == scalar(@loop_checks));
	for (my $j = 0; $j < scalar(@loop_values); ++$j) {
		my $n = $loop_values[$j];
		say "n=($n)";
		my $check = $loop_checks[$j];
		say "check=($check)";
		my $result = flippingBits $n;
		say "result=($result)";
		assert ($result == $check);
		say "";
	}
}

