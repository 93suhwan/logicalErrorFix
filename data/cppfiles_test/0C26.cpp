#include <bits/stdc++.h>
using namespace std;
long long n;
pair<string, long long> s[1000005];
long long m;
bool cmp(pair<string, long long> a, pair<string, long long> b) {
  string s = a.first, t = b.first;
  for (long long i = 0; i < (m); i++)
    if (s[i] != t[i]) {
      if (i & 1)
        return s[i] > t[i];
      else
        return s[i] < t[i];
    }
  return a.second < b.second;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (long long i = 0; i < (n); i++) cin >> s[i].first, s[i].second = i + 1;
  sort(s, s + n, cmp);
  for (long long i = 0; i < (n); i++) cout << s[i].second << " ";
  return 0;
}
