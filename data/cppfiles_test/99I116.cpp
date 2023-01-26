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
  if (tw.size() == 0) {
    cout << "YES"
         << "\n";
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n; j++) cout << ans[i][j];
      cout << "\n";
    }
    return;
  }
  for (long long i = 0; i < tw.size(); i++) {
    int x = tw[(i + 1) % (tw.size())];
    if (ans[tw[i]][x] == '!')
      ans[tw[i]][x] = '+';
    else {
      cout << "NO"
           << "\n";
      return;
    }
    if (ans[x][tw[i]] == '!')
      ans[x][tw[i]] = '-';
    else {
      cout << "NO"
           << "\n";
      return;
    }
  }
  for (long long i = 0; i < n; i++) {
    bool is = 0;
    long long cnt = 0;
    if (s[i] == '2') is = 1;
    for (long long j = 0; j < n; j++) {
      if (i == j)
        ans[i][j] = 'X';
      else if (ans[i][j] == '!')
        ans[i][j] = '=';
      if (ans[i][j] == '+') cnt++;
    }
    if (is && !cnt) {
      cout << "NO"
           << "\n";
      return;
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
