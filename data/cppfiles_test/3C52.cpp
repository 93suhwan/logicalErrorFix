#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops", \
                     "omit-frame-pointer", "inline")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native", "no-zero-upper")
using namespace std;
const long long mod = (1e9 + 7);
const long double eps = (1e-9);
const long long oo = (long long)(1e18 + 5);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string second;
  cin >> second;
  if (second.size() == 1) {
    if (second == "0" || second == "X" || second == "_")
      cout << (1) << '\n';
    else
      cout << (0) << '\n';
    return 0;
  }
  if (second[0] == '0') {
    cout << (0) << '\n';
    return 0;
  }
  if (second.size() == 2) {
    if (second == "XX") {
      cout << (0) << '\n';
      return 0;
    }
    int ans = 0;
    if ((second[0] == '2' || second[0] == 'X' || second[0] == '_') &&
        (second[1] == '5' || second[1] == 'X' || second[1] == '_'))
      ans++;
    if ((second[0] == '5' || second[0] == 'X' || second[0] == '_') &&
        (second[1] == '0' || second[1] == 'X' || second[1] == '_'))
      ans++;
    if ((second[0] == '7' || second[0] == 'X' || second[0] == '_') &&
        (second[1] == '5' || second[1] == 'X' || second[1] == '_'))
      ans++;
    cout << (ans) << '\n';
    return 0;
  }
  long long mul = 1;
  int sz = second.size() - 1;
  int m2 = 10;
  bool hay = 0;
  if (second[0] == 'X' || second[0] == '_') {
    if (second[0] == '_')
      mul = 9;
    else {
      m2 = 9;
      hay = 1;
    }
  }
  for (int i = 1; i < sz - 1; i++) {
    if (second[i] == '_') mul *= 10;
    if (second[i] == 'X') hay = 1;
  }
  if (second[sz - 1] != 'X' && second[sz] != 'X' && hay) mul *= m2;
  int ans = 0;
  if (second[sz - 1] == 'X' && second[sz] == 'X') {
    if (second[0] != 'X') ans = 1;
  } else {
    if ((second[sz - 1] == '0' || (second[sz - 1] == 'X' && second[0] != 'X') ||
         second[sz - 1] == '_') &&
        (second[sz] == '0' || (second[sz] == 'X' && second[0] != 'X') ||
         second[sz] == '_'))
      ans++;
    if ((second[sz - 1] == '2' || second[sz - 1] == 'X' ||
         second[sz - 1] == '_') &&
        (second[sz] == '5' || second[sz] == 'X' || second[sz] == '_'))
      ans++;
    if ((second[sz - 1] == '5' || second[sz - 1] == 'X' ||
         second[sz - 1] == '_') &&
        (second[sz] == '0' || (second[sz] == 'X' && second[0] != 'X') ||
         second[sz] == '_'))
      ans++;
    if ((second[sz - 1] == '7' || second[sz - 1] == 'X' ||
         second[sz - 1] == '_') &&
        (second[sz] == '5' || second[sz] == 'X' || second[sz] == '_'))
      ans++;
  }
  cout << (ans * mul) << '\n';
  return 0;
}
