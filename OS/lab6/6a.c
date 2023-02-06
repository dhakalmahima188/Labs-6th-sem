#include <stdio.h>
#include <unistd.h>

// Turnaround Time = completion of a process – submission of a process
// Waiting Time = turnaround time – burst time

// Function to find the waiting time for all processes
int waitingTime(int proc[], int n, int burst_time[], int wait_time[]){
    wait_time[0] = 0;
    for (int i = 1; i < n; i++){
        wait_time[i] = wait_time[i - 1] + burst_time[i - 1];
    }
    return 0;
}

// calculating the turn around time
int turnAroundTime(int proc[], int n, int burst_time[], int wait_time[], int tat[]){
    for (int i = 0; i < n; i++){
        tat[i] = wait_time[i] + burst_time[i];
    }
    return 0;
}

// calculate the average time
int avgTime(int proc[], int n, int burst_time[]){
    int wait_time[n], tat[n], total_wt = 0, total_tat = 0;
    int i;

    waitingTime(proc, n, burst_time, wait_time);
    turnAroundTime(proc, n, burst_time, wait_time, tat);

    printf("Processes  Burst   Waiting Turn around \n");
    // calculate total waiting time and total turn around time
    for(i = 0; i < n; i++){
        total_wt += wait_time[i];
        total_tat += tat[i];
        printf("%d\t  %d\t\t %d \t%d\n", i+1, burst_time[i], wait_time[i], tat[i]);
    }

    printf("Average waiting time = %f\n", (float)total_wt / (float)n);
    printf("Average turn around time = %f\n", (float)total_tat / (float)n);
    return 0;
}

int main(){
    int proc[] = {1, 2, 3,4};
    int n = sizeof proc / sizeof proc[0];
    int burst_time[] = {10, 5, 15,20};
    avgTime(proc, n, burst_time);
    return 0;
}
