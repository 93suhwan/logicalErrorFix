#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using i3 = pair<int, ii>;
using li = pair<ll, int>;
using lii = pair<ll, ii>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<ii>;
using vli = vector<li>;
using vpll = vector<pll>;
using vi3 = vector<i3>;
using vlii = vector<lii>;
const int N = 2e5 + 5;
const ll INF = 1e17 + 7;
const double eps = 1e-9, PI = acos(-1);
int n, m;
int a[N];
int b[N];
int occ[N];
void solve(int testCase) {
  scanf("%d %d", &n, &m);
  map<int, int> freq;
  map<int, int> start;
  for (int i = 0; i < m; i++) {
    scanf("%d", &a[i]);
    freq[a[i]]++;
    b[i] = a[i];
    occ[i] = 0;
  }
  sort(b, b + m);
  for (int i = 0; i < m; i++) {
    if (start.find(b[i]) == start.end()) {
      start[b[i]] = i;
    }
  }
  ll ans = 0;
  for (int i = 0; i < m; i++) {
    int seat = start[a[i]] + freq[a[i]] - 1;
    freq[a[i]]--;
    for (int j = 0; j < seat; j++) {
      ans += 1ll * occ[j];
    }
    occ[seat] = 1;
  }
  printf("%lld\n", ans);
}
int main() {
  int t = 1;
  scanf("%d", &t);
  for (int testCase = 1; testCase <= t; testCase++) {
    solve(testCase);
  }
  return 0;
}
