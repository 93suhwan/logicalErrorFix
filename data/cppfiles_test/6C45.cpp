#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 MOD = 1e9 + 7;
const int MX = 1e5 + 6;
vector<int> ph(MX);
vector<int> d[MX];
void get_phi() {
  for (int i = 0; i < MX; ++i) {
    ph[i] = i;
  }
  for (int i = 2; i < MX; ++i) {
    if (ph[i] == i)
      for (int j = i; j < MX; j += i) {
        ph[j] -= ph[j] / i;
      }
  }
}
void get_divisor() {
  for (int i = 1; i < MX; ++i) {
    for (int j = i; j < MX; j += i) {
      d[j].push_back(i);
    }
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  get_phi();
  get_divisor();
  int n;
  cin >> n;
  vector<i64> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  i64 ans = 0;
  vector<int> cnt(MX);
  for (int i = 1; i <= n; ++i) {
    i64 s1 = 0;
    for (int j = i; j <= n; j += i) {
      for (int e : d[a[j]]) {
        ++cnt[e];
      }
    }
    for (int j = i; j <= n; j += i) {
      for (int e : d[a[j]]) {
        if (cnt[e]) {
          i64 s2 = cnt[e];
          cnt[e] = 0;
          s2 *= s2;
          s2 %= MOD;
          s2 *= ph[e];
          s2 %= MOD;
          s1 += s2;
          s1 %= MOD;
        }
      }
    }
    ans += ph[i] * s1;
    ans %= MOD;
  }
  cout << ans;
  return 0;
}
