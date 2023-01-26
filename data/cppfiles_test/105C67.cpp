#include <bits/stdc++.h>
using namespace std;
typedef struct {
  long long j, x1, x2;
} inter;
struct comp1 {
  bool operator()(const inter& a, const inter& b) const { return a.x1 < b.x1; };
};
struct comp2 {
  bool operator()(const inter& a, const inter& b) const {
    return (a.x2 == b.x2) ? (a.x1 < b.x1) : (a.x2 < b.x2);
  };
};
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n), b(n), m(n);
  unordered_map<long long, vector<long long>> dsize;
  for (long long i = 0; i < (n); i++) {
    cin >> a[i] >> b[i] >> m[i];
    dsize[a[i] + b[i] - m[i]].push_back(i);
  }
  long long c = 0;
  vector<long long> ea(n);
  for (auto& x : dsize) {
    multiset<inter, comp1> inter1;
    multiset<inter, comp2> inter2;
    for (auto& i : x.second) {
      long long eamax = min(m[i], a[i]);
      long long eamin = max(m[i] - b[i], 0LL);
      inter1.insert(inter{i, a[i] - eamax, a[i] - eamin});
      inter2.insert(inter{i, a[i] - eamax, a[i] - eamin});
    }
    auto p1 = inter1.begin();
    while (!inter2.empty()) {
      long long targ = inter2.begin()->x2;
      while ((p1 == inter1.end()) ? false : (p1->x1 <= targ)) {
        inter2.erase(*p1);
        ea[p1->j] = a[p1->j] - targ;
        p1++;
      }
      c++;
    }
  }
  cout << c << endl;
  for (long long i = 0; i < (n); i++)
    cout << ea[i] << " " << m[i] - ea[i] << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ifstream ifs;
  if (""[0]) cin.rdbuf((ifs = ifstream("")).rdbuf());
  ;
  ofstream ofs;
  if (""[0]) cout.rdbuf((ofs = ofstream("")).rdbuf());
  ;
  ofstream lfs;
  if (""[0]) clog.rdbuf((lfs = ofstream("")).rdbuf());
  ;
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
