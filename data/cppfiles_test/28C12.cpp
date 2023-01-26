#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
long long GCD(long long a, long long b) { return (a) ? GCD(b % a, a) : b; }
long long LCM(long long a, long long b) { return a * b / GCD(a, b); }
long long fastpow(long long b, long long p) {
  if (!p) return 1;
  long long ret = fastpow(b, p >> 1);
  ret *= ret;
  if (p & 1) ret *= b;
  return ret;
}
int n, m;
int a[300005];
void solve() {
  cin >> n >> m;
  unordered_map<int, int> mp;
  int x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[(i - a[i] + n) % n]++;
  }
  vector<int> ans;
  for (int k = 0; k < n; k++) {
    if (n - mp[k] > m * 2) continue;
    vector<int> vec(n + 1, 0);
    int s, cur, mm = 0, temp;
    for (int i = 1; i <= n; i++) {
      if (a[(i + k - 1) % n + 1] == i) vec[i] = 1;
      if (vec[i]) continue;
      s = i;
      cur = s;
      temp = (cur + k - 1) % n + 1;
      while (a[temp] != s)
        vec[cur] = 1, cur = a[temp], temp = (cur + k - 1) % n + 1;
      mm++;
      vec[cur] = 1;
    }
    if (n - mp[k] - mm <= m) ans.push_back(k);
  }
  cout << ans.size() << ' ';
  for (auto xx : ans) cout << xx << ' ';
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int TT = 1;
  cin >> TT;
  for (int tc = 1; tc <= TT; tc++) {
    solve();
  }
}
