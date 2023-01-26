#include <bits/stdc++.h>
using namespace std;
void files() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
  return;
}
double eps = 1e-6;
double pi = acos(-1);
const int MXN = 1e5 + 5;
const long long MOD = 1e9 + 7;
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1, -1, 1, -1, 0, 0, -1, 1};
int dx4[] = {1, -1, 0, 0};
int dy4[] = {0, 0, 1, -1};
void sol() {
  int n;
  cin >> n;
  int keep[n];
  vector<int> red, blue;
  for (int ii = 0; ii < n; ++ii) cin >> keep[ii];
  string s;
  cin >> s;
  for (int ii = 0; ii < n; ++ii) {
    if (s[ii] == 'B')
      blue.push_back(keep[ii]);
    else
      red.push_back(keep[ii]);
  }
  sort(red.rbegin(), red.rend());
  sort(blue.rbegin(), blue.rend());
  int up = n;
  for (int ii = 0; ii < (int)red.size(); ++ii) {
    if (red[ii] > up) {
      printf("No\n");
      return;
    }
    --up;
  }
  for (int ii = 0; ii < (int)blue.size(); ++ii) {
    if (blue[ii] < up) {
      printf("No\n");
      return;
    }
    --up;
  }
  if (up != 0) {
    printf("No\n");
    return;
  }
  printf("Yes\n");
}
int main() {
  int tcase = 1;
  scanf("%d", &tcase);
  cout << fixed << setprecision(6);
  while (tcase--) {
    sol();
  }
}
