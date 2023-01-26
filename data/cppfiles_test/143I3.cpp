#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    map<long long int, long long int> m, s;
    long long int sum = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      m[a[i]]++;
    }
    sort(a, a + n);
    long long int k;
    for (long long int i = 0; i <= n; i++) {
      if (!m.count(i)) {
        k = i;
        break;
      }
    }
    long long int c = 0, d[n + 1];
    for (long long int i = 0; i <= n; i++) {
      if (i == k)
        d[i] = 0;
      else if (i < k) {
        d[i] = m[i];
        if ((m[i] - 1) > 0) s[i] = m[i] - 1;
      } else {
        if (m.count(i - 1))
          d[i] = sum;
        else {
          if (s.size() > 0) {
            auto it = s.end();
            it--;
            d[i] = i - 1 - it->first + sum;
            sum += i - 1 - it->first;
            it->second -= 1;
            if (it->second == 0) s.erase(it);
            if (m.count(i)) {
              d[i] += m[i];
              if ((m[i] - 1) > 0) s[i] = m[i] - 1;
            }
          } else {
            for (long long int j = i; j <= n; j++) d[j] = -1;
            break;
          }
        }
      }
    }
    for (long long int i = 0; i <= n; i++) cout << d[i] << " ";
    cout << endl;
  }
}
