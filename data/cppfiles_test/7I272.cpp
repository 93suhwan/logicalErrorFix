#include <bits/stdc++.h>
using namespace std;
struct input_data {
  int n;
  vector<long long> a;
};
input_data read_input() {
  input_data in;
  cin >> in.n;
  in.a.resize(in.n);
  for (int i = 0; i < in.n; ++i) {
    cin >> in.a[i];
  }
  return in;
}
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
class gcd_tree {
  vector<long long> t;
  int n;
  void build(const vector<long long>& a, int v, int l, int r) {
    if (l == r) {
      t[v] = a[l];
    } else {
      int m = (l + r) / 2;
      build(a, v * 2, l, m);
      build(a, v * 2 + 1, m + 1, r);
      t[v] = gcd(t[v * 2], t[v * 2 + 1]);
    }
  }
  long long get(int v, int l, int r, int L, int R) {
    if (l == L && r == R) {
      return t[v];
    } else {
      int m = (l + r) / 2;
      if (R <= m) {
        return get(v * 2, l, m, L, R);
      } else if (L > m) {
        return get(v * 2 + 1, m + 1, r, L, R);
      } else {
        return gcd(get(v * 2, l, m, L, m), get(v * 2 + 1, m + 1, r, m + 1, R));
      }
    }
  }

 public:
  gcd_tree(const vector<long long>& a) {
    n = a.size();
    t.resize(n * 4);
    build(a, 1, 0, n - 1);
  }
  long long get(int l, int r) { return get(1, 0, n - 1, l, r); }
};
void solve(const input_data& in) {
  if (in.n == 1) {
    printf("%d\n", in.a[0] > 1 ? 1 : 0);
    return;
  }
  vector<long long> b;
  for (int i = 1; i < in.n; ++i) {
    b.push_back(abs(in.a[i] - in.a[i - 1]));
  }
  int n = b.size();
  gcd_tree g(b);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int l = i, r = n - 1;
    while (l < r) {
      int m = (l + r + 1) / 2;
      if (g.get(i, m) > 1) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    if (g.get(i, r) > 1) {
      int len = r - i + 1;
      ans = max(ans, len);
    }
  }
  printf("%d\n", ans + 1);
}
int main() {
  ios::sync_with_stdio(0);
  int t = 1;
  cin >> t;
  while (t--) {
    auto in = read_input();
    solve(in);
  }
  return 0;
}
