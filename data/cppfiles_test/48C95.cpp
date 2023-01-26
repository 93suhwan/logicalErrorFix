#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
const int DIM = 1e5 + 5;
long long arr[DIM], psm[DIM];
pair<long long, long long> sgt[DIM << 2];
void build(int nd, int le, int ri) {
  if (le == ri)
    sgt[nd].first = sgt[nd].second = psm[le];
  else {
    int md = (le + ri) >> 1;
    build(nd << 1, le, md);
    build(nd << 1 | 1, md + 1, ri);
    sgt[nd].first = min(sgt[nd << 1].first, sgt[nd << 1 | 1].first);
    sgt[nd].second = max(sgt[nd << 1].second, sgt[nd << 1 | 1].second);
  }
}
pair<long long, long long> query(int nd, int le, int ri, int st, int en) {
  if (st <= le && ri <= en)
    return sgt[nd];
  else {
    int md = (le + ri) >> 1;
    if (en <= md)
      return query(nd << 1, le, md, st, en);
    else if (md < st)
      return query(nd << 1 | 1, md + 1, ri, st, en);
    else {
      pair<long long, long long> ans1 = query(nd << 1, le, md, st, en),
                                 ans2 = query(nd << 1 | 1, md + 1, ri, st, en);
      return make_pair(min(ans1.first, ans2.first),
                       max(ans1.second, ans2.second));
    }
  }
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    arr[i] = x - arr[i];
    psm[i] = psm[i - 1] + arr[i];
  }
  build(1, 1, n);
  while (q--) {
    int le, ri;
    cin >> le >> ri;
    pair<long long, long long> ans = query(1, 1, n, le, ri);
    if (psm[ri] - psm[le - 1] != 0 || ans.first < psm[le - 1])
      cout << "-1\n";
    else
      cout << ans.second - psm[le - 1] << "\n";
  }
  return 0;
}
