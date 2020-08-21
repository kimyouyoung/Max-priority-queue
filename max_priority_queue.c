// This assignment was conducted on repl.it

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int key;
    char name[20];
} Queue;

void insert(Queue *q, int N){

    printf("Enter name of element: ");
    scanf(" %[^\n]s",q[N].name);

    while(1){
        printf("Enter key value of element: ");
        scanf("%d", &(q[N].key));

        // The key value ranges from 1 to 10. If it falls within range, it exits the loop.
        if(q[N].key > 0 && q[N].key <= 10)
            break;
        // else Keep going around the loop.
        printf("The key ranges from 1 to 10. Try again.\n");
    }
    

    printf("New element [%s, %d] is inseted.\n", q[N].name, q[N].key);
}

void print(Queue *q, int N){

    // Print the content that says nothing on the queue.
    if(N == 0){
        printf("Empty!\n");
        return;
    }

    // Print everything in the queue array.
    for(int i = 1; i <= N; i++)
        printf("[%s, %d] ", q[i].name, q[i].key);
    printf("\n");
}

int comp(Queue *q, int i, int j){
    // If index=i is less than index=j, return true(1).
    if(q[i].key < q[j].key)
        return 1;
    // else return false(0).
    else
        return 0;
}

void swap(Queue *q, int i, int j){
    // Switch index=i and index=j.
    Queue temp = q[i];
	q[i] = q[j];
	q[j] = temp;
}

void sink(Queue *q, int i, int N){
    
    while(2*i <= N){
        // j = i's child
		int j = 2*i;
        // j < j+1 => j++
		if(j < N && comp(q, j, j+1)) j++;
		if(!comp(q, i, j)) break;
		swap(q, i, j);
        // parent = child
		i = j;
	}

}

void sort(Queue *q, int N){

    for(int i = N/2; i >= 1; i--)
		sink(q, i, N);

}

void delete(Queue *q, int N){
    printf("[%s, %d] is deleted.\n", q[1].name, q[1].key);

    // If q[2].key and q[3].key are the same, the order entered should be maintained.
    if(q[2].key == q[3].key){
        for(int i = 1 ; i < N; i++){
            q[i] = q[i+1];
        }
        return;
    }

    q[1] = q[N];
}

void retrieve(Queue *q){
    printf("[%s, %d]\n", q[1].name, q[1].key);
}

void increase(Queue *q, int N){
    int index;
    int new_key;

    while(1){
        printf("Enter index of element: ");
        scanf("%d", &index);
        if(index > 0 && index <= N)
            break;
        printf("Out of range. Please try again.\nThe range is from 1 to %d.\n", N-1);
    }

    printf("Enter new key value: ");
    scanf("%d", &new_key);

    // Change the key value of the index to a new value.
    q[index].key = new_key;
}

int main(){

    Queue q[30];
    int N = 0;
    char c;

    while(1){
        // N should not be smaller than 0.
        if(N < 0) N = 0;
        // The maximum value of N is 30.
        else if(N > 30){
            printf("You have exceeded the limit.\n");
            break;
        }
        
        // Declares the menu.
        printf("\n********* MENU *********\n");
        printf("I : Insert new element into queue.\n");
        printf("D : Delete element with largest key from queue.\n");
        printf("R : Retrieve element with largest key from queue.\n");
        printf("K : Increase key of element in queue.\n");
        printf("P : Print out all elements in queue.\n");
        printf("Q : Quit\n\n");

        printf("Choose menu: ");
        scanf(" %c", &c);

        // If lowercase letters, change to uppercase.
        if(c >= 'a' && c <= 'z')
            c = c - 32;

        // When you receive Q, shut down the program.
        if(c == 'Q')
            break;

        switch(c){
            case 'I': 
                insert(q, ++N);
                sort(q, N);
                break;
            case 'D':
                if(N <= 0){
                    printf("Queue is empty!\n");
                }else{
                    delete(q, N--);
                    sort(q, N);
                }
                break;
            case 'R':
                if(N <= 0)
                    printf("Queue is empty!\n");
                else
                    retrieve(q);
                break;
            case 'K':
                increase(q, N);
                sort(q, N);
                break;
            case 'P':
                print(q, N);
                break;
            // If you receive an option that is not on the menu, you will be re-entered.
            default : 
                printf("It does not exist in the menu. Please try again.\n");
                break;
        }
    }

    printf("Thank you. Bye!\n\n");

    return 0;
}