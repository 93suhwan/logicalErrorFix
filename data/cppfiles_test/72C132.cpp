#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkMax(T &first, T second) {
  if (second > first) first = second;
}
template <typename T>
void chkMin(T &first, T second) {
  if (second < first) first = second;
}
template <typename T>
inline void read(T &f) {
  f = 0;
  T fu = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') {
      fu = -1;
    }
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    f = (f << 3) + (f << 1) + (c & 15);
    c = getchar();
  }
  f *= fu;
}
const int MAX_N = 2e5 + 10, MAX_M = 1e6 + 10;
bool ok(string first, int k) {
  sort(first.begin(), first.end());
  int d = unique(first.begin(), first.end()) - first.begin();
  return d <= k;
}
void solve() {
  string n;
  int k;
  cin >> n >> k;
  if (ok(n, k)) {
    cout << n << '\n';
    return;
  }
  for (int i = n.size() - 1; i >= 0; i--) {
    for (n[i]++; n[i] <= '9'; n[i]++) {
      for (char j = '0'; j <= '9'; j++) {
        for (int k = i + 1; k < n.size(); k++) {
          n[k] = j;
        }
        if (ok(n, k)) {
          cout << n << '\n';
          goto nex;
        }
      }
    }
  }
nex:;
  return;
}
int main() {
  int T = 1;
  read(T);
  while (T--) {
    solve();
  }
  return 0;
}
