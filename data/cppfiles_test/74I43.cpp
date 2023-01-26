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
using vvvvvc = vector<vvvvc<T>>;
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
       [&](ll i, ll j) { return A[i] < A[j] || (A[i] == A[j] && i < j); });
  return ids;
}
ll binary_search(function<bool(ll)> check, ll ok, ll ng) {
  while (abs(ok - ng) > 1) {
    auto x = (ng + ok) / 2;
    if (check(x))
      ok = x;
    else
      ng = x;
  }
  return ok;
}
template <class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, 1 : 0);
}
void solve() {
  ll N;
  IN(N);
  vector<ll> B(N);
  IN(B);
  if (N == 2) {
    ll a = B[0], b = B[1];
    if (a != b) return NO();
    YES();
    print(0, a);
    return;
  }
  sort(B.begin(), B.end()), B.erase(unique(B.begin(), B.end()), B.end());
  if (B.size() < N) {
    vi ANS = B;
    while (ANS.size() < N) ANS.emplace_back(0);
    YES();
    print(ANS);
    return;
  }
  assert(B.size() == N);
  if (N == 3) {
    ll S = accumulate(B.begin(), B.end(), 0LL);
    if (S % 2 == 1) return NO();
    S /= 2;
    YES();
    print(S - B[0], S - B[1], S - B[2]);
    return;
  }
  vi EV, OD;
  for (auto &&x : B) {
    if (x % 2 == 0)
      EV.emplace_back(x);
    else
      OD.emplace_back(x);
  }
  if (EV.size() >= 3) {
    ll a = EV[0], b = EV[1], c = EV[2];
    ll S = (a + b + c) / 2;
    vi ANS = {S - a, S - b, S - c};
    for (ll i = (3); (i) < (ll)(EV.size()); ++(i)) ANS.emplace_back(EV[i] - a);
    for (ll i = 0; (i) < (ll)(OD.size()); ++(i)) ANS.emplace_back(OD[i] - a);
    YES();
    return print(ANS);
  }
  if (OD.size() >= 2 && EV.size() >= 1) {
    ll a = OD[0], b = OD[1], c = EV[0];
    ll S = (a + b + c) / 2;
    vi ANS = {S - a, S - b, S - c};
    for (ll i = (1); (i) < (ll)(EV.size()); ++(i))
      ANS.emplace_back(EV[i] - ANS[0]);
    for (ll i = (2); (i) < (ll)(OD.size()); ++(i))
      ANS.emplace_back(OD[i] - ANS[0]);
    YES();
    return print(ANS);
  }
  assert(EV.size() == 0);
  ll K = min(N, 25LL);
  vi DP(1 << K);
  for (ll k = 0; (k) < (ll)(K); ++(k))
    for (ll s = 0; (s) < (ll)(1 << k); ++(s)) DP[s + (1 << k)] = DP[s] + B[k];
  pi st = [&]() -> pi {
    vc<map<ll, ll>> MEMO(K + 1);
    for (ll s = 0; (s) < (ll)(1 << K); ++(s)) {
      ll n = __builtin_popcount(s);
      if (MEMO[n].count(DP[s])) {
        ll t = MEMO[n][DP[s]];
        return make_pair(s, t);
      }
      MEMO[n][DP[s]] = s;
    }
    return make_pair(-1, -1);
  }();
  ll s = st.first, t = st.second;
  if (s == -1) return NO();
  ll u = s & t;
  s -= u, t -= u;
  assert(__builtin_popcount(s) == __builtin_popcount(t));
  assert(DP[s] == DP[t]);
  assert((s & t) == 0);
  vi X, Y, Z;
  for (ll k = 0; (k) < (ll)(K); ++(k)) {
    if (s & 1 << k)
      X.emplace_back(B[k]);
    else if (t & 1 << k)
      Y.emplace_back(B[k]);
    else
      Z.emplace_back(B[k]);
  }
  for (ll k = (K); (k) < (ll)(B.size()); ++(k)) Z.emplace_back(B[k]);
  assert(X.size() == Y.size());
  vi ANS = {0};
  for (ll i = 0; (i) < (ll)(X.size()); ++(i)) {
    ANS.emplace_back(X[i] - ANS.back());
    ANS.emplace_back(Y[i] - ANS.back());
  }
  assert(ANS.back() == 0);
  ANS.pop_back();
  for (auto &&x : Z) ANS.emplace_back(x);
  YES();
  print(ANS);
}
signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);
  solve();
  return 0;
}
