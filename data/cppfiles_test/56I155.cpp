#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;
using vi = vector<ll>;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
T ceil(T x, T y) {
  assert(y >= 1);
  return (x > 0 ? (x + y - 1) / y : x / y);
}
template <class T>
T floor(T x, T y) {
  assert(y >= 1);
  return (x > 0 ? x / y : (x - y + 1) / y);
}
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(long double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T, class S>
void scan(pair<T, S> &p) {
  scan(p.first), scan(p.second);
}
template <class T>
void scan(vector<T> &a) {
  for (auto &i : a) scan(i);
}
template <class T>
void scan(T &a) {
  cin >> a;
}
void IN() {}
template <class Head, class... Tail>
void IN(Head &head, Tail &...tail) {
  scan(head);
  IN(tail...);
}
vi s_to_vi(string S, char first_char = 'a') {
  vi A(S.size());
  for (ll i = 0; (i) < (ll)(S.size()); ++(i)) {
    A[i] = S[i] - first_char;
  }
  return A;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &A) {
  os << A.first << " " << A.second;
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &A) {
  for (size_t i = 0; i < A.size(); i++) {
    if (i) os << " ";
    os << A[i];
  }
  return os;
}
void print() { cout << "\n"; }
template <class Head, class... Tail>
void print(Head &&head, Tail &&...tail) {
  cout << head;
  if (sizeof...(Tail)) cout << " ";
  print(forward<Tail>(tail)...);
}
const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
void YES(bool t = 1) { cout << YESNO[t] << endl; }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { cout << YesNo[t] << endl; }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { cout << yesno[t] << endl; }
void no(bool t = 1) { yes(!t); }
template <typename T>
vector<T> cumsum(vector<T> A) {
  ll N = A.size();
  vector<T> B(N + 1);
  B[0] = T(0);
  for (ll i = 0; (i) < (ll)(N); ++(i)) {
    B[i + 1] = B[i] + A[i];
  }
  return B;
}
vi bin_count(vi &A, ll size) {
  vi C(size);
  for (auto &&x : A) {
    ++C[x];
  }
  return C;
}
template <typename T>
vi argsort(vector<T> &A) {
  vi ids(A.size());
  iota(ids.begin(), ids.end(), 0);
  sort(ids.begin(), ids.end(),
       [&](ll i, ll j) { return make_pair(A[i], i) <= make_pair(A[j], j); });
  return ids;
}
template <class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, 1 : 0);
}
using ull = unsigned long long;
void solve() {
  auto to = [&](ll x, ll y) -> ll {
    assert(0 <= x && x < 8 && 0 <= y && y < 8);
    print(x + 1, y + 1);
    cout.flush();
    string S;
    IN(S);
    if (S.find("Right") != -1) return 1;
    if (S.find("Left") != -1) return -1;
    if (S == "Done") return 2;
    return 0;
  };
  ll op = to(0, 0);
  ll x = 0, y = 0;
  bool flg = true;
  while (op != 2) {
    if (op == 1) {
      ++y;
      op = to(x, y);
      flg = false;
      continue;
    }
    if (op == -1) {
      flg = true;
      if (x == 0) {
        x += 1;
        op = to(x, y);
      } else {
        x = 0;
        op = to(x, y);
      }
    }
    if (!flg && x != 0) {
      flg = true;
      x = 0;
      op = to(x, y);
    } else {
      flg = true;
      ++x;
      op = to(x, y);
    }
  }
}
signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);
  ll T;
  IN(T);
  for (ll _ = 0; (_) < (ll)(T); ++(_)) solve();
  return 0;
}
