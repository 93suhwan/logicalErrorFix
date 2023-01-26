#include<bits/stdc++.h>
#define int long long
using namespace std;


main() {
#if !ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0), cin.tie(0);



    int T;cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        if(k==1){
            int ans=1e9;
            for(int d=1;d<=9;d++){
                int cur=0;
                while(cur<n){
                    cur=cur*10+d;
                }
                ans=min(ans,cur);
            }

            cout<<ans<<'\n';
        }else{
            int ans=1e9;
            for(int a=1;a<=9;a++){
                for(int b=1;b<=9;b++){
                    if(a==b)continue;
                    for(int d=2;d<=11;d++){
                        for(int msk=0;msk<(1<<d);msk++){
                            int cur=0;
                            for(int i=d-1;i>=0;i--){
                                if((1<<i)&msk){
                                    cur=cur*10+a;
                                }else{
                                    cur=cur*10+b;
                                }
                            }

                            if(cur>=n){
                                ans=min(ans,cur);
                                break;
                            }
                        }
                    }
                }
            }

            cout<<ans<<'\n';
        }
    }

    exit(EXIT_SUCCESS);
}












