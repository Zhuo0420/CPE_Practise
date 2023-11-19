#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
	int n;
	while (cin >> n) {
		int input;
		int com;
		queue<int> lineQ;
		stack<int> lineS;
		priority_queue<int> linePQ;
		bool Q = 1, S = 1, PQ = 1;
		while (n--) {
			cin >> com >> input;
			if (com == 1) {				
				lineQ.emplace(input);
				lineS.emplace(input);
				linePQ.emplace(input);
			}
			else{
				int tmpQ, tmpS, tmpPQ;
				if (!lineQ.empty())	tmpQ = lineQ.front();
				if (!lineS.empty())	tmpS = lineS.top();
				if (!linePQ.empty())	tmpPQ = linePQ.top();					
				if (Q) {
					if (!lineQ.empty() && input == tmpQ)		lineQ.pop();
					else	Q = false;
				}				
				if (S) {
					if (!lineS.empty() && input == tmpS)		lineS.pop();
					else	S = false;
				}
				if (PQ) {
					if (!linePQ.empty() && input == tmpPQ)		linePQ.pop();
					else	PQ = false;	
				}
				
			}
		}
		if (Q && !S && !PQ)			cout << "queue" << endl;
		else if (!Q && S && !PQ)	cout << "stack" << endl;
		else if (!Q && !S && PQ)	cout << "priority queue" << endl;
		else if (!Q && !S && !PQ)	cout << "impossible" << endl;
		else	cout << "not sure" << endl;
	}
	return 0;
}
