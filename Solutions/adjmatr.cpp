
#include <iostream.h>
#include <conio.h>
void bfs(int adjMatrix[100][100], int n, int startVertex) {
    int visited[100] = {0};  
    int queue[100]; 
   int front = 0, rear = 0; 
    queue[rear++] = startVertex;
    visited[startVertex] = 1;
    
    cout << "BFS Traversal: ";
    
while (front < rear) {
int vertex = queue[front++];
cout << vertex << " ";
for (int i = 0; i < n; ++i) {
if (adjMatrix[vertex][i] == 1 && visited[i] == 0) {
queue[rear++] = i;
visited[i] = 1;
}
}
}
    cout << endl;
}

void dfsUtil(int adjMatrix[100][100], int n, int vertex, int visited[100]) {
    visited[vertex] = 1;
cout << vertex << " ";
    
for (int i = 0; i < n; ++i) {
if (adjMatrix[vertex][i] == 1 && visited[i] == 0) {
dfsUtil(adjMatrix, n, i, visited);
}
    }
}

void dfs(int adjMatrix[100][100], int n, int startVertex) {
    int visited[100] = {0};     cout << "DFS Traversal: ";
    dfsUtil(adjMatrix, n, startVertex, visited);
    cout << endl;
}

int main() {
    clrscr();     
    int n; 
    cout << "Enter the number of vertices: ";
    cin >> n;
    int adjMatrix[100][100];
    
    cout << "Enter the adjacency matrix (row by row):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adjMatrix[i][j];
        }
    }

    int startVertex;
    cout << "Enter the starting vertex for traversal: ";
    cin >> startVertex;
    
    if (startVertex >= n || startVertex < 0) {
        cout << "Invalid starting vertex!" << endl;
        return 1;
    }

    bfs(adjMatrix, n, startVertex);
    dfs(adjMatrix, n, startVertex);

    getch(); 
    return 0;
}