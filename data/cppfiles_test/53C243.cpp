#include <bits/stdc++.h>
using namespace std;
ostream& operator<<(ostream& os, pair<int, int> a) {
  return os << a.first << " " << a.second;
}
int x4[] = {0, 1, 0, -1};
int y4[] = {1, 0, -1, 0};
int binary_search(int x, vector<int>& ara) {
  int low = 0;
  int high = ara.size() - 1;
  int mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (ara[mid] == x) {
      return mid;
    } else if (ara[mid] > x) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t;
  cin >> t;
  int n, k;
  while (t--) {
    cin >> n >> k;
    vector<int> ara(n), pos(n);
    for (auto& i : (ara)) {
      cin >> i;
    }
    pos = ara;
    sort(pos.begin(), pos.end());
    for (int i = 0; i < n; ++i) {
      int x = binary_search(ara[i], pos);
      if (x == n - 1) {
        k--;
      } else if (i + 1 < n and x + 1 < n and ara[i + 1] != pos[x + 1]) {
        k--;
      } else if (i == n - 1) {
        k--;
      }
    }
    k >= 0 ? cout << "YES"
                  << "\n"
           : cout << "NO"
                  << "\n";
  }
  return 0;
}
