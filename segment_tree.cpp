#include <bits/stdc++.h>
using namespace std;

#define ar array
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()
#define fast ios::sync_with_stdio(false), cin.tie(nullptr)
#ifdef LOCAL
#define log(x) cerr<<"[ " << #x << " : " << (x) << " ]\n";
#else
#define log(x) (void)0x30
#endif

using ll = long long;
const int mod = 1e9+7;
vector<int> a,t;

int merge(int a,int b){
    return max(a,b);
}


void build(int v,int l,int r){
    if(l==r){
        t[v]=a[l];
    }
    else{
        int m=(l+r)/2;
        build(v*2,l,m);
        build(v*2+1,m+1,r);
        t[v]=merge(t[v*2],t[v*2+1]);
    }
}

int get(int v,int l,int r,int L,int R){
    if(l==L && r==R){
        return t[v];
    }
    else{
        int m=(l+r)/2;
        if(R<=m){
            return get(v*2,l,m,L,R);
        }
        else if(m<L){
            return get(v*2+1,m+1,r,L,R);
        }
        return merge(get(v*2,l,m,L,m),get(v*2+1,m+1,r,m+1,R));
    }
}


int32_t main(){
    int n;
    cin>>n;
    a.resize(n);
    t.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    
}
