#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<vector<int>> v;
    stack<vector<int>> second;
    for (long long i = 0; i < n; i++) {
      vector<int> v1(5, 0);
      for (int j = 0; j < 5; j++) {
        cin >> v1[j];
      }
      v.push_back(v1);
      second.push(v1);
    }
    if (n <= 1) {
      cout << n << endl;
      continue;
    }
    while (second.size() != 1) {
      vector<int> v1 = second.top();
      second.pop();
      vector<int> v2 = second.top();
      second.pop();
      int cv1 = 0, cv2 = 0;
      for (int i = 0; i < 5; i++) {
        if (v1[i] > v2[i]) {
          cv2++;
        } else if (v1[i] < v2[i]) {
          cv1++;
        }
      }
      if (cv1 > cv2) {
        second.push(v1);
      } else {
        second.push(v2);
      }
    }
    bool chck = true;
    vector<int> rem = second.top();
    for (int i = 0; i < n; i++) {
      int c = 0;
      for (int j = 0; j < 5; j++) {
        if (rem[j] <= v[i][j]) {
          c++;
        }
      }
      if (c < 3) {
        chck = false;
        break;
      }
    }
    if (chck) {
      cout << (find(v.begin(), v.end(), rem) - v.begin()) + 1 << endl;
    } else {
      cout << -1 << endl;
    }
  }
}
