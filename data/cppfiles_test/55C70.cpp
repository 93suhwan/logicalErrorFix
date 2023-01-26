#include <bits/stdc++.h>
using namespace std;
const long dx[4] = {1, 0, -1, 0}, dz[4] = {0, 1, 0, -1};
const long double pi = 3.14159265359;
const long long mod = 1e9 + 7;
long long P(long long x) {
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
  cout << endl;
}
template <class T>
void out(vector<T> x, long l = 0, long r = 0) {
  if (!r) {
    r = x.size();
  }
  for (long i = l; i < r; i++) {
    out(x[i]);
  }
  cout << endl;
}
template <class T>
void out(deque<T> x, long l = 0, long r = 0) {
  if (!r) {
    r = x.size();
  }
  for (long i = l; i < r; i++) {
    out(x[i]);
  }
  cout << endl;
}
template <class T>
void out(set<T> x) {
  while (!x.empty()) {
    out(*x.begin());
    x.erase(*x.begin());
  }
  cout << endl;
}
template <class T1, class T2>
void out(map<T1, T2> x) {
  while (!x.empty()) {
    out(*x.begin());
    x.erase(x.begin()->first);
  }
  cout << endl;
}
template <class T>
void out(queue<T> x) {
  while (!x.empty()) {
    out(x.front());
    x.pop();
  }
  cout << endl;
}
template <class T>
void out(priority_queue<T> x) {
  while (!x.empty()) {
    out(x.top());
    x.pop();
  }
  cout << endl;
}
template <class T>
void out(stack<T> x) {
  while (!x.empty()) {
    out(x.top());
    x.pop();
  }
  cout << endl;
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
long long vLE(long long x, vector<int>& VT, long l = 0, long r = -1) {
  if (r == -1) {
    r = VT.size() - 1;
  }
  if (VT[l] > x) {
    return -1;
  }
  long long z = P(r - l);
  while (z) {
    if (l + z <= r && VT[l + z] <= x) {
      l += z;
    }
    z /= 2;
  }
  return l;
}
long long vL(long long x, vector<int>& VT, long l = 0, long r = -1) {
  if (r == -1) {
    r = VT.size() - 1;
  }
  if (VT[l] >= x) {
    return -1;
  }
  long long z = P(r - l);
  while (z) {
    if (l + z <= r && VT[l + z] < x) {
      l += z;
    }
    z /= 2;
  }
  return l;
}
long long vGE(long long x, vector<int>& VT, long l = 0, long r = -1) {
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
long long vG(long long x, vector<int>& VT, long l = 0, long r = -1) {
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
struct lazy {
  vector<pair<pair<int, int>, pair<int, int> > > tree;
  vector<pair<int, int> > upd;
  pair<int, int> operation(pair<int, int> x, pair<int, int> z) {
    if (x.first > z.first) {
      return x;
    }
    return z;
  }
  void build(vector<int> v) {
    tree.clear();
    upd.clear();
    long long x = v.size();
    while (x & (x - 1)) {
      x = x & (x - 1);
    }
    if (v.size() != x) {
      x *= 2;
    }
    tree.resize(x * 2);
    upd.resize(x * 2);
    tree[0].first = make_pair(x, 0);
    for (long i = 0; i < v.size(); i++) {
      tree[i + x].first = make_pair(v[i], 0);
      tree[i + x].second = make_pair(i, i);
    }
    for (long i = v.size(); i < x; i++) {
      tree[i + x].second = make_pair(i, i);
    }
    for (long i = x - 1; i > 0; i--) {
      tree[i].first = operation(tree[i * 2].first, tree[(i * 2) + 1].first);
      tree[i].second =
          make_pair(tree[i * 2].second.first, tree[(i * 2) + 1].second.second);
    }
  }
  pair<int, int> get(int l, int r, int node = 1) {
    if (upd[node].first) {
      if (upd[node].first > tree[node].first.first) {
        tree[node].first = upd[node];
      }
      if (node < tree[0].first.first) {
        if (upd[node].first > upd[node * 2].first) {
          upd[node * 2] = upd[node];
        }
        if (upd[node].first > upd[(node * 2) + 1].first) {
          upd[(node * 2) + 1] = upd[node];
        }
      }
      upd[node] = make_pair(0, 0);
    }
    if (tree[node].second.first > r || tree[node].second.second < l) {
      return make_pair(0, 0);
    }
    if (tree[node].second.first >= l && tree[node].second.second <= r) {
      return tree[node].first;
    }
    return operation(get(l, r, node * 2), get(l, r, (node * 2) + 1));
  }
  void update(int l, int r, int x, int z, int node = 1) {
    if (upd[node].first) {
      if (upd[node].first > tree[node].first.first) {
        tree[node].first = upd[node];
      }
      if (node < tree[0].first.first) {
        if (upd[node].first > upd[node * 2].first) {
          upd[node * 2] = upd[node];
        }
        if (upd[node].first > upd[(node * 2) + 1].first) {
          upd[(node * 2) + 1] = upd[node];
        }
      }
      upd[node] = make_pair(0, 0);
    }
    if (tree[node].second.first > r || tree[node].second.second < l) {
      return;
    }
    if (tree[node].second.first >= l && tree[node].second.second <= r) {
      if (x > upd[node].first) {
        upd[node] = make_pair(x, z);
      }
      if (upd[node].first > tree[node].first.first) {
        tree[node].first = upd[node];
      }
      if (node < tree[0].first.first) {
        if (upd[node].first > upd[node * 2].first) {
          upd[node * 2] = upd[node];
        }
        if (upd[node].first > upd[(node * 2) + 1].first) {
          upd[(node * 2) + 1] = upd[node];
        }
      }
      upd[node] = make_pair(0, 0);
      return;
    }
    update(l, r, x, z, node * 2);
    update(l, r, x, z, (node * 2) + 1);
    tree[node].first =
        operation(tree[node * 2].first, tree[(node * 2) + 1].first);
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, x, z, v, mx, ans = 0, start;
  cin >> n >> m;
  vector<int> dum(m);
  lazy t3, t4;
  t3.build(dum);
  t4.build(dum);
  vector<vector<pair<int, int> > > sss(n + 1);
  vector<pair<int, int> > l, r;
  vector<int> ll, rr;
  pair<int, int> p;
  pair<int, int> p2;
  for (long long i = (0); i < (m); i++) {
    cin >> x >> z >> v;
    sss[x].push_back(make_pair(z, v));
    l.push_back(make_pair(z, x));
    ll.push_back(z);
    r.push_back(make_pair(v, x));
    rr.push_back(v);
  }
  sort(l.begin(), l.end());
  sort(ll.begin(), ll.end());
  sort(r.begin(), r.end());
  sort(rr.begin(), rr.end());
  vector<int> from(n + 1);
  for (long long i = (1); i < (n + 1); i++) {
    mx = 0;
    for (long long j = (0); j < (sss[i].size()); j++) {
      p = sss[i][j];
      z = vGE(p.first, ll);
      v = vLE(p.second, ll);
      mx = max(mx, t3.get(z, v).first);
      z = vGE(p.first, rr);
      v = vLE(p.second, rr);
      mx = max(mx, t4.get(z, v).first);
    }
    if (mx != 0) {
      for (long long j = (0); j < (sss[i].size()); j++) {
        p = sss[i][j];
        z = vGE(p.first, ll);
        v = vLE(p.second, ll);
        p2 = t3.get(z, v);
        if (p2.first == mx) {
          from[i] = p2.second;
          break;
        }
        z = vGE(p.first, rr);
        v = vLE(p.second, rr);
        p2 = t4.get(z, v);
        if (p2.first == mx) {
          from[i] = p2.second;
          break;
        }
      }
    }
    mx++;
    for (long long j = (0); j < (sss[i].size()); j++) {
      p = sss[i][j];
      z = vGE(p.first, ll);
      v = vLE(p.second, ll);
      t3.update(z, v, mx, i);
      z = vGE(p.first, rr);
      v = vLE(p.second, rr);
      t4.update(z, v, mx, i);
    }
    if (mx > ans) {
      start = i;
      ans = mx;
    }
  }
  cout << n - ans << endl;
  vector<bool> ok(n + 1);
  while (start != 0) {
    ok[start] = true;
    start = from[start];
    if (from[start] == start) {
      break;
    }
  }
  for (long long i = (1); i < (n + 1); i++) {
    if (!ok[i]) {
      cout << i << " ";
    }
  }
  cout << endl;
  return 0;
}
