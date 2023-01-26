#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template <typename T>
using vc = vector<T>;
template <typename T>
using vvc = vc<vc<T>>;
template <typename T>
void smax(T& a, T b) {
  a = max(a, b);
}
template <typename T>
void smin(T& a, T b) {
  a = min(a, b);
}
void solve() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  int l = 0, r = 0;
  int brojac = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      brojac += 2;
    }
  }
  int index = n;
  for (int i = 0; i < n; i++)
    if (s[i] == t[i]) {
      index = i;
      break;
    }
  l = index;
  for (int i = index; i < n; i++) {
    if (s[i] != t[i]) {
      r = i;
      int br = 0;
      if (s[l] == '1') {
        for (int i = l; i < r; i++) {
          if (s[i] == '0') {
            if (i < r - 1 && s[i + 1] == '0')
              br++;
            else if (i == r - 1)
              br++;
            break;
          }
        }
      }
      for (int i = l; i < r; i++) {
        if (s[i] == '0')
          br++;
        else if (i > l && s[i - 1] == '0')
          br++;
      }
      brojac += br;
      l = i + 1;
    }
  }
  r = n;
  int br = 0;
  if (s[l] == '1') {
    for (int i = l; i < r; i++) {
      if (s[i] == '0') {
        if (i < r - 1 && s[i + 1] == '0')
          br++;
        else if (i == r - 1)
          br++;
        break;
      }
    }
  }
  for (int i = l; i < r; i++) {
    if (s[i] == '0')
      br++;
    else if (i > l && s[i - 1] == '0')
      br++;
  }
  brojac += br;
  cout << brojac << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
