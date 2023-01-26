#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    unordered_map<int, vector<int>> umap;
    for (int i = 0; i < N; i++) {
      umap[v[i]].push_back(i);
    }
    vector<int> ans(N);
    int col = 1;
    int mm = 0;
    int nn = 0;
    for (auto i = umap.begin(); i != umap.end(); i++) {
      vector<int> temp = i->second;
      int l = temp.size();
      if (l >= K) {
        mm++;
        int col = 1;
        for (int j = 0; j < K; j++) {
          ans[temp[j]] = col;
          col++;
        }
        for (int j = K; j < l; j++) {
          ans[temp[j]] = 0;
        }
      } else {
        for (int j = 0; j < l; j++) {
          if (col > K) col = 1;
          ans[temp[j]] = col;
          col++;
        }
        nn += l;
      }
    }
    unordered_map<int, int> count;
    for (int i = 0; i < ans.size(); i++) count[ans[i]] = 0;
    for (int i = 0; i < ans.size(); i++) count[ans[i]]++;
    int flag = 0;
    if (K > 1) {
      flag = count[K];
    }
    for (int i = 0; i < ans.size(); i++) count[ans[i]] = 0;
    for (int i = 0; i < ans.size(); i++) {
      count[ans[i]]++;
      if (count[ans[i]] <= flag)
        cout << ans[i] << " ";
      else
        cout << "0 ";
    }
    cout << endl;
  }
  return 0;
}
