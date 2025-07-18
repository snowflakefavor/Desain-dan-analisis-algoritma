#include <iostream>
#include <cstring>

using namespace std;

const int N = 100;
int dist[N][N];

void floydWarshall(int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah node pada graph: ";
    cin >> n;

    memset(dist, 0x3f, sizeof dist ); // Fill the distance matrix with a high value
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0; // Distance from a node to itself is 0
    }

    cout << "Masukkan jarak antar node: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int w;
            cin >> w;
            dist[i][j] = w; // Input distance between nodes
        }
    }

    floydWarshall(n);
    
    cout << "Hasil jalur terpendek antar node: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
