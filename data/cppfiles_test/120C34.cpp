#include <bits/stdc++.h>
using namespace std;
vector<int> two;
void make_two(vector<int>& two) {
  int t = 1;
  for (int i = 0; i < 19; i++) {
    two.emplace_back(t);
    t *= 2;
  }
  return;
}
int zero_cnt(int bit, int num) {
  int cycle = two[bit + 1];
  int q = num / cycle;
  int r = num % cycle;
  int ret = two[bit] * q;
  if (r < two[bit]) {
    ret += r + 1;
    return ret;
  } else {
    ret += two[bit];
    return ret;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  make_two(two);
  while (t--) {
    int l, r;
    cin >> l >> r;
    int minval = INT_MAX;
    for (int bit = 0; bit < 18; bit++) {
      int tmp = zero_cnt(bit, r) - zero_cnt(bit, l - 1);
      if (tmp < minval) minval = tmp;
    }
    cout << minval << "\n";
  }
  return 0;
}
