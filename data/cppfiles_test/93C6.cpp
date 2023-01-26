#include <bits/stdc++.h>
using namespace std;
template <typename T>
class dsu {
 public:
  vector<T> size;
  vector<T> parent;
  dsu(long long sz) {
    size.resize(sz + 1);
    parent.resize(sz + 1);
  }
  void make(T a) {
    size[a] = 1;
    parent[a] = a;
  }
  T find(T a) {
    if (a == parent[a]) return a;
    return parent[a] = find(parent[a]);
  }
  void makeunion(T a, T b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      if (size[a] > size[b]) {
        parent[b] = a;
        size[a] += size[b];
      } else {
        parent[a] = b;
        size[b] += size[a];
      }
    }
  }
  long long sizenode(T a) { return size[find(a)]; }
};
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res *= a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    if (n == 1 && k == 1)
      cout << 0;
    else {
      long long ex = 1LL, c = 1LL;
      n -= 2LL;
      while (true) {
        ex *= 2LL;
        if (ex >= k) {
          ex = k;
          c += (n + (k - 1LL)) / k;
          break;
        }
        c += 1LL;
        n -= (ex);
      }
      cout << c;
    }
    cout << '\n';
  }
  cerr << "processor time: " << clock() / (double)CLOCKS_PER_SEC << "s    ";
  return 0;
}
