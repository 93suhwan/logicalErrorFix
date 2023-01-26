#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
const int MM = 998244353;
int _atharva_() {
  vector<long long> v(7);
  for (int i = 0; i < 7; i++) {
    cin >> v[i];
  };
  long long a = v[0];
  long long b = v[1];
  long long c = v[6] - a - b;
  cout << a << " ";
  ;
  cout << b << " ";
  ;
  cout << c << " ";
  ;
  cout << "\n";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  cin >> TESTS;
  while (TESTS--) _atharva_();
  cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms"
       << '\n';
  return 0;
}
