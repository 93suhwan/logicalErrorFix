#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b) {
  long long int res = 1;
  a = a % 1000000007;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % 1000000007;
      b--;
    }
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  return (b == 0) ? a : gcd(b, a % b);
}
vector<long long int> a(200005);
vector<long long int> tree(900005);
vector<long long int> lazy(900005);
vector<bool> marked(900005);
long long int n, m;
void build(long long int tl, long long int tr, long long int v) {
  if (tl == tr) {
    tree[v] = a[tl];
  } else {
    long long int mid = tl + (tr - tl) / 2;
    build(tl, mid, 2 * v);
    build(mid + 1, tr, 2 * v + 1);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
  }
}
void push(long long int v, long long int len) {
  long long int a = (len + 1) / 2;
  long long int b = len - a;
  tree[2 * v] += lazy[v] * a;
  tree[2 * v + 1] += lazy[v] * b;
  lazy[2 * v] += lazy[v];
  lazy[2 * v + 1] += lazy[v];
  lazy[v] = 0;
}
long long int get(long long int tl, long long int tr, long long int l,
                  long long int r, long long int v, long long int len) {
  if (l > r) return 0;
  if (tl == l && tr == r) return tree[v];
  push(v, len);
  long long int a = (len + 1) / 2;
  long long int b = len - a;
  long long int mid = tl + (tr - tl) / 2;
  return (get(tl, mid, l, min(mid, r), 2 * v, a) +
          get(mid + 1, tr, max(l, mid + 1), r, 2 * v + 1, b));
}
void update(long long int tl, long long int tr, long long int l,
            long long int r, long long int val, long long int v,
            long long int len) {
  if (l > r) return;
  if (l == tl && r == tr) {
    tree[v] += val * len;
    lazy[v] += val;
  } else {
    push(v, len);
    long long int a = (len + 1) / 2;
    long long int b = len - a;
    long long int mid = tl + (tr - tl) / 2;
    update(tl, mid, l, min(mid, r), val, 2 * v, a);
    update(mid + 1, tr, max(mid + 1, l), r, val, 2 * v + 1, b);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  vector<long long int> v(n + 1);
  for (long long int i = 1; i <= n; i++) cin >> v[i];
  a[n] = 0;
  for (long long int i = n - 1; i >= 1; i--) {
    if (v[i] <= v[i + 1])
      a[i] = a[i + 1] + 1;
    else
      a[i] = 0;
  }
  build(1, n, 1);
  while (m--) {
    long long int t;
    cin >> t;
    if (t == 2) {
      long long int l, r;
      cin >> l >> r;
      long long int li, ri;
      li = l;
      ri = r;
      long long int val;
      while (li <= ri) {
        long long int mid = li + (ri - li) / 2;
        long long int z = get(1, n, mid, mid, 1, n);
        if (mid + z >= r) {
          val = mid;
          ri = mid - 1;
        } else
          li = mid + 1;
      }
      long long int ans = 0;
      if (l < val) {
        ans = get(1, n, l, val - 1, 1, n);
        ans += (val - l);
      }
      long long int len = r - val + 1;
      ans += (len * (len + 1)) / 2;
      cout << ans << "\n";
    } else {
      long long int f1, f2;
      f1 = 0;
      f2 = 0;
      long long int ind, x;
      cin >> ind >> x;
      long long int prev = get(1, n, ind, ind, 1, n);
      if (ind < n) {
        if (v[ind] <= v[ind + 1]) f1 = 1;
        if (x <= v[ind + 1]) f2 = 1;
        if (f1 == 0 && f2 == 1) {
          long long int val = get(1, n, ind + 1, ind + 1, 1, n);
          update(1, n, ind, ind, val + 1, 1, n);
        }
        if (f1 == 1 && f2 == 0) {
          long long int val = get(1, n, ind + 1, ind + 1, 1, n);
          update(1, n, ind, ind, -val - 1, 1, n);
        }
      }
      if (ind > 1) {
        f1 = f2 = 0;
        if (v[ind - 1] <= v[ind]) f1 = 1;
        if (v[ind - 1] <= x) f2 = 1;
        if (f1 == 0 && f2 == 1) {
          long long int l, r;
          l = 1;
          r = ind - 1;
          long long int val;
          while (l <= r) {
            long long int mid = l + (r - l) / 2;
            long long int z = get(1, n, mid, mid, 1, n);
            if (mid + z >= ind - 1) {
              val = mid;
              r = mid - 1;
            } else
              l = mid + 1;
          }
          long long int add = get(1, n, ind, ind, 1, n) + ind - (ind - 1);
          update(1, n, val, ind - 1, add, 1, n);
        }
        if (f1 == 1 && f2 == 0) {
          long long int l, r;
          l = 1;
          r = ind;
          long long int val;
          while (l <= r) {
            long long int mid = l + (r - l) / 2;
            long long int z = get(1, n, mid, mid, 1, n);
            if (mid + z >= ind) {
              val = mid;
              r = mid - 1;
            } else
              l = mid + 1;
          }
          long long int add = prev + ind - (ind - 1);
          if (val < ind) update(1, n, val, ind - 1, -add, 1, n);
        }
      }
    }
  }
}
