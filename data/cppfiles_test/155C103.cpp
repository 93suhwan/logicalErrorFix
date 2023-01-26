#include <bits/stdc++.h>
using namespace std;
void inputArr(long long arr[], long long n) {
  for (long long i = 0; i < n; i++) cin >> arr[i];
}
void printArr(long long arr[], long long n) {
  for (long long i = 0; i < n; i++) cout << arr[i];
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<pair<long long, long long>> a(n);
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      a[i] = {x, i};
    }
    string s;
    cin >> s;
    vector<pair<long long, long long>> one, zero;
    for (long long i = 0; i < n; i++) {
      if (s[i] == '1')
        one.push_back(a[i]);
      else
        zero.push_back(a[i]);
    }
    sort(one.begin(), one.end());
    sort(zero.begin(), zero.end());
    vector<long long> ans(n);
    long long count = n;
    if (one.size()) {
      for (long long i = one.size() - 1; i >= 0; i--) {
        ans[one[i].second] = count;
        count--;
      }
    }
    if (zero.size()) {
      for (long long i = zero.size() - 1; i >= 0; i--) {
        ans[zero[i].second] = count;
        count--;
      }
    }
    for (auto x : ans) cout << x << " ";
    cout << endl;
  }
  return 0;
}
