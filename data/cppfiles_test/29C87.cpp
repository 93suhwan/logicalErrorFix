#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);
long long random2() { return (1ll << 31ll) * eng() + eng(); }
struct FT {
  vector<long long> s;
  FT(int n) : s(n) {}
  void update(int pos, long long dif) {
    for (; pos < (int)(s).size(); pos |= pos + 1) s[pos] += dif;
  }
  long long query(int pos) {
    long long res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos - 1];
    return res;
  }
  int lower_bound(long long sum) {
    if (sum <= 0) return -1;
    int pos = 0;
    for (int pw = 1 << 25; pw; pw >>= 1) {
      if (pos + pw <= (int)(s).size() && s[pos + pw - 1] < sum)
        pos += pw, sum -= s[pos - 1];
    }
    return pos;
  }
};
long long n, m, k, q, T;
const long long big = 1000000007;
const long long big2 = 1000000009;
const long long mod = 998244353;
const int MAXN = 600001;
const int SQRT = 500;
vector<int> smalls;
vector<long long> A;
long long amod[SQRT] = {0};
long long bigs = 0;
long long brute(long long i) {
  long long res = 0;
  for (int c1 = 0; c1 < (i + 1); ++c1) {
    for (int c2 = 0; c2 < (i + 1); ++c2) {
      res += A[c1] % A[c2];
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long a, b, c, d, e;
  cin >> n;
  FT ft1(MAXN);
  FT ft2(MAXN);
  long long upscore = 0;
  long long ans = 0;
  for (int c1 = 0; c1 < (n); ++c1) {
    cin >> a;
    A.push_back(a);
    if (a < SQRT) {
      ans += amod[a];
      ans += ft2.query(a) + a * bigs;
      for (auto& y : smalls) {
        ans += a % y;
      }
      smalls.push_back(a);
    } else {
      long long temp1 = upscore;
      long long a2 = a;
      while (1) {
        temp1 -= (long long(c1) - ft1.query(a2)) * a;
        if (a2 > MAXN / 2) break;
        a2 += a;
      }
      ans += temp1;
      ans += ft2.query(a) + a * bigs;
      for (auto& y : smalls) {
        ans += a % y;
      }
      a2 = a;
      while (1) {
        ft2.update(a2 - 1, -a);
        if (a2 > MAXN / 2) break;
        a2 += a;
      }
      bigs++;
    }
    ft1.update(a, 1);
    for (int c2 = 1; c2 < (SQRT); ++c2) {
      amod[c2] += a % c2;
    }
    upscore += a;
    cout << ans << " ";
  }
  return 0;
}
