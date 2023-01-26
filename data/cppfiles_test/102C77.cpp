#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long k, A, h;
long long Rank[100], powa[100];
long long Rank_List(long long bm, vector<long long> p1) {
  long long cr = 1 + (p1.size());
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
  Rank[p1[0]] = 2;
  return p1[0];
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
  vector<long long> p1, p2;
  for (long long i = 1; i <= n2; i++) p1.push_back(i);
  for (long long i = n2 + 1; i <= n; i++) p2.push_back(i);
  map<long long, long long> pos1, bm1, pos2, bm2;
  vector<array<long long, 3>> hbw1, hbw2;
  long long m = 1 << (n2 - 1);
  for (long long bm = 0; bm < m; bm++) {
    long long w1 = Rank_List(bm, p1);
    long long c1 = Get_Hash(1, n2);
    long long w2 = Rank_List(bm, p2);
    long long c2 = Get_Hash(n2 + 1, n);
    pos1[c1] = 1;
    bm1[c1] = bm;
    pos2[c2] = 1;
    bm2[c2] = bm;
    hbw1.push_back({c1, bm, w1});
    hbw2.push_back({c2, bm, w2});
  }
  for (auto x : hbw1) {
    long long h1 = x[0];
    long long cb1 = x[1];
    long long w1 = x[2];
    long long t1 = (w1 * powa[2]) % mod;
    long long t2 = (w1 * powa[1]) % mod;
    h1 = (h1 - t1 + t2) % mod;
    long long h2 = (h - h1) % mod;
    if (h2 < 0) h2 += mod;
    if (pos2[h2] == 0) continue;
    long long cb2 = bm2[h2];
    Rank_List(cb1, p1);
    Rank[w1] = 1;
    Rank_List(cb2, p2);
    print_rank(n);
    return;
  }
  for (auto x : hbw2) {
    long long h2 = x[0];
    long long cb2 = x[1];
    long long w2 = x[2];
    long long t1 = (w2 * powa[2]) % mod;
    long long t2 = (w2 * powa[1]) % mod;
    h2 = (h2 - t1 + t2) % mod;
    long long h1 = (h - h2) % mod;
    if (h1 < 0) h1 += mod;
    if (pos1[h1] == 0) continue;
    long long cb1 = bm1[h1];
    Rank_List(cb1, p1);
    Rank_List(cb2, p2);
    Rank[w2] = 1;
    print_rank(n);
    return;
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
