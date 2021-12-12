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
use sort 'stable';
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


sub twoArrays {
	my $k = $_[0];
	my @A = @{$_[1]};
	my @B = @{$_[2]};
	@A = sort { $a <=> $b } @A;
	@B = reverse sort { $a <=> $b } @B;
	for (my $i = 0; $i < scalar(@A); ++$i) {
		my $a = $A[$i];
		my $b = $B[$i];
		if ($a + $b < $k) {
			return "NO";
		}
	}
	return "YES";
}

my @input_values = ( [10, [2,1,3], [7,8,9]], [5, [1,2,2,1], [3,3,3,4]], [10, [7,6,8,4,2], [5,2,6,3,1]], [91, [18,73,55,59,37,13,1,33], [81,11,77,49,65,26,29,49]], [94, [84,2,50,51,19,58,12,90,81,68,54,73,81,31,79,85,39,2], [53,102,40,17,33,92,18,79,66,23,84,25,38,43,27,55,8,19]], [88, [66,66,32,75,77,34,23,35], [61,17,52,20,48,11,50,5]], [45, [11,16,43,5,25,22,19,32,10,26,2,42,16,1], [33,1,1,20,26,7,17,39,23,34,10,11,38,20]], [59, [15,16,44,58,5,10,16,9,4,20,24], [37,45,41,46,8,23,59,57,51,44,59]], [32, [28,14,24,25,2,20,1,26], [4,3,1,11,25,22,2,4]], [57, [1,7,42,26,45,14], [37,49,42,26,4,11]], [88, [25,60,49,4], [65,46,85,34]], [9, [2,1,1,4,1,7,3,4,3,7,3,1,3,5,6,7], [1,1,1,1,4,1,2,1,7,1,1,1,1,1,1,2]], [70, [40], [38]], );
my @input_checks = ( "YES", "NO", "NO", "NO", "YES", "NO", "NO", "YES", "NO", "NO", "YES", "NO", "YES", );
assert (scalar(@input_values) == scalar(@input_checks));

for (my $i = 0; $i < scalar(@input_values); ++$i) {
	my $k = $input_values[$i]->[0];
	my @A = @{$input_values[$i]->[1]};
	my @B = @{$input_values[$i]->[2]};
	say "k=($k), A=(@A), B=(@B)";

	my $check = $input_checks[$i];

	my $result = twoArrays $k, \@A, \@B;
	say "result=($result)";

	assert ($result eq $check);
	say "";
}



