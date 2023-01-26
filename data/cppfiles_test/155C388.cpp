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
  vector<long long> a(n);
  vector<long long int> b(n);
  vector<pair<long long, long long>> c, d;
  string s;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    a[i] = x;
    b[i] = x;
  }
  cin >> s;
  long long zero = 0, one = 0;
  for (long long i = 0; i < s.length(); i++) {
    if (s[i] == '0') {
      c.push_back(make_pair(a[i], i));
      zero++;
    } else {
      d.push_back(make_pair(a[i], i));
      one++;
    }
  }
  sort(c.begin(), c.end());
  sort(d.begin(), d.end());
  sort(b.begin(), b.end());
  vector<long long int> ans(n);
  long long j = 0;
  for (auto i : c) {
    ans[i.second] = b[j++];
  }
  for (auto i : d) {
    ans[i.second] = b[j++];
  }
  for (auto i : ans) {
    cout << i << " ";
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
