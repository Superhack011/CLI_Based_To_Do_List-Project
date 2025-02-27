#include <vector>
#include<iostream>
#include<string>

class Task {
private:
    std::string title;
    bool completed;
public:
    Task(const std::string& title) : title(title), completed(false) {}

    void markCompleted() { completed = true; }
    bool isCompleted() const { return completed; }
    std::string getTitle() const { return title; }
};


std::vector<Task> tasks;

void displayMenu() {
    std::cout << "1. Add Task\n";
    std::cout << "2. Complete Task\n";
    std::cout << "3. List Tasks\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

void addTask() {
    std::string title;
    std::cout << "Enter task title: ";
    std::cin.ignore();
    std::getline(std::cin, title);
    tasks.push_back(Task(title));
}

void completeTask() {
    int id;
    std::cout << "Enter task ID to mark as completed: ";
    std::cin >> id;
    if (id > 0 && id <= tasks.size()) {
        tasks[id-1].markCompleted();
        std::cout << "Task marked as completed!\n";
    } else {
        std::cout << "Invalid task ID!\n";
    }
}

void listTasks() {
    for (int i = 0; i < tasks.size(); i++) {
        std::cout << (i+1) << ". " << tasks[i].getTitle();
        if (tasks[i].isCompleted()) {
            std::cout << " (Completed)";
        }
        std::cout << "\n";
    }
}

int main() {
    int choice;
    while (true) {
        displayMenu();
        std::cin >> choice;
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                completeTask();
                break;
            case 3:
                listTasks();
                break;
            case 4:
                return 0;
            default:
                std::cout << "Invalid choice! Try again.\n";
        }
    }
}

