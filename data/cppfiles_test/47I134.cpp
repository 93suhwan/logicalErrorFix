#include <bits/stdc++.h>
using namespace std;
const int N = 4e6 + 5;
void run_case() {
  int n, p;
  cin >> n >> p;
  vector<int> vec;
  auto ask = [&](int t, int a, int b) {
    cout << (t == 1 ? "and" : "or") << " " << a + 1 << " " << b + 1 << endl;
    int ret;
    cin >> ret;
    return ret;
  };
  auto pre = [&]() {
    int a[3][3];
    int b[3][3];
    int sum = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = i + 1; j < 3; j++) {
        a[i][j] = a[j][i] = ask(1, i, j);
        b[i][j] = b[j][i] = ask(2, i, j);
        sum += a[i][j];
        sum += b[i][j];
      }
    }
    sum /= 2;
    vec.push_back(sum - (a[1][2] + b[1][2]));
    vec.push_back(sum - (a[0][1] + b[0][1]));
    vec.push_back(sum - (a[0][2] + b[0][2]));
  };
  auto get = [&](int idx) {
    int a = ask(1, 0, idx);
    int b = ask(2, 0, idx);
    int ret = a + b - vec[0];
    return ret;
  };
  pre();
  for (int i = 3; i < n; i++) vec.push_back(get(i));
  sort(vec.begin(), vec.end());
  cout << "finish " << vec[p - 1] << endl;
}
int main() {
  int T = 1;
  while (T--) run_case();
}
