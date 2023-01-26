#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
const long long tam = 1020210;
const long long tamlog = 17;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long INF = 1e9;
const double EPS = 1e-9;
const double PI = acos(-1);
bool marca[tam];
string t1, t2;
int n;
bool can(int pos, char chr) {
  if (pos < 0 || pos >= n) return 0;
  return (t1[pos] == chr);
}
void solve() {
  cin >> n;
  for (int i = 0; i < n + 20; i++) marca[i] = 0;
  cin >> t1 >> t2;
  for (int i = 0; i < t2.size(); i++) {
    if (t2[i] == '0') continue;
    if (can(i - 1, '1') && marca[i - 1] == 0) {
      marca[i - 1] = 1;
      continue;
    }
    if (can(i, '0') && !marca[i]) {
      marca[i] = 1;
      continue;
    }
    if (can(i + 1, '1') && !marca[i + 1]) marca[i + 1] = 1;
  }
  int tot = 0;
  for (int i = 0; i < n; i++) {
    tot += marca[i];
  }
  cout << tot << endl;
}
int main() {
  int casos;
  cin >> casos;
  while (casos--) {
    solve();
  }
}
