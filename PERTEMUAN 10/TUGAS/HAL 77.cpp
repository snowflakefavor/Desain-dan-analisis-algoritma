#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n;
    cout << "Masukkan Jumlah Kota = ";
    cin >> n;

    vector<vector<int> > cost(n, vector<int>(n));
    cout << "Nilai Cost Matrix\n";

    for (int i = 0; i < n; i++) {
        cout << "Cost Element Baris ke-: " << i + 1 << endl;
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
            // Jika bukan simpul ke dirinya sendiri dan bernilai 0, artinya tidak ada jalur
            if (i != j && cost[i][j] == 0) {
                cost[i][j] = INT_MAX;
            }
        }
    }

    cout << "\nCost List : \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cost[i][j] == INT_MAX)
                cout << "8"
                     << "\t";
            else
                cout << cost[i][j] << "\t";
        }
        cout << endl;
    }

    // Dijkstra dari simpul 0
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    dist[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;

        // Pilih simpul dengan jarak terkecil yang belum dikunjungi
        for (int i = 0; i < n; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }

        if (dist[u] == INT_MAX)
            break;

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && cost[u][v] != INT_MAX) {
                if (dist[u] + cost[u][v] < dist[v]) {
                    dist[v] = dist[u] + cost[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    // Jalur dari 1 ke 4 (indeks 0 ke 3)
    int dest = n - 1;
    vector<int> path;
    for (int v = dest; v != -1; v = parent[v]) {
        path.insert(path.begin(), v);
    }

    cout << "\nJalur Terpendek :\n";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] + 1; // cetak 1-based index
        if (i < path.size() - 1)
            cout << "--->";
    }

    cout << "\n\nMinimum Cost : " << dist[dest] << endl;

    return 0;
}

