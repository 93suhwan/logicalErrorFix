#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 16;
const long long M = 5e6 + 5;
long long n, a[N], P[20005], DF[M], res = 0, Div[N][N], MaxM;
vector<pair<long long, long long> > lst;
void add(long long &a, long long b) { a = (a + b) % MOD; }
long long Pow(long long a, long long b) {
  if (b == 0) return 1;
  long long t = Pow(a, b / 2);
  if (b % 2 == 0) return t * t % MOD;
  return t * t % MOD * a % MOD;
}
long long check_bit(long long i, long long mask) {
  return (mask & (1 << i)) > 0;
}
long long Find(pair<long long, long long> t) {
  long long low = 0, high = lst.size() - 1;
  while (low <= high) {
    long long mid = (low + high) / 2;
    if (lst[mid].first < t.first)
      low = mid + 1;
    else {
      if (lst[mid].first > t.first)
        high = mid - 1;
      else {
        if (lst[mid].second > t.second)
          high = mid - 1;
        else {
          if (lst[mid].second < t.second)
            low = mid + 1;
          else
            return mid;
        }
      }
    }
  }
}
void Prepare() {
  for (long long i = 0; i <= n - 1; i++)
    for (long long j = i + 1; j <= n - 1; j++) {
      if (i == j) continue;
      Div[i][j] = Pow(a[i] + a[j], MOD - 2) % MOD;
      Div[j][i] = Div[i][j];
    }
  for (long long mask1 = 1; mask1 <= MaxM; mask1++) {
    for (long long mask2 = 0; mask2 <= (MaxM ^ mask1); mask2++) {
      if ((mask1 & mask2) != 0) continue;
      lst.push_back({mask1, mask2});
      long long num = __builtin_popcount(mask1),
                firstPos = __builtin_ctz(mask1);
      long long cur = lst.size() - 1;
      DF[cur] = 1;
      if (num == 1) {
        for (long long i = 0; i < n; i++) {
          if (check_bit(i, mask2)) {
            DF[cur] = DF[cur] * a[firstPos] % MOD * Div[firstPos][i] % MOD;
          }
        }
      } else {
        long long subMask = (1 << firstPos), ano_subMask = (mask1 ^ subMask);
        DF[cur] =
            DF[Find({subMask, mask2})] * DF[Find({ano_subMask, mask2})] % MOD;
      }
    }
  }
}
void Solve() {
  long long res = 0;
  for (long long mask = 1; mask <= MaxM; mask++) {
    long long num_Win = __builtin_popcount(mask);
    long long Lose = (MaxM ^ mask);
    P[mask] = 1;
    for (long long subMask = 1; subMask <= mask - 1; subMask++) {
      if ((mask & subMask) != subMask) continue;
      long long ano_subMask = (mask ^ subMask);
      P[mask] = (P[mask] - P[subMask] * DF[Find({subMask, ano_subMask})] % MOD +
                 MOD) %
                MOD;
    }
    add(res, P[mask] * DF[Find({mask, Lose})] % MOD * num_Win % MOD);
  }
  cout << res << '\n';
}
void in() {
  cin >> n;
  for (long long i = 0; i <= n - 1; i++) cin >> a[i];
  MaxM = (1 << n) - 1;
}
void process() {
  Prepare();
  Solve();
}
int main() {
  if (fopen("trash.inp", "r"))
    freopen("trash.inp", "r", stdin), freopen("trash.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  in();
  process();
}
