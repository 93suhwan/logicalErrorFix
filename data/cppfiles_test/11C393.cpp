#include <bits/stdc++.h>
using namespace std;
long long mm = 1000000007;
long long powe(long long a, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = (ans * a) % mm;
    n = n / 2;
    a = (a * a) % mm;
  }
  return ans;
}
long long fac[100005];
void precum() {
  fac[0] = 1;
  for (long long i = 1; i < (100002); ++i) {
    fac[i] = (fac[i - 1] * i) % mm;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s[n];
    vector<long long> ch[26];
    for (long long i = 0; i < (n); ++i) {
      cin >> s[i];
      map<long long, long long> mp;
      for (auto x : s[i]) {
        mp[x - 'a']++;
      }
      long long m = s[i].size();
      for (long long j = 0; j < (26); ++j) {
        ch[j].push_back(2 * mp[j] - m);
      }
    }
    long long ans = 0;
    for (long long i = 0; i < (26); ++i) {
      long long cn = 0, sum = 0;
      sort(ch[i].rbegin(), ch[i].rend());
      for (auto x : ch[i]) {
        sum += x;
        if (sum > 0)
          cn++;
        else {
          break;
        }
      }
      ans = max(ans, cn);
    }
    cout << ans << '\n';
  }
}
