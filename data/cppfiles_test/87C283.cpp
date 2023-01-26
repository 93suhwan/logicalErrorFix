#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using PI = pair<int, int>;
using PL = pair<ll, ll>;
const int MOD = 1e9 + 7;
const int MAXN = 105;
int T;
int N;
ll a[MAXN];
ll solve() {
  cin >> N;
  for (int i = (1); i <= (N); ++i) cin >> a[i];
  ll cur = 0;
  for (int i = (1); i <= (N); ++i)
    if (a[i] > i + cur) {
      cur += a[i] - (i + cur);
    }
  return cur;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) cout << solve() << endl;
  return 0;
}
