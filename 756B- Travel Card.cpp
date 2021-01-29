#include <iostream>

using namespace std; 

//Basic Dynamic Programming

void answer(long long num_trips ,  long long times[]){

long long sum_cost = 0;
long long sum_time = 0;
long long ninty = 1;
long long day = 1;
long long costs[num_trips] ;
costs[0] = 0;
costs[1] = 20;
cout<<costs[1]<<endl;

    for(long long i = 2 ; i<num_trips+1 ; i++){
            while(times[i] - times[ninty] >=90) 
                ninty++;
          
            costs[i] = min(20 + costs[i-1] , costs[ninty - 1] + 50 );

            while(times[i] - times[day] >=1440) 
                day++;
            costs[i] = min(costs[i] , costs[day - 1] + 120);

            
             cout<<costs[i] - costs[i-1]<<endl;

        }       


}


int main()
{
    long long m;
    cin >> m ;
    long long times [m+1];
    long long temp = 0;
    times[0] = 0;
    for (long long i = 1; i < m+1; i++) {
        cin >> temp;
        times[i] = temp;
        /* code */
    }
    answer(m , times);
    

    return 0;
}

