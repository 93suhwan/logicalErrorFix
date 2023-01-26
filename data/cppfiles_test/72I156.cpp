#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, k, i, left_max, smallest_uniq;
  vector<int> v, uniq;
  cin >> t;
  while (t) {
    cin >> n >> k;
    v.clear();
    uniq.clear();
    while (n > 0) {
      v.push_back(n % 10);
      n = n / 10;
    }
    i = v.size() - 1;
    for (; - 1 < i && k > 0; i--) {
      if (find(uniq.begin(), uniq.end(), v[i]) == uniq.end()) {
        uniq.push_back(v[i]);
        k -= 1;
      }
    }
    if (i > -1) {
      left_max = *max_element(v.begin(), v.begin() + i);
      smallest_uniq = *min_element(uniq.begin(), uniq.end());
    }
    int smallest_high = 10, flag = 0, target;
    while (i > -1) {
      if (flag)
        v[i] = smallest_uniq;
      else if (find(uniq.begin(), uniq.end(), v[i]) == uniq.end()) {
        for (int j = 0; j < uniq.size(); j++) {
          if (v[i] < uniq[j] && uniq[j] < smallest_high) {
            smallest_high = uniq[j];
            flag = 1;
          }
        }
        if (flag == 0) {
          target = v[i + 1];
          for (int j = i + 1; j < v.size(); j += 1)
            if (v[j] == target) {
              v[j] += 1;
              i = j;
            }
          flag = 1;
        } else
          v[i] = smallest_high;
      }
      i -= 1;
    }
    for (i = v.size() - 1; - 1 < i; i--) cout << v[i];
    cout << endl;
    t--;
  }
  return 0;
}
