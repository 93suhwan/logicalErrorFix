#include <bits/stdc++.h>
using namespace std;
long long row[200010], col[200010], ans, n;
int x[200010], y[200010], visx[200010], visy[200010];
int main() {
  int T, i, j, k;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &x[i], &y[i]);
    row[x[i]]++;
    col[y[i]]++;
  }
  long long sum = 0;
  for (i = 1; i <= n; i++)
    for (j = i + 1; j <= n; j++)
      for (k = j + 1; k <= n; k++) {
        if (x[i] != x[j] && x[j] != x[k] && x[i] != x[k])
          sum++;
        else if (y[i] != y[j] && y[j] != y[k] && y[i] != y[k])
          sum++;
      }
  cout << sum << endl;
}
