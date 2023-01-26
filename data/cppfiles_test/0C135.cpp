#include <bits/stdc++.h>
using namespace std;
int n, m, o[1000555];
string s[1000555];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> s[i], o[i] = i;
  random_shuffle(o + 1, o + 1 + n);
  sort(o + 1, o + 1 + n, [&](int p, int q) {
    for (int j = 0; j < m; ++j) {
      if (s[p][j] != s[q][j]) return (s[p][j] < s[q][j]) ^ (j & 1);
    }
    return 0;
  });
  for (int i = 1; i <= n; ++i) printf("%d ", o[i]);
}
