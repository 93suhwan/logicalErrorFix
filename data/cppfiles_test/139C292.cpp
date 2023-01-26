#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,03")
#pragma GCC target( \
    "fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
using namespace std::chrono;
bool yes(string s) {
  long long int n = s.size();
  for (long long int i = 0; i < n / 2; i++)
    if (s[i] != s[n / 2 + i]) return false;
  return true;
}
int32_t main() {
  auto start1 = high_resolution_clock::now();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  long long int tc = t;
  while (t--) {
    string s;
    cin >> s;
    if (yes(s) and s.size() % 2 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
  long long int tm = (double)duration.count() / 1000;
  cerr << "Time: " << tm << " ms" << endl;
  return 0;
}
