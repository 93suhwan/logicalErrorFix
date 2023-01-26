#include <bits/stdc++.h>
using namespace std;
int t, n, a[50006][5];
int main() {
  for (scanf("%d", &t); t--;) {
    scanf("%d", &n);
    int m = n;
    for (int i = 0; i < n; i++)
      scanf("%d%d%d%d%d", a[i], a[i] + 1, a[i] + 2, a[i] + 3, a[i] + 4);
    vector<int> v;
    for (int i = 0; i < n; i++) v.push_back(i);
    while (n > 1) {
      for (int i = 0; i < n; i += 2) {
        int cnt1 = 0, cnt2 = 0;
        for (int j = 0; j < 5; j++) {
          if (a[v[i]][j] < a[v[i + 1]][j])
            cnt1++;
          else if (a[v[i]][j] > a[v[i + 1]][j])
            cnt2++;
        }
        for (int j = 0; j < 5; j++) {
          if (cnt1 > cnt2)
            v[i / 2] = v[i];
          else
            v[i / 2] = v[i + 1];
        }
      }
      if (n % 2) v[n / 2] = v[n - 1];
      n = (n + 1) / 2;
    }
    for (int i = 0; i < m; i++)
      if (i != v[0]) {
        int cnt = 0;
        for (int j = 0; j < 5; j++)
          if (a[i][j] > a[v[0]][j]) cnt++;
        if (cnt < 3) {
          puts("-1");
          goto next;
        }
      }
    printf("%d\n", v[0] + 1);
  next:;
  }
}
