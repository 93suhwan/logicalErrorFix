#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print_arr(T a, T b) {
  for (; a != b; a++) {
    cout << *a << " ";
  }
  cout << "\n";
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int> > a(n + 1, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  vector<int> ans;
  for (int y = 0; y < k; y++) {
    int ball;
    cin >> ball;
    int i = 0, j = ball - 1;
    while (i != n) {
      if (a[i][j] == 1) {
        a[i][j] = 2;
        j++;
      } else if (a[i][j] == 2) {
        i++;
      } else if (a[i][j] == 3) {
        a[i][j] = 2;
        j--;
      }
    }
    ans.push_back(j + 1);
  }
  print_arr((ans).begin(), (ans).end());
  return 0;
}
