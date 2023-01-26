#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long inf = 1LL << 62;
const long long mx = 100005;
const double eps = 1e-10;
long long dx[10] = {1, 0, -1, 0}, dy[10] = {0, -1, 0, 1};
long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long x = power(a, b / 2);
  x = x * x;
  if (b % 2) x = x * a;
  return x;
}
long long bigmod(long long a, long long b) {
  if (b == 0) return 1;
  long long x = bigmod(a, b / 2) % mod;
  x = (x * x) % mod;
  if (b % 2) x = (x * a) % mod;
  return x;
}
long long Set(long long N, long long pos) { return N = N | (1LL << pos); }
long long reset(long long N, long long pos) { return N = N & ~(1LL << pos); }
bool check(long long N, long long pos) { return (bool)(N & (1LL << pos)); }
int main() {
  long long tst, a, b, c, k, n, m, res = 0, ans = 0, t = 0;
  scanf("%lld", &tst);
  while (tst--) {
    scanf("%lld", &n);
    priority_queue<pair<long long, long long> > p;
    for (long long i = 1; i <= n; i++) {
      scanf("%lld", &a);
      p.push({a, i});
    }
    vector<pair<long long, long long> > v;
    while ((long long)(p).size() > 1) {
      pair<long long, long long> A = p.top();
      p.pop();
      pair<long long, long long> B = p.top();
      p.pop();
      if (A.first > 0 and B.first > 0) {
        v.push_back({A.second, B.second});
        A.first--;
        B.first--;
      }
      if (A.first) p.push(A);
      if (B.first) p.push(B);
    }
    cout << (long long)(v).size() << "\n";
    for (auto i : v) cout << i.first << " " << i.second << "\n";
  }
  return 0;
}
