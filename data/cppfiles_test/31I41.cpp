#include <bits/stdc++.h>
using namespace std;
const int m = 22;
int pow_two[m];
const int maxk = 19;
const int maxn = 7e5;
int n, k;
int a[maxn];
vector<bool> bits_arr[maxn];
void compute(int d, int l, int r, unordered_map<int, int>& min_xor,
             unordered_map<int, int>& max_xor,
             unordered_map<int, int>& min_dist) {
  assert((r - l + 1) > 0);
  int ll = l, lr = -1, rl = -1, rr = r;
  for (int i = l; i <= r; i++) {
    if (bits_arr[i][d] == 1)
      rl = i;
    else
      lr = i;
  }
  bool left_empty = (lr == -1), right_empty = (rl == -1);
  if (d == 0) {
    if (left_empty || right_empty) {
      min_xor[0] = max_xor[0] = ((left_empty) ? 1 : 0);
      max_xor[1] = min_xor[1] = ((left_empty) ? 0 : 1);
      min_dist[0] = min_dist[1] = ((r - l) > 0) ? 0 : INT_MAX;
    } else {
      min_xor[0] = min_xor[1] = 0;
      max_xor[0] = max_xor[1] = 1;
      min_dist[0] = min_dist[1] = (((!left_empty) && ((lr - ll) > 0)) ||
                                   ((!right_empty) && ((rr - rl) > 0)))
                                      ? 0
                                      : 1;
    }
  } else {
    unordered_map<int, int> left_min_xor, left_max_xor, left_min_dist;
    unordered_map<int, int> right_min_xor, right_max_xor, right_min_dist;
    if (!left_empty)
      compute(d - 1, ll, lr, left_min_xor, left_max_xor, left_min_dist);
    if (!right_empty)
      compute(d - 1, rl, rr, right_min_xor, right_max_xor, right_min_dist);
    for (int x = 0; x < pow_two[d + 1]; x++) {
      bool msb_one = (x >= pow_two[d]);
      int y = (msb_one) ? (x - pow_two[d]) : x;
      min_dist[x] = INT_MAX;
      if (!left_empty) min_dist[x] = min(min_dist[x], left_min_dist[y]);
      if (!right_empty) min_dist[x] = min(min_dist[x], right_min_dist[y]);
      if ((!left_empty) && (!right_empty)) {
        int min_cross_diff =
            (msb_one) ? (pow_two[d] + left_min_xor[y] - right_max_xor[y])
                      : (pow_two[d] + right_min_xor[y] - left_max_xor[y]);
        min_dist[x] = min(min_dist[x], min_cross_diff);
      }
      min_xor[x] = INT_MAX;
      max_xor[x] = INT_MIN;
      if (!left_empty) {
        min_xor[x] = min(min_xor[x], (msb_one) ? (pow_two[d] + left_min_xor[y])
                                               : (left_min_xor[y]));
        max_xor[x] = max(max_xor[x], (msb_one) ? (pow_two[d] + left_max_xor[y])
                                               : (left_max_xor[y]));
      }
      if (!right_empty) {
        min_xor[x] =
            min(min_xor[x], (msb_one) ? (right_min_xor[y])
                                      : (pow_two[d] + right_min_xor[y]));
        max_xor[x] =
            max(max_xor[x], (msb_one) ? (right_max_xor[y])
                                      : (pow_two[d] + right_max_xor[y]));
      }
    }
  }
}
void sort_and_get_bits_arr() {
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    vector<bool> b;
    int x = a[i];
    for (int j = 0; j < k; j++) {
      b.push_back((bool)(x % 2));
      x /= 2;
    }
    bits_arr[i] = b;
  }
}
int main() {
  for (int i = 0; i < m; i++)
    pow_two[i] = ((i == 0) ? 1 : (pow_two[i - 1] * 2));
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort_and_get_bits_arr();
  unordered_map<int, int> min_xor, max_xor, min_dist;
  compute(k - 1, 0, n - 1, min_xor, max_xor, min_dist);
  for (int x = 0; x < pow_two[k]; x++) cout << min_dist[x] << ' ';
  cout << endl;
}
