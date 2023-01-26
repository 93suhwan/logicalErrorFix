#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int N = 3e5 + 3;
const int mod = 1e9 + 7;
int n;
int a[N];
template <class T>
struct FT {
  vector<T> tree;
  int sz;
  FT(int n) { sz = n, tree.resize(n + 1); }
  T get(int i) {
    if (i <= 0 || i > sz) return T(0);
    T sum = T(0);
    for (; i; i -= (i & -i)) sum += tree[i];
    return sum;
  }
  void upd(int i, T val) {
    for (; i <= sz; i += (i & -i)) tree[i] += val;
  }
  void init(T *arr, int n) {
    sz = n;
    for (int i = 1; i <= n; i++) upd(i, arr[i - 1]);
  }
};
ll ans[N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  FT<ll> tree1(N);
  FT<ll> tree2(N);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    ans[i] = i * a[i] + sum;
    ans[i] -= tree1.get(a[i]);
    sum += a[i];
    int mul = a[i];
    while (mul < N) {
      tree1.upd(mul, a[i]);
      mul += a[i];
    }
    mul = (300000 / a[i]) * a[i];
    ll cnt = 0;
    while (mul != a[i]) {
      mul -= a[i];
      ll cur = i - tree2.get(mul - 1);
      ans[i] -= 1ll * mul * (cur - cnt);
      cnt = cur;
    }
    tree2.upd(a[i], 1ll);
  }
  for (int i = 0; i < n; i++) {
    printf("%lld ", ans[i]);
    ans[i + 1] += ans[i];
  }
  return 0;
}
