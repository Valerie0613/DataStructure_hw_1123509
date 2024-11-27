#hw_1123509
# Valerie_1123509_2024/11/27
'''Explanation:
Task Sorting:

Tasks are sorted by profit in descending order to prioritize high-profit tasks for scheduling.
Finding Maximum Deadline:

The maximum deadline is identified to know how many slots are available for scheduling tasks.
Tracking Slots:

A list tracks available time slots (marked as False for free and True for occupied).
Scheduling Tasks:

For each task, it attempts to find an available slot starting from its deadline and moving backward. If a slot is found, the task is scheduled, and its profit is added.
Result:

The total profit and the list of scheduled tasks are returned.
Key Complex Sections:
Sorting by Profit: Ensures that high-profit tasks are scheduled first.
Slot Assignment: Tasks are scheduled as late as possible within their deadline to maximize available slots for other tasks.
Efficiency: The greedy approach optimizes profit by scheduling tasks while respecting their deadlines.'''


import heapq

def schedule_tasks_with_deadlines(n, tasks):
    # Sort tasks by profit in descending order
    tasks.sort(key=lambda x: x[0], reverse=True)
    
    # Find the maximum deadline to know the total number of slots available
    max_deadline = max(task[1] for task in tasks)
    
    # Create an array to track available slots (0 means available, 1 means occupied)
    slots = [False] * (max_deadline + 1)  # +1 to handle 1-based index for deadlines
    scheduled_tasks = []
    total_profit = 0
    
    for profit, deadline in tasks:
        # Try to find a slot for the current task before or at its deadline
        for slot in range(deadline, 0, -1):  # Check from deadline down to 1
            if not slots[slot]:  # If slot is available
                slots[slot] = True  # Mark the slot as occupied
                scheduled_tasks.append(profit)
                total_profit += profit
                break
    
    return total_profit, scheduled_tasks

# Input
n = int(input())  # Number of tasks
tasks = [tuple(map(int, input().split())) for _ in range(n)]

# Scheduling tasks
max_profit, scheduled_tasks = schedule_tasks_with_deadlines(n, tasks)

# Output
print("Maximum Profit:", max_profit)
print("Scheduled Tasks:", scheduled_tasks)
