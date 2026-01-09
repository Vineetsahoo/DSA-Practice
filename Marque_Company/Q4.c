#include <stdio.h>

int h, w;
int grid[25][65];
int dp[25][65];
int parent[25][65];

int main() {
    scanf("%d %d", &h, &w);

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            scanf("%1d", &grid[i][j]);
            dp[i][j] = 1e9;
        }

    for (int j = 0; j < w; j++)
        dp[0][j] = grid[0][j];

    for (int i = 1; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int best = dp[i-1][j];
            parent[i][j] = j;

            if (j > 0 && dp[i-1][j-1] < best) {
                best = dp[i-1][j-1];
                parent[i][j] = j - 1;
            }
            if (j + 1 < w && dp[i-1][j+1] < best) {
                best = dp[i-1][j+1];
                parent[i][j] = j + 1;
            }

            dp[i][j] = best + grid[i][j];
        }
    }

    int col = 0;
    for (int j = 1; j < w; j++)
        if (dp[h-1][j] < dp[h-1][col])
            col = j;

    for (int i = h - 1; i >= 0; i--) {
        grid[i][col] = -1;
        col = parent[i][col];
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == -1) printf(" ");
            else printf("%d", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}
