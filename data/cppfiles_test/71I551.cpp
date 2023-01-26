#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
void solve() {
  long long n;
  long long k;
  cin >> n >> k;
  if (n == 1000000000) {
    if (k == 1) {
      for (int i = 1; i <= 9; ++i) {
        cout << 1;
      }
    } else {
      cout << n;
    }
    cout << endl;
    return;
  }
  long long f;
  long long p = n;
  string s;
  while (p) {
    s += p % 10 + '0';
    p /= 10;
  }
  reverse(s.begin(), s.end());
  f = s[0] - '0';
  if (k == 1) {
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] - '0' > f) {
        f++;
        break;
      }
      if (s[i] - '0' < f) {
        break;
      }
    }
  }
  if (k == 1) {
    for (int i = 1; i <= s.size(); ++i) {
      cout << f;
    }
    cout << endl;
  }
  if (k == 2) {
    long long v = 1;
    while (v < s.size() && s[v] == s[0]) {
      v++;
    }
    bool can = 1;
    for (int m = v + 1; m < s.size(); ++m) {
      if (s[m] > s[v] && s[m] > s[0]) {
        can = 0;
        break;
      } else if (s[m] < s[v] || s[m] < s[0]) {
        break;
      }
    }
    if (can == 1) {
      long long sec = s[v] - '0';
      long long p = 0;
      while (p < s.size()) {
        if (min(f, sec) > s[p] - '0') {
          cout << min(f, sec);
          break;
        }
        if (min(f, sec) == s[p] - '0') {
          cout << min(f, sec);
          p++;
          continue;
        }
        if (max(f, sec) > s[p] - '0') {
          cout << max(f, sec);
          break;
        }
        if (max(f, sec) == s[p] - '0') {
          cout << max(f, sec);
        }
        p++;
      }
      while (p < s.size()) {
        cout << min(f, sec);
        p++;
      }
      cout << endl;
    } else {
      long long sec = s[v] - '0' + 1;
      for (int i = 0; i < v; ++i) {
        cout << f;
      }
      cout << sec;
      for (int i = v + 1; i < s.size(); ++i) {
        cout << min(f, sec);
      }
      cout << endl;
    }
  }
  return;
}
int main() {
  fast();
  long long k = 1;
  cin >> k;
  while (k--) {
    solve();
  }
  return 0;
}
