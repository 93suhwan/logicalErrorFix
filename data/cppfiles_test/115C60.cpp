#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
using namespace std;
const long long BIG_INF = 1e18;
const int mod = 998244353;
const int INF = mod;
const int N = 1e6 + 7;
const int T = 1 << 20;
template <class T, class G>
ostream& operator<<(ostream& os, const pair<T, G>& para) {
  os << para.first << ' ' << para.second;
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
  for (const T& el : vec) os << el << ' ';
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& vec) {
  for (const T& el : vec) os << el << ' ';
  return os;
}
template <class T>
istream& operator>>(istream& is, vector<T>& vec) {
  for (T& el : vec) is >> el;
  return is;
}
template <class T, class G>
istream& operator>>(istream& os, pair<T, G>& para) {
  os >> para.first >> para.second;
  return os;
}
template <class T>
void setmax(T& a, T b) {
  a = (a >= b ? a : b);
}
template <class T>
void setmin(T& a, T b) {
  a = (a <= b ? a : b);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long pot[N];
int n, m, q;
map<pair<int, int>, int> mapa;
int krata[2];
int ogr_kol[3];
int ogr_wie[3];
int kol_bit[N][2];
int row_bit[N][2];
void usun(int a, int b) {
  if (mapa.count({a, b})) {
    int bit = mapa[{a, b}];
    krata[(a ^ b ^ bit) & 1]--;
    mapa.erase({a, b});
    ogr_kol[(kol_bit[b][0] > 0) + (kol_bit[b][1] > 0)]--;
    ogr_wie[(row_bit[a][0] > 0) + (row_bit[a][1] > 0)]--;
    row_bit[a][(b ^ bit) & 1]--;
    kol_bit[b][(a ^ bit) & 1]--;
    ogr_kol[(kol_bit[b][0] > 0) + (kol_bit[b][1] > 0)]++;
    ogr_wie[(row_bit[a][0] > 0) + (row_bit[a][1] > 0)]++;
  }
}
void dodaj(int a, int b, int bit) {
  krata[(a ^ b ^ bit) & 1]++;
  mapa[{a, b}] = bit;
  ogr_kol[(kol_bit[b][0] > 0) + (kol_bit[b][1] > 0)]--;
  ogr_wie[(row_bit[a][0] > 0) + (row_bit[a][1] > 0)]--;
  row_bit[a][(b ^ bit) & 1]++;
  kol_bit[b][(a ^ bit) & 1]++;
  ogr_kol[(kol_bit[b][0] > 0) + (kol_bit[b][1] > 0)]++;
  ogr_wie[(row_bit[a][0] > 0) + (row_bit[a][1] > 0)]++;
}
long long spos() {
  long long wiersze = (ogr_wie[2] ? 0 : pot[ogr_wie[0]]);
  long long kolumny = (ogr_kol[2] ? 0 : pot[ogr_kol[0]]);
  if (wiersze == 0 and kolumny == 0) return 0;
  return (wiersze + kolumny - (!krata[0]) - (!krata[1]) + mod) % mod;
}
void solve() {
  cin >> n >> m >> q;
  pot[0] = 1;
  for (int i = 1; i < N; i++) pot[i] = pot[i - 1] * 2 % mod;
  ogr_kol[0] = m;
  ogr_wie[0] = n;
  for (int i = 0; i < q; i++) {
    int a, b, r;
    cin >> a >> b >> r;
    usun(a, b);
    if (r != -1) dodaj(a, b, r);
    cout << spos() << '\n';
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int test = 1;
  for (int i = 1; i <= test; i++) solve();
}
