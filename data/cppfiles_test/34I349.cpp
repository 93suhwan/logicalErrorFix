#include <bits/stdc++.h>
using namespace std;
vector<long long> v[100005];
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    long long n, k;
    cin >> n >> k;
    long long ar[n];
    int d = 0;
    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      ar[i] = x;
      v[x].push_back(i + 1);
    }
    long long mx = -1e18;
    for (int i = 0; i < n; i++) {
      if (v[ar[i]].size() >= 2) {
        int d = v[ar[i]].size();
        long long p = v[ar[i]][d - 1];
        long long q = v[ar[i]][d - 2];
        long long ans = (p * q) - (k * ar[i]);
        mx = max(mx, ans);
      }
    }
    sort(ar, ar + n);
    for (int i = 1; i < n; i++) {
      if (ar[i] != ar[i - 1]) {
        long long p = v[ar[i]].back();
        long long q = v[ar[i - 1]].back();
        long long ans = (p * q) - (k * (ar[i] | ar[i - 1]));
        mx = max(mx, ans);
      }
    }
    for (int i = 0; i < n; i++) {
      v[ar[i]].clear();
    }
    cout << mx << endl;
  }
}
