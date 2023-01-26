#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
const int mod = 1e9 + 7;
const long long INFL = LLONG_MAX;
const int INFI = INT_MAX;
using namespace std;
template <class T>
void cinn(T& x) {
  cin >> x;
}
template <class H, class... T>
void cinn(H& h, T&... t) {
  cinn(h);
  cinn(t...);
}
template <class A>
void cinn(vector<A>& x) {
  for (auto& a : x) cinn(a);
}
void Shazam() {
  long long n;
  cinn(n);
  string s;
  cinn(s);
  long long on = 0, tw1 = 0;
  for (long long i = 0; i < n; i++) ((s[i] == '1') ? on++ : tw1++);
  if (tw1 != 0 && tw1 <= on) {
    cout << "NO"
         << "\n";
    return;
  }
  if (tw1 == 2 && n == 2) {
    cout << "NO"
         << "\n";
    return;
  }
  cout << "YES"
       << "\n";
  char ans[n][n];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) ans[i][j] = '!';
  }
  vector<long long> tw;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '2') {
      tw.push_back(i);
      continue;
    }
    for (long long j = 0; j < n; j++) ans[j][i] = '=';
    for (long long j = 0; j < n; j++) {
      if (i == j)
        ans[i][j] = 'X';
      else
        ans[i][j] = '=';
    }
  }
  for (long long i = 0; i < tw.size(); i++) {
    int x = tw[(i + 1) % (tw.size())];
    ans[tw[i]][x] = '+';
    ans[x][tw[i]] = '-';
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      if (i == j)
        ans[i][j] = 'X';
      else if (ans[i][j] == '!')
        ans[i][j] = '-';
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) cout << ans[i][j];
    cout << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cinn(t);
  while (t--) Shazam();
  return 0;
}
