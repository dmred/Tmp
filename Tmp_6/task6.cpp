#include <iostream>
#include <string>
using namespace std;

class Orgraf{
public:
		Orgraf(int _V): V(_V), E(0){
			M = new int*[V];
			for (int i = 0; i < V; i++) {
				M[i] = new int[V];
				for (int j = 0; j < V; j++){
					if (j == i) M[i][j] = 0;
					else M[i][j] = -1;
				}
			}
			r = new int[V];
			for (int i = 0; i < V; i++) r[i] = -1;
		}
		void add(int v1, int v2, int w){
			M[v1][v2] = w;
			E++;
		}
		void Alg_Deigstry(int N){
			r[N] = 0;
			bool *added = new bool[V]; int /*x = -1,*/ y = N;
			for (int i = 0; i < V; i++) added[i] = 0;
			for (int i = 1; i < V; i++){
				int x = -1;
				for (int j = 1; j < V; j++){
					if (!(added[j])){
						if (r[j] == -1) {
							if (M[N][j] != -1){
								r[j] = r[N] + M[N][j]; if (x == -1 && y == N) { x = r[j]; y = j; }
								else{
									if (r[j] < x) { x = r[j]; }
								}
							}
						}
						else {
							if (M[N][j] != -1){
								if(M[N][j] < r[j]) {
									r[j] = r[N] + M[N][j];
									if (x == -1 && y == N) { x = r[j]; y = j; }
									else if (r[j] < x) { x = r[j]; y = j; }
								}
							else { x = r[j]; y = j; }
							}
						}
					}
				}
				N = y; 
				added[N] = true;
			}
			for (int i = 0; i < V; i++) cout << r[i] << " "; cout << endl;
		}
private:
	int V;
	int E;
	int** M;
	int* r;
};

void main(){
	int V, E, N;
	cin >> V >> E;
	Orgraf G(V);
	cin >> N;
	for (int i = 0; i < E; i++){
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		G.add(v1, v2, w);
	}
	G.Alg_Deigstry(N);
	system("pause");
}
