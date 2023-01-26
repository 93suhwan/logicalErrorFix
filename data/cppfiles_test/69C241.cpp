#include <bits/stdc++.h>
using namespace std;
long long int po(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y >>= 1;
    x = (x * x) % p;
  }
  return res % p;
}
long long int modInverse(long long int n, long long int p) {
  return po(n, p - 2, p);
}
void count(vector<long long int>& v1, vector<long long int>& v2,
           long long int i, long long int j, long long int cur,
           long long int& cnt) {
  if (i == v1.size()) {
    cnt = max(cnt, cur);
    return;
  }
  if (v1[i] == v2[j]) {
    count(v1, v2, i + 1, j + 1, cur + 1, cnt);
  } else
    count(v1, v2, i + 1, j, cur, cnt);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> v;
    long long int nn = n;
    while (nn > 0) {
      v.push_back(nn % 10);
      nn /= 10;
    }
    long long int p = 0;
    long long int ans = INT_MAX;
    reverse(v.begin(), v.end());
    while (p <= 61) {
      long long int x = (1LL << p);
      vector<long long int> v2;
      while (x > 0) {
        v2.push_back(x % 10);
        x /= 10;
      }
      reverse(v2.begin(), v2.end());
      long long int cnt = 0;
      long long int j = 0;
      for (long long int i = 0; i < v.size(); i++) {
        if (v[i] == v2[j]) {
          cnt++;
          j++;
          if (j == v2.size()) break;
        }
      }
      long long int y = v2.size() - cnt;
      long long int z = v.size() - cnt;
      ans = min(ans, z + y);
      p++;
    }
    cout << ans << endl;
  }
}
