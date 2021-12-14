from typing import List

def gridChallenge(grid: List[str]) -> str:
    #   Sort letters in each row
    grid = [ ''.join(sorted(x)) for x in grid ]
    #   Convert list-of-strings to list-of-lists-of-chars
    grid_letters = [ list(x) for x in grid ]
    #   Transpose list-of-lists-of-chars
    grid_letters_T = list(zip(*grid_letters))
    #   Convert list-of-lists-of-chars to list-of-strings
    grid_T = [ ''.join(x) for x in grid_letters_T ]
    #   Sort letters of each row
    grid_T_sorted = [ ''.join(sorted(x)) for x in grid_T ]
    #   Was grid_T already sorted row-wise (equivalent to was grid already sorted column-wise)
    if grid_T == grid_T_sorted:
        return "YES"
    return "NO"


input_values = [ ["eabcd", "fghij", "olkmn", "trpqs", "xywuv"], ["abc", "lmp", "qrt"], ["mpxz", "abcd", "wlmf"], ["abc", "hjk", "mpq", "rtv"], ]
input_checks = [ "YES", "YES", "NO", "YES", ]
assert (len(input_values) == len(input_checks)), "Check comparison failed"

for grid, check in zip(input_values, input_checks):
    print("grid=(%s)" % grid)
    result = gridChallenge(grid)
    print("result=(%s)" % result)
    assert (result == check), "Check comparison failed"
    print()

