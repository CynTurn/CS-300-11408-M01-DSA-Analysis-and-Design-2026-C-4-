/*
 * ProjectTwo.cpp
 *
 *  Created on: Aug 16, 2026
 *      Author: cynthia.turner
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <limits>

using namespace std;

// Stores the information associated with one course.
struct Course {
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;
};

// Represents one node in the binary search tree.
struct Node {
    Course course;
    Node* left;
    Node* right;

    Node(const Course& aCourse) {
        course = aCourse;
        left = nullptr;
        right = nullptr;
    }
};

// Manages course objects using a binary search tree.
class BinarySearchTree {
private:
    Node* root;
    // Performs an in-order traversal to print courses alphabetically.
    void InOrder(Node* node) const {

        if (node == nullptr) {
            return;
        }

        // Visit the left subtree first.
        InOrder(node->left);

        // Print the current course.
        cout << node->course.courseNumber
             << ", "
             << node->course.courseTitle
             << endl;

        // Visit the right subtree last.
        InOrder(node->right);
    }

    // Recursively releases all dynamically allocated tree nodes.
    void DestroyTree(Node* node) {

        if (node == nullptr) {
            return;
        }

        DestroyTree(node->left);
        DestroyTree(node->right);

        delete node;
    }

public:
    // Constructor initializes an empty tree.
    BinarySearchTree() {
        root = nullptr;
    }
    // Destructor releases memory when the tree is no longer needed.
    ~BinarySearchTree() {
        DestroyTree(root);
    }

    // Removes all courses from the tree.
    void Clear() {
        DestroyTree(root);
        root = nullptr;
    }

    // Inserts a course into the binary search tree by course number.
    void Insert(const Course& course) {

        Node* newNode = new Node(course);

        // If the tree is empty, the new node becomes the root.
        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* current = root;

        while (true) {

            // Smaller course numbers belong in the left subtree.
            if (course.courseNumber < current->course.courseNumber) {

                if (current->left == nullptr) {
                    current->left = newNode;
                    return;
                }

                current = current->left;
            }

            // Larger course numbers belong in the right subtree.
            else {

                if (current->right == nullptr) {
                    current->right = newNode;
                    return;
                }

                current = current->right;
            }
        }
    }
    // Searches for a course by course number.
    Course* Search(const string& courseNumber) {

        Node* current = root;

        while (current != nullptr) {

            // Course was found.
            if (courseNumber == current->course.courseNumber) {
                return &(current->course);
            }

            // Search the left subtree for a smaller course number.
            if (courseNumber < current->course.courseNumber) {
                current = current->left;
            }

            // Search the right subtree for a larger course number.
            else {
                current = current->right;
            }
        }

        // nullptr indicates that the course was not found.
        return nullptr;
    }
    // Prints all courses in alphanumeric order.
    void PrintCourseList() const {
        InOrder(root);
    }
};

// Removes leading and trailing whitespace from CSV values.
string Trim(const string& text) {

    size_t first = text.find_first_not_of(" \t\r\n");

    if (first == string::npos) {
        return "";
    }

    size_t last = text.find_last_not_of(" \t\r\n");

    return text.substr(first, last - first + 1);
}


// Loads course data from a CSV file into the binary search tree.
bool LoadCourses(const string& fileName, BinarySearchTree& courseTree) {

    ifstream file(fileName);

    // Verify that the file opened successfully.
    if (!file.is_open()) {
        cout << "Error: Unable to open course file." << endl;
        return false;
    }

    string line;

    // Read the file one record at a time.
    while (getline(file, line)) {

        stringstream ss(line);
        string token;
        vector<string> tokens;

        // Separate each record using commas.
        while (getline(ss, token, ',')) {
            tokens.push_back(Trim(token));
        }

        // Every valid record must contain a course number and title.
        if (tokens.size() < 2 ||
            tokens[0].empty() ||
            tokens[1].empty()) {

            cout << "Error: Invalid course record." << endl;
            file.close();
            return false;
        }

        // Create a course object from the first two fields.
        Course course;
        course.courseNumber = tokens[0];
        course.courseTitle = tokens[1];

        // Any remaining fields represent prerequisites.
        for (size_t i = 2; i < tokens.size(); ++i) {
            if (!tokens[i].empty()) {
                course.prerequisites.push_back(tokens[i]);
            }
        }

        // Store the completed course in the binary search tree.
        courseTree.Insert(course);
    }

    file.close();

    return true;
}


int main() {

    BinarySearchTree courseTree;
    bool dataLoaded = false;
    int choice = 0;

    cout << "Welcome to the course planner." << endl;

    while (choice != 9) {

        cout << endl;
        cout << "1. Load Data Structure." << endl;
        cout << "2. Print Course List." << endl;
        cout << "3. Print Course." << endl;
        cout << "9. Exit" << endl;
        cout << "What would you like to do? ";

        // Validate that the user entered a number.
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a menu number." << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        if (choice == 1) {

            string fileName;

            cout << "Enter the course data file name: ";
            getline(cin >> ws, fileName);

            // Clear previously loaded data before loading a new file.
            courseTree.Clear();

            if (LoadCourses(fileName, courseTree)) {
                dataLoaded = true;
                cout << "Course data loaded successfully." << endl;
            }
            else {
                dataLoaded = false;
            }
        }

        else if (choice == 2) {

            if (!dataLoaded) {
                cout << "Please load the course data first." << endl;
            }
            else {
                cout << "Here is a sample schedule:" << endl;
                courseTree.PrintCourseList();
            }
        }

        else if (choice == 3) {

            if (!dataLoaded) {
                cout << "Please load the course data first." << endl;
            }
            else {
                string courseNumber;

                cout << "What course do you want to know about? ";
                cin >> courseNumber;

                // Convert the user's course number to uppercase
                // so searches are not case-sensitive.
                transform(courseNumber.begin(),
                          courseNumber.end(),
                          courseNumber.begin(),
                          [](unsigned char c) {
                              return static_cast<char>(toupper(c));
                          });

                Course* course = courseTree.Search(courseNumber);

                if (course == nullptr) {
                    cout << "Course not found." << endl;
                }
                else {
                    cout << course->courseNumber
                         << ", "
                         << course->courseTitle
                         << endl;

                    if (course->prerequisites.empty()) {
                        cout << "Prerequisites: None" << endl;
                    }
                    else {
                        cout << "Prerequisites:" << endl;

                        for (const string& prereqNumber : course->prerequisites) {

                            Course* prerequisite =
                                courseTree.Search(prereqNumber);

                            if (prerequisite != nullptr) {
                                cout << prerequisite->courseNumber
                                     << ", "
                                     << prerequisite->courseTitle
                                     << endl;
                            }
                        }
                    }
                }
            }
        }
        else if (choice == 9) {
            cout << "Thank you for using the course planner!" << endl;
        }

        else {
            cout << choice << " is not a valid option." << endl;
        }

    } // End while loop

    return 0;

} // End main



