#include <bits/stdc++.h>
using namespace std;
template <typename T>
vector<T> &operator--(vector<T> &v) {
  for (auto &i : v) --i;
  return v;
}
template <typename T>
vector<T> &operator++(vector<T> &v) {
  for (auto &i : v) ++i;
  return v;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &i : v) is >> i;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> v) {
  for (auto &i : v) os << i << ' ';
  return os;
}
template <typename T, typename U>
pair<T, U> &operator--(pair<T, U> &p) {
  --p.first;
  --p.second;
  return p;
}
template <typename T, typename U>
pair<T, U> &operator++(pair<T, U> &p) {
  ++p.first;
  ++p.second;
  return p;
}
template <typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> p) {
  os << p.first << ' ' << p.second;
  return os;
}
template <typename T, typename U>
pair<T, U> operator-(pair<T, U> a, pair<T, U> b) {
  return mp(a.first - b.first, a.second - b.second);
}
template <typename T, typename U>
pair<T, U> operator+(pair<T, U> a, pair<T, U> b) {
  return mp(a.first + b.first, a.second + b.second);
}
template <typename T, typename U>
void umin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
void umax(T &a, U b) {
  if (a < b) a = b;
}
bool prime(long long n) {
  for (long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
long long fact(long long x) {
  long long res = 1;
  for (long long i = 2; i <= x; i++) res *= i;
  return res;
}
struct Point {
  long long x, y;
};
bool slope(Point a, Point b, Point c) {
  long long dy1 = a.y - b.y;
  long long dx1 = a.x - b.x;
  long long dx2 = b.x - c.x;
  long long dy2 = b.y - c.y;
  return (dy1 * dx2 == dx1 * dy2);
}
long long ABS(vector<long long> a, long long x) {
  long long n = a.size();
  long long left = lower_bound(a.begin(), a.end(), x) - a.begin();
  if (left == n) {
    return a[n - 1];
  } else if (a[left] == x || left == 0) {
    return a[left];
  } else if (abs(a[left - 1] - x) <= abs(a[left] - x)) {
    return a[left - 1];
  } else {
    return a[left];
  }
}
void solve() {
  long long n;
  cin >> n;
  map<long long, map<char, long long>> mp;
  map<long long, long long> each;
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (char el : s) mp[i][el]++;
    each[i] = (int)s.size();
  }
  long long mx = -1;
  for (long long i = 0; i < 26; i++) {
    auto comp = [&](pair<long long, long long> a,
                    pair<long long, long long> b) {
      return (a.first - a.second < b.first - b.second);
    };
    priority_queue<pair<long long, long long>,
                   vector<pair<long long, long long>>, decltype(comp)>
        pq(comp);
    char elem = ('a' + i);
    for (long long j = 0; j < n; j++) {
      pq.push({mp[j][elem], each[j] - mp[j][elem]});
    }
    long long res = (pq.top().first - pq.top().second);
    pq.pop();
    long long cur = 0;
    while (!pq.empty() && res + (pq.top().first - pq.top().second) > 0) {
      cur++;
      res += pq.top().first - pq.top().second;
      pq.pop();
    }
    if (cur == 0) continue;
    mx = max(mx, cur);
  }
  cout << mx + 1 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
}
