#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
const long long N = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
long long _mergeSort(vector<long long>& arr, vector<long long>& temp,
                     long long left, long long right);
long long merge(vector<long long>& arr, vector<long long>& temp, long long left,
                long long mid, long long right);
long long mergeSort(vector<long long> arr) {
  vector<long long> temp(((long long)arr.size()));
  return _mergeSort(arr, temp, 0, ((long long)arr.size()) - 1);
}
long long _mergeSort(vector<long long>& arr, vector<long long>& temp,
                     long long left, long long right) {
  long long mid, inv_count = 0;
  if (right > left) {
    mid = (right + left) / 2;
    inv_count += _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid + 1, right);
    inv_count += merge(arr, temp, left, mid + 1, right);
  }
  return inv_count;
}
long long merge(vector<long long>& arr, vector<long long>& temp, long long left,
                long long mid, long long right) {
  long long i, j, k;
  long long inv_count = 0;
  i = left;
  j = mid;
  k = left;
  while ((i <= mid - 1) && (j <= right)) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
      inv_count = inv_count + (mid - i);
    }
  }
  while (i <= mid - 1) temp[k++] = arr[i++];
  while (j <= right) temp[k++] = arr[j++];
  for (i = left; i <= right; i++) arr[i] = temp[i];
  return inv_count;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n), b(n);
  map<long long, long long> pos;
  map<long long, long long> f;
  long long flag = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
    b[i] = a[i];
    f[a[i]]++;
    if (f[a[i]] == 2) {
      flag = 1;
    }
  }
  long long x = mergeSort(a);
  if (x % 2 == 0) {
    cout << "YES";
  } else if (flag == 1) {
    cout << "YES";
  } else if (x % 2 == 1) {
    cout << "NO";
  }
  return;
  sort(b.begin(), b.end());
  for (long long i = 0; i < n - 3; i++) {
    if (i < n - 3) {
      if (a[i] == b[i]) {
        continue;
      } else {
        long long p = pos[b[i]];
        if (p == i + 1) {
          long long temp1 = a[i];
          long long temp2 = a[i + 1];
          long long temp3 = a[i + 2];
          pos[a[i]] = i + 2;
          pos[a[i + 1]] = i;
          pos[a[i + 2]] = i + 1;
          a[i] = temp2;
          a[i + 1] = temp3;
          a[i + 2] = temp1;
        } else {
          long long temp1 = a[i];
          long long temp2 = a[i + 1];
          pos[a[i]] = i + 1;
          pos[b[i]] = i;
          pos[a[i + 1]] = p;
          a[i] = b[i];
          a[i + 1] = temp1;
          a[p] = temp2;
        }
      }
    }
  }
  long long r = n % 3;
  if (r == 1) {
    cout << "YES";
  } else if (r == 2) {
    if (a[n - 2] <= a[n - 1]) {
      cout << "YES";
    } else {
      cout << "NO";
    }
  } else {
    long long n1 = a[n - 3];
    long long n2 = a[n - 2];
    long long n3 = a[n - 1];
    if (n1 <= n2 && n2 <= n3) {
      cout << "YES";
    } else if (n2 >= n1 && n2 >= n3 && n2 >= n1) {
      cout << "YES";
    } else if (n1 >= n2 && n1 >= n3 && n3 >= n2) {
      cout << "YES";
    } else {
      cout << "NO";
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long t = 0;
  long long test_cases = 1;
  cin >> test_cases;
  while (t++ < test_cases) {
    solve();
    cout << "\n";
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << "\n";
  return 0;
}
