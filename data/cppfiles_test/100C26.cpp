#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int sum = 0, mx = INT_MIN, s = 0, mn;
    priority_queue<long long int, vector<long long int>, greater<long long int>>
        pqm;
    for (long long int i = 0; i < n; i++) {
      int ele;
      cin >> ele;
      s += ele;
      pqm.push(ele);
    }
    for (long long int i = n; i > 1; i--) {
      mn = pqm.top();
      pqm.pop();
      mn = mn - sum;
      if (mn > mx) {
        mx = mn;
      }
      sum = sum + mn;
      s = s - i * (mn);
    }
    if (s > mx) {
      mx = s;
    }
    cout << mx << "\n";
  }
  return 0;
}
