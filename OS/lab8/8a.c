#include <stdio.h>

int mutex = 0;
int num_full_slot = 0;
int num_empty_slot = 10;
int x = 0;

void producer(){
    // increase the mutex value so that can't interfere 
    ++mutex;
    // increase the number of full slot
    ++num_full_slot;
    // decrease the number of empty slot
    --num_empty_slot;
    
    // Produce Item
    x++;
    printf("\nProducer produces item %d", x);
    
    // signal that the producer has completed the process and no longer requires the processor
    --mutex;
}

void consumer(){
    ++mutex;
    --num_full_slot;
    ++num_empty_slot;
    printf("\nConsumer consumes item %d", x);
    x--;
    --mutex;
}

int main(){
    int choice;
    printf("\n1. Press 1 for Producer"
           "\n2. Press 2 for Consumer"
           "\n3. Press 3 for Exit");
    
    // "critical" specifies that the code is executed by only one thread at a time i.e only one thread enters the critical section at a given time
    #pragma omp critical

    while (1)
    {
        printf("\nEnter your choice :  ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (mutex == 0 && num_empty_slot != 0){
                producer();
            }
            else{
                printf("Buffer is full");
            }
            break;
        case 2:
            if(mutex == 0 && num_full_slot != 0){
                consumer();
            }
            else{
                printf("Buffer is empty");
            }
            break;
        case 3:
            exit(0);
            break;
        default:
            break;
        }
    }
}