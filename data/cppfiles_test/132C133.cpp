#include <bits/stdc++.h>
using namespace std;
void koli() {
  int n = 7;
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    v.emplace_back(x);
  };
  int maxm = *max_element(v.begin(), v.end());
  int minm = *min_element(v.begin(), v.end());
  int second = v[1];
  cout << minm << " " << second << " ";
  cout << maxm - (minm + second);
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    koli();
  };
  return 0;
}
