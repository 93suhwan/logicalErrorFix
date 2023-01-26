#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
const long long int MAX = 1e9 + 7;
void array_show(int* array, int array_n, char middle = ' ') {
  for (int i = 0; i < array_n; i++)
    printf("%d%c", array[i], (i != array_n - 1 ? middle : '\n'));
}
void array_show(long long int* array, int array_n, char middle = ' ') {
  for (int i = 0; i < array_n; i++)
    printf("%lld%c", array[i], (i != array_n - 1 ? middle : '\n'));
}
void array_show(vector<int>& vec_s, int vec_n = -1, char middle = ' ') {
  if (vec_n == -1) vec_n = vec_s.size();
  for (int i = 0; i < vec_n; i++)
    printf("%d%c", vec_s[i], (i != vec_n - 1 ? middle : '\n'));
}
void array_show(vector<long long int>& vec_s, int vec_n = -1,
                char middle = ' ') {
  if (vec_n == -1) vec_n = vec_s.size();
  for (int i = 0; i < vec_n; i++)
    printf("%lld%c", vec_s[i], (i != vec_n - 1 ? middle : '\n'));
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v1) {
  int n = v1.size();
  for (int i = 0; i < n; i++) {
    if (i) os << " ";
    os << v1[i];
  }
  return os;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  os << p.first << " " << p.second;
  return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v1) {
  int n = v1.size();
  for (int i = 0; i < n; i++) is >> v1[i];
  return is;
}
template <typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T>
class bit {
 private:
  vector<T> bit_vec;
  int bit_N = 20;
  T bit_comp(T a, T b) { return a + b; }

 public:
  bit(int n) {
    for (bit_N = 0; bit_N < 30; bit_N++) {
      if (n < (1 << bit_N)) break;
    }
    bit_vec.assign((1 << bit_N), 0);
  }
  void set(int pos, T x) {
    bit_vec[pos] = bit_comp(bit_vec[pos], x);
    for (int i = 0; i < bit_N; i++) {
      if (pos & (1 << i)) continue;
      pos |= (1 << i);
      bit_vec[pos] = bit_comp(bit_vec[pos], x);
    }
  }
  T search(int pos) {
    T s = bit_vec[pos];
    for (int i = 0; pos >= (1 << i); i++) {
      if (pos & (1 << i)) continue;
      pos -= (1 << i);
      s = bit_comp(s, bit_vec[pos]);
    }
    return s;
  }
};
template <typename T>
class Compress {
 private:
  vector<T> vec;
  vector<int> id_perm;

 public:
  void init(const vector<T>& v1) {
    int n = v1.size();
    int i, j;
    id_perm.assign(n, -1);
    vector<pair<T, int>> va;
    for (i = 0; i < n; i++) {
      va.push_back({v1[i], i});
    }
    sort(va.begin(), va.end());
    vec.clear();
    for (i = 0, j = -1; i < n; i++) {
      if (vec.empty() || vec.back() != va[i].first) {
        vec.push_back(va[i].first);
        j++;
      }
      id_perm[va[i].second] = j;
    }
  }
  Compress(const vector<T> v1) { init(v1); }
  vector<int> get_id_perm() const { return id_perm; }
  int id(const T a) {
    auto itr = lower_bound(vec.begin(), vec.end(), a);
    assert(itr != vec.end());
    assert(*itr == a);
    return itr - vec.begin();
  }
};
namespace sol {
void init() {}
void solve() {
  int n, m;
  int i, j, k;
  int a, b, c;
  cin >> n >> m;
  vector<int> v1(n), v2(m);
  vector<tuple<int, int, int>> vt;
  cin >> v1 >> v2;
  Compress<int> ca(v1);
  for (i = 0; i < n; i++) {
    vt.push_back({v1[i], 0, i});
    vt.push_back({v1[i], 2, i});
  }
  for (i = 0; i < m; i++) {
    vt.push_back({v2[i], 1, i});
  }
  set<int> s1;
  int t = 0;
  long long int s = 0;
  bit<int> bt(n);
  for (i = 0; i < n; i++) {
    a = ca.id(v1[i]);
    s += i - bt.search(a);
    bt.set(a, 1);
  }
  for (i = 0; i <= n; i++) {
    s1.insert(i);
  }
  sort(vt.begin(), vt.end());
  for (i = 0; i < vt.size(); i++) {
    tie(ignore, a, b) = vt[i];
    if (a == 1) {
      s += t;
      continue;
    }
    if (s1.empty()) {
      if (a == 0) t--;
      continue;
    }
    auto itr = s1.upper_bound(b);
    if (itr == s1.begin()) {
      if (a == 0) t--;
      continue;
    }
    itr--;
    if (a == 2) t++;
    s1.erase(itr);
    continue;
  }
  cout << s << endl;
}
}  // namespace sol
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, i;
  sol::init();
  cin >> n;
  for (i = 0; i < n; i++) {
    sol::solve();
  }
}
