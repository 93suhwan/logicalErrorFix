#include <bits/stdc++.h>
using namespace std;
long long arr[1000006];
vector<long long> vec;
unordered_map<long long, long long> mapa;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    if (a >= b) {
      cout << a + b << "\n";
      continue;
    }
    if (b % a == 0) {
      cout << b << "\n";
      continue;
    }
    cout << (a + b) / 2 << "\n";
  }
  return 0;
}
