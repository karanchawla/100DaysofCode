import unittest

def zero_matrix(matrix):

    m, n = len(matrix), len(matrix[0])
    rows = []
    cols = []
    for i in range(m):
        for j in range(n):
            if(matrix[i][j]==0):
                rows.append(i)
                cols.append(j)

    for row in rows:
        nullify_row(matrix, row)

    for col in cols:
        nullify_col(matrix, col)

    return matrix

def nullify_row(matrix, row):
    for x in range(len(matrix[0])):
        matrix[row][x] =0

def nullify_col(matrix, col):
    for x in range(len(matrix)):
        matrix[x][col] = 0


class Test(unittest.TestCase):

    data = [
        ([
            [1, 2, 3, 4, 0],
            [6, 0, 8, 9, 10],
            [11, 12, 13, 14, 15],
            [16, 0, 18, 19, 20],
            [21, 22, 23, 24, 25]
        ], [
            [0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0],
            [11, 0, 13, 14, 0],
            [0, 0, 0, 0, 0],
            [21, 0, 23, 24, 0]
        ])
    ]

    def test_zero_matrix(self):
        for test_matrix, solution in self.data:
            result = zero_matrix(test_matrix)
            self.assertEqual(result, solution)

if __name__=="__main__":
    unittest.main()
