#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
vector<int> v1{-1, -1, 0, 1, 1, 1, 0, -1};
vector<int> v2{0, 1, 1, 1, 0, -1, -1, -1};
vector<int> v3{0, 1, 0, -1, 0};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> v(n);
    long long maxi = 0;
    int ind;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      if (maxi < v[i]) {
        ind = i;
      }
      maxi = max(maxi, v[i]);
    }
    vector<long long> nsl(n, -1);
    vector<long long> nsr(n, -1);
    stack<int> s;
    for (int i = 0; i < n; i++) {
      while (!s.empty() && v[s.top()] >= v[i]) {
        nsl[s.top()] = v[i];
        s.pop();
      }
      s.push(i);
    }
    while (!s.empty()) {
      s.pop();
    }
    for (int i = n - 1; i >= 0; i--) {
      while (!s.empty() && v[s.top()] >= v[i]) {
        nsr[s.top()] = v[i];
        s.pop();
      }
      s.push(i);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, v[i] * max(nsl[i], nsr[i]));
    }
    cout << ans << endl;
  }
  return 0;
}
