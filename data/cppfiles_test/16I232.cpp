#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N = 1e5 + 10;
int index[N];

void solve()
{
    priority_queue<int, vector<int>, less<int>> q;
    vector<PII> res;
    int n;
    cin >> n;
    for(int i = 0;i < N;i ++) index[i] = 0;

    for(int i = 1;i <= n;i ++){
        int x;
        cin >> x;
        if(x){
            index[x] = i;
            q.push(x);
        }
    }

    while(q.top() && q.size() > 1){
        int x = q.top();q.pop();
        int y = q.top();q.pop();

        int tx = index[x],ty = index[y];
        res.push_back({index[y --],index[x --]});
        //cout << index[x] << " " << index[y] << '\n';
        index[x] = tx;
        index[y] = ty;
        //cout << index[x] << " " << index[y] << '\n';

        if(x > 0) q.push(x);
        if(y > 0) q.push(y);
    }

    cout << res.size() << '\n';
    if(res.size()){
        for(int i = 0;i < res.size();i ++) cout << res[i].first << " " << res[i].second << '\n';
    }
}
int main()
{
    int t;
    cin >> t;
    while(t -- ){
        solve();
    }
    return 0;
}
