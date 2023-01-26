#include <bits/stdc++.h>
using namespace std;
int INFTY = 123456789;
struct Point {
  int x;
  int y;
} INF;
inline bool operator==(const Point& lhs, const Point& rhs) {
  return ((lhs.x == rhs.x) && (lhs.y == rhs.y));
}
bool compPoint(const Point& a, const Point& b) {
  if (a.x < b.x) {
    return true;
  }
  if (a.x > b.x) {
    return false;
  }
  return a.y < b.y;
}
bool coll(Point p1, Point p2, Point p3) {
  return (((long long int)p1.x * ((long long int)p2.y - (long long int)p3.y) +
           (long long int)p2.x * ((long long int)p3.y - (long long int)p1.y) +
           (long long int)p3.x * ((long long int)p1.y - (long long int)p2.y)) ==
          0);
}
long double hyp(Point p1, Point p2) {
  long double dx = 1.0 * (p1.x - p2.x);
  long double dy = 1.0 * (p1.y - p2.y);
  return hypot(dx, dy);
}
int binarySearch(Point arr[], int p, int r, Point num) {
  if (p <= r) {
    int mid = (p + r) / 2;
    if (arr[mid] == num)
      return mid;
    else if (compPoint(arr[mid], num))
      return binarySearch(arr, mid + 1, r, num);
    else
      return binarySearch(arr, p, mid - 1, num);
  }
  return -1;
}
int main() {
  cout << setprecision(10);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  INF.x = INFTY;
  INF.y = INFTY;
  cin >> n;
  cin >> k;
  k--;
  Point PTL[n];
  for (int i = 0; i < n; i++) {
    int a, b;
    Point p;
    cin >> a;
    cin >> b;
    p.x = a;
    p.y = b;
    PTL[i] = p;
  }
  if (n == 3) {
    if (k == 0) {
      cout << min(hyp(PTL[0], PTL[2]), hyp(PTL[0], PTL[1])) +
                  hyp(PTL[1], PTL[2]);
    }
    if (k == 1) {
      cout << min(hyp(PTL[1], PTL[2]), hyp(PTL[0], PTL[1])) +
                  hyp(PTL[0], PTL[2]);
    }
    if (k == 2) {
      cout << min(hyp(PTL[0], PTL[2]), hyp(PTL[2], PTL[1])) +
                  hyp(PTL[1], PTL[0]);
    }
  } else {
    int impostidx = -1;
    if (coll(PTL[0], PTL[1], PTL[2])) {
      for (int i = 3; i < n; i++) {
        if (!coll(PTL[0], PTL[1], PTL[i])) {
          impostidx = i;
          break;
        }
      }
    } else {
      if (coll(PTL[0], PTL[1], PTL[3])) {
        impostidx = 2;
      }
      if (coll(PTL[0], PTL[2], PTL[3])) {
        impostidx = 1;
      }
      if (coll(PTL[2], PTL[1], PTL[3])) {
        impostidx = 0;
      }
    }
    if (impostidx == -1) {
      cout << "find impost error";
      return 10;
    }
    Point impPt = PTL[impostidx];
    Point chosenPt = PTL[k];
    PTL[impostidx] = INF;
    sort(PTL, PTL + n, compPoint);
    Point first = PTL[0], last = PTL[n - 2];
    long double range = hyp(first, last);
    if (impPt == chosenPt) {
      cout << min(hyp(impPt, first), hyp(impPt, last)) + range;
    } else {
      long double min_v = 1e12;
      for (int i = 0; i < n - 2; i++) {
        min_v = min(min_v, hyp(PTL[i], impPt) + hyp(PTL[i + 1], impPt) -
                               hyp(PTL[i], PTL[i + 1]));
      }
      if (chosenPt == first) {
        cout << min(hyp(impPt, last), min_v) + range;
      } else if (chosenPt == last) {
        cout << min(hyp(impPt, first), min_v) + range;
      } else {
        int loc = binarySearch(PTL, 0, n - 2, chosenPt);
        long double curMin =
            min_v + min(hyp(chosenPt, first), hyp(chosenPt, last));
        Point prevPt = PTL[loc - 1];
        Point postPt = PTL[loc + 1];
        curMin = min(curMin, hyp(impPt, first) + hyp(impPt, postPt) -
                                 hyp(chosenPt, postPt));
        curMin = min(curMin, hyp(impPt, last) + hyp(impPt, prevPt) -
                                 hyp(chosenPt, prevPt));
        cout << curMin + range;
      }
    }
  }
  return 0;
}
