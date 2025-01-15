#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
struct Activity {
    int i,s,f;
};
bool comp(Activity a, Activity b) 
{ 
    return (a.f < b.f); 
}
vector<int> greedy_activity_selector(vector<Activity> activities) {
	sort(activities.begin(), activities.end(), comp);
	vector<int> selected_activities;
    selected_activities.push_back(activities[0].i);

    int last_end_time = activities[0].f;
    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].s >= last_end_time) {
            selected_activities.push_back(activities[i].i);
            last_end_time = activities[i].f;
        }
    }

    return selected_activities;
}
int main(){
   vector<Activity> activities;
   Activity act;
    while (cin >> act.i>> act.s >> act.f) {
        activities.push_back(act);
        char ch = getchar();
		if(ch == '\n')
			break;
    }
    vector<int> selected_activities = greedy_activity_selector(activities);
    for (int i = 0; i < selected_activities.size(); i++) {
        cout << selected_activities[i] << " ";
    }
    cout << endl;	
    return 0;
}
