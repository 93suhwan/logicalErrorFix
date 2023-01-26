#include <bits/stdc++.h>
using namespace std;
bool sortcol(const vector<long int>& v1, const vector<long int>& v2) {
  return v1[0] < v2[0];
}
int main() {
  long int test;
  cin >> test;
  while (test > 0) {
    long int s;
    cin >> s;
    vector<long int> z, o;
    vector<vector<long int>> zv, ov;
    int arr[s], count = 0;
    string s1;
    for (long int i = 0; i < s; i++) cin >> arr[i];
    cin >> s1;
    vector<long int> d;
    for (long int i = 0; i < s; i++) {
      d.clear();
      if (s1[i] == '0') {
        d.push_back(arr[i]);
        d.push_back(i);
        zv.push_back(d);
        count++;
      } else {
        d.push_back(arr[i]);
        d.push_back(i);
        ov.push_back(d);
      }
    }
    if (count != 0 && s != 1 && s != count) {
      sort(arr, arr + s);
      for (long int i = 0; i < s; i++) {
        if (i < count)
          z.push_back(arr[i]);
        else
          o.push_back(arr[i]);
      }
      sort(zv.begin(), zv.end(), sortcol);
      for (long int i = 0; i < z.size(); i++) {
        arr[zv[i][1]] = z[i];
      }
      sort(ov.begin(), ov.end(), sortcol);
      for (long int i = 0; i < o.size(); i++) {
        arr[ov[i][1]] = o[i];
      }
    }
    for (long int i = 0; i < s; i++) cout << arr[i] << " ";
    cout << "\n";
    test--;
  }
  return 0;
}
