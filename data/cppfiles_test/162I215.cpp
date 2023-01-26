#include <bits/stdc++.h>
using namespace std;
void one_case() {
  int n;
  cin >> n;
  vector<int64_t> a(n);
  for (auto& el : a) {
    cin >> el;
  }
  int64_t left = 0, right = 1e9;
  while (left < right) {
    auto H = left + (right - left) / 2;
    bool ok = true;
    vector<int64_t> supp(n);
    for (int i = n - 1; i >= 0; --i) {
      if (supp[i] + a[i] < H) {
        ok = false;
        break;
      }
      auto x = min(a[i], supp[i] + a[i] - H);
      auto d = x / 3;
      if (i) {
        supp[i - 1] += d;
      }
      if (i > 1) {
        supp[i - 2] += 2 * d;
      }
    }
    if (!ok) {
      right = H;
    } else {
      left = H + 1;
    }
  }
  cout << left - 1 << "\n";
}
int main() {
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    one_case();
  }
  return 0;
}
