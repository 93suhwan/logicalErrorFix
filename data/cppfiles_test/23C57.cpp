#include <bits/stdc++.h>
using namespace std;
istream& operator>>(istream& in, __int128& a) {
  int64_t b;
  in >> b;
  a = b;
  return in;
}
ostream& operator<<(ostream& out, const __int128 a) {
  unsigned __int128 b = a < 0 ? -a : a;
  char buf[128];
  char* c = end(buf);
  do {
    --c;
    *c = "0123456789"[b % 10];
    b /= 10;
  } while (b);
  if (a < 0) {
    --c;
    *c = '-';
  }
  int64_t len = end(buf) - c;
  out.rdbuf()->sputn(c, len);
  return out;
}
template <class T>
void mini(T& a, T b) {
  a = min(a, b);
}
template <class T>
void maxi(T& a, T b) {
  a = max(a, b);
}
template <class T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <class T1, class T2>
ostream& operator<<(ostream& os, pair<T1, T2> const& a) {
  return os << "[" << a.first << ", " << a.second << "]";
}
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os,
                                  Container const& a) {
  os << "{ ";
  for (auto& i : a) os << i << " ";
  return os << "}";
}
template <class T>
void out(T a) {
  cout << a << endl;
}
template <class T, class... Args>
void out(T a, Args... args) {
  cout << a << " ";
  out(args...);
}
template <class T>
void out(std::initializer_list<T> a) {
  for (auto i : a) {
    cout << i << " ";
  }
  cout << endl;
}
template <class T>
void out(vector<vector<T>> a) {
  for (vector<T> i : a) out(i);
}
template <class T>
void out_(T a[], int l, int r) {
  for (int i = l; i <= r; i++) cout << a[i] << " ";
  cout << endl;
}
void out() { cout << "OK" << endl; }
template <class T>
void sort(vector<T>& a) {
  sort(a.begin(), a.end());
}
template <class T>
void rever(vector<T>& a) {
  reverse(a.begin(), a.end());
}
template <class T>
void uniq(vector<T>& a) {
  sort(a);
  a.erase(unique(a.begin(), a.end()), a.end());
}
template <class T>
vector<T> set_int(vector<T> a, vector<T> b) {
  sort(a);
  sort(b);
  vector<T> res;
  set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res));
  return res;
}
clock_t start_time;
void start_timer() { start_time = clock(); }
double get_time() { return (double)(clock() - start_time) / CLOCKS_PER_SEC; }
template <class T>
using min_pque = priority_queue<T, vector<T>, greater<T>>;
const int N = 4005;
long long a[N];
long long m;
vector<long long> sol(int l, int r) {
  if (l > r) {
    return {0};
  }
  if (l == r) {
    return {0, (m - 1) * a[l]};
  }
  int id = l;
  for (int i = l; i <= r; i++) {
    if (a[i] < a[id]) {
      id = i;
    }
  }
  long long mn = a[id];
  if (id == r) id--;
  vector<long long> lef = sol(l, id);
  vector<long long> rig = sol(id + 1, r);
  vector<long long> res(lef.size() + rig.size() - 1, 0);
  for (int i = 0; i <= lef.size() - 1; i++) {
    for (int j = 0; j <= rig.size() - 1; j++) {
      long long cur = lef[i] + rig[j] - 2ll * i * j * mn;
      maxi(res[i + j], cur);
    }
  }
  return res;
}
void Solve() {
  int n;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector<long long> ans = sol(1, n);
  out(ans[m]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  start_timer();
  Solve();
  return 0;
}
