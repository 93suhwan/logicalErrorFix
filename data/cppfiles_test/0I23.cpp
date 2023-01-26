#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
long long int fastmodexp(long long int a, long long int b, long long int c) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % c;
    }
    a = (a * a) % c;
    b = b >> 1;
  }
  return res;
}
long long int fastexp(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res * a);
    }
    a = (a * a);
    b = b >> 1;
  }
  return res;
}
long long int fact(long long int n) {
  long long int ans[n + 1];
  ans[0] = ans[1] = 1LL;
  for (long long int i = 2; i <= n; i++) {
    ans[i] = (i % mod * ans[i - 1] % mod) % mod;
  }
  return ans[n];
}
float roundoff(float value, unsigned char prec) {
  float pow_10 = pow(10.0f, (float)prec);
  return round(value * pow_10) / pow_10;
}
bool comparator(pair<string, long long int> arr1,
                pair<string, long long int> arr2) {
  string a = arr1.first, b = arr2.first;
  for (long long int i = 0; i < a.size(); i++) {
    if (a[i] != b[i]) {
      if (i % 2 == 1) {
        if (a[i] < b[i])
          return false;
        else
          return true;
      } else {
        if (a[i] > b[i]) return false;
      }
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  t = 1;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    vector<pair<string, long long int>> arr;
    for (long long int i = 0; i < n; i++) {
      string x;
      cin >> x;
      arr.push_back(make_pair(x, i + 1));
    }
    sort(arr.begin(), arr.end(), comparator);
    for (long long int i = 0; i < arr.size(); i++) cout << arr[i].second << " ";
    cout << "\n";
  }
  return 0;
}
