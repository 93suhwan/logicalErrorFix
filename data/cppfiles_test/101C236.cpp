#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 1;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
void solve() {
  int n;
  cin >> n;
  vector<long long> vec(n);
  for (long long i = 0; i < n; i++) {
    cin >> vec[i];
  }
  string s;
  cin >> s;
  vector<long long> vecb, vecr;
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'B') {
      vecb.push_back(vec[i]);
    } else
      vecr.push_back(vec[i]);
  }
  sort(vecb.begin(), vecb.end());
  sort(vecr.begin(), vecr.end());
  for (long long i = 0; i < vecb.size(); i++) {
    if (vecb[i] < i + 1) {
      cout << "NO\n";
      return;
    }
  }
  int k = vecb.size();
  for (long long i = 0; i < vecr.size(); i++) {
    if (vecr[i] > i + k + 1) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
