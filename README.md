.

---

# Event Management System

This is a simple event management system that uses a queue data structure to manage events. The system allows users to:
1. Add events to the queue (enqueue).
2. Remove events from the queue (dequeue).
3. Display all the events currently in the queue.
4. Exit the program.

The system is built in C using a circular queue and dynamic memory management. It includes features for handling event details such as name, description, date, and phone number.

## Features

- **Add Event**: Add an event to the queue, storing details like event name, date, description, and phone number.
- **Remove Event**: Remove the event at the front of the queue and display its details.
- **Display Events**: Display all events currently in the queue, with detailed information (name, description, date, phone number).
- **Queue Resizing**: Dynamically resize the queue if it reaches its capacity.
- **Input Validation**: Handles invalid inputs (non-integer choices, empty queue).

## Requirements

- A C compiler (e.g., GCC, Clang).
- Standard C libraries: `<stdio.h>`, `<stdlib.h>`, `<string.h>`.

## How to Compile and Run

1. **Clone the repository**:

   ```bash
   git clone https://github.com/your-username/event-management-system.git
   cd event-management-system
   ```

2. **Compile the program**:

   If you're using GCC, run the following command:

   ```bash
   gcc -o event_management event_management.c
   ```

3. **Run the program**:

   ```bash
   ./event_management
   ```

## Usage

Once the program is running, you will be prompted with a menu to choose one of the following options:

1. **Add Event (Enqueue)**: Enter the details of an event, including the name, date, description, and phone number.
2. **Remove Event (Dequeue)**: Remove and display the event at the front of the queue.
3. **Display Events**: Show all events currently stored in the queue.
4. **Exit**: Exit the program.

## Example

### Menu:
```
=== EVENT MANAGEMENT SYSTEM ===
1. ADD EVENT (Enqueue)
2. REMOVE EVENT (Dequeue)
3. DISPLAY EVENTS
4. EXIT

Enter your choice:
```

### Add Event Example:
```
Enter event name: Wedding
Enter event date (YYYY-MM-DD): 2024-05-15
Enter event description: A beautiful wedding ceremony.
Enter Your Phone no: 123-456-7890
```

### Display Events Example:
```
CURRENT EVENT IN THE QUEUE:
Event 1: Wedding
  Date: 2024-05-15
  Description: A beautiful wedding ceremony.
  Phone No: 123-456-7890
```

### Remove Event Example:
```
Dequeued Event: Wedding
```

## Code Explanation

- **Queue Implementation**: The queue is implemented using a circular buffer. The `EventQueue` struct stores the events and includes information about the current front, rear, and size of the queue. The queue dynamically resizes when it becomes full.
  
- **Event Details**: Each event is represented by the `Event` struct, which stores information such as name, description, date, and phone number.

- **Dynamic Memory Management**: The program dynamically allocates and reallocates memory for storing events. If the queue becomes full, the program resizes the queue to accommodate more events.

## Contributing

If you want to contribute to the development of this project, feel free to fork the repository, make changes, and submit a pull request. Please ensure that your code adheres to the project's coding style.

## License

This project is open-source and available under the [MIT License](LICENSE).

---

