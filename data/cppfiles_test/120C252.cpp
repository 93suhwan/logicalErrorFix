#include <bits/stdc++.h>
using namespace std;
int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) cout << arr[i] << " ";
  cout << endl;
}
int minimum(int arr[], int n) {
  int min = arr[0];
  for (int i = 1; i < n; i++)
    if (arr[i] < min) min = arr[i];
  return min;
}
int maximum(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++)
    if (arr[i] > max) max = arr[i];
  return max;
}
int maxSubarraySum(int arr[], int n) {
  int ms = INT_MIN;
  int me = 0;
  int start = 0;
  int end = 0;
  int s = 0;
  for (int i = 0; i < n; i++) {
    me += arr[i];
    if (me > ms) {
      ms = me;
      start = s;
      end = i;
    }
    if (me < 0) {
      me = 0;
      s = i + 1;
    }
  }
  return ms;
}
bool sortcol(const vector<int>& v1, const vector<int>& v2) {
  return v1[0] < v2[0];
}
vector<vector<int>> dp(200001, vector<int>(32));
void start() {
  for (int i = 1; i < 200001; i++) {
    dp[i] = dp[i - 1];
    string x = std::bitset<32>(i).to_string();
    reverse(x.begin(), x.end());
    for (int j = 0; j < x.size(); j++) {
      if (x[j] == '1') dp[i][j]++;
    }
  }
}
int main() {
  start();
  int t = 1;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    int n = r - l + 1;
    int tog = 2;
    for (; tog < l; tog *= 2)
      ;
    int frog = 1;
    for (; frog <= r; frog *= 2)
      ;
    int first = tog - l;
    int last = r - frog / 2 + 1;
    int var = frog / 4;
    int miniMUM = INT_MAX;
    for (int i = 0; i < 32; i++) {
      int VOF = dp[r][i] - dp[l - 1][i];
      int zero = (r - l + 1) - VOF;
      miniMUM = min(miniMUM, zero);
    }
    cout << miniMUM << endl;
  }
  return 0;
}
