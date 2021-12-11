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

sub inputLineSplit {
	my $kind = shift;
	my $s = shift;

	#	Remove trailing parenthesis from method str
	if ($kind eq 'M') {
		$s = substr $s, 0, length($s)-2;
	}
	my @words = ();

	my $loop_word = lc substr($s, 0, 1);

	for (my $i = 1; $i < length($s); ++$i) {
		my $x = substr $s, $i, 1;
		if ($x eq uc $x) {
			push @words, $loop_word;
			$loop_word = lc $x
		} else { 
			$loop_word = "$loop_word$x";
		}
	}
	push @words, $loop_word;

	my $result = join ' ', @words;
	return $result;
}

sub inputLineCombine {
	my $kind = shift;
	my $s = shift;

	my @words = split ' ', $s;

	if ($kind eq 'C') {
		my $temp = uc substr $words[0], 0, 1;
		$temp = $temp . substr $words[0], 1, length($words[0])-1;
		$words[0] = $temp;
	}

	for (my $i = 1; $i < scalar(@words); ++$i) {
		my $temp = uc substr $words[$i], 0, 1;
		$temp = $temp . substr $words[$i], 1, length($words[$i])-1;
		$words[$i] = $temp;
	}

	my $result = join '', @words;
	if ($kind eq 'M') {
		$result = $result . "()";
	}

	return $result;
}

my @input_values = ( "S;V;iPad\nC;M;mouse pad\nC;C;code swarm\nS;C;OrangeHighlighter\n", "C;V;can of coke\nS;M;sweatTea()\nS;V;epsonPrinter\nC;M;santa claus\nC;C;mirror\n", );
my @input_checks = ( "i pad\nmousePad()\nCodeSwarm\norange highlighter\n", "canOfCoke\nsweat tea\nepson printer\nsantaClaus()\nMirror\n", );
assert (scalar(@input_values) == scalar(@input_checks));


sub main {
	my $fh = shift;
	foreach my $input_line (<$fh>) {
		my @input_line_split = split ';', rtrim($input_line);
		my $op = $input_line_split[0];
		my $kind = $input_line_split[1];
		my $s = $input_line_split[2];
		my $result;
		if ($op eq 'S') {
			$result = inputLineSplit($kind, $s);
		} else {
			$result = inputLineCombine($kind, $s);
		}
		say $result;
	}
}

for (my $i = 0; $i < scalar(@input_values); ++$i) {
	my $input_str = $input_values[$i];
	my $check_str = $input_checks[$i];

	open my $fh, '<', \$input_str;
	my $result = capture_stdout { main($fh) };
	close $fh;

	say "result=($result)";
	assert ($result eq $check_str);
	say "";
}

