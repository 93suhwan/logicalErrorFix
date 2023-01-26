#include <bits/stdc++.h>
using namespace std;
const double EPS = (1e-7);
long long dcmp(double x, double y) {
  return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}
long long n;
string s;
long long arr[8];
vector<long long> fun() {
  vector<long long> temp(3);
  long long p = 6ll;
  for (long long i = 0; i < p; i++) {
    for (long long j = i + 1; j < p; j++) {
      for (long long k = j + 1; k < p; k++) {
        if (arr[i] + arr[j] + arr[k] == arr[6]) {
          temp[0] = arr[i];
          temp[1] = arr[j];
          temp[2] = arr[k];
          return temp;
        }
      }
    }
  }
  return temp;
}
long long solve() {
  for (long long i = 0; i < 7; i++) cin >> arr[i];
  vector<long long> temp = fun();
  for (auto it : temp) cout << it << " ";
  return 0;
}
signed main() {
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
