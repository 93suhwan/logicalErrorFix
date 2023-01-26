#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long x, long long y) { return x / gcd(x, y) * y; };
long long fastpow(long long a, long long b) {
  long long wynik = 1;
  while (b) {
    if (b & 1) wynik = (wynik * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return wynik;
}
bool isp(long long a) {
  if (a == 2) return 1;
  if (a % 2 == 0 || a == 1) return false;
  for (long long i = 3; i * i <= a; i += 2) {
    if (a % i == 0) return false;
  }
  return true;
}
const int mx = 1e5 + 5;
long long a[mx];
long long fre[mx];
bool sortPairs(const pair<char, int> &x, const pair<char, int> &y) {
  return (x.second > y.second);
}
int dx4[] = {-1, 0, 0, 1};
int dy4[] = {0, 1, -1, 0};
string dir[] = {"up", "rigth", "left", "down"};
int dx8[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy8[] = {1, -1, 0, 0, 1, -1, -1, 1};
int pri[] = {-1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0,
             1,  0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
             0,  0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0};
int temp[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int arr22[4000];
void solve() {
  unsigned long long t, n, k, x, arr1[2005], ha;
  string second, s1, ans;
  vector<long long> v;
  cin >> t;
  ha = t;
  while (t--) {
    cin >> n >> k >> x;
    cin >> second;
    for (int i = 0; i <= 2000; i++) {
      arr1[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      long long num = 0;
      while (i < n && second[i] == '*') {
        i++;
        num++;
      }
      if (num) {
        v.push_back(num * k);
      }
    }
    arr1[v.size() - 1] = 1;
    for (int i = v.size() - 2; i >= 0; i--) {
      arr1[i] = (v[i + 1] + 1) * arr1[i + 1];
      if (arr1[i] > 1e18) {
        break;
      }
    }
    x--;
    int p = 0;
    for (int i = 0; i < n; i++) {
      if (second[i] == '*') {
        if (i > 0 && second[i - 1] == '*') continue;
        while (arr1[p] > 0 && arr1[p] <= x) {
          ans += 'b';
          x -= arr1[p];
        }
        p++;
      } else {
        ans += 'a';
      }
    }
    cout << ans << endl;
    ans = "";
    v.clear();
  }
}
int main() {
  fast();
  solve();
}
