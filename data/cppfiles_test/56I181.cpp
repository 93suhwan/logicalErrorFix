#include<bits/stdc++.h>
using namespace std;main(){int t;cin>>t;string s;while(t--){for(int x=1;x<=2;x++)for(int y=1;y<=8;y++)for(int z=1;z<=8;z++){cout<<y<<' '<<abs(z-(y%2)*9)<<endl;cin>>s;if(s=="Done")goto nxt;}nxt:;}}
