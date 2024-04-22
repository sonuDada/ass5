#include <stdio.h>
void bankers_algorithm(int n, int m, int alloc[n][m], int max[n][m], int avail[m])
{
    int f[n], ans[n], ind = 0;
    for (int k = 0; k < n; k++)
    {
        f[k] = 0;
    }
    int need[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    int y = 0;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                    {
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (f[i] == 0)
        {
            flag = 0;
            printf("\nThe following system is not safe\n");
            return;
        }
    }
    printf("\nFollowing is the SAFE Sequence\n");
    for (int i = 0; i < n - 1; i++)
    {
        printf("P%d -> ", ans[i]);
    }
    printf("P%d\n", ans[n - 1]);
}
int main()
{
    int n, m;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    int alloc[n][m], max[n][m], avail[m];
    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < n; i++)
    {
        printf("For Process %d: ", i);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter the maximum required resources matrix:\n");
    for (int i = 0; i < n; i++)
    {
        printf("For Process %d: ", i);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the available resources:\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
    }
    bankers_algorithm(n, m, alloc, max, avail);
    return 0;
}