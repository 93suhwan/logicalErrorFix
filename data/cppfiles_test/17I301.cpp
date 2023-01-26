#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d, e, i, j;
  cin >> a;
  while (a--) {
    cin >> b;
    long long arr[b + 10][6];
    long long cnt[b + 10];
    multiset<long long> ms1;
    multiset<long long> ms2;
    multiset<long long> ms3;
    multiset<long long> ms4;
    multiset<long long> ms5;
    memset(cnt, 0, sizeof cnt);
    for (i = 1; i <= b; i++) {
      cin >> arr[i][1] >> arr[i][2] >> arr[i][3] >> arr[i][4] >> arr[i][5];
      ms1.insert(arr[i][1]);
      ms2.insert(arr[i][2]);
      ms3.insert(arr[i][3]);
      ms4.insert(arr[i][4]);
      ms5.insert(arr[i][5]);
    }
    map<long long, long long> mp;
    vector<long long> vec;
    long long ok = 0;
    for (i = 1; i <= b; i++) {
      long long x = arr[i][1];
      long long y = arr[i][2];
      long long z = arr[i][3];
      long long p = arr[i][4];
      long long q = arr[i][5];
      if (x <= *ms1.begin()) {
        cnt[i]++;
      }
      if (y <= *ms2.begin()) {
        cnt[i]++;
      }
      if (z <= *ms3.begin()) {
        cnt[i]++;
      }
      if (p <= *ms4.begin()) {
        cnt[i]++;
      }
      if (q <= *ms5.begin()) {
        cnt[i]++;
      }
      ok = max(ok, cnt[i]);
    }
    for (i = 1; i <= b; i++) {
      if (ok == cnt[i]) {
        vec.push_back(i);
      }
    }
    long long index = -1;
    for (j = 0; j < vec.size(); j++) {
      long long m = vec[j];
      bool chk = true;
      for (i = 1; i <= b; i++) {
        long long oc = 0;
        if (arr[m][1] > arr[i][1]) {
          oc++;
        }
        if (arr[m][2] > arr[i][2]) {
          oc++;
        }
        if (arr[m][3] > arr[i][3]) {
          oc++;
        }
        if (arr[m][4] > arr[i][4]) {
          oc++;
        }
        if (arr[m][5] > arr[i][5]) {
          oc++;
        }
        if (oc >= 3) {
          chk = false;
        }
      }
      if (chk) {
        index = m;
      }
    }
    cout << index << endl;
  }
}
