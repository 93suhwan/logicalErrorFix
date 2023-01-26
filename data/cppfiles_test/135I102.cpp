#include <bits/stdc++.h>
using namespace std;
int N = 1e6;
int W = 1e9 + 7;
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a);
    a = (a * a);
    b >>= 1;
  }
  return res;
}
int sq(int n) {
  int hi = n, lo = 0, mid;
  while (hi - lo > 1) {
    mid = (hi + lo) / 2;
    if (mid * mid <= n) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  if (hi * hi <= n) {
    return hi;
  } else {
    return lo;
  }
}
string flip(string s, int l) {
  string s2;
  int n = s.length();
  for (int i = 0; i <= l; i++) {
    if (s[i] == '1')
      s[i] = '0';
    else {
      s[i] = '1';
    }
  }
  for (int i = l; i >= 0; i--) {
    s2.push_back(s[i]);
  }
  for (int i = l + 1; i < n; i++) {
    s2.push_back(s[i]);
  }
  return s2;
}
long long nCr(long long n, long long k) {
  long long res = 1;
  k = min(k, n - k);
  for (int i = 1; i <= k; i++) {
    res *= (n - i + 1);
    res /= i;
    res = res % W;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int count = 0;
    vector<int> v;
    for (int i = 0; i < n; i++) {
      int c;
      cin >> c;
      if (c == 1) count++;
      v.push_back(c);
    }
    int sum1 = 0, sum2 = 0;
    sort(v.begin(), v.end());
    int i = n - 1, j = 0;
    int h = k;
    while (h--) {
      if (v[i] == v[i - 1]) {
        sum1++;
      }
      i = i - 2;
    }
    for (j; j <= i; j++) {
      sum1 += v[j];
    }
    cout << sum1 << " ";
    h = k;
    i = n - 1, j = 0;
    while (h--) {
      if (v[j] == 1) {
        if (v[i] == v[j]) {
          sum2++;
        }
        i--;
        j++;
      } else {
        if (v[i] == v[i - 1]) {
          sum2++;
        }
        i = i - 2;
      }
    }
    for (j; j <= i; j++) {
      sum2 += v[j];
    }
    cout << sum2 << " ";
    cout << min(sum1, sum2) << endl;
  }
  return 0;
}
