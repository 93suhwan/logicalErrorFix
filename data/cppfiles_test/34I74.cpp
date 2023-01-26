#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    vector<queue<int>> v(5002);
    for(int i=0;i<=5001;i++){
        v[i].push(0);
    }
    map<pair<int,int>,int> m;
    int c[5002][8192]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
        while(!v[a[i]].empty()){
            int u=v[a[i]].front();
            v[a[i]].pop();
            for(int j=a[i]+1;j<=5001;j++){
                if(c[j][a[i]^u]){
                    break;
                }
                c[j][a[i]^u]=1;
                v[j].push(a[i]^u);
            }
        }
    }
    int k=0;
    for(int i=0;i<8192;i++){
        if(c[5001][i]){
            k++;
        }
    }
    cout<<k<<endl;
    for(int i=0;i<8192;i++){
        if(c[5001][i]){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}    