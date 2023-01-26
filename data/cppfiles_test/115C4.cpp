#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(T& a) {
  for (auto x : a) cout << x << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, i;
  long long t;
  cin >> t;
  while (t--) {
    long long h;
    cin >> n >> h;
    long long a[n];
    for (i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    vector<int> v;
    for (i = 0; i < n - 1; i++) v.push_back(a[i + 1] - a[i]);
    sort((v).begin(), (v).end());
    long long c = 0;
    for (i = 0; i < n - 1; i++) {
      long long r = v[i] * (n - i);
      if (h <= r) {
        if (h % (n - i) == 0)
          cout << h / (n - i) << "\n";
        else
          cout << (h / (n - i)) + 1 << "\n";
        c++;
      } else
        h -= v[i];
      if (c) break;
    }
    if (c == 0) cout << h << "\n";
  }
  return 0;
}
