#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& i : v) os << i << ' ';
  return os;
}
void solve() {
  int n;
  cin >> n;
  vector<string> s(n);
  cin >> s;
  vector<int> a(n), b(n), c(n), d(n), e(n);
  for (int i = 0; i < n; i++) {
    for (auto l : s[i]) {
      switch (l) {
        case 'a':
          a[i]++;
          b[i]--;
          c[i]--;
          d[i]--;
          e[i]--;
          break;
        case 'b':
          b[i]++;
          a[i]--;
          c[i]--;
          d[i]--;
          e[i]--;
          break;
        case 'c':
          c[i]++;
          d[i]--;
          e[i]--;
          b[i]--;
          a[i]--;
          break;
        case 'd':
          d[i]++;
          e[i]--;
          b[i]--;
          a[i]--;
          c[i]--;
          break;
        case 'e':
          e[i]++;
          b[i]--;
          a[i]--;
          c[i]--;
          d[i]--;
          break;
      }
    }
  }
  sort(a.begin(), a.end(), std::greater<int>());
  sort(b.begin(), b.end(), std::greater<int>());
  sort(c.begin(), c.end(), std::greater<int>());
  sort(d.begin(), d.end(), std::greater<int>());
  sort(e.begin(), e.end(), std::greater<int>());
  int total = 0;
  int maxWords = 0;
  for (int i = 0; i < n; i++) {
    total += a[i];
    if (total < 1) {
      maxWords = i;
      break;
    }
  }
  if (total > 0) maxWords = n;
  total = 0;
  for (int i = 0; i < n; i++) {
    total += b[i];
    if (total < 1) {
      if (i > maxWords) {
        maxWords = i;
      }
      break;
    }
  }
  if (total > 0) maxWords = n;
  total = 0;
  for (int i = 0; i < n; i++) {
    total += c[i];
    if (total < 1) {
      if (i > maxWords) {
        maxWords = i;
      }
      break;
    }
  }
  if (total > 0) maxWords = n;
  total = 0;
  for (int i = 0; i < n; i++) {
    total += c[i];
    if (total < 1) {
      if (i > maxWords) {
        maxWords = i;
      }
      break;
    }
  }
  if (total > 0) maxWords = n;
  total = 0;
  for (int i = 0; i < n; i++) {
    total += d[i];
    if (total < 1) {
      if (i > maxWords) {
        maxWords = i;
      }
      break;
    }
  }
  if (total > 0) maxWords = n;
  total = 0;
  for (int i = 0; i < n; i++) {
    total += e[i];
    if (total < 1) {
      if (i > maxWords) {
        maxWords = i;
      }
      break;
    }
  }
  if (total > 0) maxWords = n;
  cout << maxWords << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
