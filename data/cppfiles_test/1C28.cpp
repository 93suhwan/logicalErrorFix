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
  double x, y;
  double deg;
};
const double PI = 3.14159265358979323846, ep = 1e-7;
void init() {}
double dist(double a, double b) { return sqrt(a * a + b * b); }
double find_deg(double x, double y) {
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
  double lb = 0, rb = 2e5;
  int turns = 32;
  while (turns--) {
    double mid = (lb + rb) / 2;
    priority_queue<pair<double, bool>, vector<pair<double, bool> >,
                   greater<pair<double, bool> > >
        pq;
    for (int i = 0; i < n; i++) {
      if (dist(v[i].x, v[i].y) > 2 * mid) continue;
      pt cen;
      if (true) {
        double s = (2 * mid + dist(v[i].x, v[i].y)) / 2;
        double area =
            sqrt(s * (s - mid) * (s - mid) * (s - dist(v[i].x, v[i].y)));
        double midpt_dist = area * 2 / dist(v[i].x, v[i].y);
        pt midpt;
        midpt.x = v[i].x / 2.0;
        midpt.y = v[i].y / 2.0;
        if (v[i].x == 0) {
          cen.x = midpt.x + (area * 2 / dist(v[i].x, v[i].y));
          cen.y = midpt.y;
        } else if (v[i].y == 0) {
          cen.x = midpt.x;
          cen.y = midpt.y + (area * 2 / dist(v[i].x, v[i].y));
        } else {
          double slope = v[i].y * 1.0 / v[i].x;
          slope = -1.0 / slope;
          double deltax = sqrt((midpt_dist * midpt_dist) / (slope * slope + 1));
          if (slope > 0) {
            cen.x = midpt.x + deltax;
            cen.y = midpt.y + (slope * deltax);
          } else {
            cen.x = midpt.x + deltax;
            cen.y = midpt.y + (slope * deltax);
          }
        }
        cen.deg = find_deg(cen.x, cen.y);
        pt cen2;
        cen2.x = (midpt.x - (cen.x - midpt.x));
        cen2.y = (midpt.y - (cen.y - midpt.y));
        cen2.deg = find_deg(cen2.x, cen2.y);
        if (cen.deg > cen2.deg) swap(cen, cen2);
        if (cen2.deg - cen.deg > 180) {
          cen.deg += 360;
          swap(cen, cen2);
        }
        pq.push({cen.deg, true});
        pq.push({cen.deg + 360, true});
        pq.push({cen2.deg, false});
        pq.push({cen2.deg + 360, false});
      }
    }
    double prev = -10000;
    int cnt = 0, best = 0;
    while (!pq.empty()) {
      pair<double, bool> cur = pq.top();
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
