#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, INF = 0x3f3f3f3f;
long long qpow(int a, int b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a;
    a = (long long)a * a;
    b >>= 1;
  }
  return ans;
}
inline int read() {
  int X = 0;
  bool flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    X = (X << 1) + (X << 3) + ch - '0';
    ch = getchar();
  }
  if (flag) return X;
  return ~(X - 1);
}
inline void write(int X) {
  if (X < 0) {
    X = ~(X - 1);
    putchar('-');
  }
  if (X > 9) write(X / 10);
  putchar(X % 10 + '0');
}
struct dsu {
 private:
  vector<int> par, ran, cnt;

 public:
  dsu(int n) {
    par.resize(n, 0);
    iota(par.begin(), par.end(), 0);
    ran.resize(n, 0);
    cnt.resize(n, 1);
  }
  int find(int first) {
    if (par[first] == first)
      return first;
    else
      return par[first] = find(par[first]);
  }
  bool unite(int first, int second) {
    first = find(first), second = find(second);
    if (first == second) return false;
    if (ran[first] < ran[second]) {
      par[first] = second;
      cnt[second] += cnt[first];
    } else {
      par[second] = first;
      cnt[first] += cnt[second];
      if (ran[first] == ran[second]) ran[first]++;
    }
    return true;
  }
  bool same(int first, int second) { return find(first) == find(second); }
  int getcnt(int first) { return cnt[find(first)]; }
};
int a, b, c;
void solve() {
  int n;
  cin >> n;
  if (n % 2 == 0)
    cout << (n - 2) / 2 << ' ' << (n) / 2 << ' ' << 1 << "\n";
  else {
    int t = (n - 1) / 2;
    if (t % 2 == 0) {
      cout << t - 1 << ' ' << t + 1 << " " << 1 << "\n";
    } else {
      cout << t - 2 << ' ' << t + 2 << ' ' << 1 << "\n";
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int __ = 1;
  cin >> __;
  while (__--) {
    solve();
  }
  return 0;
}
