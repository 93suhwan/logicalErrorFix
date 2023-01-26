#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n == 1) return false;
  if (n == 2) return true;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long arr[n];
    map<long long, vector<long long> > make_pair;
    vector<long long> ans(n, 0);
    long long cnt = 0;
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
      if (make_pair[arr[i]].size() < k) {
        make_pair[arr[i]].push_back(i);
        cnt++;
      }
    }
    long long col = 1;
    cnt = (cnt / k) * k;
    for (auto it : make_pair) {
      vector<long long> temp = it.second;
      for (long long i = 0; i < temp.size(); i++) {
        if (cnt == 0) break;
        ans[temp[i]] = col;
        col++;
        if (col > k) col = 1;
        cnt--;
      }
      if (cnt == 0) break;
    }
    for (auto x : ans) {
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}
