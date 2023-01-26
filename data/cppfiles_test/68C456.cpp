#include <bits/stdc++.h>
using namespace std;
vector<long long int> vec;
void PreHelper() {
  for (long long int i = 1; i <= 100000; i++) {
    vec.push_back(i * i);
  }
}
int main() {
  PreHelper();
  long long int t;
  cin >> t;
  while (t--) {
    long long int k;
    cin >> k;
    auto it = lower_bound(vec.begin(), vec.end(), k);
    if (it != vec.end()) {
      if ((*it) == k) {
        long long int x = it - vec.begin() + 1;
        cout << x << " " << 1 << "\n";
      } else {
        it--;
        long long int x = it - vec.begin() + 1;
        long long int mx = (*it) + x + 1;
        if (k <= mx) {
          cout << (k - (*it)) << " " << (x + 1) << "\n";
        } else {
          cout << (x + 1) << " " << (x + 1 - k + mx) << "\n";
        }
      }
    }
  }
}
