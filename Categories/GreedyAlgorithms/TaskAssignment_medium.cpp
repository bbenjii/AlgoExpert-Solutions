#include <vector>

using namespace std;


struct Task{
    int time;
    int index;
};

void sort(vector<Task> &tasks, vector<Task> &aux, int lo, int hi){
    if( hi <= lo) return;
    int mid = (lo+hi)/2;

    //sort two subarrays
    sort(tasks, aux, lo, mid);
    sort(tasks, aux,mid+1, hi);

    //merge
    //first copy the array
    for (int k = lo; k <= hi; k++){
        aux[k] = tasks[k];
    }
    //pointers to the two sorted subarrays
    int i = lo, j = mid+1;

    //merge
    for(int k = lo; k<= hi; k++){
        if (i > mid) tasks[k] = aux[j++];
        else if (j > hi) tasks[k] = aux[i++];
        else if (aux[j].time < aux[i].time) tasks[k] = aux[j++];
        else tasks[k] = aux[i++];
    }

}

void mergeSort(vector<Task> &tasks) {
    //aux array
    vector<Task> aux(tasks.size());
    sort(tasks, aux, 0, tasks.size()-1);

}


vector<vector<int>> taskAssignment(int k, vector<int> tasks){
    //write your code here

    //sort the tasks by duration
    vector<Task> orderedTasks;
    for(int i = 0; i < tasks.size(); i++){
        Task task;
        task.index = i;
        task.time = tasks[i];
        orderedTasks.push_back(task);
    }

    mergeSort(orderedTasks);

    //pair the longest tasks with the shortest tasks
    vector<vector<int>> assignments;
    for(int i = 0, z = orderedTasks.size()-1; i < z; i++,z--){
        assignments.push_back({orderedTasks[i].index, orderedTasks[z].index});
    }

    return assignments;

}
