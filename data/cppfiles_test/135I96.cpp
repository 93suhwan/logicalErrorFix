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
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      v.push_back(k);
    }
    sort(v.begin(), v.end(), greater<int>());
    map<int, int> m;
    m[1] = 1;
    int j = 1;
    for (int i = 1; i < 2 * k; i++) {
      if (v[i] != v[i - 1]) {
        j++;
        m[j]++;
      } else {
        m[j]++;
      }
    }
    vector<int> vt;
    for (int i = 1; i <= j; i++) {
      vt.push_back(m[i]);
    }
    sort(vt.begin(), vt.end(), greater<int>());
    int n1 = vt.size();
    j = n1 - 1;
    int i = 0;
    while (i < j) {
      if (vt[i] > vt[j]) {
        vt[i] = vt[i] - vt[j];
        vt[j] = 0;
        j--;
      } else if (v[j] > v[i]) {
        vt[j] = vt[j] - vt[i];
        vt[i] = 0;
        i++;
      } else {
        vt[j] = 0;
        vt[i] = 0;
        i++;
        j--;
      }
    }
    int sum = 0;
    for (int h = n - 1; h > 2 * k - 1; h--) {
      sum += v[h];
    }
    if (vt[i] > 0)
      sum += (vt[i] / 2);
    else {
      sum += (vt[j] / 2);
    }
    cout << sum << endl;
  }
  return 0;
}
