#include <bits/stdc++.h>
using namespace std;
void solve();
void cumsum(vector<long long> vec, vector<long long> sum) {
  long long s = 0;
  for (int i = 0; i < vec.size(); i++) {
    s += vec[i];
    sum.push_back(s);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int(i) = 0; (i) < (n); (i)++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (n == 1) {
      cout << a[0] << endl;
      continue;
    }
    vector<long long> b(n);
    b[0] = a[0];
    for (int i = 0; i < n - 1; i++) {
      b[i + 1] = a[i + 1] - a[i];
    }
    cout << *max_element(b.begin(), b.end()) << endl;
  }
}
