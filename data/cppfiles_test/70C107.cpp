#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    string t;
    cin >> t;
    map<char, int> ff;
    long long n = t.size();
    for (long long i = 0; i < n; i++) {
      ff[t[i]]++;
    }
    long long k = ff.size();
    if (k == 1) {
      cout << t << " " << t[0] << endl;
      continue;
    }
    vector<bool> v(26, false);
    vector<long long> x(26, 0);
    long long c = k;
    string ans2;
    for (long long i = n - 1; i >= 0; i--) {
      if (!v[t[i] - 'a']) {
        v[t[i] - 'a'] = true;
        x[t[i] - 'a'] = ff[t[i]] / c;
        c--;
        ans2.push_back(t[i]);
      }
    }
    reverse(ans2.begin(), ans2.end());
    long long m = 0;
    for (long long i = 0; i < 26; i++) m += x[i];
    string ans1 = t.substr(0, m);
    bool ok = true;
    vector<bool> v1(26, false);
    string ans3 = ans1;
    v1[ans2[0] - 'a'] = true;
    for (long long i = 0; i < k - 1; i++) {
      for (long long j = 0; j < ans1.size(); j++) {
        if (!v1[ans1[j] - 'a']) ans3.push_back(ans1[j]);
      }
      v1[ans2[i + 1] - 'a'] = true;
    }
    if (ans3 != t) {
      cout << -1 << endl;
      continue;
    }
    cout << ans1 << " " << ans2 << endl;
  }
  return 0;
}
