#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef set<int> si;
typedef string str;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<si> vsi;
typedef vector<ll> vl;
typedef vector<vl> v2l;
typedef vector<db> vd;
typedef vector<bool> vb;
typedef vector<pii> vp;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
}
void fileIO(string file) {
  freopen((file + ".in").c_str(), "r", stdin);
  freopen((file + ".out").c_str(), "w", stdout);
}
template <class T>
void debug(string s, vector<T> a) {
  cerr << "[Debug] " << s << " = ";
  for (int i = 0; i < a.size(); i++) {
    cerr << a[i];
    if (i < a.size() - 1) cerr << ", ";
  }
  cerr << '\n';
}
template <class T>
void debug(string s, T x) {
  debug(s, vector<T>({x}));
}
template <class T>
void debug(T x) {
  debug("*", x);
}
void solve() {
  int N;
  cin >> N;
  int numSets = N / 3;
  int c1 = numSets, c2 = numSets;
  N -= numSets * 3;
  if (N == 1)
    c1++;
  else if (N == 2)
    c2++;
  cout << c1 << ' ' << c2 << '\n';
}
int main() {
  fastIO();
  int T = 1;
  cin >> T;
  while (T--) solve();
}
