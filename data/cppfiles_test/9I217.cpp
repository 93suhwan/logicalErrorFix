#include <bits/stdc++.h>
using namespace std;
long long solve() {
  string str;
  cin >> str;
  long long n = str.size(), res = 0;
  unordered_map<char, long long> u;
  for (long long i = 0; i < n; i++) {
    if (u[str[i]] > 2) {
      i++;
      continue;
    }
    res++;
    u[str[i]]++;
  }
  if (res % 2 == 0) return res / 2;
  if (res - 1 > 0) return (res - 1) / 2;
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long testcases = 1;
  cin >> testcases;
  long long n;
  while (testcases--) cout << solve() << endl;
  return 0;
}
