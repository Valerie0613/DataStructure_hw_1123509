// hw_1123509
// Valerie_1123509_2024/11/27
/*
    Here's a more concise explanation of the logic and flow:

    1. Task Structure:
       - Defines a `Task` with `name` and `priority`.
       - Overloads `<` operator for max heap behavior in the priority queue.

    2. Main Function:
       - Reads the number of operations (`N`).
       - Uses a priority queue (`pq`) to store tasks with the highest priority at the top.
       - Uses a vector (`results`) to store names of tasks retrieved by `GET` operations.

    3. Processing Operations:
       - ADD: Reads task name and priority, then adds the task to the priority queue.
       - GET: Retrieves and removes the highest priority task from the queue, storing its name in `results`.

    4. Output:
       - Prints the names of tasks retrieved by `GET` operations.
       - Transfers remaining tasks from the priority queue to a vector and prints them in priority order.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// Structure representing a task, including task name and priority
struct Task {
    string name;
    int priority;

    // Constructor to initialize the task
    Task(string n, int p) : name(n), priority(p) {}

    // Overload < operator to define a max heap based on priority
    bool operator<(const Task& other) const {
        return priority < other.priority;  // Max heap
    }
};

int main()
{
    int N;  // Number of operations
    cin >> N;

    priority_queue<Task> pq;  // Max heap to store tasks
    vector<string> results;  // Store the result of each GET operation

    for (int i = 0; i < N; ++i)
    {
        string operation;
        cin >> operation;

        if (operation == "ADD")
        {
            string task_name;
            int priority;
            cin >> task_name >> priority;
            pq.push(Task(task_name, priority));  // Add task to priority queue
        }
        else if (operation == "GET")
        {
            if (!pq.empty())
            {
                Task highest_priority_task = pq.top();  // Get the task with the highest priority
                results.push_back(highest_priority_task.name);  // Save the result of the GET operation
                pq.pop();  // Remove the task with the highest priority
            }
        }
    }

    // Output the results of all GET operations
    for (const auto& task : results)
    {
        cout << task << endl;
    }

    // Store the remaining tasks in a vector
    vector<Task> remaining_tasks;
    while (!pq.empty())
    {
        remaining_tasks.push_back(pq.top());
        pq.pop();
    }

    // Display the names and priorities of remaining tasks, sorted by priority from high to low
    cout << "Remaining tasks: [";
    for (size_t i = 0; i < remaining_tasks.size(); ++i)
    {
        cout << "('" << remaining_tasks[i].name << "', " << remaining_tasks[i].priority << ")";
        if (i != remaining_tasks.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
