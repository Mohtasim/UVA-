#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100010
#define MAX 99999
#define lson(i) ((i)<<1)
#define rson(i) ((i)<<1|1)

int n,lp[N],rp[N],h[N];
struct SegTree{
	int l,r,Max,lazy;
	SegTree(){}
	SegTree(int _l,int _r){
		l = _l; r = _r; Max = 0; lazy = 1;
	}
	int mid(){
		return (l+r) >> 1;
	}
}t[N<<2];

void build(int rt,int a,int b){
	t[rt] = SegTree(a,b);
	if(a == b) return ;
	int mid = t[rt].mid();
	build(lson(rt),a,mid);
	build(rson(rt),mid+1,b);
}

void PushDown(int rt){
	if(t[rt].lazy == 0) return ;
	t[lson(rt)].Max = t[rson(rt)].Max = t[rt].Max;
	t[rt].lazy = 0;
}


void updata(int rt,int a,int b,int height){
	if(t[rt].l == a && t[rt].r == b && t[rt].lazy){
		if(height > t[rt].Max)
			t[rt].Max = height;
		return ;
	}
	PushDown(rt);
	int mid = t[rt].mid();
	if(b <= mid)
		updata(lson(rt),a,b,height);
	else if(a > mid)
		updata(rson(rt),a,b,height);
	else{
		updata(lson(rt),a,mid,height);
		updata(rson(rt),mid+1,b,height);
	}
}

int query(int rt,int a,int b,int height){
	if(t[rt].lazy){
		if(t[rt].Max <= height){
			updata(rt,a,b,height);
			return b-a+1;
		}
		else
			return 0;
	}
	PushDown(rt);
	int mid = t[rt].mid();
	if(b <= mid)
		return query(lson(rt),a,b,height);
	else if(a > mid)
		return query(rson(rt),a,b,height);
	else{
		int res1 = query(lson(rt),a,mid,height);
		int res2 = query(rson(rt),mid+1,b,height);
		return res1 + res2;
	}
}

int main(){
	int cas,n;
	scanf("%d",&cas);
	while(scanf("%d",&n)!=EOF && n){
		int ans = 0;
		build(1,1,MAX);
		for(int i = 0; i < n; i++){
			scanf("%d%d%d",&lp[i],&rp[i],&h[i]);
			rp[i]--;
			int res = query(1,lp[i],rp[i],h[i]);
			ans += res;
		}
		printf("%d\n",ans);
	}
	return 0;
}



