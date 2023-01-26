#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
const double Pi = acos(-1);
const long long Mx = 2e5 + 9;
int n, m, q;
int ans, num[200009];
void add(int a, int b) {
  if (a > b) swap(a, b);
  if (num[a] == 0) ans--;
  num[a]++;
}
void del(int a, int b) {
  if (a > b) swap(a, b);
  if (num[a] == 1) ans++;
  num[a]--;
}
int main() {
  cin >> n >> m;
  ans = n;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    add(a, b);
  }
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      add(a, b);
    }
    if (t == 2) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      del(a, b);
    }
    if (t == 3) {
      cout << ans << endl;
    }
  }
}
