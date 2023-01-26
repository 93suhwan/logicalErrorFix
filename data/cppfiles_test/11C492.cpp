#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
vector<long long> calculate(char a, vector<string> s) {
  vector<long long> f;
  for (long long i = 0; i < s.size(); i++) {
    string ff = s[i];
    long long freqc = 0;
    for (long long j = 0; j < ff.length(); j++) {
      if (ff[j] == a) freqc++;
    }
    f.push_back(2 * freqc - ff.length());
  }
  return f;
}
void solve() {
  long long n;
  cin >> n;
  vector<string> s(n);
  for (long long i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<long long> a = calculate('a', s);
  vector<long long> b = calculate('b', s);
  vector<long long> c = calculate('c', s);
  vector<long long> d = calculate('d', s);
  vector<long long> e = calculate('e', s);
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  sort(b.rbegin(), b.rend());
  sort(c.rbegin(), c.rend());
  sort(d.rbegin(), d.rend());
  sort(e.rbegin(), e.rend());
  long long aa = 0;
  long long bb = 0;
  long long cc = 0;
  long long dd = 0;
  long long ee = 0;
  long long curr = 0;
  for (long long i = 0; i < n; i++) {
    curr += a[i];
    if (curr > 0) aa++;
  }
  curr = 0;
  for (long long i = 0; i < n; i++) {
    curr += b[i];
    if (curr > 0)
      bb++;
    else
      break;
  }
  curr = 0;
  for (long long i = 0; i < n; i++) {
    curr += c[i];
    if (curr > 0)
      cc++;
    else
      break;
  }
  curr = 0;
  for (long long i = 0; i < n; i++) {
    curr += d[i];
    if (curr > 0)
      dd++;
    else
      break;
  }
  curr = 0;
  for (long long i = 0; i < n; i++) {
    curr += e[i];
    if (curr > 0)
      ee++;
    else
      break;
  }
  cout << max(aa, max(bb, max(cc, max(dd, ee)))) << '\n';
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
}
