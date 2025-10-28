#include <iostream> 
#include <vector> 
#include <climits> 
using namespace std; 
#define INF INT_MAX 
// Function to find the vertex with the minimum distance value 
int minDistance(vector<int>& dist, vector<bool>& visited, int V) { 
    int min = INF, min_index = -1; 
    for (int v = 0; v < V; v++) { 
        if (!visited[v] && dist[v] <= min) { 
            min = dist[v]; 
            min_index = v; 
        } 
    } 
    return min_index; 
} 
// Dijkstra's algorithm 
void dijkstra(vector<vector<int>>& graph, int src) { 
    int V = graph.size(); 
    vector<int> dist(V, INF);     // Distance from source to each vertex 
    vector<bool> visited(V, false); 
    dist[src] = 0;  // Distance to source itself is 0 
    
    for (int count = 0; count < V - 1; count++) { 
        int u = minDistance(dist, visited, V); 
        visited[u] = true; 
        // Update distance of adjacent vertices 
        for (int v = 0; v < V; v++) { 
            if (!visited[v] && graph[u][v] && dist[u] != INF 
                && dist[u] + graph[u][v] < dist[v]) { 
                dist[v] = dist[u] + graph[u][v]; 
            } 
        } 
    } 
    // Print the results 
    cout << "Vertex \t Distance from Source (" << src << ")\n"; 
    for (int i = 0; i < V; i++) { 
        if (dist[i] == INF) 
            cout << i << "\t INF\n"; 
        else 
            cout << i << "\t " << dist[i] << "\n"; 
    } 
} 
int main() { 
    int V; 
    cout << "Enter number of vertices: "; 
    cin >> V; 
vector<vector<int>> graph(V, vector<int>(V)); 
cout << "Enter adjacency matrix (0 if no edge):\n"; 
for (int i = 0; i < V; i++) { 
for (int j = 0; j < V; j++) { 
cin >> graph[i][j]; 
        } 
    } 
int src; 
cout << "Enter source vertex: "; 
cin >> src; 
dijkstra(graph, src); 
return 0;
}