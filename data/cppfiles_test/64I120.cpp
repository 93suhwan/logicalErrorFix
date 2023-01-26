#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 5;
const long long oo = 1e18 + 7, mod1 = 1e9 + 21, mod2 = 1e9 + 87,
                mod3 = 1e9 + 123, mod4 = 1e9 + 33;
string s;
string x;
long long n, m;
pair<pair<long long, long long>, pair<long long, long long> > pw10[N << 1];
pair<pair<long long, long long>, pair<long long, long long> > tar;
pair<pair<long long, long long>, pair<long long, long long> > IT[N << 2];
long long ans[N << 2];
void init(long long id, long long l, long long r) {
  if (l == r) {
    IT[id].first.first = IT[id].first.second = IT[id].second.first =
        IT[id].second.second = (s[l] - '0');
    return;
  }
  long long mid = (l + r) >> 1;
  init(id << 1, l, mid);
  init(id << 1 | 1, mid + 1, r);
  IT[id].first.first = (IT[id << 1].first.first * pw10[r - mid].first.first +
                        IT[id << 1 | 1].first.first) %
                       mod1;
  IT[id].first.second = (IT[id << 1].first.second * pw10[r - mid].first.second +
                         IT[id << 1 | 1].first.second) %
                        mod2;
  IT[id].second.first = (IT[id << 1].second.first * pw10[r - mid].second.first +
                         IT[id << 1 | 1].second.first) %
                        mod3;
  IT[id].second.second =
      (IT[id << 1].second.second * pw10[r - mid].second.second +
       IT[id << 1 | 1].second.second) %
      mod4;
}
pair<pair<long long, long long>, pair<long long, long long> > get(
    long long id, long long l, long long r, long long L, long long R) {
  if (l > R || r < L) return {{0, 0}, {0, 0}};
  if (l >= L && r <= R) return IT[id];
  long long mid = (l + r) >> 1;
  pair<pair<long long, long long>, pair<long long, long long> >
      a = get(id << 1, l, mid, L, R),
      b = get(id << 1 | 1, mid + 1, r, L, R);
  if (R <= mid)
    return a;
  else if (L > mid)
    return b;
  pair<pair<long long, long long>, pair<long long, long long> > c;
  c.first.first =
      (a.first.first * pw10[min(r, R) - mid].first.first + b.first.first) %
      mod1;
  c.first.second =
      (a.first.second * pw10[min(r, R) - mid].first.second + b.first.second) %
      mod2;
  c.second.first =
      (a.second.first * pw10[min(r, R) - mid].second.first + b.second.first) %
      mod3;
  c.second.second = (a.second.second * pw10[min(r, R) - mid].second.second +
                     b.second.second) %
                    mod4;
  return c;
}
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
bool ck(long long l1, long long r1, long long l2, long long r2) {
  if (l1 <= 0 || r1 > n || l2 <= 0 || l2 > n || l1 > r1 || l2 > r2) return 0;
  pair<pair<long long, long long>, pair<long long, long long> > temp1 =
                                                                    get(1, 1, n,
                                                                        l1, r1),
                                                                temp2 =
                                                                    get(1, 1, n,
                                                                        l2, r2);
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
  }
  init(1, 1, n);
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
      long long temp = min(ans[i + m - 1], m);
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
