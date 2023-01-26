#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10, maxm = 1e6 + 10, mod = 998244353, inf = 0x3f3f3f3f;
const double pi = acos(-1), eps = 1e-7;
int n, m;
string s[maxn];
map<string, int> mp;
bool cmp(string a, string b) {
  for (int i = 0; i < m; i++) {
    if (a[i] == b[i]) continue;
    if (i & 1)
      return a[i] > b[i];
    else
      return a[i] < b[i];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    mp[s[i]] = i;
  }
  sort(s + 1, s + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
    cout << mp[s[i]] << " ";
  }
  cout << "\n";
  return 0;
}
