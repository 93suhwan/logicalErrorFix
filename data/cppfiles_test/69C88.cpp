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
long long a[MAX_N];
vector<int> num[60];
bool st[60];
void init() {
  a[0] = 1;
  for (int i = 1; i <= (int)(60); i++) {
    a[i] = a[i - 1] * 2;
  }
  for (int i = 0; i <= (int)(60); i++) {
    long long t = a[i];
    while (t) {
      num[i].push_back(t % 10);
      t /= 10;
    }
    reverse(num[i].begin(), num[i].end());
  }
}
void solve() {
  string s;
  cin >> s;
  long long ans = 1e18;
  vector<int> v;
  for (int i = 0; i <= (int)(s.size() - 1); i++) {
    v.push_back(s[i] - '0');
  }
  for (int i = 0; i <= (int)(59); i++) {
    memset(st, 0, sizeof st);
    long long cnt = 0, last = 0;
    int l1 = 0, l2 = 0;
    while (l1 < v.size() && l2 < num[i].size()) {
      if (v[l1] != num[i][l2]) {
        l1++;
        cnt++;
      } else {
        l1++;
        l2++;
      }
    }
    if (l1 != v.size()) cnt += v.size() - l1;
    if (num[i].size() != l2) cnt += num[i].size() - l2;
    ans = std::min(ans, cnt);
  }
  cout << ans << '\n';
}
int main() {
  init();
  int T = 1;
  read(T);
  while (T--) {
    solve();
  }
  return 0;
}
