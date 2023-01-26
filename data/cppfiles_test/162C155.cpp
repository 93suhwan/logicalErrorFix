#include <bits/stdc++.h>
using namespace std;
template <class T>
void vprint(vector<T> v) {
  for (T i : v) {
    cout << i << " ";
  }
  cout << "\n";
}
template <class T>
void vsee(vector<T> &v) {
  cerr << "vec : [ ";
  for (T i : v) cerr << i << " ";
  cerr << "]";
}
template <class T, class V>
void mprint(map<T, V> v) {
  for (auto i : v) cout << i.first << " " << i.second << "\n";
}
template <class T, class V>
void msee(map<T, V> v) {
  for (auto i : v) cerr << i.first << " -> " << i.second << "\n";
}
template <class T, class V>
void vpsee(vector<pair<T, V>> v) {
  for (auto i : v) cerr << i.first << " -> " << i.second << "\n";
}
template <class T, class V>
void vpprint(vector<pair<T, V>> v) {
  for (auto i : v) cout << i.first << " " << i.second << "\n";
}
void vshow(vector<int> v) {
  for (auto x : v) cout << x << " ";
}
void vpshow(vector<pair<int, int>> v) {
  for (auto x : v) cout << x.first << " " << x.second << "\n";
}
void mshow(std::map<int, int> m) {
  for (auto x : m) cout << x.first << " " << x.second << "\n";
}
void smile();
long long int gcd(long long int a, long long int b) {
  return b == 0 ? a : gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return ((a * b) / gcd(a, b));
}
long long int sumDigt(long long int x) {
  long long int sum = 0;
  while (x > 0) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}
long long int factorial(long long int n) {
  long long int i, ans = 1;
  for (i = n; i > 1; i--) {
    ans *= i;
  }
  return ans;
}
bool isPrime(long long int n) {
  if (n < 2) return false;
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long int stringToNum(string &s) {
  long long int num = 0;
  for (int i = 0; i < s.size(); i++) {
    num = (num * 10) + s[i] - '0';
  }
  return num;
}
void inputVector(vector<int> &v, int n) {
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }
}
void solve() {
  long long int i, j, n;
  cin >> n;
  std::vector<long long int> ar(n);
  long long int mn = 1e9 + 5, mx = 0;
  for (i = 0; i < n; i++) {
    cin >> ar[i];
    mn = min(ar[i], mn);
    mx = max(ar[i], mx);
  }
  if (mn == ar[n - 1]) {
    cout << mn << "\n";
    return;
  }
  long long int l = 1, r = mx, mid;
  while (l + 1 < r) {
    mid = (l + r) / 2;
    std::vector<long long int> v = ar;
    bool ok = 1;
    for (int i = n - 1; i >= 2; --i) {
      if (v[i] < mid) {
        ok = 0;
        break;
      }
      int kombe = min(v[i] - mid, ar[i]) / 3;
      v[i] -= kombe * 3;
      v[i - 1] += kombe;
      v[i - 2] += kombe * 2;
    }
    if (v[0] < mid || v[1] < mid) ok = 0;
    if (ok)
      l = mid;
    else
      r = mid;
  }
  cout << l << "\n";
}
int main() {
  smile();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
void smile() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
