#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
struct SegTree {
  vector<pair<long long, long long> > seg;
  long long MAX;
  SegTree(long long N) {
    long long i;
    for (i = 1; i < 2 * N; i *= 2) {
    }
    MAX = i;
    seg.resize(i);
  }
  void cons() {
    for (long long i = MAX / 2 - 1; i >= 1; i--) {
      seg[i] = max(seg[2 * i], seg[2 * i + 1]);
    }
  }
  pair<long long, long long> sum(long long s, long long e, long long n,
                                 long long ns, long long ne) {
    if (e <= ns || ne <= s) return pair<long long, long long>(-1, -1);
    if (s <= ns && ne <= e) return seg[n];
    long long mid = ns + ne >> 1;
    return max(sum(s, e, n << 1, ns, mid), sum(s, e, n << 1 | 1, mid, ne));
  }
  void update(long long n) {
    n += MAX / 2;
    n /= 2;
    while (n) {
      seg[n] = max(seg[2 * n], seg[2 * n + 1]);
      n /= 2;
    }
  }
  void Edit(long long n, long long a) {
    seg[n + MAX / 2] =
        pair<long long, long long>(max(a, seg[n + MAX / 2].first), n);
    update(n);
  }
  pair<long long, long long> sum(long long s, long long e) {
    return sum(s, e, 1, 0, MAX / 2);
  }
};
long long A[300005];
long long B[300005];
long long gcd(long long a, long long b) {
  a = abs(a);
  b = abs(b);
  if (a < b) swap(a, b);
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
long long lev[300005];
long long DP[300005];
signed main() {
  cin.tie(0);
  cout.tie(0);
  long long N;
  cin >> N;
  long long i;
  for (i = N - 1; i >= 0; i--) cin >> A[i];
  for (i = N - 1; i >= 0; i--) cin >> B[i];
  if (A[0] == N) {
    cout << "1\n0";
    return 0;
  }
  SegTree tree(N + 5);
  long long MAX = tree.MAX;
  tree.cons();
  lev[0] = A[0];
  long long pt = 0;
  while (true) {
    if (pt >= 1) {
      pair<long long, long long> k = tree.sum(lev[pt - 1], lev[pt] + 1);
      DP[pt] = k.second;
      lev[pt + 1] = k.first;
      if (k.first == N) {
        break;
      }
      if (lev[pt + 1] == lev[pt]) {
        cout << -1;
        return 0;
      }
      pt++;
    } else {
      pair<long long, long long> k = tree.sum(0, A[0] + 1);
      DP[0] = k.second;
      lev[pt + 1] = k.first;
      if (k.first == N) {
        break;
      }
      if (lev[pt + 1] == lev[pt]) {
        cout << -1;
        return 0;
      }
      pt++;
    }
  }
  cout << pt + 2 << '\n';
  long long st = 0;
  long long cn = 0;
  for (i = 0; i < pt + 1; i++) cout << N - DP[i] << ' ';
  cout << 0;
}
