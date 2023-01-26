#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second / (a.first * 1.0) < b.second / (b.first * 1.0));
}
void solve() {
  long long n, ans = 0;
  char c;
  cin >> n;
  string s[n];
  map<char, long long> m;
  for (long long i = 0; i < n; i++) {
    cin >> s[i];
    for (long long j = 0; j < s[i].length(); j++) {
      m[s[i][j]]++;
    }
  }
  for (auto it1 : m) {
    vector<pair<long long, long long> > v;
    c = it1.first;
    long long c1 = 0, c2 = 0, temp = 0;
    for (long long i = 0; i < n; i++) {
      long long count = 0;
      for (long long j = 0; j < s[i].length(); j++) {
        if (s[i][j] == c) count++;
      }
      v.push_back({count, s[i].length()});
    }
    sort(v.begin(), v.end(), sortbysec);
    for (auto it2 : v) {
      c1 += it2.first;
      c2 += it2.second;
      if (c1 * 2 > c2)
        temp++;
      else {
        c1 -= it2.first;
        c2 -= it2.second;
      }
    }
    ans = max(ans, temp);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
