/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize,
                int* returnSize, int** returnColumnSizes)
{
    int i, j;
    int rows = matrixSize;
    int cols = matrixColSize[0];

    // Transposed matrix has 'cols' rows
    *returnSize = cols;

    // Each row of transpose has 'rows' elements
    *returnColumnSizes = malloc(cols * sizeof(int));

    // Allocate memory for rows
    int **result = malloc(cols * sizeof(int *));

    for (i = 0; i < cols; i++)
    {
        (*returnColumnSizes)[i] = rows;

        result[i] = malloc(rows * sizeof(int));

        for (j = 0; j < rows; j++)
        {
            result[i][j] = matrix[j][i];
        }
    }

    return result;
}