#include <bits/stdc++.h>
const long long mod = 1000 * 1000 * 1000 + 7;
const long long mod1 = 998244353;
const long long INF = 1ll * 1000 * 1000 * 1000 * 1000 * 1000 * 1000 + 7;
using namespace std;
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (long long)(res * x);
    y = y >> 1;
    x = (long long)(x * x);
  }
  return res;
}
template <typename T>
T MIN(T first) {
  return first;
}
template <typename T, typename... Args>
T MIN(T first, Args... args) {
  return min(first, MIN(args...));
}
template <typename T>
T MAX(T first) {
  return first;
}
template <typename T, typename... Args>
T MAX(T first, Args... args) {
  return max(first, MAX(args...));
}
template <typename... Args>
void logger(string vars, Args&&... values) {
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
}
long long rec(vector<string> temp, char x) {
  vector<long long> res;
  long long tans = 0;
  long long dif = 0;
  for (int(i) = (0); (i) < (int((temp).size())); ++(i)) {
    long long cnt = 0;
    for (int(j) = (0); (j) < ((int)temp[i].length()); ++(j)) {
      if (temp[i][j] == x) cnt += 1;
    }
    if (2 * cnt > (int)temp[i].length()) {
      tans += 1;
      dif += 2 * cnt - temp[i].length();
    } else {
      res.push_back(2 * cnt - temp[i].length());
    }
  }
  sort(res.begin(), res.end());
  for (int(i) = (0); (i) < (int((res).size())); ++(i)) {
    if (dif > abs(res[i])) {
      tans += 1;
      dif -= abs(res[i]);
    }
  }
  return tans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    vector<string> a(n);
    for (int(i) = (0); (i) < (n); ++(i)) cin >> a[i];
    long long ans = 0;
    for (char i = 'a'; i <= 'e'; i++) {
      ans = max(ans, rec(a, i));
    }
    cout << ans << "\n";
  }
  return 0;
}
