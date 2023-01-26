#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    for (auto &i : arr) cin >> i;
    int cnt = 0;
    long long prev = INT_MIN;
    for (long long i : arr) {
      if (i < prev) {
        cnt++;
      }
      prev = i;
    }
    if (cnt + 1 <= k)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
