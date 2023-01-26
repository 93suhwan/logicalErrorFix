#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template <typename T>
struct Fenwick {
  int n;
  vector<T> bit;
  Fenwick(int _n) : n(_n), bit(n + 1) {}
  void update(int p, T v) {
    for (++p; p <= n; p += p & -p) bit[p] += v;
  }
  T query(int p) {
    T ret{};
    for (++p; p > 0; p -= p & -p) ret += bit[p];
    return ret;
  }
};
int main() {
  int n;
  scanf("%d", &n);
  vector<int> A(n);
  const int MAX = 300000;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &A[i]);
  }
  Fenwick<int> fcnt(MAX + 1);
  Fenwick<ll> fsum(MAX + 1);
  Fenwick<ll> rangeFenw(MAX + 1);
  ll curSum = 0;
  vector<ll> ans(n);
  for (int i = 0; i < n; ++i) {
    curSum += (ll)A[i] * i - rangeFenw.query(A[i]);
    for (int j = 0; j <= MAX; j += A[i]) {
      int k = min(MAX, j + A[i] - 1);
      int cnt = fcnt.query(k) - fcnt.query(j - 1);
      ll sum = fsum.query(k) - fsum.query(j - 1);
      ll add = sum - (ll)cnt * j;
      curSum += add;
      rangeFenw.update(j, j);
      rangeFenw.update(k + 1, -j);
    }
    fcnt.update(A[i], 1);
    fsum.update(A[i], A[i]);
    42;
    ans[i] = curSum;
  }
  for (int i = 0; i < n; ++i) {
    printf("%lld ", ans[i]);
  }
}
