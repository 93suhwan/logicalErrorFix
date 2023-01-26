#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e9;
int n, m;
int fwt[6][200005];
char p[6][4] = {"abc", "acb", "bac", "bca", "cab", "cba"};
string s;
void update(int ord, int a, int k) {
  while (a <= n) {
    fwt[ord][a] += k;
    a += a & -a;
  }
}
int query(int ord, int a, int b) {
  int sum = 0;
  while (a) {
    sum -= fwt[ord][a];
    a -= a & -a;
  }
  while (b) {
    sum += fwt[ord][b];
    b -= b & -b;
  }
  return sum;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> s;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 6; j++) {
      if (s[i] != p[j][i % 3]) {
        update(j, i + 1, 1);
      }
    }
  }
  while (m--) {
    int ans = MAX;
    int l, r;
    cin >> l >> r;
    for (int i = 0; i < 6; i++) ans = min(ans, query(i, l - 1, r));
    cout << ans << '\n';
  }
}
