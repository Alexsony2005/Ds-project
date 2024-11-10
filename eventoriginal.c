#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Event {
    char name[75];
    char description[255];
    char phone[15];
    char date[20];
} Event;

typedef struct EventQueue {
    Event *events;
    int front, rear, size, capacity;
} EventQueue;

void initialQueue(EventQueue *que, int Capacity);

int isFull(EventQueue *que);

void resizeQueue(EventQueue *que);

void enqueue(EventQueue *que, Event e);

Event dequeue(EventQueue *que);

void displayQueue(EventQueue *que);

Event getEventDetails();

int main() {
    EventQueue queue;
    int initialCapacity = 2;
    initialQueue(&queue, initialCapacity);

    int choice;
    Event e;

    while(1) {
        printf("\n=== EVENT MANAGEMENT SYSTEM ===\n");
        printf("1. ADD EVENT (Enqueue)\n");
        printf("2. REMOVE EVENT (Dequeue)\n");
        printf("3. DISPLAY EVENTS\n");
        printf("4. EXIT\n");
        printf("\nEnter your choice: ");


        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("\nINVALID INPUT! Please enter an integer.\n");
            continue;
        }

        switch (choice) {
            case 1:
                e = getEventDetails();
                enqueue(&queue, e);
                printf("\nEvent added to the queue.\n");
                break;
            case 2:
                e = dequeue(&queue);
                break;
            case 3:
                displayQueue(&queue);
                break;
            case 4:
                printf("\nEXITING THE PROGRAM.\n");
                exit(1);
            default:
                printf("INVALID CHOICE! Please try again.\n");
        }

    }


    free(queue.events);
    return 0;
}

void initialQueue(EventQueue *que, int Capacity) {
    que->events = (Event *)malloc(Capacity * sizeof(Event));
    if (!que->events) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    que->front = 0;
    que->rear = -1;
    que->size = 0;
    que->capacity = Capacity;
}

int isFull(EventQueue *que) {
    return que->size == que->capacity;
}

int isEmpty(EventQueue *que) {
    return que->size == 0;
}

void resizeQueue(EventQueue *que) {
    que->capacity *= 2;
    que->events = (Event *)realloc(que->events, que->capacity * sizeof(Event));
    if (!que->events) {
        printf("Memory reallocation failed!\n");
        exit(1);
    }

}

void enqueue(EventQueue *que, Event e) {
    if (isFull(que)) {
        resizeQueue(que);
    }
    que->rear = (que->rear + 1) % que->capacity;
    que->events[que->rear] = e;
    que->size++;
}

Event dequeue(EventQueue *que) {
    if (isEmpty(que)) {
        printf("\nQUEUE IS EMPTY! Cannot dequeue.\n");
        Event emptyEvent = {"", "", "", ""};
        return emptyEvent;

        }
    Event e = que->events[que->front];
    printf("Dequeued Event: %s\n", e.name);
    que->front = (que->front + 1) % que->capacity;
    que->size--;
    return e;
}

void displayQueue(EventQueue *que) {
    if (isEmpty(que)) {
        printf("\nQUEUE IS EMPTY! No events to display.\n");
        return;
    }
    printf("\nCURRENT EVENT IN THE QUEUE:\n");
    int i = que->front;
    for (int count = 0; count < que->size; count++) {
        printf("Event %d: %s\n", count + 1, que->events[i].name);
        printf("  Date: %s\n", que->events[i].date);
        printf("  Description: %s\n", que->events[i].description);
        printf("  Phone No: %s\n\n", que->events[i].phone);
        i = (i + 1) % que->capacity;
    }
}

Event getEventDetails() {
    Event e;
    printf("Enter event name: ");
    getchar();
    fgets(e.name, sizeof(e.name), stdin);
    for (int i = 0; i < strlen(e.name); i++) {
        if (e.name[i] == '\n') {
            e.name[i] = '\0';
        }
    }


    printf("Enter event date (YYYY-MM-DD): ");
    fgets(e.date, sizeof(e.date), stdin);
    for (int i = 0; i < strlen(e.date); i++) {
        if (e.date[i] == '\n') {
            e.date[i] = '\0';
        }
    }

    printf("Enter event description: ");
    fgets(e.description, sizeof(e.description), stdin);
    for (int i = 0; i < strlen(e.description); i++) {
        if (e.description[i] == '\n') {
            e.description[i] = '\0';
        }
    }
    printf("Enter Your Phone no: ");
    fgets(e.phone, sizeof(e.phone), stdin);
    for (int i = 0; i < strlen(e.phone); i++) {
        if (e.phone[i] == '\n') {
            e.phone[i] = '\0';
        }
    }

    return e;
}
