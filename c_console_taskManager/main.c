#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 100
#define MAX_DESC_LEN 255

typedef struct {
    int id;
    char title[MAX_TITLE_LEN];
    char description[MAX_DESC_LEN];
    char dueDate[11]; // Format: YYYY-MM-DD
} Task;

void addTask(FILE *file, Task task) {
    fseek(file, 0, SEEK_END);
    fwrite(&task, sizeof(Task), 1, file);
    printf("Task added successfully.\n");
}

void deleteTask(FILE *file, int id) {
    FILE *tempFile = fopen("temp.dat", "wb");
    if (!tempFile) {
        perror("Unable to open temporary file");
        exit(EXIT_FAILURE);
    }

    Task task;
    int found = 0;

    rewind(file);
    while (fread(&task, sizeof(Task), 1, file)) {
        if (task.id == id) {
            found = 1;
            continue;
        }
        fwrite(&task, sizeof(Task), 1, tempFile);
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove("tasks.dat");
        rename("temp.dat", "tasks.dat");
        printf("Task deleted successfully.\n");
    } else {
        remove("temp.dat");
        printf("Task with ID %d not found.\n", id);
    }
}

void viewTasks(FILE *file) {
    Task task;
    rewind(file);
    printf("Task List:\n");
    while (fread(&task, sizeof(Task), 1, file)) {
        printf("ID: %d\nTitle: %s\nDescription: %s\nDue Date: %s\n\n", task.id, task.title, task.description, task.dueDate);
    }
}

void editTask(FILE *file, int id, Task newTask) {
    FILE *tempFile = fopen("temp.dat", "wb");
    if (!tempFile) {
        perror("Unable to open temporary file");
        exit(EXIT_FAILURE);
    }

    Task task;
    int found = 0;

    rewind(file);
    while (fread(&task, sizeof(Task), 1, file)) {
        if (task.id == id) {
            fwrite(&newTask, sizeof(Task), 1, tempFile);
            found = 1;
        } else {
            fwrite(&task, sizeof(Task), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove("tasks.dat");
        rename("temp.dat", "tasks.dat");
        printf("Task updated successfully.\n");
    } else {
        remove("temp.dat");
        printf("Task with ID %d not found.\n", id);
    }
}

int main() {
    FILE *file = fopen("tasks.dat", "rb+");
    if (!file) {
        file = fopen("tasks.dat", "wb+");
        if (!file) {
            perror("Unable to open file");
            return EXIT_FAILURE;
        }
    }

    int choice;
    Task task;
    int id;

    do {
        printf("\nTask Manager\n");
        printf("1. Add Task\n");
        printf("2. Delete Task\n");
        printf("3. View Tasks\n");
        printf("4. Edit Task\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter task ID: ");
                scanf("%d", &task.id);
                getchar(); // Consume newline character
                printf("Enter task title: ");
                fgets(task.title, MAX_TITLE_LEN, stdin);
                task.title[strcspn(task.title, "\n")] = '\0'; // Remove newline character
                printf("Enter task description: ");
                fgets(task.description, MAX_DESC_LEN, stdin);
                task.description[strcspn(task.description, "\n")] = '\0'; // Remove newline character
                printf("Enter task due date (YYYY-MM-DD): ");
                fgets(task.dueDate, sizeof(task.dueDate), stdin);
                task.dueDate[strcspn(task.dueDate, "\n")] = '\0'; // Remove newline character
                addTask(file, task);
                break;

            case 2:
                printf("Enter task ID to delete: ");
                scanf("%d", &id);
                deleteTask(file, id);
                break;

            case 3:
                viewTasks(file);
                break;

            case 4:
                printf("Enter task ID to edit: ");
                scanf("%d", &id);
                getchar(); // Consume newline character
                printf("Enter new task title: ");
                fgets(task.title, MAX_TITLE_LEN, stdin);
                task.title[strcspn(task.title, "\n")] = '\0'; // Remove newline character
                printf("Enter new task description: ");
                fgets(task.description, MAX_DESC_LEN, stdin);
                task.description[strcspn(task.description, "\n")] = '\0'; // Remove newline character
                printf("Enter new task due date (YYYY-MM-DD): ");
                fgets(task.dueDate, sizeof(task.dueDate), stdin);
                task.dueDate[strcspn(task.dueDate, "\n")] = '\0'; // Remove newline character
                task.id = id;
                editTask(file, id, task);
                break;

            case 5:
                fclose(file);
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 5);

    return 0;
}
