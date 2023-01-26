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
    vector<pair<long long, long long>> vec;
    for (i = 1; i <= b; i++) {
      long long x = arr[i][1];
      long long y = arr[i][2];
      long long z = arr[i][3];
      long long p = arr[i][4];
      long long q = arr[i][5];
      ms1.erase(ms1.find(x));
      ms2.erase(ms2.find(y));
      ms3.erase(ms3.find(z));
      ms4.erase(ms4.find(p));
      ms5.erase(ms5.find(q));
      if (ms1.size() == 0 || x < *ms1.begin()) {
        cnt[i]++;
      }
      if (ms2.size() == 0 || y < *ms2.begin()) {
        cnt[i]++;
      }
      if (ms3.size() == 0 || z < *ms3.begin()) {
        cnt[i]++;
      }
      if (ms4.size() == 0 || p < *ms4.begin()) {
        cnt[i]++;
      }
      if (ms5.size() == 0 || q < *ms5.begin()) {
        cnt[i]++;
      }
      vec.push_back({cnt[i], i});
      mp[cnt[i]]++;
      ms1.insert(x);
      ms2.insert(y);
      ms3.insert(z);
      ms4.insert(p);
      ms5.insert(q);
    }
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    if (mp[vec[0].first] == 1) {
      cout << vec[0].second << endl;
    } else {
      cout << -1 << endl;
    }
  }
}
