#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
template <class T>
void debug(vector<T>& arr) {
  cerr << "[ ";
  for (auto& i : arr) {
    cerr << i << " ";
  }
  cerr << "]" << endl;
}
template <class T>
void debug(T& a) {
  cerr << a << endl;
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2>& P) {
  cout << "{" << P.first << ", " << P.second << "}";
  return out;
}
template <class T1, class T2>
void debug(pair<T1, T2>& P) {
  cerr << "{" << P.first << ", " << P.second << "}" << endl;
}
void solve() {
  long long n;
  string s;
  cin >> n >> s;
  long long cnt = count(s.begin(), s.end(), '?');
  if (cnt == 0) {
    cout << s << endl;
    return;
  }
  if (cnt == n) {
    for (long long i = 0; i < n; i++) {
      if (i & 1)
        cout << 'B';
      else
        cout << 'R';
    }
    cout << endl;
    return;
  }
  long long F;
  for (long long i = 0; i < n; i++) {
    if (s[i] != '?') {
      F = i;
      break;
    }
  };
  for (long long i = F; i >= 0; i--) {
    if (i == 0) {
      if (s[1] == 'R')
        s[0] = 'B';
      else
        s[0] = 'R';
    } else {
      if (s[i + 1] == 'R' && s[i - 1] == 'R')
        s[i] = 'B';
      else if (s[i + 1] == 'B' && s[i - 1] == 'B')
        s[i] = 'R';
      else if (s[i - 1] == '?' && s[i + 1] == 'R')
        s[i] = 'B';
      else if (s[i - 1] == '?' && s[i + 1] == 'B')
        s[i] = 'R';
      else
        s[i] = 'R';
    }
  }
  for (long long i = F + 1; i < n; i++) {
    if (i == n - 1) {
      if (s[i - 1] == 'R')
        s[n - 1] = 'B';
      else
        s[n - 1] = 'R';
    } else {
      if (s[i + 1] == 'R' && s[i - 1] == 'R')
        s[i] = 'B';
      else if (s[i + 1] == 'B' && s[i - 1] == 'B')
        s[i] = 'R';
      else if (s[i + 1] == '?' && s[i - 1] == 'R')
        s[i] = 'B';
      else if (s[i + 1] == '?' && s[i - 1] == 'B')
        s[i] = 'R';
      else
        s[i] = 'R';
    }
  }
  cout << s << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t begin = clock();
  long long t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    cerr << "Testcase #" << i + 1 << endl;
    solve();
    cerr << endl;
  }
  return 0;
}
