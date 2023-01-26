#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T > 0) {
    long long n, sum = 0, sum2 = 0;
    cin >> n;
    unordered_map<long long, long long> m;
    long long temp;
    for (int i = 0; i < n; i++) {
      cin >> temp;
      sum = sum + temp;
      m[temp] = m[temp] + 1;
    }
    if ((2 * sum) % n != 0) {
      cout << 0 << '\n';
    } else {
      if (m.size() == 1) {
        long long count = 0;
        cout << ((n) * (n - 1)) / 2 << '\n';
      } else {
        long long count = 0, test = ((2 * sum) / n);
        auto tempit = m.begin();
        for (auto it = m.begin(); it != m.end(); it++) {
          tempit = m.find(test - (it->first));
          if (tempit != m.end()) {
            count = count + (tempit->second) * (it->second);
          }
        }
        count = count / 2;
        cout << count << '\n';
      }
    }
    T--;
  }
}
