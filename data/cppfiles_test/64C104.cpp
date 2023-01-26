#include <bits/stdc++.h>
bool local = false;
using namespace std;
template <class T>
void print(T v) {
  cout << ((int)(v).size()) << "\n";
  for (auto x : v) cout << x << ' ';
  cout << "\n";
};
template <class T>
void print1(T v) {
  cout << ((int)(v).size()) << "\n";
  for (auto x : v) cout << x + 1 << ' ';
  cout << "\n";
};
template <class T1, class T2>
ostream &operator<<(ostream &o, pair<T1, T2> x) {
  return o << x.first << ' ' << x.second;
}
template <class T1, class T2>
istream &operator>>(istream &o, pair<T1, T2> &x) {
  return o >> x.first >> x.second;
}
template <class T>
ostream &operator<<(ostream &o, vector<T> &x) {
  for (auto &el : x) o << el << ' ';
  return o;
}
template <class T>
istream &operator>>(istream &o, vector<T> &x) {
  for (auto &el : x) o >> el;
  return o;
}
template <class T1, class T2>
pair<T1, T2> operator+(pair<T1, T2> a, pair<T1, T2> b) {
  a.first += b.first;
  a.second += b.second;
  return a;
}
template <class T1, class T2>
pair<T1, T2> operator-(pair<T1, T2> a, pair<T1, T2> b) {
  a.first -= b.first;
  a.second -= b.second;
  return a;
}
template <class T1, class T2>
void operator+=(pair<T1, T2> &a, pair<T1, T2> b) {
  a.first += b.first;
  a.second += b.second;
}
template <class T1, class T2>
void operator-=(pair<T1, T2> &a, pair<T1, T2> b) {
  a.first -= b.first;
  a.second -= b.second;
}
int nint() {
  int x;
  cin >> x;
  return x;
}
double getTime() { return clock() / (double)CLOCKS_PER_SEC; };
mt19937 rnd(0);
int rand(int n) { return rnd() % n; }
int rand(int l, int r) { return rnd() % (r - l + 1) + l; }
const int mod = 1000000000 + 7;
void initIO() {
  if (local) {
    freopen("input.txt", "r", stdin);
    srand((int)time(0));
    rnd.seed((int)time(0));
  } else {
    {
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
    };
  }
}
void solve();
void precalc();
int TID;
signed main() {
  initIO();
  int tc = 1;
  precalc();
  for (int tt = 0; tt < (tc); tt++) {
    TID = tt;
    solve();
  }
  if (local)
    cout << "\n"
         << "time = " << getTime() << "\n";
}
void precalc() {}
int n;
int m;
vector<int> v1[100500], v2[100500];
int color[100500];
set<int> s1[100500], s2[100500];
int use[100500];
int g;
set<int> g1, g2;
void setcolor(int x, int c) {
  color[x] = c;
  s1[c].insert(x);
  g1.insert(c);
}
void add1(int x) {
  g++;
  use[x] = 1;
  int c = color[x];
  s1[c].erase(x);
  s2[c].insert(x);
  if (!((int)(s1[c]).size())) g1.erase(c);
  g2.insert(c);
}
void merge(int x, int y) {
  int c1 = color[x];
  int c2 = color[y];
  assert(c1 != c2);
  if (((int)(s2[c1]).size()) + ((int)(s1[c1]).size()) >
      ((int)(s2[c2]).size()) + ((int)(s1[c1]).size()))
    swap(c1, c2);
  for (int x : s2[c1]) {
    color[x] = c2;
    s2[c2].insert(x);
  }
  s2[c1].clear();
  for (int x : s1[c1]) {
    color[x] = c2;
    s1[c2].insert(x);
  }
  s1[c1].clear();
  g1.erase(c1);
  g2.erase(c1);
  if (((int)(s1[c2]).size())) g1.insert(c2);
  if (((int)(s2[c2]).size())) g2.insert(c2);
}
void addAll(int x) {
  add1(x);
  for (int y : v1[x])
    if (!use[y]) addAll(y);
}
void go(int x, int c) {
  setcolor(x, c);
  for (int y : v2[x])
    if (color[y] == -1) go(y, c);
}
void solve() {
  int m1, m2;
  cin >> n >> m1 >> m2;
  for (int i = 0; i < (m1); i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    v1[a].emplace_back(b);
    v1[b].emplace_back(a);
  }
  for (int i = 0; i < (m2); i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    v2[a].emplace_back(b);
    v2[b].emplace_back(a);
  }
  if (m1 < m2) {
    for (int i = 0; i < (n); i++) swap(v1[i], v2[i]);
    swap(m1, m2);
  }
  memset(color, -1, sizeof(color));
  int c = 0;
  for (int i = 0; i < (n); i++)
    if (color[i] == -1) {
      go(i, c);
      c++;
    };
  ;
  addAll(0);
  int k = n - m1 - 1;
  cout << k << "\n";
  for (int o = 0; o < (k); o++) {
    int f = 0;
    for (int i : g1)
      if (((int)(s1[i]).size()) && ((int)(s2[i]).size()) != g) {
        int x = *s1[i].begin();
        for (int j : g2)
          if (i != j && ((int)(s2[j]).size())) {
            int y = *s2[j].begin();
            cout << x + 1 << ' ' << y + 1 << "\n";
            addAll(x);
            merge(x, y);
            f = 1;
            break;
          }
        break;
      }
    assert(f);
  }
}
