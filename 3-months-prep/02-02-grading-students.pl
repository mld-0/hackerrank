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

sub roundGrade {
	my $grade = $_[0];
	if ($grade < 38) {
		return $grade;
	}
	my $nearest_multiple_5 = $grade;
	while ($nearest_multiple_5 % 5 != 0) {
		$nearest_multiple_5 += 1;
	}
	if ($nearest_multiple_5 - $grade < 3) {
		return $nearest_multiple_5;
	} else {
		return $grade;
	}
}

sub gradingStudents {
	my @grades = @{$_[0]};
	my @result = map { roundGrade($_) } @grades;
	return @result;
}


my @input_values = ( [73, 67, 38, 33], [37, 38], [80, 96, 18, 73, 78, 60, 60, 15, 45, 15, 10, 5, 46, 87, 33, 60, 14, 71, 65, 2, 5, 97, 0], );
my @input_checks = ( [75, 67, 40, 33], [37, 40], [80, 96, 18, 75, 80, 60, 60, 15, 45, 15, 10, 5, 46, 87, 33, 60, 14, 71, 65, 2, 5, 97, 0], );
assert (scalar(@input_values) == scalar(@input_checks));

for (my $i = 0; $i < scalar(@input_values); ++$i) {
	my @grades = @{$input_values[$i]};
	say "grades=(@grades)";
	my @check = @{$input_checks[$i]};

	my @result = gradingStudents \@grades;
	say "result=(@result)";

	assert ("@result" eq "@check");
	say "";
}

