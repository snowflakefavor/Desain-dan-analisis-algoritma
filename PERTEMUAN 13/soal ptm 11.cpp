#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

const int INF = 1000000000;

const string namesArr[] = {
    "Kyanka","Dava","Doni","Wildan","Haikal","Agus",
    "Abrar","Azizah","Annisa","Yunita","Jonathan","Rofii",
    "Nanda","Ale","Agung","Martin","Sudrajat","Steven"
};
const int N = sizeof(namesArr) / sizeof(namesArr[0]);

map<string,int> idx;

vector< vector<int> > fw_next;

vector<int> getFloydPath(int u, int v) {
    vector<int> path;
    if(fw_next[u][v] == -1) return path;
    path.push_back(u);
    while(u != v) {
        u = fw_next[u][v];
        path.push_back(u);
    }
    return path;
}

pair< vector<int>, vector<int> >
dijkstra(const vector< vector<int> >& adj, int src) {
    vector<int> dist(N, INF), parent(N, -1);
    dist[src] = 0;
    priority_queue< pair<int,int>,
                    vector<pair<int,int> >,
                    greater<pair<int,int> > > pq;
    pq.push(make_pair(0, src));

    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(d > dist[u]) continue;
        for(int v = 0; v < N; ++v) {
            if(adj[u][v] < INF) {
                int w = adj[u][v];
                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
    }
    return make_pair(dist, parent);
}

void addEdge(vector< vector<int> >& adj,
             const string& a, const string& b, int w) {
    int u = idx[a], v = idx[b];
    if(adj[u][v] > w) adj[u][v] = w;
    if(adj[v][u] > w) adj[v][u] = w;
}

int main(){
    for(int i = 0; i < N; ++i) {
        idx[namesArr[i]] = i;
    }

    vector< vector<int> > adj(N, vector<int>(N, INF));
    for(int i = 0; i < N; ++i) adj[i][i] = 0;

    addEdge(adj,"Kyanka","Dava",1);
    addEdge(adj,"Kyanka","Abrar",3);
    addEdge(adj,"Abrar","Azizah",1);
    addEdge(adj,"Abrar","Steven",2);
    addEdge(adj,"Azizah","Annisa",1);
    addEdge(adj,"Azizah","Steven",1);
    addEdge(adj,"Dava","Doni",1);
    addEdge(adj,"Dava","Annisa",2);
    addEdge(adj,"Doni","Wildan",2);
    addEdge(adj,"Doni","Annisa",4);
    addEdge(adj,"Annisa","Yunita",2);
    addEdge(adj,"Wildan","Jonathan",1);
    addEdge(adj,"Wildan","Haikal",4);
    addEdge(adj,"Jonathan","Rofii",2);
    addEdge(adj,"Jonathan","Nanda",2);
    addEdge(adj,"Haikal","Agus",4);
    addEdge(adj,"Rofii","Agus",2);
    addEdge(adj,"Rofii","Agung",2);
    addEdge(adj,"Nanda","Ale",2);
    addEdge(adj,"Ale","Agung",1);
    addEdge(adj,"Nanda","Sudrajat",4);
    addEdge(adj,"Martin","Nanda",1);
    addEdge(adj,"Martin","Sudrajat",3);

    cout<<"=== Menu ===\n";
    cout<<"1. Jalur tercepat (Dijkstra)\n";
    cout<<"2. Cetak semua jarak terpendek \n";
    cout<<"Pilih fitur (1/2): ";
    int fitur; cin>>fitur;
    cin.ignore();

    if(fitur == 1){
        string ssrc, sdst;
        cout<<"Masukkan siswa asal: "; getline(cin, ssrc);
        cout<<"Masukkan siswa tujuan: "; getline(cin, sdst);
        if(!idx.count(ssrc)||!idx.count(sdst)){
            cout<<"Nama siswa tidak valid.\n";
            return 0;
        }
        int src = idx[ssrc], dst = idx[sdst];
        pair<vector<int>,vector<int> > sol = dijkstra(adj, src);
        vector<int> dist = sol.first, parent = sol.second;

        if(dist[dst]>=INF){
            cout<<"Tidak ada jalur yang tersedia dari "
                <<ssrc<<" ke "<<sdst<<".\n";
        } else {
            vector<int> path;
            for(int v=dst; v!=-1; v=parent[v])
                path.push_back(v);
            reverse(path.begin(), path.end());
            cout<<"Jalur tercepat: ";
            for(size_t i=0; i<path.size(); ++i){
                cout<<namesArr[path[i]]
                    <<(i+1<path.size()?" -> ":"");
            }
            cout<<"\nTotal waktu: "<<dist[dst]<<"\n";
        }
    }
    else if(fitur == 2){
        vector< vector<int> > dist = adj;
        fw_next.assign(N, vector<int>(N, -1));
        for(int i=0;i<N;++i)
            for(int j=0;j<N;++j)
                if(dist[i][j]<INF)
                    fw_next[i][j]=j;

        for(int k=0;k<N;++k)
            for(int i=0;i<N;++i)
                for(int j=0;j<N;++j)
                    if(dist[i][k]<INF && dist[k][j]<INF &&
                       dist[i][j] > dist[i][k]+dist[k][j]){
                        dist[i][j] = dist[i][k]+dist[k][j];
                        fw_next[i][j] = fw_next[i][k];
                    }

        int maxLen = 0;
        for(int i=0;i<N;++i)
            maxLen = max(maxLen, (int)namesArr[i].length());
        int w = maxLen + 2;

        cout<<setw(w)<<"";
        for(int j=0;j<N;++j)
            cout<<setw(w)<<namesArr[j];
        cout<<"\n";

        for(int i=0;i<N;++i){
            cout<<setw(w)<<namesArr[i];
            for(int j=0;j<N;++j){
                if(dist[i][j]>=INF)
                    cout<<setw(w)<<"INF";
                else
                    cout<<setw(w)<<dist[i][j];
            }
            cout<<"\n";
        }

        cout<<"\nCetak jalur dan waktu (Y/T)? ";
        char yn; cin>>yn;
        if(yn=='Y'||yn=='y'){
            for(int i=0;i<N;++i){
                for(int j=0;j<N;++j){
                    if(i==j) continue;
                    cout<<"\nDari "<<namesArr[i]
                        <<" ke "<<namesArr[j]<<": ";
                    if(dist[i][j]>=INF){
                        cout<<"Tidak ada jalur.\n";
                    } else {
                        vector<int> p = getFloydPath(i,j);
                        for(size_t k=0; k<p.size(); ++k){
                            cout<<namesArr[p[k]]
                                <<(k+1<p.size()?" -> ":"");
                        }
                        cout<<" | waktu = "<<dist[i][j]<<"\n";
                    }
                }
            }
        }
    }
    else {
        cout<<"Pilihan tidak valid.\n";
    }

    return 0;
}
