#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class EmployeeNode {
public:
    string name;
    vector<EmployeeNode*> subordinates;
    EmployeeNode* parent;

    EmployeeNode(const string& name) : name(name), parent(nullptr) {}
};

class Company {
private:
    EmployeeNode* ceo;
    unordered_map<string, EmployeeNode*> employees; // Map to store employees by name

public:
    // Constructor to initialize the company with the CEO
    Company(const string& ceo_name) {
        ceo = new EmployeeNode(ceo_name);
        employees[ceo_name] = ceo;
    }

    // Hire a new employee under a manager
    void hire(const string& manager_name, const string& new_employee_name) {
        EmployeeNode* manager = employees[manager_name];
        if (manager) {
            EmployeeNode* new_employee = new EmployeeNode(new_employee_name);
            new_employee->parent = manager;
            manager->subordinates.push_back(new_employee);
            employees[new_employee_name] = new_employee;
        } else {
            cout << "Error: Manager " << manager_name << " not found." << endl;
        }
    }

    // Fire an employee and promote their highest-ranking subordinate if any
    void fire(const string& employee_name) {
        EmployeeNode* employee = employees[employee_name];
        if (!employee) {
            cout << "Error: Employee " << employee_name << " not found." << endl;
            return;
        }

        // Check if the employee to be fired is the CEO
        if (employee == ceo) {
            if (employee->subordinates.empty()) {
                cout << "Error: CEO " << employee_name << " has no subordinates and cannot be fired." << endl;
                return;
            }

            // Promote the first subordinate to be the new CEO
            ceo = employee->subordinates.front();
            ceo->parent = nullptr;

            // Transfer other subordinates to the new CEO
            ceo->subordinates.insert(ceo->subordinates.end(),
                                     employee->subordinates.begin() + 1,
                                     employee->subordinates.end());

            // Update the parent pointers for all new subordinates under the new CEO
            for (auto& sub : ceo->subordinates) {
                sub->parent = ceo;
            }

            // Remove the old CEO from the company's records
            employees.erase(employee_name);
            delete employee; // Free memory
            return;
        }

        // If the employee is not the CEO, proceed with the usual firing process
        EmployeeNode* parent = employee->parent;
        if (!parent) return; // Safety check, should not happen as we handle CEO above

        if (!employee->subordinates.empty()) {
            // Promote the first subordinate
            EmployeeNode* promoted = employee->subordinates.front();
            promoted->parent = parent;

            // Replace the fired employee in the parent's subordinates list with the promoted one
            auto& siblings = parent->subordinates;
            replace(siblings.begin(), siblings.end(), employee, promoted);

            // Move the remaining subordinates under the promoted employee
            promoted->subordinates.insert(promoted->subordinates.end(),
                                          employee->subordinates.begin() + 1,
                                          employee->subordinates.end());

            // Update the parent pointers for all subordinates now under the promoted employee
            for (auto& sub : promoted->subordinates) {
                sub->parent = promoted;
            }
        } else {
            // If the employee has no subordinates, just remove them from the parent
            parent->subordinates.erase(remove(parent->subordinates.begin(),
                                              parent->subordinates.end(),
                                              employee),
                                       parent->subordinates.end());
        }

        // Remove the employee from the company's records
        employees.erase(employee_name);
        delete employee; // Free memory
    }

    // Print the current company structure in the specified format
    void print_structure() const {
        print_helper(ceo, 0);
        cout << string(60, '-') << endl;
    }

private:
    // Helper function for recursive printing
    void print_helper(EmployeeNode* employee, int level) const {
        if (!employee) return;

        cout << string(level, '+') << employee->name << endl;
        for (EmployeeNode* sub : employee->subordinates) {
            print_helper(sub, level + 1);
        }
    }
};

int main() {
    string ceo_name;
    getline(cin, ceo_name);  // Read the CEO's name
    Company company(ceo_name);

    string command;
    while (getline(cin, command)) {
        if (command == "end") {
            break;
        } else if (command == "print") {
            company.print_structure();
        } else if (command.find("fire ") == 0) {
            string employee_name = command.substr(5);
            company.fire(employee_name);
        } else {
            size_t pos = command.find(" hires ");
            if (pos != string::npos) {
                string manager_name = command.substr(0, pos);
                string new_employee_name = command.substr(pos + 7);
                company.hire(manager_name, new_employee_name);
            }
        }
    }

    return 0;
}
