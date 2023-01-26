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
  if (n % 2 == 1) {
    tmp++;
  }
  long long res = 1;
  for (int i = 0; i < k; i++) {
    res *= tmp;
    res %= mod;
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
