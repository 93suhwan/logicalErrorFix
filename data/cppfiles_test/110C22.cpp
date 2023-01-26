#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long max_n = 100005;
long long ptr[3];
pair<long long, long long> points[3][max_n], test_points[3][max_n];
long long x[3][max_n], y[3][max_n];
long long n;
bool check_config(long long cnt, bool flip_x, bool flip_y, bool flip_xy) {
  for (long long i = 1; i <= n / 3; i++) {
    for (long long c = 0; c < 3; c++) test_points[c][i] = points[c][i];
  }
  for (long long i = 1; i <= n / 3; i++) {
    for (long long c = 0; c < 3; c++) {
      if (flip_xy) swap(test_points[c][i].first, test_points[c][i].second);
      if (flip_x) test_points[c][i].first = -test_points[c][i].first;
      if (flip_y) test_points[c][i].second = -test_points[c][i].second;
    }
  }
  for (long long i = 1; i <= n / 3; i++) {
    for (long long c = 0; c < 3; c++) x[c][i] = test_points[c][i].first;
  }
  vector<long long> color_order = {0, 1, 2};
  do {
    nth_element(x[color_order[0]] + 1, x[color_order[0]] + cnt,
                x[color_order[0]] + n / 3 + 1);
    long long bound_0 = x[color_order[0]][cnt];
    long long lesser_1 = 0;
    for (long long i = 1; i <= n / 3; i++) {
      if (x[color_order[1]][i] <= bound_0) lesser_1++;
    }
    if (lesser_1 + cnt > n / 3) continue;
    nth_element(x[color_order[1]] + 1, x[color_order[1]] + lesser_1 + cnt,
                x[color_order[1]] + n / 3 + 1);
    long long bound_1 = x[color_order[1]][lesser_1 + cnt];
    long long lesser_2 = 0;
    for (long long i = 1; i <= n / 3; i++) {
      if (x[color_order[2]][i] <= bound_1) lesser_2++;
    }
    if (lesser_2 + cnt <= n / 3) return 1;
  } while (next_permutation(color_order.begin(), color_order.end()));
  color_order = {0, 1, 2};
  do {
    nth_element(x[color_order[0]] + 1, x[color_order[0]] + cnt,
                x[color_order[0]] + n / 3 + 1);
    long long bound_0 = x[color_order[0]][cnt];
    long long lesser_1 = 0;
    for (long long i = 1; i <= n / 3; i++) {
      if (x[color_order[1]][i] <= bound_0) lesser_1++;
    }
    if (lesser_1 + cnt > n / 3) continue;
    long long cnt_greater = 0;
    for (long long i = 1; i <= n / 3; i++) {
      if (test_points[color_order[1]][i].first > bound_0) {
        y[color_order[1]][cnt_greater + 1] =
            test_points[color_order[1]][i].second;
        cnt_greater++;
      }
    }
    nth_element(y[color_order[1]] + 1, y[color_order[1]] + cnt,
                y[color_order[1]] + cnt_greater + 1);
    long long bound_1 = y[color_order[1]][cnt];
    long long sat = 0;
    for (long long i = 1; i <= n / 3; i++) {
      if (test_points[color_order[2]][i].first > bound_0 &&
          test_points[color_order[2]][i].second > bound_1)
        sat++;
    }
    if (sat >= cnt) return 1;
  } while (next_permutation(color_order.begin(), color_order.end()));
  return 0;
}
bool check(long long cnt) {
  for (long long flip_x = 0; flip_x <= 1; flip_x++) {
    for (long long flip_y = 0; flip_y <= 1; flip_y++) {
      for (long long flip_xy = 0; flip_xy <= 1; flip_xy++) {
        if (check_config(cnt, flip_x, flip_y, flip_xy)) {
          return 1;
        }
      }
    }
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    long long x_i, y_i, c_i;
    cin >> x_i >> y_i >> c_i;
    points[c_i - 1][ptr[c_i - 1] + 1] = make_pair(x_i, y_i);
    ptr[c_i - 1]++;
  }
  long long l = 1, r = n / 3;
  while (l < r) {
    long long mid = (l + r + 1) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  cout << 3 * l << "\n";
}
