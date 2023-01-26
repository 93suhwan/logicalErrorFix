#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
const long long remi = 998244353;
using namespace std;
const long long N = 1e5 + 10;
bool checka(vector<long long> &v, long long n, long long a) {
  bool flag2 = 0;
  for (long long i = 0; i < n; i++) {
    if (i % 2 == 0 && v[i] % a != 0) {
      flag2 = 1;
      break;
    } else if (i % 2 != 0 && v[i] % a == 0) {
      flag2 = 1;
      break;
    }
  }
  return flag2;
}
bool checkb(vector<long long> &v, long long n, long long b) {
  bool flag22 = 0;
  for (long long i = 0; i < n; i++) {
    if (i % 2 == 0 && v[i] % b == 0) {
      flag22 = 1;
      break;
    } else if (i % 2 != 0 && v[i] % b != 0) {
      flag22 = 1;
      break;
    }
  }
  return flag22;
}
void Sun_god() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long pos = max(v[0], v[1]);
  long long mini = min(v[0], v[1]);
  while (pos >= mini) {
    if (checka(v, n, pos) == 0 || checkb(v, n, pos) == 0) {
      cout << pos << "\n";
      return;
    }
    pos--;
  }
  cout << 0 << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    Sun_god();
  }
  return 0;
}
