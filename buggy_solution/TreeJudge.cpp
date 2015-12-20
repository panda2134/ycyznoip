/*
  Buggy!
  by:panda_2134
  QQ:759997057
  Problem:http://noi.openjudge.cn/ch0308/310/
  the bug is @ Line 56.
  SIGSENV when run that line.
*/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<vector>



using namespace std;

int cur=0;
bool ok=true;
vector<int> color(5001);
vector<vector<int> > Adj(5001);
set<int> nodes;

int readone();
void dfsVisit(int q);

int main(){
	while(readone()!=-1){
		for(set<int>::iterator i=nodes.begin();i!=nodes.end();i++){
			if(color[*i]==0){
				dfsVisit(*i);
			}
			if(ok){
				printf("Case %d is a tree.",++cur);
			}else{
				printf("Case %d is not a tree.",++cur);
			}
		}
		for(int q=0;q<1000;q++)
			Adj[q].clear();
		nodes.clear();
		color.clear();
	}
}

int readone(){
	int m,n;
	while(scanf("%d %d",m,n)==2){
		if(m==-1 && n==-1){
			return -1;
		}
		if(m==-1 && n==0){
			return 0;
		}
		Adj[m].push_back(n);
		nodes.insert(m);
	}
}

void dfsVisit(int q){
	color[q]=1;
	for(int i=0;i<Adj[q].size();i++){
		if(color[Adj[q][i]]==0){
			dfsVisit(Adj[q][i]);
		}else{
			//not a tree
			ok=false;
			return;
		}
	}	
}
