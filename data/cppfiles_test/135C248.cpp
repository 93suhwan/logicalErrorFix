#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  int sum = 0;
  for (int i = 0; i < n; i++) cin >> v[i], sum += v[i];
  sort((v).begin(), (v).end(), greater<int>());
  vector<bool> taken(n, false);
  int id = k;
  for (int i = 0; i < id; i++) {
    sum -= v[i] + v[k];
    sum += min(v[i], v[k]) / max(v[i], v[k]);
    k++;
  }
  cout << sum << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
