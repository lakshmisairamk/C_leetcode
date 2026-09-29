/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) 
{
    int **result;
    int i, j;

    // Number of rows
    *returnSize = numRows;

    // Allocate memory for row sizes
    *returnColumnSizes = malloc(numRows * sizeof(int));

    // Allocate memory for the rows
    result = malloc(numRows * sizeof(int *));

    for (i = 0; i < numRows; i++)
    {
        // Row i has i + 1 elements
        (*returnColumnSizes)[i] = i + 1;

        result[i] = malloc((i + 1) * sizeof(int));

        for (j = 0; j <= i; j++)
        {
            // First and last elements are always 1
            if (j == 0 || j == i)
            {
                result[i][j] = 1;
            }
            else
            {
                // Add two numbers directly above
                result[i][j] =
                    result[i - 1][j - 1] +
                    result[i - 1][j];
            }
        }
    }

    return result;
}