#include <bits/stdc++.h>
using namespace std;
int n;
double p;
const double EPS = 1e-9;
double getOne(int x) {
  double one = 1.0 * x / n * (n - x) / (n - 1) * (n - x - 1) / (n - 2);
  double two = 1.0 * (n - x) / n * x / (n - 1) * (n - x - 1) / (n - 2);
  double three = 1.0 * (n - x) / n * (n - x - 1) / (n - 1) * x / (n - 2);
  return (one + two + three) * 0.5;
}
double getTwo(int x) {
  double one = 1.0 * (n - x) / n * x / (n - 1) * (x - 1) / (n - 2);
  double two = 1.0 * x / n * (n - x) / (n - 1) * (x - 1) / (n - 2);
  double three = 1.0 * x / n * (x - 1) / (n - 1) * (n - x) / (n - 2);
  return one + two + three;
}
double getThree(int x) {
  return 1.0 * x / n * (x - 1) / (n - 1) * (x - 2) / (n - 2);
}
bool check(int x) {
  double one = (x >= 1 && (n - x) >= 2) ? getOne(x) : 0;
  double two = (x >= 2 && (n - x) >= 1) ? getTwo(x) : 0;
  double three = (x >= 3) ? getThree(x) : 0;
  return fabs(one + two + three - p) < EPS;
}
int solve() {
  int l = 0, r = n - 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}
int main() {
  scanf("%d%lf", &n, &p);
  printf("%d\n", solve());
}
