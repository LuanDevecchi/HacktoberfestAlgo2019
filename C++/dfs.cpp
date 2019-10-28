#include<bits/stdc++.h>
using namespace std;

int v,e;

vector<std::vector<int>> g;
vector<int> starttime;
vector<int> finishtime;
vector<int> visited;


void dfs(int v)
{
  cout<<v<<" ";
  visited[v]=1;
  for(auto iter = g[v].begin() ; iter != g[v].end(); iter++)
  {
    if( visited[*iter] != 1 )
    {
      dfs(*iter);
    }
  }
}


int main()
{


  cin>>v>>e;
  g.resize(v+1);
  starttime.resize(v+1,0);
  finishtime.resize(v+1,0);
  visited.resize(v+1,0);

  int v1,v2;
  for(int i=0;i<e;i++)
  {
      cin>>v1>>v2;

      g[v1].push_back(v2);
      g[v2].push_back(v1);
  }


  // cout<<"Printing the Adjacency list\n";
  //
  // for(int i=0;i<v;i++)
  // {
  //   cout<<"For the vertex "<<i<<endl;
  //   for(auto iterator = g[i].begin() ; iterator != g[i].end() ; iterator++ )
  //   {
  //       cout<<i<< *iterator<<" ";
  //   }
  // }


cout<<endl<<"DFS OF GRAPH"<<endl;
for(int u: g[v])                                        //Restart dfs
{
  if(!visited[u])
  dfs(u);
}

  return 0;
}
