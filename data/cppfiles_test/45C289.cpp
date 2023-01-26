#include <bits/stdc++.h>
using namespace std;
struct perl {
  int n;
  vector<int> p;
};
int main() {
  int t;
  cin >> t;
  vector<perl> a;
  a.resize(t);
  for (int i = 0; i < t; ++i) {
    cin >> a[i].n;
    for (int j = 0; j < a[i].n; ++j) {
      int x;
      cin >> x;
      a[i].p.push_back(x);
    }
  }
  vector<int> height;
  for (int i = 0; i < t; ++i) {
    bool nn = false;
    int h_now = 1;
    int no = 0;
    vector<int> b;
    b = a[i].p;
    for (int j = 0; j < a[i].n; ++j) {
      if (b[j] == 0) {
        no += 1;
      }
      if (no == 2) {
        height.push_back(-1);
        nn = true;
        break;
      }
      if (j == 0 && b[j] == 1) {
        h_now += 1;
        no = 0;
      } else if (j > 0 && b[j] == 1 && b[j - 1] == 0) {
        h_now += 1;
        no = 0;
      } else if (j > 0 && b[j] == 1 && b[j - 1] == 1) {
        h_now += 5;
        no = 0;
      }
    }
    if (!nn) {
      height.push_back(h_now);
    }
  }
  for (int i = 0; i < t; ++i) {
    cout << height[i] << '\n';
  }
  return 0;
}
