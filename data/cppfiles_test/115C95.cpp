#include <bits/stdc++.h>
using namespace std;
bool check(vector<long long>& a, long long k, long long h) {
  long long sum = k;
  for (int i = 1; i < a.size(); i++) {
    sum += min(k, a[i] - a[i - 1]);
    if (sum >= h || sum < 0) {
      return true;
    }
  }
  return sum >= h;
}
long long bs(vector<long long>& a, long long h) {
  long long low = 1;
  long long hi = h;
  long long m;
  long long k = -1;
  while (low < hi) {
    m = low + ((hi - low) / 2);
    if (check(a, m, h)) {
      hi = m;
    } else {
      low = m + 1;
    }
  }
  return hi;
}
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    long long n, h;
    cin >> n >> h;
    vector<long long> a(n);
    for (auto& i : a) {
      cin >> i;
    }
    cout << bs(a, h) << "\n";
  }
  return 0;
}
