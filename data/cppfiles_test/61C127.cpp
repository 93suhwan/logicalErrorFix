#include <bits/stdc++.h>
using namespace std;
long long calc3(long long n) { return n * (n - 1) * (n - 2) / 6; }
long long calc(map<int, long long> &mp) {
  vector<long long> vec;
  long long sum = 0;
  for (auto pr : mp) {
    vec.push_back(pr.second);
    sum += pr.second;
  }
  long long res = 0;
  for (int i = 0; i < vec.size(); i++) {
    sum -= vec[i];
    res += (sum * vec[i] * (vec[i] - 1)) / 2;
    sum += vec[i];
  }
  return res;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    int brr[n];
    map<int, long long> mp1;
    map<int, long long> mp2;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      cin >> brr[i];
      mp1[arr[i]]++;
      mp2[brr[i]]++;
    }
    long long ans = calc3(n);
    for (int i = 0; i < n; i++) {
      ans -= (mp1[arr[i]] - 1) * (mp2[brr[i]] - 1);
    }
    cout << ans << endl;
  }
  return 0;
}
