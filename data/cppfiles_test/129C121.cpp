#include <bits/stdc++.h>
using namespace std;
long long fun(long long n) {
  long long maxPrime = -1;
  while (n % 2 == 0) {
    maxPrime = 2;
    n >>= 1;
  }
  while (n % 3 == 0) {
    maxPrime = 3;
    n = n / 3;
  }
  for (int i = 5; i <= sqrt(n); i += 6) {
    while (n % i == 0) {
      maxPrime = i;
      n = n / i;
    }
    while (n % (i + 2) == 0) {
      maxPrime = i + 2;
      n = n / (i + 2);
    }
  }
  if (n > 4) maxPrime = n;
  return maxPrime;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> a;
    unordered_map<int, int> m;
    bool flag = false;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      if (v[i] <= n && m.find(v[i]) == m.end())
        m[v[i]]++;
      else
        a.push_back(v[i]);
    }
    sort(a.begin(), a.end());
    int i = 1, j = 0;
    while (i <= n) {
      if (m.find(i) != m.end())
        i++;
      else {
        int d = (a[j] % 2 == 0) ? (a[j] / 2 - 1) : (a[j] / 2);
        if (i > d) {
          flag = true;
          break;
        } else {
          j++;
          i++;
          cnt++;
        }
      }
    }
    if (flag == true)
      cout << -1 << "\n";
    else
      cout << cnt << "\n";
  }
  return 0;
}
