#include <bits/stdc++.h>
using namespace std;
struct layer {
  long long sum;
  long long v;
};
signed main() {
  long long t;
  cin >> t;
  for (long long r = 0; r < t; ++r) {
    long long n, s;
    cin >> n >> s;
    cout << s / (n / 2 + 1) << "\n";
  }
}
