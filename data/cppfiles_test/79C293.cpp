#include <bits/stdc++.h>
using namespace std;
long long maxm = -1e18;
long long minm = 1e18;
long long mod = 1e9 + 7;
long long mod1 = 1e9 + 9;
const long double Pi = 3.141592653;
long long int fact(long long int n) {
  if (n == 0) {
    return 1;
  } else if (n == 1) {
    return 1;
  }
  long long int res = 1;
  for (long long int i = 2; i <= n; i++) res = res * i;
  return res;
}
long long int nCr(long long int n, long long int r) {
  return fact(n) / (fact(r) * fact(n - r));
}
bool cmp(pair<long long int, vector<long long int>> a,
         pair<long long int, vector<long long int>> b) {
  return (a.first > b.first);
}
bool isint(double n) {
  long long int j = n;
  double w = n - j;
  if (w > 0) {
    return false;
  }
  return true;
}
long long int count3(long long int x) {
  long long int ret = 0;
  while (x % 3 == 0) {
    ret++;
    x /= 3;
  }
  return ret;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  long long t = 1;
  cin >> t;
  vector<string> v;
  v.push_back("1");
  for (long long int i = 2; i <= 100; i++) {
    bool c = true;
    for (long long int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        v.push_back(to_string(i));
        break;
      }
    }
  }
  while (t--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<char, long long int> m;
    for (long long int i = 0; i < s.size(); i++) {
      m[s[i]]++;
    }
    for (long long int i = 0; i < v.size(); i++) {
      unordered_map<char, long long int> m1;
      for (long long int j = 0; j < v[i].size(); j++) {
        m1[v[i][j]]++;
      }
      bool w = true;
      for (auto it : m1) {
        if (m.find(it.first) != m.end()) {
          if (it.second > m[it.first]) {
            w = false;
            break;
          }
        } else {
          w = false;
          break;
        }
      }
      long long int k = 0;
      for (long long int x = 0; x < s.size(); x++) {
        if (k == v[i].size()) {
          break;
        }
        if (s[x] == v[i][k]) {
          k++;
        }
      }
      if (k != v[i].size()) {
        w = false;
      }
      if (w) {
        cout << v[i].size() << '\n';
        cout << v[i] << '\n';
        break;
      }
    }
  }
  return 0;
}
