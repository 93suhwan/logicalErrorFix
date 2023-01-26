#include <bits/stdc++.h>
#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-signed-bitwise"
#pragma ide diagnostic ignored "cert-err58-cpp"
using ll = long long;
using uint = unsigned;
const int MAXN = 1000010, INF = 1000000100;
using namespace std;
int a[MAXN], lg2[2 * MAXN];
bool used[MAXN];
struct Spt {
  vector<bool> f[25];
  void build(int n, const vector<bool> &a) {
    for (int i = 0; i <= lg2[2 * n]; ++i) {
      f[i].resize(2 * n);
    }
    for (int i = 0; i < 2 * n; ++i) {
      f[0][i] = a[(i >= n ? i - n : i)];
    }
    for (int d = 1; (1 << d) <= 2 * n; ++d) {
      for (int i = 0; i + (1 << d) <= 2 * n; ++i) {
        f[d][i] = f[d - 1][i] & f[d - 1][i + (1 << (d - 1))];
      }
    }
  }
  int get(int l, int r) {
    int d = lg2[r - l];
    return f[d][l] & f[d][r - (1 << d)];
  }
};
struct Block {
  vector<bool> a;
  Spt spt;
};
int compute(Block &b) {
  int n = b.a.size();
  b.spt.build(n, b.a);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int l = 0, r = n + 1;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (b.spt.get(i, i + m)) {
        l = m;
      } else {
        r = m;
      }
    }
    if (l == n) {
      l = INF;
    }
    ans = max(ans, l);
  }
  return ans;
}
vector<Block> b;
void one() {
  int n, d;
  cin >> n >> d;
  b.clear();
  fill(used, used + n, false);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    if (used[i]) {
      continue;
    }
    used[i] = true;
    b.push_back(Block());
    b.back().a.push_back(a[i]);
    for (int j = (i + n - d) % n; j != i; j = (j + n - d) % n) {
      b.back().a.push_back(a[j]);
      used[j] = true;
    }
  }
  int ans = 0;
  for (int i = 0; i < b.size(); ++i) {
    ans = max(ans, compute(b[i]));
  }
  cout << (ans == INF ? -1 : ans) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  lg2[1] = 0;
  for (int i = 2; i < 2 * MAXN; ++i) {
    lg2[i] = lg2[i / 2] + 1;
  }
  int t;
  cin >> t;
  while (t--) {
    one();
  }
  return 0;
}
