#include <bits/stdc++.h>
using namespace std;
long long int modexp(long long int x, long long int n, long long int mod) {
  x %= mod;
  long long int res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n /= 2;
  }
  return res;
}
long long int modInverse(long long int n, long long int p) {
  return modexp(n, p - 2, p);
}
long long int nCr(long long int n, long long int r, long long int p) {
  if (r == 0) return 1;
  long long int fac[n + 1];
  fac[0] = 1;
  for (long long int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
bool check(string &curr, vector<char> &v, string &s) {
  string ans = curr;
  set<char> st;
  for (long long int i = 0; i <= v.size() - 1; i++) {
    st.insert(v[i]);
    for (auto x : curr) {
      if (st.find(x) == st.end()) ans += x;
      if (ans.size() > s.size()) return false;
    }
  }
  return ans == s;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t = 1;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long int n = s.size();
    long long int i, j, k;
    map<char, long long int> make_pair;
    set<char> st;
    vector<char> v;
    for (i = n - 1; i >= 0; i--) {
      if (st.find(s[i]) == st.end()) v.push_back(s[i]);
      st.insert(s[i]);
      make_pair[s[i]]++;
    }
    reverse((v).begin(), (v).end());
    string ans = "";
    long long int cnt = 0;
    for (i = 0; i <= v.size() - 1; i++) {
      cnt += make_pair[v[i]] / (i + 1);
    }
    string curr = s.substr(0, cnt);
    if (check(curr, v, s)) {
      cout << curr << " ";
      for (auto x : v) cout << x;
      cout << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
  return 0;
}
