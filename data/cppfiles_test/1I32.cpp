#include <bits/stdc++.h>
using namespace std;
int n, k;
struct point1 {
  long double x, y;
} point[100005];
long double dis(point1 x, point1 y) {
  return sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
}
struct node {
  long double a;
  int flag = 1;
  bool operator<(const node n1) const {
    if (fabs(a - n1.a) <= 1e-6) return flag < n1.flag;
    return a < n1.a;
  }
} node[400005];
bool check1(long double nowr) {
  point1 o;
  o.x = 0;
  o.y = 0;
  int count1 = 0;
  for (int i = 1; i <= n; i++) {
    long double temp111 = dis(point[i], o);
    if (temp111 > 2 * nowr) continue;
    long double temp1;
    if (point[i].x == 0) {
      if (point[i].y > 0)
        temp1 = 3.1415926 / 2;
      else {
        temp1 = -3.1415926 / 2;
      }
    } else {
      temp1 = atan(point[i].y / point[i].x);
      if (point[i].y < 0) temp1 += 3.1415926;
    }
    if (temp1 < 1e-6) temp1 += 2 * 3.1415926;
    long double temp11 = dis(point[i], o);
    long double temp2 = acos(temp11 / (2 * nowr));
    long double temp3 = temp1 + temp2;
    if (temp3 > 2 * 3.1415926) temp3 -= 2 * 3.1415926;
    long double temp4 = temp1 - temp2;
    if (temp4 < 1e-6) temp4 += 2 * 3.1415926;
    if (temp4 > temp3) {
      count1++;
      node[count1].a = 0;
      node[count1].flag = 1;
      count1++;
      node[count1].a = temp3;
      node[count1].flag = -1;
      count1++;
      node[count1].a = temp4;
      node[count1].flag = 1;
      count1++;
      node[count1].a = 2 * 3.1415926;
      node[count1].flag = -1;
    } else {
      count1++;
      node[count1].a = temp4;
      node[count1].flag = 1;
      count1++;
      node[count1].a = temp3;
      node[count1].flag = -1;
    }
  }
  sort(node + 1, node + count1 + 1);
  int noww = 0;
  for (int i = 1; i <= count1; i++) {
    if (node[i].flag == 1)
      noww++;
    else {
      noww--;
    }
    if (noww >= k) return 1;
  }
  return 0;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> point[i].x >> point[i].y;
  }
  long double l = 0;
  long double r = 200000;
  while (r - l >= 1e-6) {
    long double mid = (l + r) / 2;
    if (check1(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << fixed << setprecision(10) << l;
}
