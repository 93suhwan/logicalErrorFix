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
        if (x > maxi) {
          maxi = x;
          idx = j;
        }
      }
      v.push_back(make_pair(maxi - idx + 1, k));
    }
    sort(v.rbegin(), v.rend());
    for (i = 0; i < v.size(); i++) {
      long long a = v[i].first, b;
      int c;
      if (i + 1 < v.size()) {
        b = v[i + 1].first;
        c = v[i + 1].second;
      }
      if (a > (b + c)) {
        v[i + 1].first = b + (a - (b + c));
      }
      i++;
    }
    cout << v[v.size() - 1].first;
    cout << "\n";
  }
  return 0;
}
