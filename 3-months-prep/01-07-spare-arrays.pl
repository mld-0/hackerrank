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


sub matchingStrings {
	my @strings = @{$_[0]};
	my @queries = @{$_[1]};
	my @result;
	my %strings_counter;
	foreach (@strings) {
		$strings_counter{$_} += 1;  # an unintialized hash element is 0
	}
	for (my $i = 0; $i < scalar(@queries); ++$i) {
		my $loop_query = $queries[$i];
		if (exists $strings_counter{$loop_query}) {
			$result[$i] = $strings_counter{$loop_query};
		} else {
			$result[$i] = 0;
		}
	}
	return @result;
}


my @input_values = ( "4\naba\nbaba\naba\nxzxb\n3\naba\nxzxb\nab\n", "3\ndef\nde\nfgh\n3\nde\nlmn\nfgh", "13\nabcde\nsdaklfj\nasdjf\nna\nbasdn\nsdaklfj\nasdjf\nna\nasdjf\nna\nbasdn\nsdaklfj\nasdjf\n5\nabcde\nsdaklfj\nasdjf\nna\nbasdn\n", );
my @input_checks = ( "2\n1\n0\n", "1\n0\n1\n", "1\n3\n4\n3\n2\n", );
assert (scalar(@input_values) == scalar(@input_checks));

for (my $i = 0; $i < scalar(@input_values); ++$i) {
	my $input_str = $input_values[$i];
	my $check_str = $input_checks[$i];

	my @check = split '\n', $check_str;

	my @input_str_split = split '\n', $input_str;
	my $strings_count = $input_str_split[0];
	my @strings = @input_str_split[1..$strings_count];
	my $queries_count = $input_str_split[$strings_count+1];
	my @queries = @input_str_split[$strings_count+2..$strings_count+1+$queries_count];

	say "strings_count=($strings_count)";
	say "strings=(@strings)";
	say "queries_count=($queries_count)";
	say "queries=(@queries)";

	say "check=(@check)";

	my @result = matchingStrings \@strings, \@queries;
	say "result=(@result)";

	assert ("@result" eq "@check");
	say "";
}

