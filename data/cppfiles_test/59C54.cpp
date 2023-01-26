#include <bits/stdc++.h>
using namespace std;
int dirx[] = {1, -1, 0, 0};
int diry[] = {0, 0, 1, -1};
struct point {
  int x;
  int y;
};
bool isprime(long long n) {
  if (n < 2) return 0;
  if (n == 2) return 1;
  if (!(n & 1)) return 0;
  long long sq = sqrt(n);
  for (long long i = 3; i <= sq; i += 2) {
    if (n % i == 0) return 0;
  }
  return 1;
}
map<int, int> mp;
bool cmp(pair<int, int> a, pair<int, int> b) {
  return (a.first < b.first && a.second > b.second);
}
bool pow_of_two(int n) { return !(n & (n - 1)); }
bool cmp1(int a, int b) { return mp[a] > mp[b]; }
void solve() {
  int n, ans = 0;
  cin >> n;
  bool ara[1009][10];
  map<int, int> mp;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 5; j++) cin >> ara[i][j];
  for (int i = 1; i <= 5; i++) {
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      if (ara[j][i] == 1) cnt++;
    }
    if (cnt >= (n / 2)) mp[i] = 1;
  }
  for (int i = 1; i <= 5; i++) {
    for (int j = i + 1; j <= 5; j++) {
      bool ok = true;
      for (int k = 1; k <= n; k++) {
        if (ara[k][i] == 0 && ara[k][j] == 0) {
          ok = false;
          break;
        }
      }
      if (ok && mp[i] && mp[j]) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
