#include<iostream>
#include<math.h>
using namespace std;

const int MAX = 1000;
const int MIN = -1000;


int minimax(int depth, int nodeIndex, bool chance,
            int utilities[], int alpha, int beta)
{
    // Terminating condition
    if (depth == 3)
        return utilities[nodeIndex];

    if (chance)
    {
        int best = MIN;


        for (int i=0; i<2; i++)
        {
            cout<<depth+1<<"\t"<<nodeIndex*2+i<<"\t"<<"PlayerB"<<"\t"<<alpha<<"\t"<<beta<<"\n";
           int val = minimax(depth+1, nodeIndex*2+i,false, utilities, alpha, beta);

            best = max(best, val);
            alpha = max(alpha, best);

            if (beta <= alpha)
            {
                cout<<"--------Subtree Pruned----------\n";
                 break;
            }

        }
        return best;
    }
    else
    {
        int best = MAX;


        for (int i=0; i<2; i++)
        {
        	cout<<depth+1<<"\t"<<nodeIndex*2+i<<"\t"<<"PlayerA"<<"\t"<<alpha<<"\t"<<beta<<"\n";
            int val = minimax(depth+1, nodeIndex*2+i,true, utilities, alpha, beta);

            best = min(best, val);
            beta = min(beta, best);

            if (beta <= alpha)
            {
                cout<<"--------Subtree Pruned----------\n";
                 break;
            }

        }
        return best;
    }
}

// Driver Code
int main()
{
    int moves;
    cout<<"\nenter the no of total moves by A and B";
    cin>>moves;
    int leaves=pow(2,moves);
    int *utilities=new int[leaves];

    cout<<"\nenter the utility value of "<<pow(2,moves)<<" leaf nodes from left to right \n";

    for(int i=0;i<leaves;i++)
        cin>>utilities[i];

    cout<<"The utility utilities from left to right are\n";
     for(int i=0;i<leaves;i++)
        cout<<utilities[i]<<" ";

        cout<<"\n\n";

    cout<<"The following recursive calls are made with the respective utilities - \n\n";
    cout<<"Depth\tIndex\tMax\tAlpha\tbeta\n";
    cout<<"-------------------------------------------------------\n";
    cout <<"0\t0\tPlayerA\t-1000\t1000\n";
    cout<<"\nThe optimal utility is = "<<minimax(0, 0, true, utilities, MIN, MAX)<<"\n";
    return 0;
}
