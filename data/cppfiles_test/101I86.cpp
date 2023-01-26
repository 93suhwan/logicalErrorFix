#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000000;
const long long MOD = 1000000007;
const long long FMOD = 998244353;
const long long MAXN = 1e5 + 5;
const long double eps = 1e-9;
const long double PI = acos(-1);
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
void solve() {
  map<long long, vector<long long>> hor;
  map<long long, vector<long long>> ver;
  long long n, m, k;
  cin >> n >> m >> k;
  set<long long> ver_str;
  for (long long i = 0; i < n; i++) {
    long long tmp;
    cin >> tmp;
    ver_str.insert(tmp);
  };
  set<long long> hor_str;
  for (long long i = 0; i < m; i++) {
    long long tmp;
    cin >> tmp;
    hor_str.insert(tmp);
  }
  vector<pair<long long, long long>> people;
  ;
  for (long long i = 0; i < k; i++) {
    long long a, b;
    cin >> a >> b;
    people.push_back({a, b});
  };
  sort(people.begin(), people.end());
  vector<long long> hori_x;
  vector<long long> veri_y;
  set<pair<long long, long long>> bad;
  for (long long i = 0; i < k; i++) {
    long long x = people[i].first;
    long long y = people[i].second;
    if (ver_str.find(x) != ver_str.end() && hor_str.find(y) == hor_str.end()) {
      veri_y.push_back(y);
      ver[x].push_back(y);
      bad.insert({x, y});
    }
    if (ver_str.find(x) == ver_str.end() && hor_str.find(y) != hor_str.end()) {
      hori_x.push_back(x);
      hor[y].push_back(x);
      bad.insert({x, y});
    }
  }
  sort(veri_y.begin(), veri_y.end());
  sort(hori_x.begin(), hori_x.end());
  ;
  for (auto it : hor) {
    sort(it.second.begin(), it.second.end());
  }
  for (auto it : ver) {
    sort(it.second.begin(), it.second.end());
  }
  long long ans = 0;
  for (long long i = 0; i < k; i++) {
    if (bad.find(people[i]) != bad.end()) {
      long long x = people[i].first;
      long long y = people[i].second;
      ;
      if (ver_str.find(x) != ver_str.end() &&
          hor_str.find(y) == hor_str.end()) {
        auto it = hor_str.lower_bound(y);
        long long tmp = *it;
        ;
        ;
        auto it1 = lower_bound(veri_y.begin(), veri_y.end(), tmp);
        it1--;
        auto it2 = lower_bound(veri_y.begin(), veri_y.end(), y);
        auto it4 = upper_bound(veri_y.begin(), veri_y.end(), y);
        auto it3 = veri_y.begin();
        ;
        long long number = it1 - it2;
        ans += number;
        ;
        ;
        auto it12 = upper_bound(ver[x].begin(), ver[x].end(), tmp);
        it12--;
        if (*it12 > y) {
          ans -= it12 - lower_bound(ver[x].begin(), ver[x].end(), y);
        };
        it--;
        tmp = *it;
        ;
        it4--;
        long long number2 =
            it4 - lower_bound(veri_y.begin(), veri_y.end(), tmp);
        ;
        auto it13 = upper_bound(ver[x].begin(), ver[x].end(), tmp);
        ;
        if (*it13 < y) {
          number2 -= lower_bound(ver[x].begin(), ver[x].end(), y) - it13;
        }
        ans += number2;
      }
      if (ver_str.find(x) == ver_str.end() &&
          hor_str.find(y) != hor_str.end()) {
        auto it = ver_str.lower_bound(x);
        long long tmp = *it;
        ;
        ;
        auto it1 = lower_bound(hori_x.begin(), hori_x.end(), tmp);
        it1--;
        auto it2 = lower_bound(hori_x.begin(), hori_x.end(), x);
        auto it4 = upper_bound(hori_x.begin(), hori_x.end(), x);
        auto it3 = hori_x.begin();
        ;
        long long number = it1 - it2;
        ans += number;
        ;
        auto it12 = upper_bound(hor[y].begin(), hor[y].end(), tmp);
        it12--;
        if (*it12 > x) {
          ans -= it12 - lower_bound(hor[y].begin(), hor[y].end(), x);
        };
        it--;
        tmp = *it;
        ;
        it4--;
        long long number2 =
            it4 - lower_bound(hori_x.begin(), hori_x.end(), tmp);
        ;
        auto it13 = upper_bound(hor[y].begin(), hor[y].end(), tmp);
        ;
        if (*it13 < x) {
          number2 -= lower_bound(hor[y].begin(), hor[y].end(), x) - it13;
        }
        ans += number2;
      };
    }
  }
  cout << ans / 2 << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
