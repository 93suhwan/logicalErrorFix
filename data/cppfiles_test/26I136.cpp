#include "bits/stdc++.h"
using namespace std;

#define int  long long
#define Expecto_Patronum ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int w;

void compress(int a[],int n){

    pair<int,int> b[n];
    for(int i = 0;i < n;i++){
        b[i].first = a[i];
        b[i].second = i;
    }

    sort(b,b + n);

    w = 1;
    a[b[0].second] = w;
    for(int i = 1;i < n;i++){
        if(b[i].first != b[i - 1].first){
            w++;
        }
        a[b[i].second] = w;
    }

    // for(int i = 0;i < n;i++) cout << a[i] << ' '; cout << '\n';
}

int N;

class Fenwicktree{
    vector<int> bit;
    int n;

public:
    Fenwicktree(int arr[],int arr_size){
        n = arr_size;
        bit.resize(n + 1,0);
        for(int i = 0;i < n;i++){
            update(i,arr[i]);
        }
    }

    void update(int i,int x){
        for(++i;i <= n;i += (i & (-i))){
            bit[i] += x;
        }
    }

    int sum(int i){
        int res = 0;
        for(++i;i > 0;i -= (i & (-i))){
            res += bit[i];
        }
        return res;
    }

    int sum(int l,int r){
        return (sum(r) - sum(l - 1));
    }
};

void solve(){

    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i < n;i++) cin >> a[i];

    compress(a,n);  
    N = w + 1;
    int cnt[N] = {0};
    Fenwicktree ft = Fenwicktree(cnt,N);

    deque<int> dq;
    for(int i = 0;i < n;i++){
        ft.update(a[i],1);
        int l = ft.sum(0,a[i] - 1);
        int r = ft.sum(a[i] + 1,N - 1);
        if(l <= r){
            dq.push_front(a[i]);
        }
        else{
            dq.push_back(a[i]);
        }
    }

    int k = 0,arr[n];
    for(auto &x : dq){
        arr[k] = x;
        k++;
    }

    // for(auto &x : arr) cout << x << ' '; cout << '\n';
    
    int res = 0;
    for(int i = 0;i < n;i++){
        ft.update(arr[i],-1);
        // cout << arr[i] << ' ' << ft.sum(0,arr[i] - 1) << '\n';
        res += ft.sum(0,arr[i] - 1);
    }

    cout << res << '\n';
}

int32_t main()
{
    Expecto_Patronum;  
    int t;
    cin >> t;
    while(t--){
        solve();
        // cout << '\n';
    }
    return 0;
}