#include <bits/stdc++.h>
using namespace std;
using ulli = unsigned long long int;
using lli = long long int;
using ld = long double;
using ll = long long;
void solve() {
  lli n, k;
  cin >> n >> k;
  vector<lli> v(n);
  for (int i = 0; i < (int)(n); ++i) cin >> v[i];
  sort((v).begin(), (v).end());
  lli ans1{0}, ans2{0};
  lli i{0}, j{n - 1};
  lli st = k;
  while (i < j && k > 0) {
    ans1 += v[i] / v[j];
    k--;
    i++;
    j--;
  }
  for (lli p{i}; p <= j; p++) {
    ans1 += v[p];
  }
  lli idx = n - 1;
  for (lli p{st}; p > 0; p--) {
    ans2 += v[idx - 1] / v[idx];
    idx = idx - 2;
  }
  for (lli p{0}; p <= idx; p++) {
    ans2 += v[p];
  }
  cout << min(ans2, ans1) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  int T{1};
  cin >> T;
  while (T--) {
    solve();
  }
}
