#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print(vector<T> &a) {
  for (auto x : a) cout << x << ' ';
  cout << '\n';
}
long long query(long long x, long long y) {
  cout << "? " << x << " " << y << "\n";
  cout.flush();
  long long c;
  cin >> c;
  return c;
}
void take_inp(vector<long long> &a) {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(), a.end());
}
string red(string s) {
  string ss = "";
  for (long long i = 0; i < s.length(); i++)
    if (s[i] != '*') ss += s[i];
  return ss;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n, k, x;
    cin >> n >> k >> x;
    string s;
    cin >> s;
    if (x == 1) {
      cout << red(s) << "\n";
      continue;
    }
    vector<vector<long long> > v;
    for (long long i = n - 1; i >= 0; i--) {
      if (s[i] == 'a') {
        continue;
      }
      long long j = i;
      while (j >= 0 && s[i] == s[j]) j--;
      v.push_back({i, (i - j)});
      i = j + 1;
    }
    long long prd = 1;
    long long i;
    reverse(v.begin(), v.end());
    for (i = (long long)v.size() - 1; i >= 0; i--) {
      prd = prd * (v[i][1] * k + 1);
      if (prd >= x) break;
    }
    string ans = s.substr(0, v[0][0]);
    for (long long j = i; j < v.size(); j++) {
      prd /= v[j][1] * k + 1;
      long long cnt = ceil(double(x / prd));
      for (long long k = 1; k < cnt; k++) ans += 'b';
      x -= (cnt - 1) * (prd);
      if (j == (long long)v.size() - 1) {
        for (long long k = v[j][0] + 1; k < n; k++) ans += s[i];
      } else {
        for (long long k = v[j][0] + 1; k < v[j + 1][0]; k++) ans += s[k];
      }
    }
    ans = red(ans);
    cout << ans << "\n";
  }
}
