#include <bits/stdc++.h>
using namespace std;
int n, k;
char s[5050];
int pref[5050];
long long num[5050];
namespace Combo {
long long* fact;
long long* inv;
long long binexp(long long a, long long b) {
  if (b == 0) return 1ll;
  if (b == 1) return a % 998244353;
  if (b % 2) return (a * binexp(a, b - 1)) % 998244353;
  return binexp((a * a) % 998244353, b / 2);
}
long long choose(long long a, long long b) {
  if (a < b) return 0;
  long long res = (fact[a] * inv[b]) % 998244353;
  res *= inv[a - b];
  res %= 998244353;
  return res;
}
void build(long long n) {
  fact = new long long[n];
  inv = new long long[n];
  fact[0] = 1;
  inv[0] = 1;
  for (int i = 1; i < n; i++) {
    fact[i] = (fact[i - 1] * (long long)i) % 998244353;
    inv[i] = binexp(fact[i], 998244353 - 2);
  }
}
};  // namespace Combo
long long cnt(int i, int j) {
  long long co = pref[j] - pref[i - 1];
  return (Combo::choose(j - i + 1, co) + 998244353 - 1) % 998244353;
}
long long get(int l, int r, long long cn) {
  return (cnt(l, r) * num[cn]) % 998244353;
}
int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  Combo::build(5050 * 5);
  vector<pair<int, int>> seg;
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + (s[i] - '0');
  }
  for (int i = 2; i <= n; i++) {
    long long cv = 0;
    for (int j = 0; j <= n; j++) {
      long long nn = Combo::choose(i - 2, j);
      if (j % 2 == 0) nn = (998244353 - nn) % 998244353;
      cv += nn;
      cv %= 998244353;
    }
    num[i] = cv;
  }
  for (int i = 1; i <= n; i++) {
    if (i > 1 && s[i - 1] != '1') continue;
    int ce = i;
    for (int j = i + 1; j <= n; j++) {
      if (pref[j] - pref[i - 1] > k) break;
      ce = j;
    }
    int cv = pref[ce] - pref[i - 1];
    if (cv == k && cnt(i, ce)) seg.push_back({i, ce});
  }
  long long ans = 1;
  for (int i = 0; i < seg.size(); i++) {
    int l = seg[i].first;
    int r = seg[i].second;
    ans += cnt(l, r);
    ans %= 998244353;
    for (int j = i - 1; j >= 0; j--) {
      int cl = seg[j].first;
      int cr = seg[j].second;
      if (cr < l) break;
      ans += get(l, cr, i - j + 1);
      ans %= 998244353;
    }
  }
  printf("%lld\n", ans);
}
