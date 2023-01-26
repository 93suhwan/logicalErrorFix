#include <bits/stdc++.h>
using namespace std;
void func2(string s, string t, long long cnt1, long long *cnt3, long long *cnt);
void func(string s) {
  bool a[30];
  long long cnt[30];
  memset(cnt, 0, sizeof(cnt));
  memset(a, false, sizeof(a));
  long long cnt1 = 0;
  for (auto &i : s) {
    if (!a[i - 'a']) cnt1++;
    a[i - 'a'] = true;
    cnt[i - 'a']++;
  }
  long long diff[30];
  long long cnt3[30];
  memset(diff, 0, sizeof(diff));
  memset(cnt3, 0, sizeof(cnt3));
  long long dm = 0;
  for (long long i = 0; i < s.size(); i++) {
    cnt3[s[i] - 'a']++;
    long long temp = cnt3[s[i] - 'a'];
    long long temp2 = cnt[s[i] - 'a'];
    long long temp3 = temp - 1;
    if (temp3 != 0) {
      if (temp2 % temp3 == 0) {
        long long val = temp2 / temp3;
        if (0 < val && val <= cnt1) diff[val]--;
        if (0 < val && val <= cnt1 && diff[val] == 0) dm--;
      }
      if (temp2 % temp == 0) {
        long long val = temp2 / temp;
        if (0 < val && val <= cnt1 && diff[val] == 0) dm++;
        if (0 < val && val <= cnt1) diff[val]++;
      }
    } else {
      if (temp2 % temp == 0) {
        long long val = temp2 / temp;
        if (0 < val && val <= cnt1 && diff[val] == 0) dm++;
        if (0 < val && val <= cnt1) diff[val]++;
      }
    }
    if (dm == cnt1) {
      func2(s, s.substr(0, i + 1), cnt1, cnt3, cnt);
      return;
    }
  }
  cout << "-1" << endl;
  return;
}
void func2(string s, string t, long long cnt1, long long *cnt3,
           long long *cnt) {
  char arr[30];
  bool valid[t.size()];
  memset(arr, 0, sizeof(arr));
  memset(valid, true, sizeof(valid));
  for (long long i = 0; i < 30; i++) {
    if (cnt3[i]) {
      char temp = (i + 97);
      arr[cnt[i] / cnt3[i]] = temp;
    }
  }
  string ans = t;
  long long cnt4 = 0;
  while (cnt4 != cnt1) {
    cnt4++;
    for (long long i = 0; i < t.size(); i++) {
      if (t[i] == arr[cnt4]) valid[i] = false;
    }
    for (long long i = 0; i < t.size(); i++) {
      if (valid[i]) ans.push_back(t[i]);
    }
  }
  string order = "";
  for (long long i = 1; i <= cnt1; i++) order.push_back(arr[i]);
  if (s == ans) {
    cout << t << " " << order << endl;
  } else {
    cout << "-1" << endl;
  }
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    func(s);
  }
}
