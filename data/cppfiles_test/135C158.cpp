#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k, i, sum = 0, x, start, end;
    cin >> n >> k;
    vector<long long int> v;
    for (i = 0; i < n; i++) {
      cin >> x;
      v.push_back(x);
      sum += x;
    }
    start = 0, end = start + k;
    sort(v.begin(), v.end(), greater<long long int>());
    while (k--) {
      sum = sum - v[start] - v[end];
      sum += v[end] / v[start];
      start++;
      end++;
    }
    cout << sum << endl;
  }
}
