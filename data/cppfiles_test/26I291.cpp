#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s1;
  string s2;
  cin >> s1;
  s2 = s1;
  long long n = 10;
  for (long long i = 0; i < n; i++) {
    if (i % 2 == 0) {
      if (s2[i] == '?') s2[i] = '0';
      if (s1[i] == '?') s1[i] = '1';
    } else {
      if (s2[i] == '?') s2[i] = '1';
      if (s1[i] == '?') s1[i] = '0';
    }
  }
  long long i;
  long long min = -1;
  long long t1 = 0;
  long long sc1 = 0;
  long long t2 = 0;
  long long sc2 = 0;
  long long es1 = sc1 + 5 - t1;
  long long es2 = sc2 + 5 - t2;
  for (i = 1; i <= n; i++) {
    if (i % 2 != 0) {
      t1++;
      if (s1[i - 1] == '1') sc1++;
      es1 = sc1 + 5 - t1;
      if (es2 < sc1) break;
      if (sc2 > es1) break;
    } else {
      t2++;
      if (s1[i - 1] == '1') sc2++;
      es2 = sc2 + 5 - t2;
      if (sc2 > es1) break;
      if (es2 < sc1) break;
    }
  }
  min = i;
  t1 = 0;
  sc1 = 0;
  t2 = 0;
  sc2 = 0;
  es1 = sc1 + 5 - t1;
  es2 = sc2 + 5 - t2;
  for (long long i = 1; i < n; i++) {
    if (i % 2 != 0) {
      t1++;
      if (s2[i - 1] == '1') sc1++;
      es1 = sc1 + 5 - t1;
      if (es2 < sc1) break;
      if (sc2 > es1) break;
    } else {
      t2++;
      if (s2[i - 1] == '1') sc2++;
      es2 = sc2 + 5 - t2;
      if (sc2 > es1) break;
      if (es2 < sc1) break;
    }
  }
  if (min > i) min = i;
  if (min > 10) min = 10;
  cout << min << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
