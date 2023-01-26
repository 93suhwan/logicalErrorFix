#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
const int mod = 1e9 + 7;
int t, n, k, a[MAX], s[MAX];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  int x = n;
  n *= k;
  int cap = (x + k - 2) / (k - 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector<int> sol1(x), sol2(x);
  for (int i = x + 1; i <= n; i++) {
    int top = s[i];
    int pos = 0;
    if (sol1[a[i] - 1]) continue;
    for (int j = i - 1; j >= 1; j--) {
      top = max(top, s[j]);
      if (top > cap) break;
      if (a[i] == a[j]) {
        pos = j;
        break;
      }
    }
    if (pos) {
      sol1[a[i] - 1] = pos;
      sol2[a[i] - 1] = i;
      for (int j = pos; j <= i; j++) s[j]++;
    }
  }
  for (int i = 0; i < x; i++) {
    assert(sol1[i]);
    assert(sol2[i]);
    cout << sol1[i] << ' ' << sol2[i] << '\n';
  }
}
