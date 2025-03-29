#include <iostream>
#include <list>
using namespace std;
#define N 8
char vertices[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
int adjacencyM[N][N]= {{0, 1, 0, 0, 0, 0, 0, 1},
                       {1, 0, 1, 0, 0, 0, 0, 0},
                       {0, 1, 0, 1, 0, 0, 0, 1},
                       {0, 0, 1, 0, 1, 0, 1, 0},
                       {0, 0, 0, 1, 0, 1, 0, 0},
                       {0, 0, 0, 0, 1, 0, 1, 0},
                       {0, 0, 0, 1, 0, 1, 0, 1},
                       {1, 0, 1, 0, 0, 0, 1, 0}};

int visited[N] {0};
class Hamiltonian{
public:
  int start;
  list<int> cycle;
  bool hasCycle = false;
  Hamiltonian(int start){
    this->start = start;
  }
  void findCycle(){
    cycle.push_back(start);
    solve(start);
  }
  void solve(int vertex){
    if(vertex == start && cycle.size() == N+1){
      hasCycle = true;
      displayCycle();
      return;
    }
    for(int i=0; i<N; i++){
      if(adjacencyM[vertex][i] == 1 && visited[i] == 0){
        int nbr =i;
        visited[nbr] = 1;
        cycle.push_back(nbr);
        solve(nbr);

        visited[nbr] = 0;
        cycle.pop_back();
      }
    }
  }
  void displayCycle(){
    cout << "[";
    for(int v: cycle){
      cout << vertices[v] << " " ;
    }
    cout << "] \n";
  }
};

int main() {
  cout<< "Name: Vanshika Aggarwal"<< endl;
  cout<< "Roll No: 22001003138"<< endl;
  Hamiltonian hamiltonian = Hamiltonian(0);
  hamiltonian.findCycle();
  if(!hamiltonian.hasCycle){
    cout << "No Hamiltonian Cycle";
  }
}