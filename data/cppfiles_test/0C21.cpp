#include <bits/stdc++.h>
using namespace std;
const long long FULL = (1e5) + 100;
const long long INF = 1e18;
const long long MOD = (1e9) + 7;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(9);
  map<char, char> mp;
  for (char i = 'Z', j = 'A'; i <= 'A', j <= 'Z'; i--, j++) {
    mp[i] = j;
  }
  long long n, m;
  cin >> n >> m;
  vector<pair<string, long long> > ar(n);
  for (long long i = 0; i < n; i++) {
    cin >> ar[i].first;
    ar[i].second = i + 1;
    for (long long j = 0; j < m; j++) {
      if (j & 1) {
        ar[i].first[j] = mp[ar[i].first[j]];
      }
    }
  }
  sort(ar.begin(), ar.end());
  for (auto i : ar) {
    cout << i.second << ' ';
  }
  return 0;
}
