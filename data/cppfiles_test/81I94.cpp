#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, d;
pii A[500005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> d;
  int m = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    int s, a;
    cin >> s >> a;
    if (s < d) continue;
    if (s >= a) {
      ans++;
      continue;
    }
    A[++m] = pii(a, s);
  }
  sort(A + 1, A + m + 1);
  int p = d;
  for (int i = 1; i <= m; i++) {
    if (A[i].second < p) continue;
    ans++;
    p = A[i].first;
  }
  cout << ans;
  return 0;
}
