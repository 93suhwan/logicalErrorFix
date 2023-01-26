#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 5;
const long long oo = 1e18 + 7, mod1 = 1e9 + 21, mod2 = 1e9 + 87,
                mod3 = 1e9 + 123, mod4 = 1e9 + 33;
string s;
string x;
long long n, m;
pair<pair<long long, long long>, pair<long long, long long> > pref[N];
pair<pair<long long, long long>, pair<long long, long long> > pw10[N << 1];
pair<pair<long long, long long>, pair<long long, long long> > tar;
pair<pair<long long, long long>, pair<long long, long long> > IT[N << 2];
long long ans[N << 2];
void z() {
  string temp = x + s;
  long long l = 0, r = 0;
  ans[0] = temp.length();
  for (long long i = 1; i < temp.length(); i++) {
    if (r < i) {
      l = r = i;
      while (r < temp.length() && temp[r] == temp[r - l]) r++;
      r--;
      ans[i] = (r - l + 1);
    } else if (ans[i - l] < (r - i + 1))
      ans[i] = ans[i - l];
    else {
      l = i;
      while (r < temp.length() && temp[r] == temp[r - l]) r++;
      r--;
      ans[i] = (r - l + 1);
    }
  }
  for (long long i = 0; i < s.length(); i++) ans[i + 1] = ans[i + x.length()];
}
pair<pair<long long, long long>, pair<long long, long long> > get(long long l,
                                                                  long long r) {
  pair<pair<long long, long long>, pair<long long, long long> > ans;
  ans.first.first =
      (pref[r].first.first -
       pref[l - 1].first.first * pw10[r - l + 1].first.first + mod1 * mod1) %
      mod1;
  ans.first.second =
      (pref[r].first.second -
       pref[l - 1].first.second * pw10[r - l + 1].first.second + mod2 * mod2) %
      mod2;
  ans.second.first =
      (pref[r].second.first -
       pref[l - 1].second.first * pw10[r - l + 1].second.first + mod3 * mod3) %
      mod3;
  ans.second.second =
      (pref[r].second.second -
       pref[l - 1].second.second * pw10[r - l + 1].second.second +
       mod4 * mod4) %
      mod4;
  return ans;
}
bool ck(long long l1, long long r1, long long l2, long long r2) {
  if (l1 <= 0 || r1 > n || l2 <= 0 || r2 > n || l1 > r1 || l2 > r2) return 0;
  pair<pair<long long, long long>, pair<long long, long long> > temp1 =
                                                                    get(l1, r1),
                                                                temp2 =
                                                                    get(l2, r2);
  if (((temp1.first.first + temp2.first.first) % mod1) != tar.first.first)
    return 0;
  if (((temp1.first.second + temp2.first.second) % mod2) != tar.first.second)
    return 0;
  if (((temp1.second.first + temp2.second.first) % mod3) != tar.second.first)
    return 0;
  if (((temp1.second.second + temp2.second.second) % mod4) != tar.second.second)
    return 0;
  cout << l1 << " " << r1 << "\n";
  cout << l2 << " " << r2 << "\n";
  return 1;
}
void process() {
  cin >> s >> x;
  n = s.length(), m = x.length();
  z();
  s = '*' + s;
  x = '*' + x;
  for (long long i = 1; i <= m; i++) {
    tar.first.first = (tar.first.first * 10 + (x[i] - '0')) % mod1;
    tar.first.second = (tar.first.second * 10 + (x[i] - '0')) % mod2;
    tar.second.first = (tar.second.first * 10 + (x[i] - '0')) % mod3;
    tar.second.second = (tar.second.second * 10 + (x[i] - '0')) % mod4;
  }
  pw10[0] = {{1, 1}, {1, 1}};
  for (long long i = 1; i <= n; i++) {
    pw10[i].first.first = (pw10[i - 1].first.first * 10) % mod1;
    pw10[i].first.second = (pw10[i - 1].first.second * 10) % mod2;
    pw10[i].second.first = (pw10[i - 1].second.first * 10) % mod3;
    pw10[i].second.second = (pw10[i - 1].second.second * 10) % mod4;
    pref[i].first.first = (pref[i - 1].first.first * 10 + (s[i] - '0')) % mod1;
    pref[i].first.second =
        (pref[i - 1].first.second * 10 + (s[i] - '0')) % mod2;
    pref[i].second.first =
        (pref[i - 1].second.first * 10 + (s[i] - '0')) % mod3;
    pref[i].second.second =
        (pref[i - 1].second.second * 10 + (s[i] - '0')) % mod4;
  }
  for (long long i = 1; i < n; i++) {
    if (ck(i - m + 2, i, i + 1, i + m - 1)) {
      return;
    }
    if (i >= m) {
      long long temp = min(ans[i - m + 1], m);
      if (ck(i - m + 1, i, i + 1, i + (m - temp))) {
        return;
      }
      if (ck(i - m + 1, i, i + 1, i + (m - temp - 1))) {
        return;
      }
    }
  }
  for (long long i = 2; i <= n; i++) {
    if ((i + m - 1) <= n) {
      long long temp = min(ans[i], m);
      if (ck(i - (m - temp), i - 1, i, i + m - 1)) {
        return;
      }
      if (ck(i - (m - temp) + 1, i - 1, i, i + m - 1)) {
        return;
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  process();
}
