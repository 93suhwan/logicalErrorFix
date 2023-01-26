#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> dish(n), Ans(n);
    vector<int> M(n, m);
    long long A = 0, B = 0;
    for (int i = 0; i < n; i++) {
      cin >> dish[i].first >> dish[i].second;
      if (dish[i].first < M[i]) {
        dish[i].second -= M[i] - dish[i].first;
        Ans[i].second += M[i] - dish[i].first;
        M[i] = dish[i].first;
      }
      if (dish[i].second < M[i]) {
        dish[i].first -= M[i] - dish[i].second;
        Ans[i].first += M[i] - dish[i].second;
        M[i] = dish[i].second;
      }
      A += dish[i].first, B += dish[i].second;
    }
    int i = 0;
    while (i < n) {
      if (A < B) {
        int tmp = min(B - A, (long long)M[i]);
        dish[i].second -= tmp;
        Ans[i].second += tmp;
        B -= tmp;
        M[i] -= tmp;
      } else if (A == B) {
        int half = M[i] / 2;
        dish[i].first -= half, dish[i].second -= M[i] - half;
        Ans[i].first += half, Ans[i].second += M[i] - half;
        A -= half, B -= M[i] - half;
        M[i] = 0;
      } else {
        int tmp = min(A - B, (long long)M[i]);
        dish[i].first -= tmp;
        Ans[i].first += tmp;
        A -= tmp;
        M[i] -= tmp;
      }
      if (M[i] == 0) i++;
    }
    cout << abs(A - B) << '\n';
    for (auto p : Ans) cout << p.first << ' ' << p.second << '\n';
  }
  return 0;
}
