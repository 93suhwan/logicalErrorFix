#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> v1, v2;
    long long max = -1;
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      if (x > 0) v1.push_back(x);
      if (x < 0) v2.push_back(-x);
      max = std::max(max, abs(x));
    }
    sort(v1.rbegin(), v1.rend());
    sort(v2.rbegin(), v2.rend());
    long long resp = 0;
    for (long long i = 0; i < v1.size(); i += k) resp += v1[i] * 2;
    for (long long i = 0; i < v2.size(); i += k) resp += v2[i] * 2;
    cout << resp - max << endl;
  }
  return 0;
}
