int expand(char *s, int left, int right)
{
    int count = 0;

    while (left >= 0 && s[right] != '\0' &&
           s[left] == s[right])
    {
        count++;
        left--;
        right++;
    }

    return count;
}

int countSubstrings(char* s)
{
    int i;
    int count = 0;

    for (i = 0; s[i] != '\0'; i++)
    {
        // Odd-length palindromes
        count += expand(s, i, i);

        // Even-length palindromes
        count += expand(s, i, i + 1);
    }

    return count;
}