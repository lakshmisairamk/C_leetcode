int findTheWinner(int n, int k)
{
    // Base case
    if (n == 1)
        return 1;

    // Recursive Josephus formula
    return (findTheWinner(n - 1, k) + k - 1) % n + 1;
}