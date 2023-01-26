#include <bits/stdc++.h>
using namespace std;
int fun(vector<int> arr1, vector<int> arr2, int n1, int n2) {
  set<int> s;
  for (int i = 0; i < n1; i++) s.insert(arr1[i]);
  for (int i = 0; i < n2; i++) s.insert(arr2[i]);
  return s.size();
}
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int a;
    cin >> a;
    int arr[a][5];
    std::vector<int> v1(a), v2(a), v3(a), v4(a), v5(a);
    int t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < 5; j++) cin >> arr[i][j];
    }
    for (int i = 0; i < a; i++) {
      if (arr[i][0] == 1) {
        v1[t1] = i;
        t1++;
      }
    }
    for (int i = 0; i < a; i++) {
      if (arr[i][1] == 1) {
        v2[t2] = i;
        t2++;
      }
    }
    for (int i = 0; i < a; i++) {
      if (arr[i][2] == 1) {
        v3[t3] = i;
        t3++;
      }
    }
    for (int i = 0; i < a; i++) {
      if (arr[i][3] == 1) {
        v4[t4] = i;
        t4++;
      }
    }
    for (int i = 0; i < a; i++) {
      if (arr[i][4] == 1) {
        v5[t5] = i;
        t5++;
      }
    }
    if (t1 >= a / 2) {
      if (t2 >= a / 2) {
        int temp = fun(v1, v2, t1, t2);
        if (temp == a) {
          cout << "YES" << endl;
          continue;
        }
      }
      if (t3 >= a / 2) {
        if (fun(v1, v3, t1, t3) == a) {
          cout << "YES" << endl;
          continue;
        }
      }
      if (t4 >= a / 2) {
        if (fun(v1, v4, t1, t4) == a) {
          cout << "YES" << endl;
          continue;
        }
      }
      if (t5 >= a / 2) {
        if (fun(v1, v5, t1, t5) == a) {
          cout << "YES" << endl;
          continue;
        }
      }
    }
    if (t2 >= a / 2) {
      if (t3 >= a / 2) {
        if (fun(v2, v3, t2, t3) == a) {
          cout << "YES" << endl;
          continue;
        }
      }
      if (t4 >= a / 2) {
        if (fun(v2, v4, t2, t4) == a) {
          cout << "YES" << endl;
          continue;
        }
      }
      if (t5 >= a / 2) {
        if (fun(v2, v5, t2, t5) == a) {
          cout << "YES" << endl;
          continue;
        }
      }
    }
    if (t3 >= a / 2) {
      if (t4 >= a / 2) {
        if (fun(v3, v4, t3, t4) == a) {
          cout << "YES" << endl;
          continue;
        }
      }
      if (t5 >= a / 2) {
        if (fun(v3, v5, t3, t5) == a) {
          cout << "YES" << endl;
          continue;
        }
      }
    }
    if (t4 >= a / 2) {
      if (t5 >= a / 2) {
        if (fun(v4, v5, t4, t5) == a) {
          cout << "YES" << endl;
          continue;
        }
      }
    }
    cout << "NO" << endl;
  }
}
