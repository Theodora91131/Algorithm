#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Items{
	double value,weight;
};
bool comp(Items a, Items b) 
{ 
    return ((double)a.value/a.weight > (double)b.value/b.weight); 
}
double greedy_fractional_k_p(vector<Items> &stuff,double load){
	sort(stuff.begin(),stuff.end(),comp);
	 double packing_stuff = 0.0;
	 double now_load = 0.0;
    for (int i = 0; i < stuff.size(); i++) {
        if (now_load + stuff[i].weight <= load) {
            now_load += stuff[i].weight;
            packing_stuff += stuff[i].value;
            
        }
        else {
        	
            packing_stuff += stuff[i].value * (((double)load - now_load) / (double)stuff[i].weight);
            break;
        }
    }
 	return packing_stuff;
}
int main(){
	Items pack;
	vector<Items>stuff; 
	double load;
	cin >> load && load < 0;
	while(cin>> pack.value >> pack.weight){	 
		stuff.push_back(pack);
		char ch = getchar();
		if(ch == '\n')
			break;
	}
	double packing_stuff = greedy_fractional_k_p(stuff,load);

    printf("%.6f\n",packing_stuff);
    	
	return 0;
	} 
