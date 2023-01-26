#include <bits/stdc++.h>
using namespace std;
void debug(vector<int> v) {
  cout << "[] ";
  for (auto x : v) cout << x << " ";
  cout << "\n";
}
int getPrefix(int l, int r, vector<int>& prefix, bool isReverse = false) {
  if (l > r) return 0;
  int ret;
  if (l == 0)
    ret = prefix[r];
  else
    ret = prefix[r] - prefix[l - 1];
  if (isReverse) ret = ret * -1;
  return ret;
}
void solve() {
  int n, Query;
  cin >> n >> Query;
  string s;
  cin >> s;
  vector<int> A(n);
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '+')
      A[i] = 1;
    else
      A[i] = -1;
    if (i & 1) A[i] = A[i] * -1;
  }
  vector<int> prefix(n);
  prefix[0] = A[0];
  for (int i = 1; i < n; i++) prefix[i] = A[i] + prefix[i - 1];
  while (Query--) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if ((b - a + 1) & 1)
      cout << 1 << "\n";
    else {
      int val;
      if (a & 1)
        val = getPrefix(a, b, prefix, true);
      else
        val = getPrefix(a, b, prefix);
      if (val == 0)
        cout << 0 << "\n";
      else
        cout << 2 << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    solve();
  }
  return 0;
}
