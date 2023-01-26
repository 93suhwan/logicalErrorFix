#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
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
struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2> &p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};
long long ceil(long long uper, long long lower) {
  long long ans = uper / lower;
  ans += (0 == uper % lower);
  return ans;
}
long long power(long long base, long long e) {
  if (0 == e)
    return 1;
  else if (1 == e)
    return base;
  long long temp = power(base, e / 2);
  if (e & 1) return temp * temp * base;
  return temp * temp;
}
long long find_factor(long long len) {
  long long div = 1;
  long long temp = ceil(sqrt(len));
  unordered_set<long long> st;
  for (long long div = 1; div <= temp; div++) {
    if (len % div == 0) {
      st.insert(div);
      st.insert(len / div);
    }
  }
  return st.size();
}
int Parent[100000];
int Rank[100000];
void makeset(int n) {
  for (int i = 0; i <= n; i++) {
    Parent[i] = i;
    Rank[i] = 0;
  }
}
int find_parent(int node) {
  if (node == Parent[node]) return node;
  return Parent[node] = find_parent(Parent[node]);
}
void union_both_set(int u, int v) {
  u = find_parent(u);
  v = find_parent(v);
  if (Rank[u] < Rank[v])
    Parent[u] = v;
  else if (Rank[v] < Rank[u])
    Parent[v] = u;
  else {
    Parent[v] = u;
    Rank[u] += 1;
  }
}
vector<long long> decToBinary(int n) {
  vector<long long> binaryNum(32, 0);
  int i = 31;
  while (n > 0) {
    binaryNum[i] = n % 2;
    n = n / 2;
    i--;
  }
  return binaryNum;
}
bool cmp(pair<long long, long long> &lp, pair<long long, long long> &rp) {
  if (lp.first != rp.first)
    return lp.first < rp.first;
  else
    return lp.second > rp.second;
}
void solve() {
  long long no_of_range, l, r;
  cin >> no_of_range;
  vector<pair<long long, long long> > vp;
  for (long long i = 0; i < no_of_range; i++) {
    cin >> l >> r;
    vp.push_back({l, r});
  }
  sort(vp.begin(), vp.end(), cmp);
  for (long long i = 0; i < vp.size(); i++) {
    if (vp[i].first == vp[i].second)
      cout << vp[i].first << " " << vp[i].second << " " << vp[i].first << "\n";
    else if (vp[i].second == vp[i + 1].second) {
      cout << vp[i].first << " " << vp[i].second << " " << vp[i].first << "\n";
    } else {
      cout << vp[i].first << " " << vp[i].second << " " << vp[i + 1].second + 1
           << "\n";
    }
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test;
  cin >> test;
  while (test--) {
    solve();
  }
  return (0);
}
