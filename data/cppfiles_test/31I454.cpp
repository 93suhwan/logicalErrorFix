#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using Pi = pair<ll, ll>;
using Tup = tuple<ll, ll, ll>;
using vl = vector<ll>;
using vd = vector<ld>;
using vvd = vector<vd>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vp = vector<Pi>;
using vvc = vector<vector<char>>;
using vvl = vector<vector<ll>>;
using vvvl = vector<vector<vector<ll>>>;
using vvvvl = vector<vvvl>;
const ll INF = 1LL << 60;
const ld PI = 3.1415926535897932385;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
void printb(ll N, ll d = 16) {
  for (ll i = 0; i < (d); ++i) {
    cout << (N / ((1LL) << (d - i - 1))) % 2;
  }
  cout << endl;
}
void printv(vector<ll> a) {
  for (ll i = 0; i < (a.size()); ++i) {
    if (i == a.size() - 1) {
      cout << a[i] << endl;
    } else {
      cout << a[i] << " ";
    }
  }
}
void printv2(vector<ll> a) {
  for (ll i = 0; i < (a.size()); ++i) {
    cout << a[i] << endl;
  }
}
void printvv(vvl a) {
  for (ll i = 0; i < (a.size()); ++i) {
    printv(a[i]);
  }
}
bool In_map(ll y, ll x, ll h, ll w) {
  if (y < 0 || x < 0 || y >= h || x >= w) {
    return 0;
  } else {
    return 1;
  }
}
bool compare(Pi a, Pi b) {
  if (a.first != b.first) {
    return a.first < b.first;
  } else {
    return a.second < b.second;
  }
}
const vector<ll> dx{1, 0, -1, 0};
const vector<ll> dy{0, 1, 0, -1};
void Main() {
  ll n;
  cin >> n;
  vl a(n);
  map<ll, ll> m;
  vl b(n);
  ll flag = 0;
  for (ll i = 0; i < (n); ++i) {
    cin >> a[i];
  }
  if (n % 2 == 1) {
    b[0] = a[2];
    b[1] = a[2];
    b[2] = -(a[0] + a[1]);
    ll p = 0;
    ll pi;
    for (ll i = 3; i < (n); ++i) {
      if (p != 0) {
        b[i] = p;
        b[pi] = -a[i];
        p = 0;
      } else {
        p = a[i];
        pi = i;
      }
    }
  } else {
    ll p = 0;
    ll pi;
    for (ll i = 0; i < (n); ++i) {
      if (p != 0) {
        b[i] = p;
        b[pi] = -a[i];
        p = 0;
      } else {
        p = a[i];
        pi = i;
      }
    }
  }
  printv(b);
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    Main();
  }
  return 0;
}
