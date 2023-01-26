#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const long long int mod = 1e9 + 7;
long long int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0, ans1 = 0,
              ans2 = 0, ans3 = 0;
bool prime[1000001];
bool comp(string s1, string s2) {
  if (s1.size() > s2.size()) {
    return true;
  } else if (s1.size() < s2.size()) {
    return false;
  } else {
    if (s1 > s2) {
      return false;
    } else {
      return true;
    }
  }
}
void sieve() {
  memset(prime, true, sizeof(prime));
  for (long long int i = 2; i * i <= 1000000; i++)
    if (prime[i])
      for (long long int j = i * i; j <= 1000000; j += i) prime[j] = false;
  prime[0] = prime[1] = false;
}
void solve() {
  vector<long long int> v1;
  for (long long int i = 0; i < 7; i++) {
    long long int a1;
    cin >> a1;
    v1.push_back(a1);
  }
  sort((v1).begin(), (v1).end());
  cout << v1[0] << " " << v1[1] << " " << (v1.back() - v1[0] - v1[1]) << endl;
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
