#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k, x;
  cin >> n >> k >> x;
  string s;
  cin >> s;
  s = '?' + s;
  vector<long long> v;
  long long len = 0;
  for (int i = n; i >= 1; i--) {
    if (s[i] != '*') {
      continue;
    }
    if (s[i] == '*' && s[i - 1] == '*') {
      len++;
    } else if (s[i] == '*') {
      len++;
      v.push_back(k * len + 1);
      len = 0;
    }
  }
  vector<long long> v1;
  for (int i = v.size() - 1; i >= 0; i--) {
    v1.push_back(v[i]);
  }
  long long ava = 1000000000000000000;
  if (v1.size() >= 2) {
    for (int i = v1.size() - 2; i >= 0; i--) {
      v1[i] = v1[i] * v1[i + 1];
      if ((ava / v1[i]) < v1[i + 1]) {
        for (int j = i; j >= 0; j--) {
          v1[j] = LLONG_MAX;
        }
        break;
      }
    }
  }
  int z = v1.size();
  v1.push_back(LLONG_MAX);
  vector<long long> ans;
  int i = 0;
  while (i < z) {
    if (i == z - 1) {
      ans.push_back(x);
      break;
    }
    long long q = x / v1[i + 1];
    long long rem = x % v1[i + 1];
    x = rem;
    if (x == 0) {
      x = v1[i + 1];
    }
    if (i != z - 1) ans.push_back(q);
    i++;
  }
  int idx = 0;
  string t;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'a') {
      t += 'a';
      continue;
    }
    if (idx < ans.size()) {
      int req = ans[idx] - 1;
      for (int j = 0; j < req; j++) {
        t += 'b';
      }
      idx++;
    }
    for (int j = i; j <= n; j++) {
      if (s[j] == 'a') {
        i = j - 1;
        break;
      }
    }
  }
  cout << t << "\n";
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
