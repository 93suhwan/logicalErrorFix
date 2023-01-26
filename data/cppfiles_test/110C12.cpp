#include <bits/stdc++.h>
using namespace std;
template <class>
struct is_container : false_type {};
template <class... Ts>
struct is_container<vector<Ts...>> : true_type {};
template <class... Ts>
struct is_container<map<Ts...>> : true_type {};
template <class... Ts>
struct is_container<unordered_map<Ts...>> : true_type {};
template <class... Ts>
struct is_container<set<Ts...>> : true_type {};
template <class... Ts>
struct is_container<unordered_set<Ts...>> : true_type {};
template <class... Ts>
struct is_container<multiset<Ts...>> : true_type {};
template <class... Ts>
struct is_container<unordered_multiset<Ts...>> : true_type {};
template <class T, class = typename enable_if<is_container<T>::value>::type>
ostream& operator<<(ostream& o, T x) {
  int f = 1;
  o << "{";
  for (auto y : x) {
    o << (f ? "" : ", ") << y;
    f = 0;
  }
  return o << "}";
}
template <class T, class U>
ostream& operator<<(ostream& o, pair<T, U> x) {
  return o << "(" << x.first << ", " << x.second << ")";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a[3];
  for (int i = 0; i < n; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    a[c - 1].push_back({x, y});
  }
  vector<int> ord_x[3], ord_y[3];
  for (int i : {0, 1, 2}) {
    ord_x[i].resize(n / 3);
    ord_y[i].resize(n / 3);
    iota(ord_x[i].begin(), ord_x[i].end(), 0);
    iota(ord_y[i].begin(), ord_y[i].end(), 0);
    sort(ord_x[i].begin(), ord_x[i].end(),
         [&](int j, int k) { return a[i][j].first < a[i][k].first; });
    sort(ord_y[i].begin(), ord_y[i].end(),
         [&](int j, int k) { return a[i][j].second < a[i][k].second; });
  }
  int sol = 0;
  for (int iter : {0, 1}) {
    int lo = 0, hi = n / 3 + 1;
    while (lo + 1 < hi) {
      int mid = (lo + hi) / 2;
      bool possible = false;
      int perm[3] = {0, 1, 2};
      do {
        int pos_0 = mid - 1;
        int prev_x = a[perm[0]][ord_x[perm[0]][pos_0]].first;
        int pos_1 = 0;
        while (pos_1 < n / 3 &&
               a[perm[1]][ord_x[perm[1]][pos_1]].first <= prev_x)
          pos_1++;
        pos_1 += mid - 1;
        if (pos_1 >= n / 3) continue;
        prev_x = a[perm[1]][ord_x[perm[1]][pos_1]].first;
        int pos_2 = 0;
        while (pos_2 < n / 3 &&
               a[perm[2]][ord_x[perm[2]][pos_2]].first <= prev_x)
          pos_2++;
        pos_2 += mid - 1;
        if (pos_2 >= n / 3) continue;
        possible = true;
      } while (next_permutation(perm, perm + 3));
      do {
        int pos_0 = mid - 1;
        int prev_x = a[perm[0]][ord_x[perm[0]][pos_0]].first;
        int pos_1 = 0, cnt_1 = 0;
        while (pos_1 < n / 3) {
          if (a[perm[1]][ord_y[perm[1]][pos_1]].first > prev_x) cnt_1++;
          if (cnt_1 == mid) break;
          pos_1++;
        }
        if (cnt_1 != mid) continue;
        int bottom_y = a[perm[1]][ord_y[perm[1]][pos_1]].second;
        int pos_2 = n / 3 - 1, cnt_2 = 0;
        while (pos_2 >= 0) {
          if (a[perm[2]][ord_y[perm[2]][pos_2]].first > prev_x) cnt_2++;
          if (cnt_2 == mid) break;
          pos_2--;
        }
        if (cnt_2 != mid) continue;
        int top_y = a[perm[2]][ord_y[perm[2]][pos_2]].second;
        if (bottom_y < top_y) possible = true;
      } while (next_permutation(perm, perm + 3));
      do {
        int pos_0 = n / 3 - mid;
        int prev_x = a[perm[0]][ord_x[perm[0]][pos_0]].first;
        int pos_1 = 0, cnt_1 = 0;
        while (pos_1 < n / 3) {
          if (a[perm[1]][ord_y[perm[1]][pos_1]].first < prev_x) cnt_1++;
          if (cnt_1 == mid) break;
          pos_1++;
        }
        if (cnt_1 != mid) continue;
        int bottom_y = a[perm[1]][ord_y[perm[1]][pos_1]].second;
        int pos_2 = n / 3 - 1, cnt_2 = 0;
        while (pos_2 >= 0) {
          if (a[perm[2]][ord_y[perm[2]][pos_2]].first < prev_x) cnt_2++;
          if (cnt_2 == mid) break;
          pos_2--;
        }
        if (cnt_2 != mid) continue;
        int top_y = a[perm[2]][ord_y[perm[2]][pos_2]].second;
        if (bottom_y < top_y) possible = true;
      } while (next_permutation(perm, perm + 3));
      if (possible)
        lo = mid;
      else
        hi = mid;
    }
    sol = max(sol, lo);
    for (int i : {0, 1, 2}) {
      for (int j = 0; j < n / 3; j++) swap(a[i][j].first, a[i][j].second);
      swap(ord_x[i], ord_y[i]);
    }
  }
  sol *= 3;
  cout << sol << '\n';
  return 0;
}
