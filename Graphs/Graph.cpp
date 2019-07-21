// Directed Graph
// Implement itrerative BFS and DFS

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <queue>
#include <stack>

class Graph {
    
    private:
    std::list<int>* adj_list;
    int total_nodes;
    void print_node(int node) {
        std::cout << node << " ";
    }

    void All_DFS_Util(int src, std::vector<bool> &visited) {
        std::stack<int> stack;
        stack.push(src);
        while (!stack.empty()) {

            int node = stack.top();
            stack.pop();
            // stack may contain the same node more than once,
            // so we need to print the node only if it is not visited
            if (!visited[node]) {
                print_node(node);
                visited[node] = true;
            }
            // Get all adjacent vertices of the popped node
            // if an anjacent node hasn't been visisted yet,
            // then push it to the stack
            for (auto itr = adj_list[node].begin(); itr != adj_list[node].end(); ++itr) {
                int adjacent_node = *itr;
                if (!visited[adjacent_node]) {
                    stack.push(adjacent_node);
                }
            }

        }
        std::cout << std::endl;
    }

    void All_BFS_Util(int src, std::vector<bool> &visited) {
        std::queue<int> queue;
        visited[src] = true;
        queue.push(src);
        int node;
        int adjacent_node;
        std::list<int>::iterator itr;
        while (!queue.empty()) {
            node = queue.front();
            print_node(node); 
            queue.pop();
            for (itr = adj_list[node].begin(); itr != adj_list[node].end(); ++itr) {
                adjacent_node = *itr;
                if (!visited[adjacent_node]) {
                    visited[adjacent_node] = true;
                    queue.push(adjacent_node);
                }
            }
        }
        std::cout << std::endl;
    }

    public:
    Graph(int total_nodes):total_nodes(total_nodes){
        adj_list = new std::list<int>[total_nodes];
    }

    void add_edge(int src, int dest) {
        adj_list[src].push_back(dest);
    }

    void All_BFS() {
        std::vector<bool> visited(total_nodes, false);
        for (int node = 0; node < total_nodes; ++node) {
            if (!visited[node]) {
                All_BFS_Util(node, visited);
            }
        }
    }

    void BFS(int src) {
        // Mark all vertices as not visited
        std::vector<bool> visited(total_nodes,false);
        std::queue<int> queue;
        visited[src] = true;
        queue.push(src);
        std::list<int>::iterator itr;
        int node;
        int adjacent_node;
        while (!queue.empty()) {
            node = queue.front();
            print_node(node);
            for (itr = adj_list[node].begin(); itr != adj_list[node].end(); ++itr) {
                adjacent_node = *itr;
                if (!visited[adjacent_node]) {
                    visited[adjacent_node] = true;
                    queue.push(adjacent_node);
                }
            }
            queue.pop();
        }
        std::cout << std::endl;
    }

    void DFS(int src) {
        std::vector<bool> visited(total_nodes, false);
        std::stack<int> stack;
        stack.push(src);
        while (!stack.empty()) {

            int node = stack.top();
            stack.pop();
            // stack may contain the same node more than once,
            // so we need to print the node only if it is not visited
            if (!visited[node]) {
                print_node(node);
                visited[node] = true;
            }
            // Get all adjacent vertices of the popped node
            // if an anjacent node hasn't been visisted yet,
            // then push it to the stack
            for (auto itr = adj_list[node].begin(); itr != adj_list[node].end(); ++itr) {
                int adjacent_node = *itr;
                if (!visited[adjacent_node]) {
                    stack.push(adjacent_node);
                }
            }

        }
        std::cout << std::endl;

    }



    void All_DFS() {
        std::vector<bool> visited(total_nodes, false);
        for (int node = 0; node < total_nodes; ++node) {
            if (!visited[node]) {
                All_DFS_Util(node,visited);
            }
        }
    }

    ~Graph() {
        std::cout << "Destroying the graph instance" << std::endl;
    }

};


// Driver Code
int main () {

    // Create a graph
    Graph *graph1 = new Graph(4);
    graph1->add_edge(0,1);
    graph1->add_edge(0,2);
    graph1->add_edge(1,2);
    graph1->add_edge(2,0);
    graph1->add_edge(2,3);
    graph1->add_edge(3,3);
 
    std::cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    graph1->BFS(2); 
    graph1->DFS(2);
    graph1->All_BFS();
    graph1->All_DFS();
    delete graph1;
  
    return 0;
}