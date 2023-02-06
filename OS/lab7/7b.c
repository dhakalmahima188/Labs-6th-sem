#include <stdio.h>
// Turnaround Time = completion of a process – submission of a process
// Waiting Time = turnaround time – burst time

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main(){
    int NUM = 4;
    int process[] = {1, 2, 3, 4};
    int burst_time[] = {5, 7, 2, 3};
    int priority[] = {1, 6, 4, 5};

    // get the sorted array based on the priority
    for (int i = 0; i < NUM - 1; i++){
        for (int j = 0; j < NUM - i - 1; j++){
            if(priority[j] < priority[j + 1]){
                swap(&process[j], &process[j + 1]);
                swap(&burst_time[j], &burst_time[j + 1]);
                swap(&priority[j], &priority[j + 1]);
            }
        }
    }

    // T stores the starting time of the process
    int t = 0;
    printf("Executing the process in required order\n");
    for (int i = 0; i < NUM; i++){
        printf("P%d is executed from %d to %d\n", process[i], t, t + burst_time[i]);
    }

    printf("\n");
    int wait_time = 0;
    int total_waiting_time = 0;
    int total_TAT_time = 0;
    printf("Process ID\t Burst Time\t Wait Time \t Turn Around Time\n");
    for (int i = 0; i < NUM; i++){
        printf("P%d \t\t\t %d\t\t %d \t\t %d\n", process[i], burst_time[i], wait_time, wait_time + burst_time[i]);
        total_waiting_time += wait_time;
        total_TAT_time += wait_time + burst_time[i];
        wait_time += burst_time[i];
    }

    printf("Average Waiting Time is %f \n", (float)total_waiting_time / (float)NUM);
    printf("Average Turn Around Time is %f \n", (float)total_TAT_time / (float)NUM);

}