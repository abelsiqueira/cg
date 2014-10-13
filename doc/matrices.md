# Matrix formats

We can read matrices using the Triplet format, but internally we use the
Compressed Sparse Column format.

## Triplet format

We simply store all nonzero elements of the matrix, along with the row and
column indexes. No order is expected.

## Compressed Sparse Column

This format stores the nonzero elements of the matrix by columns, then by rows.
It also stores the row index of each element, and the index of start of a new
column in these arrays. Note that we store the indexes starting in 0.

As an example, consider the matrix

        0 1 0 0 3
    A = 7 0 2 0 9
        4 6 0 0 5

The arrays stored are

    A  = [7, 4, 1, 6, 2, 3, 9, 5]
    Ai = [1, 2, 0, 2, 1, 0, 1, 2]
    Ap = [0, 2, 4, 5, 5, 8]

## Compressed Sparse Column for symmetric matrices

If a matrix is symmetric, we do not store every element of it. Rather, we store
only the lower diagonal elements. As such, for the matrix

        1 0 2
    A = 0 3 5
        2 5 0

the stored arrays are

    A  = [1, 2, 3, 5]
    Ai = [0, 2, 1, 2]
    Ap = [0, 2, 4]
