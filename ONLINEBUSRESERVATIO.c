#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

// Passenger structure
typedef struct {
    char name[100];
    int ticket_number;
} Passenger;

// Queue structure for holding passengers
typedef struct {
    Passenger passengers[MAX];
    int front, rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(Queue *q) {
    return (q->rear == MAX - 1);
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return (q->front == -1);
}

// Add passenger to the queue
void enqueue(Queue *q, Passenger p) {
    if (isFull(q)) {
        printf("Reservation system is full. Cannot book more tickets.\n");
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear++;
        q->passengers[q->rear] = p;
        printf("Ticket booked successfully for %s, Ticket Number: %d\n", p.name, p.ticket_number);
    }
