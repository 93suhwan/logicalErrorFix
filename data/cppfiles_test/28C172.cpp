#include <bits/stdc++.h>
using namespace std;
int n, a[500005], val[500005], b[500005], pos[500005];
vector<int> ans;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int tc, m;
  cin >> tc;
  while (tc--) {
    ans.clear();
    cin >> n >> m;
    for (int i = 0; i < n; i++) val[i] = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      int ip = (i + 1 - a[i] + n) % n;
      val[ip]++;
    }
    for (int i = 0; i < n; i++) {
      if (val[i] < n - 2 * m) continue;
      cerr << i << endl;
      for (int j = n - i; j < n; j++) b[j - (n - i)] = j + 1;
      for (int j = 0; j < n - i; j++) b[j + i] = j + 1;
      for (int j = 0; j < n; j++) pos[b[j]] = j;
      int rlt = 0;
      for (int j = 0; j < n; j++)
        if (a[j] != b[j]) {
          int id = pos[a[j]];
          rlt++;
          pos[b[j]] = id;
          swap(b[j], b[id]);
        }
      if (rlt <= m) ans.push_back(i);
    }
    cout << ans.size();
    for (auto v : ans) cout << " " << v;
    cout << endl;
  }
  return 0;
}
