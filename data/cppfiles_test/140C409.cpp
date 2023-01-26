#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  while (n--) {
    long long t;
    cin >> t;
    if (t == 1) {
      cout << 1 << endl;
      continue;
    }
    map<long long, long long> m;
    for (long long i = 1; i < t; i++) {
      if (pow(i, 2) > t) break;
      if (pow(i, 2) <= t) m[pow(i, 2)]++;
      if (pow(i, 3) <= t) m[pow(i, 3)]++;
    }
    cout << m.size() << endl;
  }
}
