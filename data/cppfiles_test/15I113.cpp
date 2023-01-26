#include <bits/stdc++.h>
using namespace std;
int ar[200005];
char ch[200005];
int n, m, ii, k;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return {i, j};
}
struct printer {
  ~printer() { cerr << endl; }
  template <class c>
  printer& operator,(c x) {
    cerr << boolalpha << x;
    return *this;
  }
  printer& operator,(string x) {
    cerr << x;
    return *this;
  }
  template <class c, class d>
  printer& operator,(pair<c, d> x) {
    return *this, "(", x.first, ", ", x.second, ")";
  }
  template <class... d, template <class...> class c>
  printer& operator,(c<d...> x) {
    return *this, range(begin(x), end(x));
  }
  template <class c>
  printer& operator,(rge<c> x) {
    *this, "[";
    for (auto it = x.b; it != x.e; ++it) *this, (it == x.b ? "" : ", "), *it;
    return *this, "]";
  }
};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long my_rand(long long l, long long r) {
  return uniform_int_distribution<long long>(l, r)(rng);
}
int Size[200005];
int parent[200005];
int Findparent(int x) {
  return (x == parent[x]) ? x : (parent[x] = Findparent(parent[x]));
}
void initialize(int x) {
  for (int i = 0; i <= x; i++) parent[i] = i, Size[i] = 1;
}
void solve() {
  int t = my_rand(1, 10);
  cout << t << endl;
  while (t--) {
    int x = my_rand(2, 100);
    cout << x << " " << my_rand(2, x) << endl;
    initialize(x);
    for (int i = 1; i < x; i++) {
      while (1) {
        int a = my_rand(1, x);
        int b = my_rand(1, x);
        if (Findparent(a) == Findparent(b))
          continue;
        else {
          parent[Findparent(b)] = Findparent(a);
          cout << a << " " << b << endl;
          break;
        }
      }
    }
    cout << endl;
  }
}
int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}
