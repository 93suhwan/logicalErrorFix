#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ford(i,a,b) for(int i=a;i<=b;i++)

int n,h,a[105];

bool check(int x){
    int ok=0;
    int d=a[1],c;
    ford(i,1,n){
        c=a[i]+x-1;
        if(d<a[i]) d=a[i];
        if(d==a[i]) ok+=max(c-d+1,0LL);
        else ok+=max(c-d,0LL);
        d=c;
    }
    return (ok>=h);
}

void run_case(int tests){
    cin>>n>>h;
    ford(i,1,n) cin>>a[i];
    int l=1,r=1e18,kq;
    while(l<=r){
        int m=(l+r)>>1;
        if(check(m)) kq=m,r=m-1;
        else l=m+1;
    }
    cout<<kq<<'\n';
}

main(){
     ios_base::sync_with_stdio(false);
     cin.tie(0);

     int test;

     cin>>test;

     ford(tests,1,test) run_case(tests);

}
