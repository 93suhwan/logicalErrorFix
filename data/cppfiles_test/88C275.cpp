#include <bits/stdc++.h>
using namespace std;
long long m;
bool func(pair<long long, long long> &a, pair<long long, long long> &b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first < b.first;
}
long long mergesort(long long arr[], long long st, long long end) {
  if (end - st == 1) {
    if (arr[st] < arr[end]) {
      long long temp = arr[st];
      arr[st] = arr[end];
      arr[end] = temp;
      return 1;
    }
    return 0;
  } else if (end - st == 0) {
    return 0;
  }
  long long mid = (st + end) / 2;
  long long inv = mergesort(arr, st, mid) + mergesort(arr, mid + 1, end);
  long long temp[end - st + 1];
  long long ptr = 0;
  long long a = st, b = mid + 1;
  while (a <= mid || b <= end) {
    if (a == mid + 1) {
      temp[ptr] = arr[b];
      b++;
      ptr++;
      continue;
    }
    if (b == end + 1) {
      temp[ptr] = arr[a];
      a++;
      ptr++;
      continue;
    } else if (arr[b] < arr[a]) {
      temp[ptr] = arr[a];
      a++;
      ptr++;
    } else {
      temp[ptr] = arr[b];
      inv += (mid - a + 1);
      b++;
      ptr++;
    }
  }
  for (long long i = st; i <= end; i++) {
    arr[i] = temp[i - st];
  }
  return inv;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n >> m;
    vector<pair<long long, long long>> v(n * m);
    for (long long i = 0; i < n * m; i++) {
      cin >> v[i].first;
      v[i].second = i;
    }
    sort(v.begin(), v.end(), func);
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      long long temp[m];
      for (long long j = 0; j < m; j++) {
        temp[j] = v[i * m + j].second;
      }
      long long j = 0;
      while (j < m - 1) {
        long long pos1 = j;
        while (j < m - 1 && v[i * m + j].first == v[i * m + j + 1].first) {
          j++;
        }
        long long ks = j;
        while (ks > pos1) {
          long long dc = temp[pos1];
          temp[pos1] = temp[ks];
          temp[ks] = dc;
          ks--;
          pos1++;
        }
        j++;
      }
      ans += mergesort(temp, 0, m - 1);
    }
    cout << ans << "\n";
  }
  return 0;
}
