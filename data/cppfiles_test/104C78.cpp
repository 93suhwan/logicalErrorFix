#include <bits/stdc++.h>
using namespace std;
const int SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
void test_case() {
  long long int N, M, X = 0, Y = 0;
  cin >> N >> M;
  vector<int> a(N), b(N), m(N, M), x(N), y(N);
  set<pair<int, int> > second;
  auto getA = [&](int i, int qt) {
    m[i] -= qt;
    x[i] += qt;
    a[i] -= qt;
    X -= qt;
  };
  auto getB = [&](int i, int qt) {
    m[i] -= qt;
    y[i] += qt;
    b[i] -= qt;
    Y -= qt;
  };
  auto getL = [&]() {
    int l = second.begin()->second;
    second.erase(pair<int, int>(b[l] - a[l], l));
    return l;
  };
  auto getR = [&]() {
    int r = second.rbegin()->second;
    second.erase(pair<int, int>(b[r] - a[r], r));
    return r;
  };
  auto first = [&](int i) {
    if (a[i] < m[i]) getB(i, m[i] - a[i]);
    if (b[i] < m[i]) getA(i, m[i] - b[i]);
    assert(min(a[i], b[i]) >= m[i]);
    if (m[i]) second.emplace(b[i] - a[i], i);
  };
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
    X += a[i];
    Y += b[i];
  }
  for (int i = 0; i < N; i++) first(i);
  while (second.size()) {
    if (X > Y) {
      int l = getL();
      getA(l, min((long long int)m[l], X - Y));
      first(l);
    } else if (X < Y) {
      int r = getR();
      getB(r, min((long long int)m[r], Y - X));
      first(r);
    } else if (second.size() > 1) {
      int l = getL();
      int r = getR();
      int k = min(m[l], m[r]);
      getA(l, k);
      getB(r, k);
      first(l);
      first(r);
    } else {
      int l = getL();
      getA(l, m[l] / 2);
      getB(l, m[l]);
    }
  }
  cout << abs(X - Y) << endl;
  for (int i = 0; i < N; i++) cout << x[i] << " " << y[i] << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    test_case();
  }
  return 0;
}
