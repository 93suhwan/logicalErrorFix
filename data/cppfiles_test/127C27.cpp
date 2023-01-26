#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 7;
const long long M = 1e9 + 7;
const long long mod = 1e9 + 7;
void solve() {
  string str, t;
  cin >> str >> t;
  sort(str.begin(), str.end());
  if (t == "abc") {
    if (str[0] != 'a') {
      cout << str << "\n";
      return;
    }
    long long i = 0, j = 0;
    for (; i < str.size() - 1; i++) {
      if (str[i] == 'b') {
        break;
      }
    }
    for (j = i; j < str.size() - 1; j++) {
      if (str[j] == 'c') {
        break;
      }
    }
    while (j < str.size() && str[j] == 'c') {
      swap(str[i], str[j]);
      i++;
      j++;
    }
  }
  cout << str << "\n";
}
long long n;
long long a[N], pref[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
}
