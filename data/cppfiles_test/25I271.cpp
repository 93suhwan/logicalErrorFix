#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s, t;
  cin >> s >> t;
  if (s == t) {
    cout << "YES" << '\n';
    return;
  }
  char first = t[0];
  vector<long long> v;
  for (long long i = 0; i < s.size(); ++i) {
    if (s[i] == first) {
      v.push_back(i);
    }
  }
  long long n = s.size();
  for (long long i = 0; i < v.size(); ++i) {
    long long indx = v[i];
    long long j = 1;
    long long cur_char = t[j];
    string gg = "";
    gg += t[0];
    while (1) {
      if (indx + 1 < n && s[indx + 1] == cur_char) {
        j++;
        cur_char = t[j];
        gg += s[indx + 1];
        indx += 1;
        continue;
      }
      break;
    }
    while (1) {
      if (indx - 1 >= 0 && s[indx - 1] == cur_char) {
        j++;
        cur_char = t[j];
        gg += s[indx - 1];
        indx = indx - 1;
        continue;
      }
      break;
    }
    if (gg == t) {
      cout << "YES" << '\n';
      return;
    }
  }
  cout << "NO" << '\n';
  return;
}
void file_io_with_fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
signed main() {
  file_io_with_fast_io();
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
