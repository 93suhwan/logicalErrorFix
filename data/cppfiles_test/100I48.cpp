#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a;
    vector<long long> p;
    for (int i = 0; i <= n - 1; i += 1) {
      cin >> a;
      p.push_back(a);
    }
    if (p.size() == 1) {
      cout << p[0] << "\n";
    } else {
      sort(p.begin(), p.end());
      for (int i = 0; i <= n - 2; i += 1) {
        for (int j = i + 1; j <= n - 1; j += 1) {
          p[j] -= p[i];
        }
      }
      cout << max(p[n - 2], p[n - 1]) << "\n";
    }
  }
}
