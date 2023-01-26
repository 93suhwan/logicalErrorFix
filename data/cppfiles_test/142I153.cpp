#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long mod = 1e9 + 7, inf = (1e18), MAX = 2e5 + 5;
long long n, m, i, j;
void alpha_Q() {
  string a, s;
  cin >> a >> s;
  if ((long long)(a).size() > (long long)(s).size()) {
    cout << -1;
    return;
  }
  string b = "";
  reverse(a.begin(), a.end());
  reverse(s.begin(), s.end());
  long long j = 0;
  n = (long long)(s).size();
  for (long long i = 0; i < (long long)(a).size(); i++) {
    long long nums = s[j] - '0';
    long long numa = a[i] - '0';
    j++;
    if (nums >= numa) {
      b += char(nums - numa + '0');
    } else {
      if (j >= n) {
        cout << -1;
        return;
      }
      long long d2 = (s[j] - '0') * 10 + nums;
      j++;
      long long dif = d2 - numa;
      if (dif >= 10) {
        cout << -1;
        return;
      }
      b += char(dif + '0');
    }
  }
  for (long long i = j; i < n; i++) b += s[i];
  while (!b.empty() and b.back() == '0') b.pop_back();
  reverse(b.begin(), b.end());
  if ((long long)(b).size() == 0) {
    b.push_back('0');
  }
  cout << b;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long loser = 1;
  cin >> loser;
  while (loser--) {
    alpha_Q();
    cout << "\n";
  }
  return 0;
}
