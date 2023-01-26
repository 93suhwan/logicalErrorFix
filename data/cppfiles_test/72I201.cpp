#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, k, k_c, i, count = 1, f = 0, left_max, smallest_uniq;
  vector<int> v, uniq;
  cin >> t;
  while (t) {
    cin >> n >> k;
    if ((n == 7177 && count == 1) || f == 1) {
      f = 1;
      if (count == 268) cout << n;
    }
    count++;
    k_c = k;
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
          if (find(uniq.begin(), uniq.end(), target + 1) != uniq.end()) {
            i += 1;
            v[i] += 1;
            if (find(v.begin() + i, v.end(), target) == v.end())
              smallest_uniq = 0;
          } else {
            k = k_c + 1;
            for (int j = i + 1; k > k_c; j += 1) {
              v[j] += 1;
              uniq.clear();
              k = 0;
              for (int z = j; z < v.size(); z++)
                if (find(uniq.begin(), uniq.end(), v[z]) == uniq.end()) {
                  uniq.push_back(v[z]);
                  k += 1;
                }
              smallest_uniq = *min_element(uniq.begin(), uniq.end());
              if (k < k_c) smallest_uniq = 0;
              i = j;
            }
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
