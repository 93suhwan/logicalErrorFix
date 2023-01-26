#include <bits/stdc++.h>
template <class T>
class Bit {
 public:
  T a[524288];
  void add(int x, T k) {
    while (x < 524288) a[x] += k, x += x + 1 & ~x;
  }
  T qry(int x) {
    T res = 0;
    while (x >= 0) res += a[x], x -= x + 1 & ~x;
    return res;
  }
};
Bit<int> bit_cnt;
Bit<long long int> bit_sum;
std::set<int> st;
int a[524288];
long long int p[524288];
long long int cache[512];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i) {
    int cur_cnt = bit_cnt.qry(a[i]);
    long long int cur_sum = bit_sum.qry(a[i]);
    for (int j = 1; j < 512; ++j) {
      int nx_cnt = bit_cnt.qry(a[i] / (j + 1));
      long long int nx_sum = bit_sum.qry(a[i] / (j + 1));
      p[i] -= (nx_sum - cur_sum) * j * (nx_cnt - cur_cnt);
      cur_cnt = nx_cnt, cur_sum = nx_sum;
    }
    p[i] += (long long int)a[i] * (bit_cnt.a[524288 - 1] - cur_cnt);
    int x = (a[i] - 1) / 512;
    for (auto k : st) {
      if (k > x) break;
      p[i] += a[i] % k;
    }
    if (a[i] < 512)
      p[i] += cache[a[i]];
    else {
      int tt = bit_cnt.a[524288 - 1];
      p[i] += bit_sum.a[524288 - 1];
      long long int sc = 0;
      for (int j = 1; a[i] * j - 1 < 524288; ++j) {
        int cnt = tt - bit_cnt.qry(a[i] * j - 1);
        if (!cnt) break;
        sc += cnt;
      }
      p[i] -= a[i] * sc;
    }
    bit_cnt.add(a[i], 1);
    bit_sum.add(a[i], a[i]);
    st.insert(a[i]);
    for (int j = 1; j < 512; ++j) cache[j] += a[i] % j;
  }
  for (int i = 1; i < n; ++i) p[i] += p[i - 1];
  for (int i = 0; i < n; ++i) printf(" %lld" + !i, p[i]);
  printf("\n");
  return 0;
}
