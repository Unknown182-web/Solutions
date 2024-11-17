#include <iostream.h>

#define MAX 100 
void addEdge(int adj[MAX][MAX], int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1; 
}
void BFT(int adj[MAX][MAX], int start, int numVertices) {
int visited[MAX] = {0}; 
  int queue[MAX]; 
  int front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    while (front != rear) {
   int node = queue[front++];
cout << node << " ";
for (int i = 0; i < numVertices; i++) {
if (adj[node][i] == 1 && !visited[i]) {
visited[i] = 1;
queue[rear++] = i;}
}
}
    cout << endl;
}

void DFT(int adj[MAX][MAX], int start, int numVertices) {
    int visited[MAX] = {0};      int stack[MAX];     
    int top = -1;
    stack[++top] = start;
    while (top != -1) {
int node = stack[top--];
if (!visited[node]) {
visited[node] = 1;
cout << node << " ";
for (int i = numVertices - 1; i >= 0; i--) {
if (adj[node][i] == 1 && !visited[i]) {
stack[++top] = i;
}
}
}
}
    cout << endl;
}

int main() {
    int adj[MAX][MAX] = {0};  
    int numEdges, numVertices;

    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    cout << "Enter the number of edges: ";
    cin >> numEdges;
    for (int i = 0; i < numEdges; ++i) {
int u, v;
cout << "Enter edge (u v): ";
cin >> u >> v;
addEdge(adj, u, v);
    }
    int start;
cout << "Enter the start node for BFT and DFT: ";
cin >> start;

cout << "Breadth-First Traversal (BFT) starting from node " << start << ": ";
BFT(adj, start, numVertices);

cout << "Depth-First Traversal (DFT) starting from node " << start << ": ";
DFT(adj, start, numVertices);

    return 0;
}