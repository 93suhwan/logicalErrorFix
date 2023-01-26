#include <bits/stdc++.h>
using namespace std;
long long mod = 10e9;
long long fun(vector<long long> arr1, vector<long long> arr2, long long n1,
              long long n2) {
  long long i = 0, j = 0, k = 0, count = 0;
  while (i < n1 && j < n2) {
    if (arr1[i] < arr2[j]) {
      count++;
      i++;
      k++;
    } else if (arr2[j] < arr1[i]) {
      count++;
      k++;
      j++;
    } else {
      i++;
      j++;
    }
  }
  cout << count << " ";
  return count;
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a;
    cin >> a;
    long long arr[a][5];
    std::vector<long long> v1(a), v2(a), v3(a), v4(a), v5(a);
    long long t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;
    for (long long i = 0; i < a; i++) {
      for (long long j = 0; j < 5; j++) cin >> arr[i][j];
    }
    for (long long i = 0; i < a; i++) {
      if (arr[i][0] == 1) {
        v1[t1] = i;
        t1++;
      }
    }
    for (long long i = 0; i < a; i++) {
      if (arr[i][1] == 1) {
        v2[t] = i;
        t2++;
      }
    }
    for (long long i = 0; i < a; i++) {
      if (arr[i][2] == 1) {
        v3[t] = i;
        t3++;
      }
    }
    for (long long i = 0; i < a; i++) {
      if (arr[i][3] == 1) {
        v4[t] = i;
        cout << v4[t] << " ";
        t4++;
      }
    }
    for (long long i = 0; i < a; i++) {
      if (arr[i][4] == 1) {
        v5[t] = i;
        t5++;
      }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    sort(v3.begin(), v3.end());
    sort(v4.begin(), v4.end());
    sort(v5.begin(), v5.end());
    cout << endl;
    cout << t1 << " " << t2 << " " << t3 << " " << t4 << " " << t5 << " "
         << a / 2 << endl;
    if (t1 >= a / 2) {
      if (t2 >= a / 2) {
        long long temp = fun(v1, v2, t1, t2);
        if (temp >= a / 2) {
          cout << "YES" << endl;
          break;
        }
      }
      if (t3 >= a / 2) {
        if (fun(v1, v3, t1, t3) >= a / 2) {
          cout << "YES" << endl;
          break;
        }
      }
      if (t4 >= a / 2) {
        if (fun(v1, v4, t1, t4) >= a / 2) {
          cout << "YES" << endl;
          break;
        }
      }
      if (t5 >= a / 2) {
        if (fun(v1, v5, t1, t5) >= a / 2) {
          cout << "YES" << endl;
          break;
        }
      }
    }
    if (t2 >= a / 2) {
      if (t3 >= a / 2) {
        if (fun(v2, v3, t2, t3) >= a / 2) {
          cout << "YES" << endl;
          break;
        }
      }
      if (t4 >= a / 2) {
        if (fun(v2, v4, t2, t4) >= a / 2) {
          cout << "YES" << endl;
          break;
        }
      }
      if (t5 >= a / 2) {
        if (fun(v2, v5, t2, t5) >= a / 2) {
          cout << "YES" << endl;
          break;
        }
      }
    }
    if (t3 >= a / 2) {
      if (t4 >= a / 2) {
        if (fun(v3, v4, t3, t4) >= a / 2) {
          cout << "YES" << endl;
          break;
        }
      }
      if (t5 >= a / 2) {
        if (fun(v3, v5, t3, t5) >= a / 2) {
          cout << "YES" << endl;
          break;
        }
      }
    }
    if (t4 >= a / 2) {
      if (t5 >= a / 2) {
        if (fun(v4, v5, t4, t5) >= a / 2) {
          cout << "YES" << endl;
          break;
        }
      }
    }
    cout << "NO" << endl;
  }
}
