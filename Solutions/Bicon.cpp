#include <iostream.h>
#include <conio.h> 
#include <stdio.h>
#define MAX 100
int timer = 0;
int disc[MAX], low[MAX], parent[MAX];
int adj[MAX][MAX];  // Adjacency matrix
int vertices;
int stack[MAX][2], top = -1;  // Stack for edges
void push(int u, int v) {
stack[++top][0] = u;
stack[top][1] = v;
}

void pop(int &u, int &v) {
u = stack[top][0];
v = stack[top--][1];
}
void printBCC(int bcc[][2], int size) {
cout << "BCC: ";
for (int i = 0; i < size; i++) {
cout << "(" << bcc[i][0] << ", " << bcc[i][1] << ") ";
}
cout << "\n";
}
void BCCUtil(int u) {
disc[u] = low[u] = ++timer;
int children = 0;
for (int v = 0; v < vertices; v++) {
if (adj[u][v]) {  // Check if there's an edge between u and v
if (disc[v] == -1) {  // If v is not visited
children++;
parent[v] = u;
push(u, v);  
BCCUtil(v);
low[u] = (low[u] < low[v]) ? low[u] : low[v];
if ((parent[u] == -1 && children > 1) || (parent[u] != -1 && low[v] >= disc[u])) {
int bcc[MAX][2];
int size = 0;
int x, y;
do {
pop(x, y);
bcc[size][0] = x;
bcc[size++][1] = y;
} while (!(x == u && y == v));
printBCC(bcc, size);
}
} else if (v != parent[u] && disc[v] < disc[u]) {
low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
push(u, v);  
}
        }
    }
}

void findBiconnectedComponents() {
for (int i = 0; i < vertices; i++) {
disc[i] = -1;  // Initialize discovery and low arrays
low[i] = -1;
parent[i] = -1;
}
for (int i = 0; i < vertices; i++) {
if (disc[i] == -1) {
BCCUtil(i);
if (top != -1) {
int bcc[MAX][2];
int size = 0;
while (top != -1) {
int x, y;
pop(x, y);
bcc[size][0] = x;
bcc[size++][1] = y;
}
printBCC(bcc, size);
}
}
}
}

int main() {
clrscr();  
int e;
cout << "Enter the number of vertices: ";
 cin >> vertices;

cout << "Enter the number of edges: ";
cin >> e;
for (int i = 0; i < vertices; i++) {
for (int j = 0; j < vertices; j++) {
adj[i][j] = 0;
}
}
cout << "Enter the edges (u v) format:\n";
for (int i = 0; i < e; i++) {
int u, v;
cin >> u >> v;
adj[u][v] = 1;
adj[v][u] = 1;
}
cout << "Biconnected Components are:\n";
findBiconnectedComponents();
    getch();
}
