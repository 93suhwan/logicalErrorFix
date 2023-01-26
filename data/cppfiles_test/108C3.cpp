#include <bits/stdc++.h>
using namespace std;
long long i, j, p, q, n, m, t, k, ans;
bool b[100006];
struct Pic {
  long long first, second, ind;
} a[100006];
bool fff(Pic a, Pic b) { return (a.first < b.first); }
bool fff1(Pic a, Pic b) { return (a.second < b.second); }
vector<int> v[100006];
void dfs(int u) {
  b[u] = 1;
  for (auto i : v[u]) {
    if (!b[i]) dfs(i);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n;
    fill(b + 1, b + n + 1, 0);
    p = 0;
    ans = 0;
    for (i = 1; i <= n; i++) {
      cin >> a[i].first;
      a[i].ind = i;
      v[i].clear();
    }
    for (i = 1; i <= n; i++) cin >> a[i].second;
    sort(a + 1, a + n + 1, fff);
    p = a[n].ind;
    for (i = n; i > 1; i--) {
      v[a[i - 1].ind].push_back(a[i].ind);
    }
    sort(a + 1, a + n + 1, fff1);
    q = a[n].ind;
    for (i = n; i > 1; i--) {
      v[a[i - 1].ind].push_back(a[i].ind);
    }
    dfs(p);
    dfs(q);
    for (i = 1; i <= n; i++) cout << b[i];
    cout << endl;
  }
  return 0;
}
