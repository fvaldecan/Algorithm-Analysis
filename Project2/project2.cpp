#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <sstream>
#include <queue>
#include <algorithm>
using namespace std;
struct Node{
    int s;
    int e;
    int rev;
    int clientNum;
    int incomingEdges;
    Node*next;
    vector<int>clientsTaken;
};
Node*copyNode(Node*originalNode){
    Node *copy = new Node;
    copy->s = originalNode->s;
    copy->e = originalNode->e;
    copy->rev = originalNode->rev;
    copy->clientNum = originalNode->clientNum;
    copy->incomingEdges = originalNode->incomingEdges++;
    copy->next = nullptr;
    return copy;
}

vector<Node*>getNeighbors(Node*vertex){
    vector<Node*>neighbors;
    while(vertex->next != nullptr) {
        neighbors.push_back(vertex->next);
        vertex = vertex->next;
    }
    return neighbors;
}

vector<Node*>topsortBFS(const vector<Node*>&adjList) {   
    // Topological sort: Queue
    vector<Node*>topoList;
    vector<int>count;
    queue<Node*>Q;
    int vertex;
    for(vertex = 0; vertex < adjList.size(); vertex++) count.push_back(0);
    for (vertex = 0; vertex < adjList.size(); vertex++) {
        vector<Node*>neighborList = getNeighbors(adjList[vertex]);
        int neighborListSize = neighborList.size();
        int neighbor;
        int neighborClientNum;
        for(neighbor = 0; neighbor < neighborListSize; neighbor++){
            neighborClientNum = neighborList[neighbor]->clientNum;
            count[neighborClientNum]++;
        }
    }
    for(vertex = 0; vertex < adjList.size();vertex++)
        if(count[vertex] == 0) Q.push(adjList[vertex]);

    while(!Q.empty()){
        topoList.push_back(Q.front());
        vector<Node*>neighborList = getNeighbors(Q.front());
        Q.pop();
        int neighborListSize = neighborList.size();
        int neighbor;
        int neighborClientNum;
        for(neighbor = 0; neighbor < neighborListSize; neighbor++){
            neighborClientNum = neighborList[neighbor]->clientNum;
            count[neighborClientNum]--;
            if(count[neighborClientNum] == 0)
                Q.push(adjList[neighborClientNum]);
        }
        
    }
    return topoList;
}
void addEdge(Node*client1,Node*client2){
    Node* client2Copy = copyNode(client2);
    while(client1->next != nullptr){
        client1 = client1->next;
    }
    client1->next = client2Copy;
}
vector<Node*>createAdjList(const string& textfile) {
    ifstream input(textfile);
    vector<Node*>adjList;
    //Create start Node and push back into Adjacency List
    Node*start = new Node();
    start->s = 0;
    start->e = 0;
    start->rev = 0;
    start->next = nullptr;
    start->clientNum = 0;
    adjList.push_back(start);
    string line;
    // Get Start Day, End Day, and Revenue from text file
    int i = 0;
    while (getline(input, line)){
        istringstream iss(line);
        //Create Client i Node and push into Adjacency List
        Node*client = new Node();
        int a,b,c;
        iss >> a;
        iss >> b;
        iss >> c;
        client->s = a;
        client->e = b;
        client->rev = c;
        client->clientNum = i+1;
        adjList.push_back(client);
        i++;
    }
    //Adding Edges to clients nodes where their Client i's end days
    //are less than or equal to Client j's start days

    for(int i = 1; i < adjList.size();i++){
        for(int j = 1; j < adjList.size();j++){
            if(i==j) continue;
            else if(adjList[i]->e <= adjList[j]->s)
                addEdge(adjList[i],adjList[j]);
        }
        //Connect to start if there isn't any incoming edges
        if(adjList[i]->incomingEdges == 0)
            addEdge(start,adjList[i]);
    }
    //Create end Node
    Node*end = new Node();
    end->s = 0;
    end->e = 0;
    end->rev = 0;
    end->clientNum = adjList.size();
    end->next = nullptr;
    adjList.push_back(end);

    //Adding end Node to clients that have next = nullptr
    for(int i = 1; i < adjList.size()-1;i++){
        if(adjList[i]->next == nullptr)
            addEdge(adjList[i],end);
    }
    return adjList;
}

int main(int argc, char*argv[]){
    string textfile = argv[1];
    vector<Node*>adjList = createAdjList(textfile);
    int adjListSize = adjList.size();
    for(int i = 0; i < adjListSize;i++){
        cout << "(Client: " << adjList[i]->clientNum ;
        cout << ", Start Day: " << adjList[i]->s;
        cout << ", End Day: " << adjList[i]->e;
        cout << ", Revenue: " << adjList[i]->rev << ") " << endl;
    }
    cout << endl;
    int vertex;
    for(vertex = 0; vertex < adjListSize;vertex++){
        if(vertex == adjListSize-1){
            cout << "(Client: " << adjList[vertex]->clientNum ;
            cout << ", Start Day: " << adjList[vertex]->s;
            cout << ", End Day: " << adjList[vertex]->e;
            cout << ", Revenue: " << adjList[vertex]->rev << ")";
        }else{
            cout << "(Client: " << adjList[vertex]->clientNum ;
            cout << ", Start Day: " << adjList[vertex]->s;
            cout << ", End Day: " << adjList[vertex]->e;
            cout << ", Revenue: " << adjList[vertex]->rev << ")->";
        }
        vector<Node*>neighborList = getNeighbors(adjList[vertex]);
        int neighborListSize = neighborList.size();
        int neighbor;
        for(neighbor = 0; neighbor < neighborListSize;neighbor++){
            if(neighbor == neighborListSize-1){
                cout << "(Client: " << neighborList[neighbor]->clientNum ;
                cout << ", Start Day: " << neighborList[neighbor]->s;
                cout << ", End Day: " << neighborList[neighbor]->e;
                cout << ", Revenue: " << neighborList[neighbor]->rev << ")";
            }else{
                cout << "(Client: " << neighborList[neighbor]->clientNum ;
                cout << ", Start Day: " << neighborList[neighbor]->s;
                cout << ", End Day: " << neighborList[neighbor]->e;
                cout << ", Revenue: " << neighborList[neighbor]->rev << ")->";
            }
        }
        cout << endl;
    }
    //Number of Clients
    int numOfClients = adjListSize -1;
    
    //Topological Sort the Adjacency List
    
    vector<Node*>topoList = topsortBFS(adjList);
    cout << "Topo List: ";
    for(int i = 0; i < topoList.size();i++){
	cout << topoList[i]->clientNum << " " ;
    }
    cout << endl;
    reverse(topoList.begin(), topoList.end());
    int topoListSize = topoList.size();
    vector<int>maxRevenues(topoListSize,0); // Initialize
    //int vertex;
    for(vertex = 0; vertex < topoListSize;vertex++){
        vector<Node*>neighborList = getNeighbors(topoList[vertex]);
        vector<int>revenues(topoListSize,0);
        int neighborListSize = neighborList.size();
        int neighbor;
        for(neighbor = 0; neighbor < neighborListSize;neighbor++){
            revenues[neighborList[neighbor]->clientNum] = topoList[vertex]->rev + maxRevenues[neighborList[neighbor]->clientNum];
        }

        int max = 0;
        int maxIndex = 0;
        int revenueSize = revenues.size();
        for(int revenue = 0; revenue < revenueSize; revenue++){
            if(revenues[revenue] > max){
                maxIndex = revenue;
                max = revenues[revenue];
            }
        }
        topoList[topoList[vertex]->clientNum]->clientsTaken = topoList[maxIndex]->clientsTaken;
        topoList[topoList[vertex]->clientNum]->clientsTaken.push_back(maxIndex);
        maxRevenues[topoList[vertex]->clientNum] += max;
       
    }
    cout << endl;
    cout << endl;
    cout << "There are " << numOfClients << " clients in this file" << endl;

    // Find Optimal Path and Revenue
    cout << "Optimal revenue earned is " << maxRevenues[0] << endl;
    vector<int>optPath = topoList[0]->clientsTaken;
    reverse(optPath.begin(), optPath.end());
    cout << "Clients contributing to this optimal revenue: ";
    for(int i = 0; i < optPath.size()-2;i++){
        cout << optPath[i] << " ";
    }
    cout << endl;
    cout << endl;
    

    return 0;
}
