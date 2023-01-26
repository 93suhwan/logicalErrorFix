#include <bits/stdc++.h>
using namespace std;
vector<pair<int, char>> func(vector<int>& A, string& S, int n) {
  if (A.size() == 0) {
    return {};
  }
  vector<pair<int, char>> ans;
  sort(A.begin(), A.end());
  unordered_map<char, int> sum;
  sum['R'] = 0;
  sum['L'] = 0;
  int i = 0;
  int j = 0;
  while (j < n && i < n) {
    char c = S[i];
    while (j < n) {
      if (S[j] == c) {
        j++;
      } else {
        break;
      }
    }
    char x = c == 'R' ? 'R' : 'L';
    char y = x == 'R' ? 'L' : 'R';
    int k = j - 1;
    while (k >= 0 && k >= i) {
      if (sum[x] <= sum[y]) {
        sum[x] += A[k];
        pair<int, char> p = make_pair(A[k], x);
        ans.push_back(p);
      } else {
        int diff = sum[x] - sum[y];
        if (diff > A[k]) {
          sum[y] += A[k];
          pair<int, char> p = make_pair(A[k], y);
          ans.push_back(p);
        } else {
          sum[x] += A[k];
          pair<int, char> p = make_pair(A[k], x);
          ans.push_back(p);
        }
      }
      k--;
    }
    i = j;
  }
  return ans;
}
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  int i = 0;
  while (i < N) {
    cin >> A[i];
    i++;
  }
  string S;
  cin >> S;
  vector<pair<int, char>> ans = func(A, S, N);
  for (auto i : ans) {
    cout << i.first << " " << i.second << endl;
  }
  return 0;
}
