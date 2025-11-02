#include <stdio.h>
#define MAX 10

int n;
int graph[MAX][MAX];
int color[MAX];

int isSafe(int v, int c) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && color[i] == c)
            return 0;
    }
    return 1;
}

int graphColoring(int v, int m) {
    if (v == n)
        return 1;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            color[v] = c;

            if (graphColoring(v + 1, m))
                return 1;

            color[v] = 0;  // backtrack
        }
    }
    return 0;
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int m;
    for (m = 1; m <= n; m++) {
        for (int i = 0; i < n; i++)
            color[i] = 0;

        if (graphColoring(0, m)) {
            printf("\nSolution found with %d colors:\n", m);
            for (int i = 0; i < n; i++)
                printf("Vertex %d --> Color %d\n", i + 1, color[i]);
            return 0;
        }
    }

    printf("\nNo solution possible (this should never happen for a connected graph)\n");
    return 0;
}
