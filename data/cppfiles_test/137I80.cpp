#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5, mod = 1e9 + 7;
const long long ll_lim = 1e18 + 7;
const long long int_lim = 1e9 + 7;
int tc;
long long x, y;
bool maximize(long long& x, long long y) {
  if (x < y) {
    x = y;
    return 1;
  }
  return 0;
}
bool minimize(long long& x, long long y) {
  if (x > y) {
    x = y;
    return 1;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> x >> y;
  string S = "", T = "", S_1 = "", S_2 = "";
  while (x > 0) {
    if (x % 2 == 0)
      S = "0" + S;
    else
      S = "1" + S;
    x /= 2ll;
  }
  while (S[0] == '0') S.erase(0, 1);
  while (y > 0) {
    if (y % 2 == 0)
      T = "0" + T;
    else
      T = "1" + T;
    y /= 2ll;
  }
  while (T[0] == '0') T.erase(0, 1);
  int n = S.size();
  S_1 = S + "1";
  reverse(S_1.begin(), S_1.end());
  int m = S_1.size();
  S_2 = S + "0";
  reverse(S_2.begin(), S_2.end());
  if (S_2 == T || S == T) {
    cout << "YES";
    return 0;
  }
  while (S_2[0] == '0') S_2.erase(0, 1);
  int k = S_2.size();
  bool ok = 0;
  for (int i = 0; i < T.size(); i++) {
    string xo = T.substr(i, n);
    string xo1 = T.substr(i, m);
    string xo2 = T.substr(i, k);
    if (xo == S) {
      ok = 1;
      for (int j = i + n; j < T.size() - 1; j++)
        if (T[j] == '0') ok = 0;
      if (ok) break;
    }
    if (xo1 == S_1) {
      ok = 1;
      for (int j = i + m; j < T.size() - 1; j++)
        if (T[j] == '0') ok = 0;
      if (ok) break;
    }
    if (xo2 == S_2) {
      ok = 1;
      for (int j = i + k; j < T.size() - 1; j++)
        if (T[j] == '0') ok = 0;
      if (ok) break;
    }
    if (T[i] == '0') break;
  }
  if (ok)
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
}
