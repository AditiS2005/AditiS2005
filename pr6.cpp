#include<iostream>
using namespace std;

class Graph {
    int a[10][10], vcnt;
    bool visited[10];

public:
    Graph() {
        vcnt = 0;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                a[i][j] = 0;
    }

    void read_adjacency();
    void display_adjacency();
    void BFS();
    void DFS();
    void resetVisited();
};

void Graph::read_adjacency() {
    cout << "Enter number of vertices: ";
    cin >> vcnt;

    cout << "Enter adjacency matrix (0/1):\n";
    for (int i = 0; i < vcnt; i++) {
        for (int j = 0; j < vcnt; j++) {
            cout << "Edge " << i << " to " << j << ": ";
            cin >> a[i][j];
        }
    }
}

void Graph::display_adjacency() {
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < vcnt; i++) {
        for (int j = 0; j < vcnt; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

class Queue {
    int q[20], front, rear;

public:
    Queue() {
        front = 0;
        rear = 0;
    }

    void insert(int val) {
        if (rear < 20)
            q[rear++] = val;
        else
            cout << "Queue overflow!\n";
    }

    int Delete() {
        if (front < rear)
            return q[front++];
        else
            return -1; // underflow
    }

    bool isEmpty() {
        return front == rear;
    }
};

class Stack {
    int s[20], top;

public:
    Stack() {
        top = -1;
    }

    void push(int val) {
        if (top < 19)
            s[++top] = val;
        else
            cout << "Stack overflow!\n";
    }

    int pop() {
        if (top >= 0)
            return s[top--];
        else
            return -1; // underflow
    }

    bool isEmpty() {
        return top == -1;
    }
};

void Graph::resetVisited() {
    for (int i = 0; i < vcnt; i++) {
        visited[i] = false;
    }
}

void Graph::BFS() {
    resetVisited();

    int start;
    cout << "\nEnter starting vertex for BFS (0 to " << vcnt - 1 << "): ";
    cin >> start;

    Queue q;
    visited[start] = true;
    q.insert(start);

    cout << "BFS Traversal: ";

    while (!q.isEmpty()) {
        int curr = q.Delete();
        cout << curr << " ";

        for (int i = 0; i < vcnt; i++) {
            if (a[curr][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.insert(i);
            }
        }
    }

    cout << "\n";
}

void Graph ::DFS() {
    resetVisited();

    int start;
    cout << "\nEnter starting vertex for DFS (0 to " << vcnt - 1 << "): ";
    cin >> start;

    Stack s;
    visited[start] = true;
    s.push(start);

    cout << "DFS Traversal: ";

    while (!s.isEmpty()) {
        int curr = s.pop();
        cout << curr << " ";

        for (int i = vcnt - 1; i >= 0; i--) {
            if (a[curr][i] == 1 && !visited[i]) {
                visited[i] = true;
                s.push(i);
            }
        }
    }

    cout << "\n";
}

int main() {
    Graph g;
    int choice;

    g.read_adjacency();
    g.display_adjacency();

    do {
        cout << "\nMenu:\n1. BFS\n2. DFS\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            g.BFS();
            break;
        case 2:
            g.DFS();
            break;
        case 3:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
