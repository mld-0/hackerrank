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

use List::Util qw(min max sum);

sub miniMaxSum {
	my @arr = @{$_[0]};
	my $values_max = max @arr;
	my $values_min = min @arr;
	my $values_sum = sum @arr;
	printf("%i %i\n", $values_sum - $values_max, $values_sum - $values_min);
}

my @input_values = ("1 2 3 4 5\n", "256741038 623958417 467905213 714532089 938071625\n", );
my @input_checks = ( "10 14\n", "2063136757 2744467344\n", );
assert (scalar(@input_values) == scalar(@input_checks));

for (my $i = 0; $i < scalar(@input_values); ++$i) {
	my @arr = split /\s+/, rtrim $input_values[$i] ;
	my $check = $input_checks[$i];
	say "arr=(@arr)\n";

	my $result = capture_stdout { miniMaxSum \@arr };
	say "result=($result)";

	assert ($result eq $check);
	say "";
}

