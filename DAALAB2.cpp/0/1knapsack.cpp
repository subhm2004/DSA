#include <iostream> 
using namespace std; 
int max(int a, int b) { return (a > b) ? a : b; } 
int knapSack(int W, int wt[], int val[], int n) 
{ 
	if (n == 0 || W == 0) 
		return 0; 
	if (wt[n - 1] > W) 
		return knapSack(W, wt, val, n - 1); 
	else
		return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),knapSack(W, wt, val, n - 1)); 
}  
int main() {
    int item, W;
    cout<< "Name: Vanshika Aggrawal"<< endl;
    cout<< "Roll No. 22001003138"<< endl;
    cout<< "Enter the number of items: "<< endl;
    cin>> item;
	int *profit= new int[item];
	int *weight= new int[item]; 
    for(int i=0; i< item; i++){
        cout<< "Enter the profit of "<< i+1<< " item: "<< endl;
        cin>> profit[i];
        cout<< "Enter the weight of "<< i+1<< " item: "<< endl;
        cin>> weight[i];
        cout<< endl;
    }
	int n = sizeof(profit) / sizeof(profit[0]);
	cout << "The maximum value is: "<<knapSack(W, weight, profit, n); 
	return 0; 
} 

