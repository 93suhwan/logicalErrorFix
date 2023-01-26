#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
int T;
int n;
int a[2055];
vector<int> ans;
void work(int m) {
  if (a[m] == m && a[m - 1] == m - 1) {
    return;
  }
  if (a[1] != m) {
    int p = 1;
    while (a[p] != m) p += 2;
    ans.push_back(p);
    reverse(a + 1, a + p + 1);
  }
  if (a[2] != m - 1) {
    int p = 2;
    while (a[p] != m - 1) p += 2;
    ans.push_back(p - 1);
    reverse(a + 1, a + p);
    ans.push_back(p + 1);
    reverse(a + 1, a + p + 2);
    ans.push_back(3);
    reverse(a + 1, a + 3 + 1);
  }
  ans.push_back(m);
  reverse(a + 1, a + m + 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n;
    bool flag = 1;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      if ((a[i] & 1) != (i & 1)) {
        flag = 0;
      }
    }
    if (!flag) {
      cout << -1 << "\n";
      continue;
    }
    ans.clear();
    for (int i = n; i > 1; i -= 2) {
      work(i);
    }
    cout << ans.size() << "\n";
    for (int v : ans) cout << v << " ";
    cout << "\n";
  }
  return 0;
}
