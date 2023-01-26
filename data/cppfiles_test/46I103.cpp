#include <bits/stdc++.h>
using namespace std;
typedef struct triplet {
  int parent;
  int dist;
} tr;
bool cmp(pair<long long int, long long int> p1,
         pair<long long int, long long int> p2) {
  return p1.first < p2.first;
}
int Sol(vector<int> arr, int mx_ind, int n) {
  if (arr[mx_ind] == arr[n - 1]) return 0;
  int res = 1;
  int low = arr[n - 1];
  for (int i = n - 2; i > mx_ind; i--) {
    if (arr[i] > low) {
      res++;
      low = arr[i];
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int mx = -1, mx_ind;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      if (arr[i] > mx) {
        mx = arr[i];
        mx_ind = i;
      }
    }
    cout << Sol(arr, mx_ind, n) << '\n';
  }
}
