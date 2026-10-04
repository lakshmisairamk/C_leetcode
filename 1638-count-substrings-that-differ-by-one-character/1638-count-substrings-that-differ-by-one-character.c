int countSubstrings(char* s, char* t)
{
    int count = 0;

    int n = 0;
    int m = 0;

    while (s[n] != '\0')
        n++;

    while (t[m] != '\0')
        m++;

    // Choose starting position in s
    for (int i = 0; i < n; i++)
    {
        // Choose starting position in t
        for (int j = 0; j < m; j++)
        {
            int diff = 0;

            // Compare characters while both strings continue
            for (int k = 0;
                 i + k < n && j + k < m;
                 k++)
            {
                if (s[i + k] != t[j + k])
                    diff++;

                // Exactly one difference
                if (diff == 1)
                    count++;

                // More than one difference is invalid
                if (diff > 1)
                    break;
            }
        }
    }

    return count;
}