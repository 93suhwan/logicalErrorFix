#include <bits/stdc++.h>
using namespace std;
const long double e = 1e-8;
const long double pi = acos(-1);
long double polar_ang(pair<long long, long long> vec) {
  long double ang = atan2(vec.second, vec.first);
  if (ang < 0) {
    ang += 2 * pi;
  }
  return ang;
}
long double dist(pair<long long, long long> lol) {
  return hypot(lol.first, lol.second);
}
bool check(long double rad, vector<pair<long long, long long>> &a,
           long long k) {
  vector<pair<long double, long double>> lol;
  long long cnt = 0;
  for (auto el : a) {
    if (el.first == 0 && el.second == 0) {
      cnt++;
      continue;
    }
    long double d = dist(el);
    if (d + e > 2 * rad) {
      continue;
    }
    long double ang = acos(d / (2 * rad));
    long double pol = polar_ang(el);
    long double a1 = pol - ang, a2 = pol + ang;
    if (a1 < 0) {
      a1 += 2 * pi;
    }
    if (a2 > 2 * pi) {
      a2 -= 2 * pi;
    }
    if (a1 < a2) {
      lol.emplace_back(a1 - e, a2 + e);
    } else {
      lol.emplace_back(a1 - e, 2 * pi + e);
      lol.emplace_back(0 - e, a2 + e);
    }
  }
  vector<pair<long double, long long>> evs;
  for (auto el : lol) {
    evs.emplace_back(el.first, 0);
    evs.emplace_back(el.second, 1);
  }
  sort(evs.begin(), evs.end());
  if (cnt >= k) {
    return true;
  }
  for (auto el : evs) {
    if (el.second == 0) {
      cnt++;
    } else {
      cnt--;
    }
    if (cnt >= k) {
      return true;
    }
  }
  return false;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n, k;
  cin >> n >> k;
  vector<pair<long long, long long>> pts(n);
  for (auto &el : pts) {
    cin >> el.first >> el.second;
  }
  long double L = 0.0, R = 2.3e5, eps = 1e-5;
  while (R - L > eps) {
    long double r = (L + R) / 2;
    if (check(r, pts, k)) {
      R = r;
    } else {
      L = r;
    }
  }
  cout << fixed << setprecision(20) << L << '\n';
}
