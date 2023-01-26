#include <bits/stdc++.h>
using namespace std;
int n, k;
pair<double, double> nodes[1000000];
double dict(pair<double, double> x, pair<double, double> y) {
  double res = (x.first - y.first) * (x.first - y.first) +
               (x.second - y.second) * (x.second - y.second);
  return sqrt(res);
}
pair<double, double> find_line(pair<double, double> x, pair<double, double> y) {
  pair<double, double> res;
  if (x.first == y.first) {
    res.second = x.first;
    res.first = 10e17;
  } else {
    res.first = (y.second - x.second) / (y.first - x.first);
    res.second =
        (x.second * y.first - x.first * y.second) / (y.first - x.first);
  }
  return res;
}
bool same_line(pair<double, double> x, pair<double, double> y) {
  if ((abs(x.first - y.first) <= 10e-9) && (abs(x.second - y.second) <= 10e-9))
    return true;
  return false;
}
void swap(int x, int y) {
  pair<double, double> tmp = nodes[x];
  nodes[x] = nodes[y];
  nodes[y] = tmp;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%lf %lf", &nodes[i].first, &nodes[i].second);
  }
  pair<double, double> startNode = nodes[k];
  int dif = 1;
  double res;
  if (n == 3) {
    if (k == 1) {
      res = min(dict(nodes[1], nodes[2]), dict(nodes[1], nodes[3])) +
            dict(nodes[2], nodes[3]);
      printf("%.6lf\n", res);
    }
    if (k == 2) {
      res = min(dict(nodes[2], nodes[1]), dict(nodes[2], nodes[3])) +
            dict(nodes[1], nodes[3]);
      printf("%.6lf\n", res);
    }
    if (k == 3) {
      res = min(dict(nodes[3], nodes[1]), dict(nodes[3], nodes[2])) +
            dict(nodes[1], nodes[2]);
      printf("%.6lf\n", res);
    }
    return 0;
  }
  pair<double, double> line_12 = find_line(nodes[1], nodes[2]);
  pair<double, double> line_13 = find_line(nodes[1], nodes[3]);
  if (same_line(line_12, line_13)) {
    for (int i = 4; i <= n; ++i)
      if (!same_line(line_12, find_line(nodes[1], nodes[i]))) {
        dif = i;
        break;
      }
  } else if (same_line(line_12, find_line(nodes[2], nodes[4]))) {
    dif = 3;
  } else if (same_line(line_13, find_line(nodes[3], nodes[4]))) {
    dif = 2;
  }
  swap(dif, n);
  sort(nodes + 1, nodes + n);
  if (same_line(nodes[n], startNode)) {
    res = dict(nodes[1], nodes[n - 1]) +
          min(dict(nodes[1], nodes[n]), dict(nodes[n], nodes[n - 1]));
    printf("%.6lf\n", res);
  } else {
    res = 10e17;
    bool ok = true;
    for (int i = 1; i <= n - 1; ++i)
      if (ok) {
        if (i == 1) {
          res = min(
              res,
              min(dict(startNode, nodes[1]) + dict(nodes[n - 1], nodes[n]),
                  dict(startNode, nodes[n - 1]) + dict(nodes[1], nodes[n])) +
                  dict(nodes[1], nodes[n - 1]));
        } else {
          double way_1 =
              dict(startNode, nodes[i]) + dict(nodes[i], nodes[n - 1]) +
              dict(nodes[n], nodes[n - 1]) + dict(nodes[i - 1], nodes[n]) +
              dict(nodes[i - 1], nodes[1]);
          double way_2 =
              dict(startNode, nodes[n - 1]) + dict(nodes[i], nodes[n - 1]) +
              dict(nodes[n], nodes[i]) + dict(nodes[i - 1], nodes[n]) +
              dict(nodes[i - 1], nodes[1]);
          res = min(res, min(way_1, way_2));
        }
        if (same_line(nodes[i], startNode)) {
          ok = false;
          if (i == n - 1)
            res = min(
                res,
                min(dict(startNode, nodes[1]) + dict(nodes[n - 1], nodes[n]),
                    dict(startNode, nodes[n - 1]) + dict(nodes[1], nodes[n])) +
                    dict(nodes[1], nodes[n - 1]));
          else {
            double way_1 = dict(startNode, nodes[i]) +
                           dict(nodes[i], nodes[1]) + dict(nodes[n], nodes[1]) +
                           dict(nodes[i + 1], nodes[n]) +
                           dict(nodes[i + 1], nodes[n - 1]);
            double way_2 = dict(startNode, nodes[1]) +
                           dict(nodes[i], nodes[1]) + dict(nodes[n], nodes[i]) +
                           dict(nodes[i + 1], nodes[n]) +
                           dict(nodes[i + 1], nodes[n - 1]);
            res = min(res, min(way_1, way_2));
          }
        }
      } else {
        if (i == n - 1)
          res = min(
              res,
              min(dict(startNode, nodes[1]) + dict(nodes[n - 1], nodes[n]),
                  dict(startNode, nodes[n - 1]) + dict(nodes[1], nodes[n])) +
                  dict(nodes[1], nodes[n - 1]));
        else {
          double way_1 = dict(startNode, nodes[i]) + dict(nodes[i], nodes[1]) +
                         dict(nodes[n], nodes[1]) +
                         dict(nodes[i + 1], nodes[n]) +
                         dict(nodes[i + 1], nodes[n - 1]);
          double way_2 = dict(startNode, nodes[1]) + dict(nodes[i], nodes[1]) +
                         dict(nodes[n], nodes[i]) +
                         dict(nodes[i + 1], nodes[n]) +
                         dict(nodes[i + 1], nodes[n - 1]);
          res = min(res, min(way_1, way_2));
        }
      }
    printf("%.6lf\n", res);
  }
}
