#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using llf = long double;
using pi = pair<int, int>;
const int MAXN = 2100005;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v;
  v.push_back(1);
  while (v.back() * k < n) {
    int x = v.back() * k;
    v.push_back(x);
  }
  cout << ((int)(v).size()) << endl;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int x = ((int)(v).size()) - 1; x >= 0; x--) {
        if (i / v[x] != j / v[x]) {
          printf("%d ", x + 1);
          break;
        }
      }
    }
  }
}
