#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;
vector<int> indexes[maxn];
long long index_mask[maxn];
int arr[maxn], n, k, tmp[maxn];
void check() {
  for (int i = 0; i < k; i++) {
    int c = indexes[i].size();
    for (int j = 0; j < c; j++) tmp[j] = arr[indexes[i][j]];
    sort(tmp, tmp + c);
    for (int j = 0; j < c; j++) arr[indexes[i][j]] = tmp[j];
  }
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      cout << "REJECTED\n";
      exit(0);
    }
  }
}
set<pair<long long, long long> > sts[maxn];
void go(long long msk1, long long msk2, int i) {
  assert((msk1 & msk2) == 0);
  if (sts[i].count({msk1, msk2})) return;
  sts[i].insert({msk1, msk2});
  if (i == k) {
    long long all = msk1 | msk2;
    if (__builtin_popcountll(all) < n - 1) {
      cout << "REJECTED\n";
      exit(0);
    }
    int cnt = __builtin_popcountll(msk1);
    if (msk1 != ((1ll << cnt) - 1)) {
      cout << "REJECTED\n";
      exit(0);
    }
    cnt = __builtin_popcountll(msk2);
    if (msk2 != (((1ll << cnt) - 1) << (n - cnt))) {
      cout << "REJECTED\n";
      exit(0);
    }
    return;
  }
  long long total_mask = index_mask[i];
  int total_mask_count = __builtin_popcountll(total_mask);
  int l = __builtin_popcountll(total_mask & msk1),
      r = total_mask_count - __builtin_popcountll(total_mask & msk2);
  long long now = total_mask;
  msk1 &= ~total_mask;
  msk2 &= ~total_mask;
  long long now_count = total_mask_count;
  while (true) {
    long long one = now ^ total_mask;
    long long two = now;
    int cnt = total_mask_count - now_count;
    if (l <= cnt && cnt <= r) go(msk1 | one, msk2 | two, i + 1);
    if (now == 0) break;
    now -= now & (-now);
    now_count--;
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int cnt;
    cin >> cnt;
    while (cnt--) {
      int x;
      cin >> x;
      --x;
      indexes[i].push_back(x);
      index_mask[i] |= 1 << x;
    }
  }
  iota(arr, arr + n, 0);
  srand(time(0));
  reverse(arr, arr + n);
  check();
  for (int _ = 0; _ < 100; _++) {
    random_shuffle(arr, arr + n);
    check();
  }
  go(0, 0, 0);
  return cout << "ACCEPTED\n", 0;
}
