#include <bits/stdc++.h>
using namespace std;
int n, m;
int adj[100][100];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int n1, n2;
    scanf("%d%d", &n1, &n2);
    n1--;
    n2--;
    if (n1 < 100 && n2 < 100) {
      adj[n1][n2] = 1;
      adj[n2][n1] = 1;
    }
  }
  n = min(n, 100);
  for (int a = 0; a < n; a++) {
    for (int b = a + 1; b < n; b++) {
      for (int c = b + 1; c < n; c++) {
        for (int d = c + 1; d < n; d++) {
          for (int e = d + 1; e < n; e++) {
            vector<int> v = {a, b, c, d, e};
            int tot = 0;
            for (int i : v)
              for (int j : v) tot += adj[i][j];
            if (tot == 0 || tot == 25) {
              for (int i : v) printf("%d ", i + 1);
              printf("\n");
              return 0;
            }
          }
        }
      }
    }
  }
  printf("-1\n");
}
