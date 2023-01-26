#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int INF = 1000000000 + 1e8;
const long long LINF = 2000000000000000000;
const int N = 1e5 + 1010;
const long long mod = 1e9 + 7;
int phi[N];
vector<int> divs[N];
int cnt[N];
void calcPhi() {
  phi[0] = 0;
  phi[1] = 1;
  for (int i = 2; i < N; i++) phi[i] = i;
  for (int i = 2; i < N; i++)
    if (phi[i] == i)
      for (int j = i; j < N; j += i) phi[j] -= phi[j] / i;
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &to : a) cin >> to;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        divs[i].push_back(j);
        if (j != a[i] / j) {
          divs[i].push_back(a[i] / j);
        }
      }
    }
  }
  calcPhi();
  long long ans = 0;
  long long s = 0;
  for (int x = 1; x <= n; x++) {
    for (int i = x - 1; i < n; i += x) {
      for (int q = 0; q < int(divs[i].size()); q++) {
        cnt[divs[i][q]]++;
      }
    }
    s = 0;
    for (int i = x - 1; i < n; i += x) {
      for (int q = 0; q < int(divs[i].size()); q++) {
        if (cnt[divs[i][q]] > 0) {
          s = (s + 1LL * cnt[divs[i][q]] * cnt[divs[i][q]] * phi[divs[i][q]]);
          s %= mod;
          cnt[divs[i][q]] = 0;
        }
      }
    }
    ans = (ans + phi[x] * s) % mod;
  }
  cout << ans;
}
int main() {
  srand(time(0));
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tst = 1;
  while (tst--) {
    solve();
  }
}
