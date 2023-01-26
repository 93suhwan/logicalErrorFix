#include <bits/stdc++.h>
using namespace std;
int main() {
  size_t t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (size_t i = 0; i < n; ++i) {
      cin >> a[i];
    }
    if (a.size() == 1) {
      cout << a[0] << endl;
      continue;
    }
    sort(a.begin(), a.end());
    long long s = 0;
    long long res = 0;
    size_t i;
    for (i = 0; i < n - 1; ++i) {
      if (a[i] + s <= 0) {
        s -= a[i] + s;
        continue;
      }
      break;
    }
    vector<long long> diffs(n - i + 1);
    diffs[0] = a[i] + s;
    for (size_t j = i; j < n - 1; ++j) {
      diffs[j - i + 1] = a[j + 1] - a[j];
    }
    cout << *max_element(diffs.begin(), diffs.end()) << endl;
  }
  return 0;
}
