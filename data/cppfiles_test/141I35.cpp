#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, j, k;
  long long int a, s, d;
  vector<int> v1;
  vector<int> v2;
  vector<int> v3;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> a >> s;
    string c = to_string(a);
    int size1 = c.size();
    c = to_string(s);
    int size2 = c.size();
    for (j = 0; j < size1; j++) {
      d = a % 10;
      a = a / 10;
      v1.push_back(d);
    }
    for (j = 0; j < size2; j++) {
      d = s % 10;
      s = s / 10;
      v2.push_back(d);
    }
    k = 0;
    j = 0;
    for (; (k < size1) && (j < size2);) {
      if (v2[j] > v1[k]) {
        v3.push_back(v2[j] - v1[k]);
        k++;
        j++;
      }
      if (v2[j] < v1[k]) {
        v3.push_back((v2[j] + 10) - v1[k]);
        k++;
        j += 2;
      }
      if (v2[j] == v1[k]) {
        v3.push_back(0);
        k++;
        j++;
      }
    }
    if (k != size1) cout << "-1";
    if (j != size2) {
      for (; j < size2; j++) v3.push_back(v2[j]);
    }
    if (k == size1) {
      while (v3.back() == 0) v3.pop_back();
      k = (v3.size() - 1);
      while (k != 0) {
        cout << v3[k];
        k--;
      }
    }
    cout << endl;
    v1.clear();
    v2.clear();
    v3.clear();
  }
  return 0;
}
