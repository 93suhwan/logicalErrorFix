#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long pow(long long x, long long power) {
  if (power == 0) return 1;
  long long r = pow(x, power / 2);
  if (power & 1) return r * r * x;
  return r * r;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  map<int, bool> mp;
  mp[2] = mp[3] = mp[5] = mp[7] = 1;
  vector<vector<int>> v(8);
  v[2] = {2, 5, 7};
  v[3] = {2, 3, 5};
  v[5] = {2, 7, 5};
  v[7] = {2, 5, 7};
  vector<int> it = {2, 3, 5, 7};
  while (t--) {
    vector<pair<int, int>> vec(10, {-1, -1});
    int k;
    cin >> k;
    string s;
    cin >> s;
    int b = 0;
    for (int i = 0; i < k; i++) {
      if (!mp[s[i] - '0']) {
        b = s[i] - '0';
        break;
      }
      if (!(~vec[s[i] - '0'].first)) vec[s[i] - '0'].first = i;
      vec[s[i] - '0'].second = i;
    }
    if (b) {
      cout << "1\n" << b << '\n';
      continue;
    }
    int f = 0, l = 0;
    for (int i = 0; i < 4; i++) {
      int n = v[it[i]].size();
      if (~vec[it[i]].first) {
        for (int j = 0; j < n; j++) {
          if (vec[it[i]].first < vec[v[it[i]][j]].second) {
            f = it[i];
            l = v[it[i]][j];
            b = 1;
            break;
          }
        }
      }
      if (b) break;
    }
    cout << "2\n" << f << l << '\n';
  }
  return 0;
}
