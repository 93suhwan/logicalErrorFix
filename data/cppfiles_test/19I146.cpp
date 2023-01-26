#include <bits/stdc++.h>
using namespace std;
bool dfs(string s, string t, long long ind, long long node) {
  if (ind == t.length() - 1) {
    return true;
  }
  if (node == s.length() - 1) {
    return false;
  }
  for (long long j = 1; j < s.length() - node; j += 2) {
    if (s[node + j] == t[ind + 1] && dfs(s, t, ind + 1, node + j)) {
      return true;
    }
  }
  return false;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> v;
  map<long long, long long> mp;
  long long cnt = 0;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    if (x != 0 && mp[abs(x)] == 0) {
      mp[abs(x)]++;
      cnt++;
    }
    v.push_back(x);
  }
  long long val = (n * (n - 1)) / 2;
  if (cnt < val) {
    cout << "YES" << endl;
    return;
  }
  if (n == 1) {
    if (v[0] == 0) {
      cout << "YES" << endl;
      return;
    }
    cout << "NO" << endl;
    return;
  }
  if (n == 2) {
    if (abs(v[0]) == abs(v[1])) {
      cout << "YES" << endl;
      return;
    }
    cout << "NO" << endl;
    return;
  }
  if (abs(v[0] + v[1]) == abs(v[2]) || abs(v[0] - v[1]) == abs(v[2])) {
    cout << "YES" << endl;
    return;
  }
  if (abs(v[2] + v[1]) == abs(v[0]) || abs(v[2] - v[1]) == abs(v[0])) {
    cout << "YES" << endl;
    return;
  }
  if (abs(v[0] + v[2]) == abs(v[1]) || abs(v[0] - v[2]) == abs(v[1])) {
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
  return;
}
int main() {
  cin.sync_with_stdio(false), cin.tie(NULL);
  long long t;
  cin >> t;
  long long x = 0;
  while (t--) {
    x++;
    solve();
  }
  return 0;
}
