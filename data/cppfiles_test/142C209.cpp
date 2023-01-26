#include <bits/stdc++.h>
using namespace std;
const int modmx = 1e9 + 7;
const long long neutral = NULL;
const vector<int> tree_const(0);
const int maxn = 1e5 + 1;
string sum_longArithmetician(string a, string b) {
  if (a.size() > b.size()) swap(a, b);
  int n = a.size();
  vector<int> a1(a.size());
  for (int i = a.size() - 1; i >= 0; i--) {
    a1[a.size() - 1 - i] = a[i] - '0';
  }
  vector<int> b1(b.size());
  for (int i = b.size() - 1; i >= 0; i--) {
    b1[b.size() - 1 - i] = b[i] - '0';
  }
  int c = 0;
  for (int i = 0; i < n; i++) {
    int x;
    x = a1[i] + b1[i] + c;
    c = x / 10;
    b1[i] = x % 10;
  }
  if (c > 0) {
    for (int i = n; i < b1.size(); i++) {
      int x = b1[i] + c;
      b1[i] = x % 10;
      c = x / 10;
    }
    if (c > 0) b1.push_back(c);
  }
  string ans = "";
  for (int i = b1.size() - 1; i >= 0; i--) ans += char(b1[i] + '0');
  return ans;
}
int n, m;
vector<vector<int> > a;
bool check(int x) {
  vector<bool> b(m);
  bool para = false;
  for (int i = 0; i < n; i++) {
    int c = 0;
    for (int j = 0; j < m; j++) {
      if (a[i][j] >= x) {
        c++;
        b[j] = true;
      }
    }
    if (c > 1) para = true;
  }
  if (!para && m > 1) return false;
  bool ans = true;
  for (bool f : b) {
    ans = ans && f;
  }
  return ans;
}
void solve() {
  cin >> n >> m;
  a.assign(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  int l = 1, r = 2;
  while (check(r)) r *= 2;
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  cout << l << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
