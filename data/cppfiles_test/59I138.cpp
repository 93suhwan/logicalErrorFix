#include <bits/stdc++.h>
using namespace std;
template <class Temp>
vector<Temp> read(long long int n) {
  vector<Temp> input;
  for (long long int i = 0; i < n; i++) {
    Temp k;
    cin >> k;
    input.push_back(k);
  }
  return input;
}
template <class Temp>
vector<vector<Temp>> read_matrix(long long int n, long long int m) {
  vector<vector<Temp>> input(n + 1, vector<Temp>(m + 1, 0));
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= m; j++) {
      Temp k;
      cin >> k;
      input[i][j] = k;
    }
  }
  return input;
}
template <class Temp>
void print(vector<long long int> &v) {
  for (Temp a : v) {
    cout << a << " ";
  }
  cout << endl;
}
vector<long int> coor;
bool comparator(long int &i, long int &j) {
  return abs(coor[i]) > abs(coor[j]);
}
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 200007;
template <int SZ>
struct DSU {
  int parent[SZ], size[SZ];
  DSU() {
    for (int i = 0; i < SZ; i++) parent[i] = i, size[i] = 0;
  }
  int get(int x) {
    if (parent[x] != x) parent[x] = get(parent[x]);
    return parent[x];
  }
  void unify(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return;
    if (size[x] < size[y]) swap(x, y);
    if (size[x] == size[y]) size[x]++;
    parent[y] = x;
  }
};
int mod = 1e9 + 7;
struct BIT {
  int n;
  vector<int> bit;
  BIT(int N) {
    n = N;
    bit.assign(n + 1, 0);
  }
  void update(int i, int v) {
    for (; i <= n; i += i & (-i)) {
      bit[i] = (bit[i] + v) % mod;
      if (bit[i] < 0) bit[i] += mod;
    }
  }
  int query(int i) {
    int ret = 0;
    for (; i > 0; i -= i & (-i)) ret = (ret + bit[i]) % mod;
    return ret;
  }
  void update(int l, int r, int v) {
    update(l, v);
    if (r != n) update(r + 1, -v);
  }
};
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(5, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      vector<int> vis(n, -1);
      if (j == i) continue;
      int m = 0;
      int f = 0;
      int z = 0;
      for (int k = 0; k < n; k++) {
        if (a[k][i] == 1 && a[k][j] == 1)
          z++;
        else if (a[k][i] == 1)
          m++;
        else if (a[k][j] == 1)
          f++;
      }
      if (m + f - z == n && m != 0 && f != 0) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}
void test() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  test();
}
