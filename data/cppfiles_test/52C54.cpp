#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t NUM;
  cin >> NUM;
  vector<double> ans(NUM);
  for (int64_t i = 0; i < NUM; i++) {
    int64_t n;
    cin >> n;
    int64_t sum = 0;
    int64_t max_el = std::numeric_limits<int64_t>::min();
    for (int64_t i = 0; i < n; i++) {
      int64_t temp;
      cin >> temp;
      sum += temp;
      if (temp > max_el) {
        max_el = temp;
      }
    }
    cout << fixed << setprecision(9)
         << max_el + ((double)sum - max_el) / (n - 1) << endl;
  }
  return 0;
}
