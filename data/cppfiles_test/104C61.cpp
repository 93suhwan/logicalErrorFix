#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> fish(n), meat(n);
    for (int i = 0; i < n; ++i) {
      cin >> fish[i] >> meat[i];
    }
    vector<int> left(n, m), X(n), Y(n);
    for (int i = 0; i < n; ++i) {
      if (fish[i] < left[i]) {
        Y[i] += left[i] - fish[i];
        meat[i] -= Y[i];
        left[i] -= Y[i];
      }
      if (meat[i] < left[i]) {
        X[i] += left[i] - meat[i];
        fish[i] -= X[i];
        left[i] -= X[i];
      }
    }
    int64_t lb = 0, rb = 0, totalLeft = 0;
    lb = accumulate(fish.begin(), fish.end(), 0);
    rb = accumulate(meat.begin(), meat.end(), 0);
    totalLeft = accumulate(left.begin(), left.end(), 0);
    for (int i = 0; i < n; ++i) {
      if (lb - rb > left[i]) {
        X[i] += left[i];
        lb -= left[i];
      } else if (rb - lb > left[i]) {
        Y[i] += left[i];
        rb -= left[i];
      } else {
        if (lb - rb > 0) {
          X[i] += lb - rb;
          left[i] -= lb - rb;
          lb -= lb - rb;
        }
        if (rb - lb > 0) {
          Y[i] += rb - lb;
          left[i] -= rb - lb;
          rb -= rb - lb;
        }
        X[i] += left[i] >> 1;
        lb -= left[i] >> 1;
        Y[i] += left[i] - (left[i] >> 1);
        rb -= left[i] - (left[i] >> 1);
      }
    }
    cout << abs(lb - rb) << '\n';
    for (int i = 0; i < n; ++i) {
      cout << X[i] << ' ' << Y[i] << '\n';
    }
  }
  return 0;
}
