#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b);
bool prime(int n);
long long sumdigit(long long n);
bool ispowerof2(int n);
long long onesinbinary(long long n);
long long power(long long a, long long b);
bool cmp(pair<int, int> x, pair<int, int> y) { return x.second < y.second; }
bool cmp(int x, int y) { return x > y; }
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    char arr[2][n];
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        cin >> arr[i][j];
      }
    }
    int ans = 0;
    vector<int> v;
    for (int i = 0; i < n; i++) {
      if (arr[0][i] == '0' && arr[1][i] == '0')
        ans++;
      else if (arr[0][i] == '0' || arr[1][i] == '0')
        ans += 2;
      else {
        v.push_back(i);
      }
    }
    int x = v.size();
    for (int i = 0; i < x; i++) {
      if (v[i] < n - 1 && v[i] > 0) {
        if (arr[0][v[i] - 1] == '0' && arr[1][v[i] - 1] == '0') {
          ans++;
        } else if (arr[0][v[i] + 1] == '0' && arr[1][v[i] + 1] == '0') {
          ans++;
          arr[0][v[i] + 1] = '1', arr[1][v[i] + 1] = '1';
        }
      } else if (v[i] == n - 1) {
        if (arr[0][v[i] - 1] == '0' && arr[1][v[i] - 1] == '0') {
          ans++;
        }
      } else if (v[i] == 0) {
        if (arr[0][v[i] + 1] == '0' && arr[1][v[i] + 1] == '0') {
          ans++;
          arr[0][v[i] + 1] = '1', arr[1][v[i] + 1] = '1';
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
long long onesinbinary(long long n) {
  long long cnt = 0;
  while (n) {
    n = n & (n - 1);
    cnt++;
  }
  return cnt;
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool prime(int n) {
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
long long sumdigit(long long n) {
  int c = 0;
  while (n > 0) {
    c += n % 10;
    n /= 10;
  }
  return c;
}
bool ispowerof2(int n) {
  if (n == 0) return false;
  return (!(n & ((n) & (n - 1))));
}
long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long res = 1;
  while (b) {
    if (b % 2 == 1) res = (res * a) % 1000000007;
    a = (a * a) % 1000000007;
    b /= 2;
  }
  return res;
}
