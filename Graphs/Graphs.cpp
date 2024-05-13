#include <iostream>
using namespace std;

struct edge;

struct vertex {
    int value;
    bool visited;
    vertex* vpoint;
    edge* epoint;
};

struct edge {
    vertex* connect;
    edge* next;
};


struct VertexQueue {
    vertex* v;
    VertexQueue* next;
};

void enqueue(VertexQueue** front, VertexQueue** rear, vertex* v) {
    VertexQueue* newNode = new VertexQueue;
    newNode->v = v;
    newNode->next = NULL;
    if (*front == NULL && *rear == NULL) {
        *front = *rear = newNode;
    }
    else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

vertex* dequeue(VertexQueue** front, VertexQueue** rear) {
    if (*front == NULL) 
    {
        cout << "Queue Underflow" << endl;
        return NULL;
    }
    VertexQueue* temp = *front;
    vertex* v = temp->v;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    delete temp;
    return v;
}

bool isEmpty(VertexQueue* front) {
    return front == NULL;
}


void insertvertex(vertex** initialvertex) {
    vertex* vptr = new vertex;
    cout << "Insert Vertex Value: ";
    cin >> vptr->value;
    vptr->vpoint = NULL;
    vptr->epoint = NULL;

    if (*initialvertex == NULL) {
        *initialvertex = vptr;
    }
    else {
        vertex* curr = *initialvertex;
        while (curr->vpoint != NULL) {
            curr = curr->vpoint;
        }
        curr->vpoint = vptr;
    }
}

void insertdirectededge(vertex** initialVertex, int startValue, int endValue) {
    vertex* startVertex = NULL;
    vertex* endVertex = NULL;
    vertex* curr = *initialVertex;

    while (curr != NULL) {
        if (curr->value == startValue) {
            startVertex = curr;
        }
        if (curr->value == endValue) {
            endVertex = curr;
        }
        curr = curr->vpoint;
    }

    if (startVertex == NULL || endVertex == NULL) {
        cout << "Error: One or both vertices not found" << endl;
        return;
    }

    edge* newEdge = new edge;
    newEdge->connect = endVertex;
    newEdge->next = startVertex->epoint;
    startVertex->epoint = newEdge;
}

void printdirectedgraphdegree(vertex* initialVertex) {
    vertex* curr = initialVertex;
    while (curr != NULL) {
        int outDegree = 0;
        int inDegree = 0;

        edge* outEdge = curr->epoint;
        while (outEdge != NULL) {
            outDegree++;
            outEdge = outEdge->next;
        }
        vertex* temp = initialVertex;
        while (temp != NULL) {
            edge* inEdge = temp->epoint;
            while (inEdge != NULL) {
                if (inEdge->connect == curr) {
                    inDegree++;
                }
                inEdge = inEdge->next;
            }
            temp = temp->vpoint;
        }

        cout << "Vertex " << curr->value << ": In-Degree = " << inDegree << ", Out-Degree = " << outDegree << endl;
        curr = curr->vpoint;
    }
}


void insertundirectededge(vertex** initialVertex, int startValue, int endValue) {
    vertex* startVertex = NULL;
    vertex* endVertex = NULL;
    vertex* curr = *initialVertex;

    while (curr != NULL) {
        if (curr->value == startValue) {
            startVertex = curr;
        }
        if (curr->value == endValue) {
            endVertex = curr;
        }
        curr = curr->vpoint;
    }

    if (startVertex == NULL || endVertex == NULL) {
        cout << "Error: One or both vertices not found" << endl;
        return;
    }

    edge* edge1 = new edge;
    edge1->connect = endVertex;
    edge1->next = startVertex->epoint;
    startVertex->epoint = edge1;

    if (startVertex != endVertex) {
        edge* edge2 = new edge;
        edge2->connect = startVertex;
        edge2->next = endVertex->epoint;
        endVertex->epoint = edge2;
    }
}

void printundirectedgraphdegree(vertex* initialVertex) {
    vertex* curr = initialVertex;
    while (curr != NULL) {
        int degree = 0;
        edge* e = curr->epoint;
        while (e != NULL) {
            degree++;
            e = e->next;
        }
        cout << "Vertex " << curr->value << " has degree " << degree << "." << endl;
        curr = curr->vpoint;
    }
}

void resetVisited(vertex* head) {
    vertex* v = head;
    while (v != NULL) {
        v->visited = false;
        v = v->vpoint;
    }
}


void bfs(vertex* start) {
    if (start == NULL) return;

    VertexQueue* front = NULL, * rear = NULL;
    start->visited = true;
    enqueue(&front, &rear, start);

    while (!isEmpty(front)) {
        vertex* current = dequeue(&front, &rear);
        cout << "Visited vertex: " << current->value << endl;

        for (edge* e = current->epoint; e != NULL; e = e->next) {
            if (!e->connect->visited) {
                e->connect->visited = true;
                enqueue(&front, &rear, e->connect);
            }
        }
    }
}

void dfs(vertex* v) {
    if (v == NULL || v->visited) return;  

    v->visited = true;
    cout << "Visited vertex: " << v->value << endl;

    for (edge* e = v->epoint; e != nullptr; e = e->next) {
        if (!e->connect->visited) {
            dfs(e->connect);
        }
    }
}



int main() {
    vertex* initialvertex = NULL;
    int select, graphcase;
    cout << "Press 1 to construct a directed graph." << endl;
    cout << "Press 2 to construct an undirected graph." << endl;
    cin >> graphcase;
    cout << "Press 1 to insert a vertex." << endl;
    cout << "Press 2 to insert an edge." << endl;
    cout << "Press 3 to find degree." << endl;
    cout << "Press 4 to perform BFS." << endl;
    cout << "Press 5 to perform DFS." << endl;
    cin >> select;

    while (select != 0) {
        if (select == 1) {
            insertvertex(&initialvertex);
        }
        else if (select == 2) {
            int start, end;
            cout << "Enter start vertex: ";
            cin >> start;
            cout << "Enter end vertex: ";
            cin >> end;
            if (graphcase == 1) {
                insertdirectededge(&initialvertex, start, end);
            }
            else if (graphcase == 2) {
                insertundirectededge(&initialvertex, start, end);
            }
        }
        else if (select == 3) {
            if (graphcase == 1) {
                printdirectedgraphdegree(initialvertex);
            }
            else if (graphcase == 2) {
                printundirectedgraphdegree(initialvertex);
            }
        }
        else if (select == 4) {
            resetVisited(initialvertex); 
            bfs(initialvertex);
        }
        else if (select == 5) {
            resetVisited(initialvertex);  
            dfs(initialvertex);  
        }
        cout << "Enter your choice again (0 to exit): ";
        cin >> select;
    }

    return 0;
}

