#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const unsigned gen_seed =
    std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);
class streesum {
 public:
  std::vector<long long> t;
  int s;
  void build(int n, int v, int tl, int tr) {
    if (v == 1) {
      t.resize(n * 4);
      s = n;
    }
    if (tl == tr)
      t[v] = 0;
    else {
      int tm = (tl + tr) / 2;
      build(n, v * 2, tl, tm);
      build(n, v * 2 + 1, tm + 1, tr);
      t[v] = t[v * 2] + t[v * 2 + 1];
    }
  }
  long long get(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) return t[v];
    int tm = (tl + tr) / 2;
    return (get(v * 2, tl, tm, l, min(r, tm)) +
            get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  }
  void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr)
      t[v] += new_val;
    else {
      int tm = (tl + tr) / 2;
      if (pos <= tm)
        update(v * 2, tl, tm, pos, new_val);
      else
        update(v * 2 + 1, tm + 1, tr, pos, new_val);
      t[v] = (t[v * 2] + t[v * 2 + 1]);
    }
  }
};
int main() {
  int n, r;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  const int A = 300010;
  streesum num, sum, dec;
  num.build(A, 1, 0, A - 1);
  sum.build(A, 1, 0, A - 1);
  dec.build(A, 1, 0, A - 1);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int v = a[i];
    int k = 0;
    ans += (long long)v * i;
    ans += dec.get(1, 0, A - 1, 0, v);
    while (k * v < A) {
      int l = k * v;
      int r = min(((k + 1) * v - 1), A - 1);
      long long nn = num.get(1, 0, A - 1, l, r);
      if (nn > 0) {
        long long ss = sum.get(1, 0, A - 1, l, r);
        ans += ss - nn * k * v;
      }
      if (k > 0) dec.update(1, 0, A - 1, k * v, -v);
      k++;
    }
    num.update(1, 0, A - 1, v, 1);
    sum.update(1, 0, A - 1, v, v);
    printf("%lld ", ans);
  }
}
