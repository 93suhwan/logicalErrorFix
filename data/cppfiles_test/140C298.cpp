#include <bits/stdc++.h>
using namespace std;
void init() {
  cin.tie(0);
  cin.sync_with_stdio(0);
}
void zerbooo() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
}
long long a[10000000] = {};
int main() {
  init();
  zerbooo();
  int n;
  cin >> n;
  while (n > 0) {
    long long t;
    cin >> t;
    vector<int> v1;
    for (int i = 0; i <= t; ++i) {
      if (i * i > t)
        break;
      else
        v1.push_back(i);
    }
    for (int i = 0; i * i * i <= t; ++i) {
      if (sqrt(i * i * i) - (int)sqrt(i * i * i) == 0)
        continue;
      else
        v1.push_back(i);
    }
    cout << v1.size() - 1 << "\n";
    --n;
  }
  return 0;
}
