#include <bits/stdc++.h>
using namespace std;
const int MX = 3e5 + 10;
int N;
bool ex[MX];
struct fen {
  long long pref[MX];
  int cnt[MX];
  int lsone(int x) { return x & (-x); }
  void upd(int p, long long v) {
    for (; p < MX; p += lsone(p)) cnt[p]++, pref[p] += v;
  }
  pair<long long, int> rs(int a, int b) {
    long long sum = 0;
    int num = 0;
    for (; b; b -= lsone(b)) sum += pref[b], num += cnt[b];
    for (; a; a -= lsone(a)) sum -= pref[a], num -= cnt[a];
    return make_pair(sum, num);
  }
} ft;
struct fen2 {
  long long pref[MX];
  int lsone(int x) { return x & (-x); }
  void upd(int p) {
    int n = p;
    for (; p < MX; p += lsone(p)) pref[p] += n;
  }
  long long rs(int b) {
    long long sum = 0;
    for (; b; b -= lsone(b)) sum += pref[b];
    return sum;
  }
} ft2;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  int bound = sqrt(MX);
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    int v;
    cin >> v;
    ft.upd(v, -v);
    ft2.upd(v);
    ex[v] = true;
    if (i == 0) {
      cout << 0;
      continue;
    }
    {
      ans += ft2.rs(v - 1);
      for (int j = 1; j <= bound && j < v; j++)
        if (ex[j]) ans += v % j;
      int nx = min(v, bound + 1);
      while (nx < v) {
        int div = v / nx, rg = div == 1 ? v - 1 : (v - 1) / (div - 1);
        pair<long long, int> temp = ft.rs(nx - 1, rg);
        ans += 1ll * (temp.first + 1ll * temp.second * rg) * div +
               1ll * temp.second * (v % rg);
        nx = rg + 1;
      }
    }
    {
      pair<long long, int> temp = ft.rs(v, MX - 1);
      ans += 1ll * v * temp.second;
      for (int j = v + 1; j <= bound; j++)
        if (ex[j]) ans += j % v;
      int nx = max(v + 1, bound + 1);
      while (nx < MX) {
        int div = nx / v, rg = v * (div + 1) > MX ? MX - 1 : v * (div + 1) - 1;
        pair<long long, int> temp = ft.rs(nx - 1, rg);
        temp.first = -temp.first;
        ans += 1ll * (temp.first - 1ll * temp.second * nx) +
               1ll * temp.second * (nx % v);
        nx = rg + 1;
      }
    }
    cout << " " << ans;
  }
  cout << '\n';
}
