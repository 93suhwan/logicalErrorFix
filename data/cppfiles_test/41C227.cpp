#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9 + 3;
char str[200005];
int cnt[200005][3][3], cur[3], cur2[3], ans, pr, n, m;
vector<int> v = {0, 1, 2};
void cm(int num) {
  cur[0] = num / 3 + ((num % 3) >= 0);
  cur[1] = num / 3 + ((num % 3) >= 1);
  cur[2] = num / 3 + ((num % 3) >= 2);
  return;
}
int main() {
  int i, j, k, a, b;
  scanf("%d %d", &n, &m);
  scanf("%s", str);
  cnt[0][0][str[0] - 'a']++;
  for (i = 1; i < n; i++) {
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 3; k++) {
        cnt[i][j][k] = cnt[i - 1][j][k];
      }
    }
    cnt[i][i % 3][str[i] - 'a']++;
  }
  for (i = 1; i <= m; i++) {
    scanf("%d %d", &a, &b);
    --a;
    --b;
    cm(b - a);
    pr = inf;
    do {
      ans = 0;
      for (j = 0; j < 3; j++) {
        if (a == 0)
          ans += cur[j] - (cnt[b][(a + j) % 3][v[j]]);
        else
          ans += cur[j] -
                 (cnt[b][(a + j) % 3][v[j]] - cnt[a - 1][(a + j) % 3][v[j]]);
      }
      pr = min(ans, pr);
    } while (next_permutation(v.begin(), v.end()));
    cout << pr << "\n";
  }
  return 0;
}
