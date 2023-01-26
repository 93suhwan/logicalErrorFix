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
      cin >> ar[i];
      v[ar[i]].push_back(i + 1);
    }
    long long mx = -1e9;
    for (int i = 0; i < n; i++) {
      if (v[ar[i]].size() >= 2) {
        long long p = v[ar[i]].back();
        v[ar[i]].pop_back();
        long long q = v[ar[i]].back();
        long long ans = (p * q) - (k * ar[i]);
        mx = max(mx, ans);
      }
    }
    for (int i = 0; i < n; i++) {
      v[ar[i]].clear();
    }
    long long ans = (n * (n - 1)) - (k * (ar[n - 1] | ar[n - 2]));
    cout << max(mx, ans) << endl;
  }
}
