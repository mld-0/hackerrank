
magic_squares = [ 
    [[8,1,6],[3,5,7],[4,9,2]],
    [[6,1,8],[7,5,3],[2,9,4]], 
    [[4,9,2],[3,5,7],[8,1,6]],
    [[2,9,4],[7,5,3],[6,1,8]],
    [[8,3,4],[1,5,9],[6,7,2]],
    [[4,3,8],[9,5,1],[2,7,6]],
    [[6,7,2],[1,5,9],[8,3,4]],
    [[2,7,6],[9,5,1],[4,3,8]],
]

def is_magic_square(square):
    expected = 15
    for row in range(len(square)):
        total = 0
        for col in range(len(square[0])):
            total += square[row][col]
        if total != expected:
            return False
    for col in range(len(square[0])):
        total = 0
        for row in range(len(square)):
            total += square[row][col]
        if total != expected:
            return False
    return True


def square_transform_cost(square_to, square_from):
    assert len(square_to) == len(square_from), "Dimensions mismatch"
    assert len(square_to[0]) == len(square_from[0]), "Dimensions mismatch"

    rows = len(square_to)
    cols = len(square_to[0])

    distance = 0
    for row in range(rows):
        for col in range(cols):
            distance += abs(square_to[row][col] - square_from[row][col])

    return distance
            


for square in magic_squares:
    result = is_magic_square(square)
    print(result)
print()

input_square = [[4,9,2],[3,5,7],[8,1,5]]

for square in magic_squares:
    distance = square_transform_cost(square, input_square)
    print(distance)
print()

