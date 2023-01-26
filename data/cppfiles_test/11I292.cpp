#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int q = 0; q < t; q++) {
    int n;
    cin >> n;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
    vector<int> v5;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      int count1 = 0;
      int count2 = 0;
      int count3 = 0;
      int count4 = 0;
      int count5 = 0;
      for (int j = 0; j < s.size(); j++) {
        if (s[j] == 'a') {
          count1++;
        }
        if (s[j] == 'b') {
          count2++;
        }
        if (s[j] == 'c') {
          count3++;
        }
        if (s[j] == 'd') {
          count4++;
        }
        if (s[j] == 'e') {
          count5++;
        }
      }
      v1.push_back(2 * count1 - s.size());
      v2.push_back(2 * count2 - s.size());
      v3.push_back(2 * count3 - s.size());
      v4.push_back(2 * count4 - s.size());
      v5.push_back(2 * count5 - s.size());
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    sort(v3.begin(), v3.end());
    sort(v4.begin(), v4.end());
    sort(v5.begin(), v5.end());
    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());
    reverse(v3.begin(), v3.end());
    reverse(v4.begin(), v4.end());
    reverse(v5.begin(), v5.end());
    int f1[n];
    int f2[n];
    int f3[n];
    int f4[n];
    int f5[n];
    for (int i = 0; i < n; i++) {
      f1[i] = 0;
      f2[i] = 0;
      f3[i] = 0;
      f4[i] = 0;
      f5[i] = 0;
    }
    f1[0] = v1[0];
    f2[0] = v2[0];
    f3[0] = v3[0];
    f4[0] = v4[0];
    f5[0] = v5[0];
    for (int i = 1; i < n; i++) {
      f1[i] = f1[i - 1] + v1[i];
    }
    for (int i = 1; i < n; i++) {
      f2[i] = f2[i - 1] + v2[i];
    }
    for (int i = 1; i < n; i++) {
      f3[i] = f3[i - 1] + v3[i];
    }
    for (int i = 1; i < n; i++) {
      f4[i] = f4[i - 1] + v4[i];
    }
    for (int i = 1; i < n; i++) {
      f5[i] = f5[i - 1] + v5[i];
    }
    int ans1 = 0;
    int ans2 = 0;
    int ans3 = 0;
    int ans4 = 0;
    int ans5 = 0;
    if (v1[0] > 0) {
      for (int i = 0; i < n; i++) {
        if (f1[i] < 0) {
          ans1 = i;
          break;
        }
      }
      if (f1[n - 1] >= 0) {
        ans1 = n;
      }
    }
    if (v2[0] > 0) {
      for (int i = 0; i < n; i++) {
        if (f2[i] < 0) {
          ans2 = i;
          break;
        }
      }
      if (f2[n - 1] >= 0) {
        ans2 = n;
      }
    }
    if (v3[0] > 0) {
      for (int i = 0; i < n; i++) {
        if (f3[i] < 0) {
          ans3 = i;
          break;
        }
      }
      if (f3[n - 1] >= 0) {
        ans3 = n;
      }
    }
    if (v4[0] > 0) {
      for (int i = 0; i < n; i++) {
        if (f4[i] < 0) {
          ans4 = i;
          break;
        }
      }
      if (f4[n - 1] >= 0) {
        ans4 = n;
      }
    }
    if (v5[0] > 0) {
      for (int i = 0; i < n; i++) {
        if (f5[i] < 0) {
          ans5 = i;
          break;
        }
      }
      if (f5[n - 1] >= 0) {
        ans5 = n;
      }
    }
    vector<int> ans;
    ans.push_back(ans1);
    ans.push_back(ans2);
    ans.push_back(ans3);
    ans.push_back(ans4);
    ans.push_back(ans5);
    int max = 0;
    for (int i = 0; i < 5; i++) {
      if (max < ans[i]) {
        max = ans[i];
      }
    }
    cout << max << endl;
  }
}
