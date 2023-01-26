#include <bits/stdc++.h>
using namespace std;
const long long MX = 3e5 + 10;
long long N;
bool ex[MX];
struct fen {
  long long pref[MX];
  long long cnt[MX];
  long long lsone(long long x) { return x & (-x); }
  void upd(long long p, long long v) {
    for (; p < MX; p += lsone(p)) cnt[p]++, pref[p] += v;
  }
  pair<long long, long long> rs(long long a, long long b) {
    long long sum = 0;
    long long num = 0;
    for (; b; b -= lsone(b)) sum += pref[b], num += cnt[b];
    for (; a; a -= lsone(a)) sum -= pref[a], num -= cnt[a];
    return make_pair(sum, num);
  }
} ft;
struct fen2 {
  long long pref[MX];
  long long lsone(long long x) { return x & (-x); }
  void upd(long long p) {
    long long n = p;
    for (; p < MX; p += lsone(p)) pref[p] += n;
  }
  long long rs(long long b) {
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
  long long bound = sqrt(MX);
  long long ans = 0;
  for (long long i = 0; i < N; i++) {
    long long v;
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
      for (long long j = 1; j <= bound && j < v; j++)
        if (ex[j]) ans += v % j;
      long long nx = min(v, bound + 1);
      while (nx < v) {
        long long div = v / nx, rg = div == 1 ? v - 1 : (v - 1) / (div - 1);
        pair<long long, long long> temp = ft.rs(nx - 1, rg);
        ans += 1ll * (temp.first + 1ll * temp.second * rg) * div +
               1ll * temp.second * (v % rg);
        nx = rg + 1;
      }
    }
    {
      pair<long long, long long> temp = ft.rs(v, MX - 1);
      ans += 1ll * v * temp.second;
      for (long long j = v + 1; j <= bound; j++)
        if (ex[j]) ans += j % v;
      long long nx = max(v + 1, bound + 1);
      while (nx < MX) {
        long long div = nx / v,
                  rg = v * (div + 1) > MX ? MX - 1 : v * (div + 1) - 1;
        pair<long long, long long> temp = ft.rs(nx - 1, rg);
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
