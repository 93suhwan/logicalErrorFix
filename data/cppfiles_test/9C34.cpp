#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using LL = __int128;
template <class T>
class BIT {
 private:
  int N;
  vector<T> nodes;

 public:
  BIT(int N) {
    this->N = N;
    nodes.assign(N + 1, 0);
  }
  void add(int k, T x) {
    for (int i = k; i <= N; i += (i & -i)) {
      nodes[i] += x;
    }
  }
  T sum(int k) {
    T result = 0;
    for (int i = k - 1; i > 0; i -= (i & -i)) {
      result += nodes[i];
    }
    return result;
  }
  T sum(int s, int t) { return sum(t) - sum(s); }
  int lower_bound(T x) {
    if (sum(N + 1) < x) return -1;
    int ok = N + 1;
    int ng = 0;
    while (ok - ng > 1) {
      int trying = (ok + ng) / 2;
      if (sum(trying + 1) >= x) {
        ok = trying;
      } else {
        ng = trying;
      }
    }
    return ok;
  }
  int upper_bound(T x) {
    if (sum(N + 1) <= x) return -1;
    int ok = N + 1;
    int ng = 0;
    while (ok - ng > 1) {
      int trying = (ok + ng) / 2;
      if (sum(trying + 1) > x) {
        ok = trying;
      } else {
        ng = trying;
      }
    }
    return ok;
  }
};
int n, m, k;
int a[1000][1000];
vector<BIT<int>> bit;
bool is_ok(int l, int k, int c) { return bit[c].sum(l, k) == 0; }
ll find_max_ok(ll lower, ll upper, int c) {
  ll ok = lower;
  ll ng = upper;
  while (ng - ok > 1) {
    ll trying = (ng + ok) / 2;
    if (is_ok(lower, trying, c)) {
      ok = trying;
    } else {
      ng = trying;
    }
  }
  return ok;
}
void solve() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    bit.push_back(BIT<int>(n));
  }
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      cin >> a[r][c];
      if (a[r][c] != 2) bit[c].add(r + 1, 1);
    }
  }
  for (int t = 0; t < k; t++) {
    int c;
    cin >> c;
    c--;
    int r = 0;
    while (1) {
      r = find_max_ok(r + 1, n + 2, c) - 1;
      if (r == n) {
        cout << c + 1 << " ";
        break;
      }
      if (a[r][c] == 1) {
        a[r][c] = 2;
        bit[c].add(r + 1, -1);
        c++;
      } else if (a[r][c] == 3) {
        a[r][c] = 2;
        bit[c].add(r + 1, -1);
        c--;
      }
    }
  }
  cout << endl;
}
int main() {
  cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  solve();
  return 0;
}
