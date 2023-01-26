#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using VI = vector<int>;
using VL = vector<LL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
void dout() { cerr << endl; }
template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
  cerr << H << ' ';
  dout(T...);
}
const int MAX = 1 << 10;
int n, k;
int col[MAX], len[MAX];
int x[MAX];
int e[MAX][MAX];
bool ok(int c) {
  for (int i = (0); i < (n); ++i) {
    for (int j = (1); j < (c + 1); ++j) x[j] = -1;
    for (int j = (0); j < (i); ++j) x[col[j]] = max(x[col[j]], len[j]);
    col[i] = 1;
    for (int j = (2); j < (c + 1); ++j)
      if (x[j] < x[col[i]]) col[i] = j;
    len[i] = x[col[i]] + 1;
    if (len[i] >= k) return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  int l = 1, r = n;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (ok(m))
      r = m;
    else
      l = m;
  }
  ok(r);
  cout << r << "\n";
  for (int i = (0); i < (n); ++i)
    for (int j = (i + 1); j < (n); ++j) cout << col[i] << " ";
  cout << "\n";
}
