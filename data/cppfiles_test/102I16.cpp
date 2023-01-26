#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long k, A, h;
long long Rank[100], powa[100];
void Rank_List(long long bm, vector<long long> p1) {
  long long cr = 1 + (p1.size()) / 2;
  while (p1.size() != 1) {
    vector<long long> p2;
    long long m = p1.size();
    for (long long i = 0; i < m; i += 2) {
      long long x = (bm % 2);
      bm /= 2;
      long long y = x ^ 1;
      long long px = p1[i + x];
      long long py = p1[i + y];
      Rank[px] = cr;
      p2.push_back(py);
    }
    p1 = p2;
    cr = (cr / 2) + 1;
  }
  Rank[p1[0]] = 1;
}
long long Get_Hash(long long l, long long r) {
  long long val = 0;
  for (long long i = l; i <= r; i++) {
    long long cur = (i * powa[Rank[i]]) % mod;
    val = (val + cur) % mod;
  }
  return val;
}
void print_rank(long long n) {
  for (long long i = 1; i <= n; i++) cout << Rank[i] << " ";
  cout << endl;
}
void solve() {
  cin >> k >> A >> h;
  long long n = 1 << (k);
  long long n2 = n / 2;
  powa[0] = 1;
  for (long long i = 1; i < 100; i++) powa[i] = (powa[i - 1] * A) % mod;
  vector<long long> p1;
  for (long long i = 1; i <= n; i++) p1.push_back(i);
  long long m = 1 << (n - 1);
  for (long long bm = 0; bm < m; bm++) {
    Rank_List(bm, p1);
    long long cur = Get_Hash(1, n);
    if (cur == h) {
      print_rank(n);
      return;
    }
  }
  cout << -1 << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
