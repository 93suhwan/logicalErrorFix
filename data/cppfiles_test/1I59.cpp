#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void yes() {
  cout << "YES\n";
  return;
}
void no() {
  cout << "NO\n";
  return;
}
template <class T>
void out(T temp) {
  cout << temp << endl;
  return;
}
void out(double temp) {
  cout << setprecision(7) << fixed << temp << endl;
  return;
}
void out(long double temp) {
  cout << setprecision(7) << fixed << temp << endl;
  return;
}
struct pt {
  int x, y;
  long double deg;
};
const long double PI = 3.14159265358979323846, ep = 1e-6;
void init() {}
long double dist(long double a, long double b) { return sqrt(a * a + b * b); }
long double find_deg(long double x, long double y) {
  if (x == 0 && y == 0) {
    return -1;
  }
  if (x > 0 && y == 0) {
    return 0;
  }
  if (x > 0 && y > 0) {
    return atan2(abs(y), abs(x)) / PI * 180;
  } else if (x == 0 && y > 0) {
    return 90;
  } else if (x < 0 && y > 0) {
    return 90 + atan2(abs(x), abs(y)) / PI * 180;
  } else if (x < 0 && y == 0) {
    return 180;
  } else if (x < 0 && y < 0) {
    return 180 + atan2(abs(y), abs(x)) / PI * 180;
  } else if (x == 0 && y < 0) {
    return 270;
  } else if (x > 0 && y < 0) {
    return 270 + atan2(abs(x), abs(y)) / PI * 180;
  } else {
    cout << "GO DEBUG HAHAHAHAHAHAHAHA\n";
    while (true) continue;
  }
  return -2;
}
void solve(int case_no) {
  int n, k;
  cin >> n >> k;
  vector<pt> v;
  for (int i = 0; i < n; i++) {
    pt cur;
    cin >> cur.x >> cur.y;
    cur.deg = find_deg(cur.x, cur.y);
    if (cur.deg == -2) {
      cout << "wrong smh\n";
      while (true) continue;
      return;
    } else if (cur.deg == -1) {
      k--;
    } else {
      v.push_back(cur);
    }
  }
  if (k <= 0) return out("0.00000000");
  n = v.size();
  cout << setprecision(8) << fixed;
  long double lb = 0, rb = 2e5;
  int turns = 50;
  while (turns--) {
    long double mid = (lb + rb) / 2;
    priority_queue<pair<long double, bool>, vector<pair<long double, bool> >,
                   greater<pair<long double, bool> > >
        pq;
    for (int i = 0; i < n; i++) {
      if (dist(v[i].x, v[i].y) > 2 * mid) continue;
      pt cen;
      if (true) {
        long double s = 2 * mid + dist(v[i].x, v[i].y);
        long double area =
            sqrt(s * (s - mid) * (s - mid) * (s - dist(v[i].x, v[i].y)));
        long double midpt_dist = area / dist(v[i].x, v[i].y);
        pt midpt;
        midpt.x = v[i].x / 2.0;
        midpt.y = v[i].y / 2.0;
        long double slope = v[i].y * 1.0 / v[i].x;
        slope = -1.0 / slope;
        long double deltax =
            sqrt((midpt_dist * midpt_dist) / (slope * slope + 1));
        cen.x = midpt.x + deltax;
        cen.y = midpt.y + (slope * deltax);
        cen.deg = find_deg(cen.x, cen.y);
        long double reflect_deg =
            (atan2(midpt_dist, (dist(v[i].x, v[i].y) / 2.0))) / PI * 180;
        if (find_deg(cen.x, cen.y) < find_deg(v[i].x, v[i].y)) {
          pq.push({cen.deg, true});
          pq.push({cen.deg + 360, true});
          pq.push({cen.deg + 720, true});
          pq.push({cen.deg + reflect_deg * 2, false});
          pq.push({cen.deg + reflect_deg * 2 + 360, false});
          pq.push({cen.deg + reflect_deg * 2 + 720, false});
        } else {
          pq.push({cen.deg - reflect_deg * 2, true});
          pq.push({cen.deg - reflect_deg * 2 + 360, true});
          pq.push({cen.deg - reflect_deg * 2 + 720, true});
          pq.push({cen.deg, false});
          pq.push({cen.deg + 360, false});
          pq.push({cen.deg + 720, false});
        }
      }
    }
    long double prev = -10000;
    int cnt = 0, best = 0;
    while (!pq.empty()) {
      pair<long double, bool> cur = pq.top();
      pq.pop();
      if (abs(cur.first - prev) > ep) {
        best = max(best, cnt);
      }
      prev = cur.first;
      if (cur.second)
        cnt++;
      else
        cnt--;
    }
    if (best >= k)
      rb = mid;
    else
      lb = mid;
  }
  cout << lb << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  srand(time(NULL));
  init();
  int t = 1;
  for (int i = 1; i <= t; i++) solve(i);
}
