#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int mod = 1e9 + 7;
vector<int> dg[100];
void dd(long long n, int i) {
  while (n) {
    dg[i].push_back(n % 10);
    n /= 10;
  }
  reverse(dg[i].begin(), dg[i].end());
}
vector<int> dig;
void dd(long long n) {
  dig.clear();
  while (n) {
    dig.push_back(n % 10);
    n /= 10;
  }
  reverse(dig.begin(), dig.end());
}
int cal(vector<int> a, vector<int> b) {
  int cnt = 0, com = 0;
  int pa = 0, pb = 0;
  do {
    while (pa < a.size() && a[pa] != b[pb]) {
      ++pa;
      ++cnt;
    }
    if (pa < a.size() && pb < b.size() && a[pa] == b[pb])
      ++com, ++pa, ++pb;
    else
      break;
  } while (pb < b.size() && pa < a.size());
  return a.size() + b.size() - com * 2;
}
void solve() {
  long long n;
  cin >> n;
  dd(n);
  int ans = 100, tar;
  for (int i = 0; i <= 40; ++i) {
    int now = cal(dig, dg[i]);
    if (now < ans) {
      ans = now;
      tar = i;
    }
  }
  cout << ans << '\n';
}
int main() {
  for (long long i = 0; i <= 40; ++i) dd(1LL << i, i);
  int T;
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) solve();
  return 0;
}
