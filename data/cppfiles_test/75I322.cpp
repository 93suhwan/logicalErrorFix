#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const int mod = 1e6 + 3;
long long power(long long n, int pow) {
  long long ans = 1;
  while (pow > 0) {
    if (pow & 1) {
      ans *= n;
      ans %= mod;
    }
    pow = pow / 2;
    n = n * n;
    n = n % mod;
  }
  return ans;
}
void reverse(string &s, int l, int r) {
  while (l < r) {
    swap(s[l++], s[r--]);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int i;
    vector<pair<long long, int>> v;
    for (i = 0; i < n; i++) {
      int k;
      cin >> k;
      long long maxi = 0;
      int j, idx;
      for (j = 0; j < k; j++) {
        long long x;
        cin >> x;
        if ((x - j + 1) > maxi) {
          maxi = x;
          idx = j;
        }
      }
      v.push_back(make_pair(maxi - idx + 1, k));
    }
    sort(v.begin(), v.end());
    long long ans = v[0].first;
    int c = 0;
    for (i = 0; i < v.size(); i++) {
      if (i + 1 < v.size()) {
        c += v[i].second;
        if (v[i + 1].first > (ans + c)) {
          ans = v[i + 1].first - c;
        }
      }
    }
    cout << ans;
    cout << "\n";
  }
  return 0;
}
