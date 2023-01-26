#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
long long qpow(long long b, long long p, long long Mod = 1e9 + 7) {
  long long r = 1;
  while (p) {
    if (p & 1) r = r * b % Mod;
    b = b * b % Mod;
    p >>= 1;
  }
  return r;
}
const int mod = 1e9 + 7;
const int N = 2e7 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = (1ll << 60);
void pre(int n = 1e7) { return; }
void solves() {
  int a, b;
  cin >> a >> b;
  if ((a + b) & 1) {
    int tot = (a + b + 1) / 2 + min(a, b) - abs(a - b) / 2 + 1;
    cout << tot << '\n';
    for (int i = abs(a - b) / 2; i <= (a + b + 1) / 2 + min(a, b); ++i) {
      cout << i << " ";
    }
    cout << '\n';
  } else {
    cout << (a + b - abs(a - b)) / 2 + min(a, b) / 2 + 1 << '\n';
    for (int i = abs(a - b) / 2; i <= (a + b) / 2 + min(a, b); i += 2)
      cout << i << " ";
    cout << '\n';
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int _OwO_ = 1;
  cin >> _OwO_;
  pre();
  while (_OwO_--) solves();
}
