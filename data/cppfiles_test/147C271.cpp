#include <bits/stdc++.h>
const int64_t M = 1e9 + 7;
const int64_t INF = 1e6 + 5;
const int MAXN = 2e5 + 5;
using namespace std;
int lpartition(int arr[], int l, int h) {
  int i, j, pivot, temp;
  pivot = arr[h];
  i = l - 1;
  for (j = l; j <= h - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  temp = arr[i + 1];
  arr[i + 1] = arr[h];
  arr[h] = temp;
  return (i + 1);
}
bool sortbydec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
bool subsetsum(long long int sum, long long int n, long long int arr[]) {
  bool t[n + 1][sum + 1];
  long long int i, j;
  for (i = 1; i < sum + 1; i++) {
    t[0][i] = false;
  }
  for (i = 0; i < n + 1; i++) {
    t[i][0] = true;
  }
  for (i = 1; i < n + 1; i++) {
    for (j = 1; j < sum + 1; j++) {
      if (arr[i - 1] <= j)
        t[i][j] = (t[i - 1][j - arr[i - 1]]) || (t[i - 1][j]);
      else
        t[i][j] = t[i - 1][j];
    }
  }
  return t[n][sum];
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long int count = 0;
    char ch;
    long long int i;
    for (i = 0; i < s.length(); i++) {
      if (s[i] == 'N') count++;
    }
    if (count == 1)
      cout << "NO"
           << "\n";
    else
      cout << "YES"
           << "\n";
  }
  return 0;
}
