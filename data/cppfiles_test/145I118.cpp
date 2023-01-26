//HEADER
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define all(a) begin(a), end(a)
#define sort(a) sort(all(a))

// speed up cin and cout
void setIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

struct mine{
    int i, x, y, time;
    mine(int I, int X, int Y, int t){
        i = I;
        x = X;
        y = X;
        time = t;
    }
};

int dfs(int curr, int k, vi &visited, map<int, vector<pii>> &xM, map<int, vector<pii>> &yM, vector<mine> &mines){
    visited[curr] = true;
    int x = mines[curr].x;
    int y = mines[curr].y;
    int ret = mines[curr].time;
    for(auto next : xM[x]){
        if(visited[next.first]){
            continue;
        }
        if(abs(mines[next.first].y-y <= k)){
            ret = min(ret, dfs(next.first, k, visited, xM, yM, mines));
        } 
    }
    for(auto next : yM[y]){
        if(visited[next.first]){
            continue;
        }
        if(abs(mines[next.first].x-x <= k)){
            ret = min(ret, dfs(next.first, k, visited, xM, yM, mines));
        }
    }
    return ret;
}

void solve(){
    int n, k;
    cin >> n >> k;
    map<int, vector<pii>> xM;
    map<int, vector<pii>> yM;
    vector<mine> mines;
    for(int i = 0; i < n; i++){
        int x, y, time;
        cin >> x >> y >> time;
        xM[x].push_back({i, time});
        yM[y].push_back({i, time});
        mines.push_back(mine(i, x, y, time));
    }
    vi groups;
    vi visited(n, 0);
    for(int i = 0; i < n; i++){
        if(visited[i]){
            continue;
        }
        groups.push_back(dfs(i, k, visited, xM, yM, mines));
    }
    sort(groups);
    reverse(all(groups));
    int l = 0;
    int r = groups.size()-1;
    while(l < r){
        while(groups[r] <= l){
            r--;
        }
        l++;
    }
    // cout << "GROUP SIZES: " << groups.size() << "\n";
    cout << l << "\n";
}

int t;
int main(){
    setIO();
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}
