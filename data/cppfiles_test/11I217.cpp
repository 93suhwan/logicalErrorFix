#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int MAX_CHAR = 256;
unordered_map<string, vector<int>> mp;
bool compa(string first, string second) {
  if ((first.size() - mp[first][0]) == (second.size() - mp[second][0])) {
    return mp[first][0] > mp[second][0];
  }
  return (first.size() - mp[first][0]) < (second.size() - mp[second][0]);
}
bool compb(string first, string second) {
  if ((first.size() - mp[first][1]) == (second.size() - mp[second][1])) {
    return mp[first][1] > mp[second][1];
  }
  return (first.size() - mp[first][1]) < (second.size() - mp[second][1]);
}
bool compc(string first, string second) {
  if ((first.size() - mp[first][2]) == (second.size() - mp[second][2])) {
    return mp[first][2] > mp[second][2];
  }
  return (first.size() - mp[first][2]) < (second.size() - mp[second][2]);
}
bool compd(string first, string second) {
  if ((first.size() - mp[first][3]) == (second.size() - mp[second][3])) {
    return mp[first][3] > mp[second][3];
  }
  return (first.size() - mp[first][3]) < (second.size() - mp[second][3]);
}
bool compe(string first, string second) {
  if ((first.size() - mp[first][4]) == (second.size() - mp[second][4])) {
    return mp[first][4] > mp[second][4];
  }
  return (first.size() - mp[first][4]) < (second.size() - mp[second][4]);
}
int get_result(vector<string> &arr, char ch, int n) {
  if (ch == 'a') {
    sort(arr.begin(), arr.end(), compa);
  }
  if (ch == 'b') {
    sort(arr.begin(), arr.end(), compb);
  }
  if (ch == 'c') {
    sort(arr.begin(), arr.end(), compc);
  }
  if (ch == 'd') {
    sort(arr.begin(), arr.end(), compd);
  }
  if (ch == 'e') {
    sort(arr.begin(), arr.end(), compe);
  }
  int count = 0;
  int char_val = 0, sum = 0;
  int i = 0;
  while (char_val >= sum and i < n) {
    int point = (int)ch - 'a';
    sum += arr[i].size() - mp[arr[i]][point];
    char_val += mp[arr[i]][point];
    if (char_val > sum) {
      count++;
    } else {
      break;
    }
    i++;
  }
  return count;
}
void solve() {
  int n;
  cin >> n;
  vector<string> arr(n);
  mp.clear();
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    for (auto j : arr[i]) {
      int temp = (int)(j - 'a');
      if (temp == 0) {
        a++;
      }
      if (temp == 1) {
        b++;
      }
      if (temp == 2) {
        c++;
      }
      if (temp == 3) {
        d++;
      }
      if (temp == 4) {
        e++;
      }
    }
    mp[arr[i]] = {a, b, c, d, e};
  }
  int result = INT_MIN;
  for (int i = 0; i < 5; i++) {
    char temp = 'a' + i;
    result = max(result, get_result(arr, temp, n));
  }
  cout << result << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int cases;
  cin >> cases;
  while (cases--) {
    solve();
  }
  return 0;
}
