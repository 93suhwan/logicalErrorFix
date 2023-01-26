#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
vector<long long> adj[200005];
vector<long long> max_seg(400005);
vector<long long> pref(400005);
vector<long long> suff(400005);
vector<long long> t(400005);
void build(long long tl, long long tr, long long idx, vector<long long>& v) {
  if (tl == tr) {
    t[idx] = v[tl];
    return;
  }
  long long m = (tl + tr) / 2;
  build(tl, m, 2 * idx, v);
  build(m + 1, tr, 2 * idx + 1, v);
  t[idx] = max(t[2 * idx], t[2 * idx + 1]);
}
void update(long long tl, long long tr, long long idx, vector<long long>& v,
            long long pos, long long new_val) {
  if (tl == tr) {
    t[idx] = new_val;
    return;
  }
  long long mid = (tl + tr) / 2;
  if (pos <= mid)
    update(tl, mid, 2 * idx, v, pos, new_val);
  else
    update(mid + 1, tr, 2 * idx + 1, v, pos, new_val);
  t[idx] = max(t[2 * idx], t[2 * idx + 1]);
}
long long atleastX(long long tl, long long tr, long long idx,
                   vector<long long>& v, long long k) {
  if (k > t[idx]) return 0;
  if (tl == tr) {
    return tl;
  }
  long long mid = (tl + tr) / 2;
  long long max1 = t[2 * idx];
  long long max2 = t[2 * idx + 1];
  if (max1 >= k) {
    return atleastX(tl, mid, 2 * idx, v, k);
  } else {
    return atleastX(mid + 1, tr, 2 * idx + 1, v, k);
  }
}
vector<long long> val(100005, 0);
vector<long long> level(100005, 0);
vector<pair<long long, long long> > zo(100005);
vector<long long> even_leaf;
long long one, zero;
void dfs(long long s, long long par) {
  if (par != -1) {
    val[s] = !val[par];
    level[s] = level[par] + 1;
  }
  long long ch = 0;
  for (long long child : adj[s]) {
    if (child != par) {
      dfs(child, s);
      ch++;
    }
  }
  if (ch == 0 && level[s] % 2 == 0) {
    even_leaf.push_back(s);
    if (val[s] == 1) one++;
    if (val[s] == 0) zero++;
  }
}
void situn(long long cc) {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  if (v[0] % 2 == 0) {
    cout << "NO";
    return;
  }
  cout << "YES";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  long long cc = 1;
  while (t--) {
    situn(cc);
    cc++;
    cout << endl;
  }
  return 0;
}
