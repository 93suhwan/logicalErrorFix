#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 43;
bool isp[MAXN];
int phi[MAXN];
long long mod = 1e9 + 7;
long long add(long long a, long long b) { return (a + b) % mod; }
long long ml(long long a, long long b) { return (a * b) % mod; }
long long cnt[MAXN];
bool usd[MAXN];
vector<int> divs[MAXN];
void solve() {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; ++i) {
    int curr;
    cin >> curr;
    v.push_back(curr);
  }
  phi[1] = 1;
  for (int i = 2; i < MAXN; ++i) {
    isp[i] = true;
    phi[i] = i;
  }
  for (int i = 1; i < MAXN; ++i) {
    for (int j = i; j < MAXN; j += i) divs[j].push_back(i);
    if (!isp[i]) continue;
    for (int j = i; j < MAXN; j += i) {
      isp[j] = false;
      phi[j] /= i;
      phi[j] *= i - 1;
    }
    isp[i] = true;
  }
  long long sm = 0;
  for (int i = 1; i <= n; ++i) {
    long long crr = 0;
    for (int j = i - 1; j < n; j += i) {
      for (auto e : divs[v[j]]) {
        cnt[e]++;
      }
    }
    for (int j = i - 1; j < n; j += i) {
      long long sm2 = 0;
      for (auto e : divs[v[j]]) {
        if (usd[e]) continue;
        sm2 = add(sm2, ml(phi[e], ml(cnt[e], cnt[e])));
        usd[e] = true;
      }
      crr = add(crr, sm2);
    }
    for (int j = i - 1; j < n; j += i) {
      for (auto e : divs[v[j]]) {
        cnt[e] = 0;
        usd[e] = false;
      }
    }
    sm = add(sm, ml(crr, phi[i]));
  }
  cout << sm << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(20);
  solve();
  return 0;
}
