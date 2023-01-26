#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 9;
const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int bas = 13333;
const double eps = 1e-7;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
int a[maxn];
void INIT() {}
void init() {}
priority_queue<int, vector<int>, less<int>> ser;
priority_queue<int, vector<int>, greater<int>> seb;
void solve() {
  while (!ser.empty()) ser.pop();
  while (!seb.empty()) seb.pop();
  int n;
  cin >> n;
  for (int i = 0; i <= n - 1; i++) cin >> a[i];
  string s;
  cin >> s;
  int nb, nr;
  nb = nr = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'B') {
      seb.push(a[i]), nb++;
    } else
      ser.push(a[i]), nr++;
  }
  int flag = 0;
  for (int i = n; i > n - nr; i--) {
    int top = ser.top();
    ser.pop();
    if (top > i) {
      cout << "NO" << '\n';
      return;
    }
  }
  for (int i = 1; i <= nb; i++) {
    int top = seb.top();
    seb.pop();
    if (top < i) {
      cout << "NO" << '\n';
      return;
    }
  }
  cout << "YES" << '\n';
  return;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  init();
  long long T;
  cin >> T;
  while (T--) INIT(), solve();
  return 0;
}
