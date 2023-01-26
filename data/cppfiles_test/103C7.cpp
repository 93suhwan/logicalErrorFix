#include <bits/stdc++.h>
using namespace std;
const long dx[4] = {1, 0, -1, 0}, dz[4] = {0, 1, 0, -1};
const long double pi = 3.14159265359;
const long long mod = 1e9 + 7;
long long p(long long x) {
  while (x & (x - 1)) {
    x = x & (x - 1);
  }
  return x;
}
long long squared(long long x) { return (x * x) % mod; }
long long power(long long x, long long p) {
  if (p == 0) {
    return 1;
  }
  if (p % 2 == 1) {
    return (power(x, p - 1) * x) % mod;
  }
  return squared(power(x, p / 2));
}
long long inv(long long x) { return power(x, mod - 2); }
long long log(long long x, long long z) {
  if (x < z) {
    return 0;
  }
  return 1 + log(x / z, z);
}
template <class T>
void re(T& x) {
  cin >> x;
}
template <class T1, class T2>
void re(pair<T1, T2>& x) {
  re(x.first);
  re(x.second);
}
template <class T>
void re(vector<T>& x) {
  for (long i = 0; i < x.size(); i++) {
    re(x[i]);
  }
}
template <class T>
void re(deque<T>& x) {
  for (long i = 0; i < x.size(); i++) {
    re(x[i]);
  }
}
template <class T>
void out(T x) {
  cout << x << " ";
}
template <class T1, class T2>
void out(pair<T1, T2> x) {
  out(x.first);
  out(x.second);
  cout << "\n";
}
template <class T>
void out(vector<T> x, long l = 0, long r = 0) {
  if (!r) {
    r = x.size();
  }
  for (long i = l; i < r; i++) {
    out(x[i]);
  }
  cout << "\n";
}
template <class T>
void out(deque<T> x, long l = 0, long r = 0) {
  if (!r) {
    r = x.size();
  }
  for (long i = l; i < r; i++) {
    out(x[i]);
  }
  cout << "\n";
}
template <class T>
void out(set<T> x) {
  while (!x.empty()) {
    out(*x.begin());
    x.erase(*x.begin());
  }
  cout << "\n";
}
template <class T1, class T2>
void out(map<T1, T2> x) {
  while (!x.empty()) {
    out(*x.begin());
    x.erase(x.begin()->first);
  }
  cout << "\n";
}
template <class T>
void out(queue<T> x) {
  while (!x.empty()) {
    out(x.front());
    x.pop();
  }
  cout << "\n";
}
template <class T>
void out(priority_queue<T> x) {
  while (!x.empty()) {
    out(x.top());
    x.pop();
  }
  cout << "\n";
}
template <class T>
void out(stack<T> x) {
  while (!x.empty()) {
    out(x.top());
    x.pop();
  }
  cout << "\n";
}
template <class T>
T cross(complex<T> x, complex<T> z) {
  return (conj(x) * z).imag();
}
template <class T>
T dot(complex<T> x, complex<T> z) {
  return (conj(x) * z).real();
}
set<long long>::iterator T;
long long vLE(long long x, vector<long long>& VT, long l = 0, long r = -1) {
  if (r == -1) {
    r = VT.size() - 1;
  }
  if (VT[l] > x) {
    return -1;
  }
  long long z = p(r - l);
  while (z) {
    if (l + z <= r && VT[l + z] <= x) {
      l += z;
    }
    z /= 2;
  }
  return l;
}
long long vL(long long x, vector<long long>& VT, long l = 0, long r = -1) {
  if (r == -1) {
    r = VT.size() - 1;
  }
  if (VT[l] >= x) {
    return -1;
  }
  long long z = p(r - l);
  while (z) {
    if (l + z <= r && VT[l + z] < x) {
      l += z;
    }
    z /= 2;
  }
  return l;
}
long long vGE(long long x, vector<long long>& VT, long l = 0, long r = -1) {
  if (r == -1) {
    r = VT.size() - 1;
  }
  if (VT[l] >= x) {
    return l;
  }
  l = vL(x, VT, l, r);
  if (l == r) {
    return -1;
  }
  return l + 1;
}
long long vG(long long x, vector<long long>& VT, long l = 0, long r = -1) {
  if (r == -1) {
    r = VT.size() - 1;
  }
  if (VT[l] > x) {
    return l;
  }
  l = vLE(x, VT, l, r);
  if (l == r) {
    return -1;
  }
  return l + 1;
}
long long sLE(long long x, set<long long>& ST) {
  if (ST.count(x)) {
    return x;
  }
  if (*ST.begin() > x) {
    return -1;
  }
  ST.insert(x);
  T = ST.find(x);
  T--;
  ST.erase(x);
  return *T;
}
long long sL(long long x, set<long long>& ST) {
  if (*ST.begin() >= x) {
    return -1;
  }
  if (ST.count(x)) {
    T = ST.find(x);
    T--;
    return *T;
  }
  ST.insert(x);
  T = ST.find(x);
  T--;
  ST.erase(x);
  return *T;
}
long long sGE(long long x, set<long long>& ST) {
  if (ST.count(x)) {
    return x;
  }
  if (*ST.rbegin() < x) {
    return -1;
  }
  ST.insert(x);
  T = ST.find(x);
  T++;
  ST.erase(x);
  return *T;
}
long long sG(long long x, set<long long>& ST) {
  if (*ST.rbegin() <= x) {
    return -1;
  }
  if (ST.count(x)) {
    T = ST.find(x);
    T++;
    return *T;
  }
  ST.insert(x);
  T = ST.find(x);
  T++;
  ST.erase(x);
  return *T;
}
bool vis[4000010] = {}, done[4000010] = {};
int ans[4000010] = {}, depth[4000010] = {}, to[4000010] = {};
bool found;
int z, node, n, m;
bool check(int x) {
  if (x >= n * m || x < 0) {
    return false;
  }
  return true;
}
void solve(int x, int d) {
  if (!check(x)) {
    return;
  }
  if (done[x]) {
    return;
  }
  if (vis[x]) {
    ans[x] = d - depth[x];
    z = ans[x];
    found = true;
    node = x;
    done[x] = true;
    return;
  }
  vis[x] = true;
  depth[x] = d;
  solve(to[x], d + 1);
  if (found) {
    if (x == node) {
      found = false;
      return;
    }
    ans[x] = z;
    done[x] = true;
    return;
  }
  if (check(to[x])) {
    ans[x] = ans[to[x]] + 1;
    done[x] = true;
    return;
  }
  ans[x] = 1;
  done[x] = true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, x;
  cin >> t;
  for (long long i = (0); i < (t); i++) {
    cin >> n >> m;
    string v[n];
    for (long long j = (0); j < (n); j++) {
      cin >> v[j];
    }
    for (long long j = (0); j < (n); j++) {
      for (long long k = (0); k < (m); k++) {
        x = (j * m) + k;
        if (v[j][k] == 'U') {
          to[x] = x - m;
          continue;
        }
        if (v[j][k] == 'D') {
          to[x] = x + m;
          continue;
        }
        if (v[j][k] == 'R') {
          if (k == m - 1) {
            to[x] = -1;
            continue;
          }
          to[x] = x + 1;
          continue;
        }
        if (k == 0) {
          to[x] = -1;
          continue;
        }
        to[x] = x - 1;
      }
    }
    for (long long j = (0); j < (n * m); j++) {
      found = false;
      solve(j, 0);
    }
    int mx = 0, x = 0;
    for (long long j = (0); j < (n * m); j++) {
      if (ans[j] > mx) {
        mx = ans[j];
        x = j;
      }
    }
    for (long long j = (0); j < (n * m); j++) {
      ans[j] = 0;
      vis[j] = false;
      done[j] = false;
      to[j] = 0;
      depth[j] = 0;
    }
    cout << (x / m) + 1 << " " << (x % m) + 1 << " " << mx << "\n";
  }
  return 0;
}
