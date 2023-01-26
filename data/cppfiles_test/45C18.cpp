#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T& x) {
  cin >> x;
}
template <class H, class... T>
void read(H& h, T&... t) {
  read(h);
  read(t...);
}
template <class A>
void read(vector<A>& x) {
  for (auto& a : x) read(a);
}
template <class H>
void print(vector<H>& x) {
  for (auto& a : x) cout << a << " ";
  cout << endl;
}
template <class P>
void debug(P h) {}
template <class W, class... V>
void debug(W h, V... t) {}
bool checkbitt(long long int num, int pos) { return (num >> pos) & 1; }
long long int setbitt(long long int num, long long int pos) {
  return (1 << pos) | num;
}
long long int resetbitt(long long int num, int pos) {
  if (!checkbitt(num, pos))
    return num;
  else
    return (1 << pos) ^ num;
}
long long int bigmod(long long int a, long long int b, long long int mod) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b & 1) {
    return ((a % mod) * (bigmod(a, b - 1, mod) % mod)) % mod;
  }
  long long int x = bigmod(a, b / 2, mod);
  return (x * x) % mod;
}
long long int geti() {
  long long int x;
  read(x);
  return x;
}
long long int cdiv(long long int a, long long int b) {
  long long int ret = a / b;
  if (a % b) ret++;
  return ret;
}
const long long int mod = 1e9 + 7;
const long long int N = 2e5 + 10;
int dx[4] = {+0, +0, +1, -1};
int dy[4] = {-1, +1, +0, +0};
int solve() {
  long long int n;
  cin >> n;
  vector<long long int> arr(n);
  read(arr);
  int x = 0;
  int y = 0;
  vector<long long int> a, b;
  int i = 0;
  for (auto& t : arr) {
    if (t % 2) {
      a.push_back(i);
      x++;
    } else {
      b.push_back(i);
      y++;
    }
    i++;
  }
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  if ((n % 2) == 1 && abs(x - y) > 1) {
    cout << -1 << endl;
    return 0;
  } else if (n % 2 == 0 && x != y) {
    cout << -1 << endl;
    return 0;
  }
  long long int res = 0;
  long long int ans = 0;
  if (a.size() < b.size()) {
    swap(a, b);
  } else if (x == y && (arr[0] % 2) == 0) {
    swap(a, b);
  }
  for (int i = 0, j = 0; i < n; i += 2, j++) {
    res += (abs(a[j] - i));
  }
  for (int i = 1, j = 0; i < n; i += 2, j++) {
    ans += (abs(b[j] - i));
  }
  res = min(ans, res);
  if (x == y) {
    swap(a, b);
    long long int tres = 0;
    long long int tans = 0;
    for (int i = 0, j = 0; i < n; i += 2, j++) {
      tres += (abs(a[j] - i));
    }
    for (int i = 1, j = 0; i < n; i += 2, j++) {
      tans += (abs(b[j] - i));
    }
    tres = min(tres, tans);
    res = min(tres, res);
  }
  cout << res << endl;
  return 0;
  return 0;
}
int main(int argc, char* argv[]) {
  if (argc <= 1) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
  }
  int cs = 1, cn = 1;
  read(cs);
  while (cs--) {
    solve();
  }
}
