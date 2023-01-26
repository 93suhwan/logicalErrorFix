#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  bool f = 1;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      f = 0;
      break;
    }
  }
  return f;
}
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    int a;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a;
      sum += a;
      arr.push_back({a, i + 1});
    }
    if (!isPrime(sum) and sum != 1) {
      cout << n << endl;
      for (auto it : arr) cout << it.second << " ";
      cout << "\n";
      continue;
    }
    for (int i = 0; i < n; i++) {
      long long k = sum - arr[i].first;
      if (!isPrime(k) and k != 1) {
        arr[i].first = -1;
        break;
      }
    }
    vector<int> res;
    for (auto it : arr)
      if (it.first != -1) res.push_back(it.second);
    cout << res.size() << endl;
    for (auto it : res) cout << it << " ";
    cout << "\n";
  }
  return 0;
}
