#include <bits/stdc++.h>
using namespace std;
template <class T>
bool isFloatequal(T a, T b) {
  if (abs(a - b) < 1e-9) {
    return true;
  }
  return false;
}
unsigned long int binomialCoeff(unsigned int n, unsigned int k) {
  unsigned long int res = 1;
  if (k > n - k) k = n - k;
  for (int i = 0; i < k; ++i) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
unsigned long int catalan(unsigned int n) {
  unsigned long int c = binomialCoeff(2 * n, n);
  return c / (n + 1);
}
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> a(n);
  vector<long long int> b(n);
  string s;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    a[i] = make_pair(x, i);
    b[i] = x;
  }
  cin >> s;
  long long zero = 0, one = 0;
  for (auto i : s) {
    if (i == '0')
      zero++;
    else {
      one++;
    }
  }
  sort(b.begin(), b.end());
  vector<long long int> ans(n);
  long long j = 0, p = zero;
  for (auto i : s) {
    if (i == '0') {
      cout << b[j] << " ";
      j++;
    } else {
      cout << b[p] << " ";
      p++;
    }
  }
  cout << endl;
}
int main(int argc, const char* argv[]) {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
