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
    sort(arr.begin(), arr.end(), [&](pair<int, int> a, pair<int, int> b) {
      if (a.first == b.first) return a.second < b.second;
      return a.first > b.first;
    });
    for (int i = arr.size() - 1; i >= 0; i--) {
      if (!isPrime(sum)) {
        break;
      } else {
        sum -= arr.back().first;
        arr.pop_back();
      }
    }
    cout << arr.size() << endl;
    for (auto it : arr) cout << it.second << " ";
    cout << "\n";
  }
  return 0;
}
