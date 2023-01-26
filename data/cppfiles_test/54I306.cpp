#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O0")
#pragma GCC optimize("O1")
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int n, k;
vector<int> powers;
void calc() {
  long long tmp = 1;
  for (int i = 0; i <= N; i++) {
    powers.push_back(tmp);
    tmp *= 2;
    tmp %= mod;
  }
}
void solve() {
  cin >> n >> k;
  long long tmp = powers[n - 1];
  long long res = 1;
  if (n % 2 == 1) {
    tmp++;
    for (int i = 0; i < k; i++) {
      res *= tmp;
      res %= mod;
    }
    cout << res << endl;
    return;
  }
  tmp--;
  for (int i = 0; i < k; i++) {
    res *= tmp;
    res %= mod;
  }
  long long tmp2[k + 10];
  tmp2[0] = 1;
  long long pn[k + 10];
  pn[0] = 1;
  for (int i = 1; i <= k; i++) {
    tmp2[i] = tmp2[i - 1] * tmp;
    tmp2[i] %= mod;
  }
  for (int i = 1; i <= k; i++) {
    pn[i] = pn[i - 1] * powers[n];
    pn[i] %= mod;
  }
  for (int i = 1; i <= k; i++) {
    res += tmp2[i - 1] * pn[k - i];
  }
  cout << res << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  calc();
  while (t--) {
    solve();
  }
}
