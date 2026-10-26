# CS-300-DSA-Analysis-and-Design
Coursework and portfolio artifacts for CS 300: Data Structures and Algorithms.

## Portfolio Artifacts

### Project One - Data Structure Analysis

Project One contains my analysis of the run-time performance and memory usage of the Vector, Hash Table, and Binary Search Tree data structures. I compared the advantages and disadvantages of each structure and evaluated which data structure would be most appropriate for the course planner.

### Project Two - Course Planner

Project Two contains my working C++ course planner. The program uses a Binary Search Tree to store course information and an in-order traversal to print the Computer Science course list in alphanumeric order.

## Reflection

### What was the problem you were solving in the projects for this course?

The problem I was solving throughout these projects was determining how course information could be stored, searched, and displayed efficiently in a course-planning program. In Project One, I analyzed different data structures, including a Vector, Hash Table, and Binary Search Tree, and compared their run-time performance, memory usage, advantages, and disadvantages. In Project Two, I applied what I learned by developing a working course planner using a Binary Search Tree. The program loads course information, allows a user to search for a specific course, and prints the complete course list in alphanumeric order.

### How did you approach the problem? Consider why data structures are important to understand.

I approached the problem by first considering what the program needed to accomplish and then comparing how each data structure could support those requirements. I evaluated searching, insertion, sorted output, memory usage, and implementation complexity. This helped me understand that selecting a data structure should be based on how the data will actually be used rather than simply choosing the structure with the fastest performance in one area. Data structures are important because they directly affect how efficiently a program can organize, access, and process information. For this project, the Binary Search Tree provided a good balance because it supported efficient searching while also allowing the courses to be printed in alphanumeric order through an in-order traversal.

### How did you overcome any roadblocks you encountered while going through the activities or project?

One of the challenges I encountered was moving from pseudocode and run-time analysis to a complete working C++ program. Breaking the problem into smaller functions helped me work through this process. I separated responsibilities such as loading the course data, inserting courses into the Binary Search Tree, searching for a course, and printing the course list. I also tested the program's menu options and input handling as I worked. When something did not behave as expected, reviewing one part of the program at a time made it easier to identify where the problem was occurring instead of making multiple changes at once.

### How has your work on this project expanded your approach to designing software and developing programs?

My work in this course expanded my approach to software development by showing me the importance of considering efficiency during the design process. Before implementing a solution, I can compare possible data structures and think about how frequently operations such as searching, inserting, and sorting will occur. I also learned that the fastest structure for one operation is not necessarily the best overall choice. For example, although a Hash Table offers very fast average search performance, the Binary Search Tree was better suited to this project because an in-order traversal naturally produces the required alphanumeric course listing. This experience has encouraged me to connect program requirements with design decisions before writing the final implementation.

### How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?

This project has helped me become more intentional about organizing code so that it is easier to read, test, and modify. Using clearly defined functions and meaningful names makes the purpose of each part of the program easier to understand. Separating tasks such as loading data, searching the tree, printing courses, and managing the user menu also makes the program easier to maintain because changes can be made to one part without unnecessarily affecting the rest of the program. I have also become more aware of documenting the purpose of important sections of code and keeping the program organized so that another developer could understand the logic and adapt it in the future.

## Project Reflection Update

### Briefly summarize the DriverPass project. Who was the client? What type of system did they want you to design?

The client was DriverPass, a company that wanted to help customers prepare for their driving tests through online learning and behind-the-wheel training. They needed a web-based system where customers could create accounts, purchase training packages, take practice tests, and schedule driving lessons. Employees also needed tools to manage appointments, instructors, vehicles, customer information, and reports.

### What did you do particularly well?

I did particularly well at organizing the client’s needs into functional and nonfunctional requirements. I considered both the customer’s experience and the employees’ responsibilities, including scheduling, security, permissions, and recordkeeping. My experience supporting Camstar helped me recognize the importance of clear requirements and understanding how one process affects another.

### If you could choose one part of your work on these documents to revise, what would you pick? How would you improve it?

I would revise the UML diagrams to make their layout and connections easier to follow. Organizing the diagrams was challenging, especially when several actors or decisions were involved. I would improve the spacing, use consistent labels, and make alternate paths clearer, such as what happens when an appointment is unavailable. I would also review the diagrams together to ensure that they consistently represent the same requirements.

### How did you interpret the user’s needs and implement them into your system design? Why is it so important to consider the user’s needs when designing?

I reviewed the DriverPass interview and identified what each user needed to accomplish. I translated those needs into requirements and used UML models to describe the interactions, workflows, and information the system would support. For example, the need to schedule driving lessons led to requirements for checking instructor and vehicle availability and preventing conflicting reservations. Considering user needs is essential because a technically functional system can still fail if it does not support the people and business processes it was created to serve.

### How do you approach designing software? What techniques or strategies would you use in the future to analyze and design a system?

I approach software design by first understanding the business problem, identifying the users, and documenting their needs before choosing a technical solution. I then break larger processes into smaller workflows and use models to examine how the parts connect. In future projects, I would continue using stakeholder interviews, use cases, UML diagrams, and iterative reviews. I would also connect each requirement to its design elements and planned tests so that I can verify that the proposed solution addresses the original need.
