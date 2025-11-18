Optimal Pathfinding Engine on 2D Grid Maps

This repository contains the implementation of a pathfinding engine developed to calculate minimum-cost paths on 2D grid maps under complex movement constraints. The project models a traversal problem where movement is restricted by altitude differences (represented by ASCII values) and optimized through bidirectional teleportation nodes validated by mathematical sequences.

Project Overview

The primary objective of this system is to determine the optimal path from a source to a destination on a weighted grid. The engine addresses several algorithmic challenges:

Altitude-Constrained Traversal: Movement between adjacent cells is restricted based on the difference in their "altitude," defined by the ASCII value of the character in the cell.

Climbing: Allowed if the destination altitude is at most 2 units higher.

Descending: Allowed if the destination altitude is at most 3 units lower.

Teleportation Optimization: The system identifies special "portal" cells that allow instantaneous travel (zero cost) between two points. These portals are dynamically validated using Fibonacci sequence properties.

Global Path Optimization: The engine computes multiple potential routes—direct paths and portal-assisted shortcuts—to derive the absolute minimum distance.

Repository Structure

The solution is modularized into three tasks, each addressing a specific component of the problem:

File

Description

task1.c

Fibonacci Validation Module: Implements the logic to verify if a given number is part of the Fibonacci sequence. This serves as the validation mechanism for unlocking teleportation doors based on their grid coordinates.

task2.c

Multi-Point Distance Calculator: A pathfinding engine that computes shortest paths between multiple key coordinates (Start, End, Portal 1, Portal 2). It assumes portal locations are pre-determined and handles the graph traversal under altitude constraints.

task3.c

Integrated Pathfinding Engine: The complete solution. It parses the raw map data, identifies potential portal candidates by calculating their unique IDs, validates them using the Fibonacci logic, and integrates the pathfinding algorithms to determine the globally optimal path.

Technical Details

Algorithms and Data Structures

Breadth-First Search (BFS) / Flood Fill: A custom implementation of the Flood Fill algorithm is used to traverse the grid. Since the edge weight for a valid move is constant (1 step), BFS guarantees the shortest path from the source.

Custom Queue Implementation: To avoid dependencies on external libraries and ensure low-level memory control, a static array-based queue (queue[MAX_SIZE * MAX_SIZE][3]) is implemented to manage the frontier during graph traversal.

Dynamic Programming: The Fibonacci sequence calculation in task3.c uses memoization (storing computed values in int fib[MAX_SIZE]) to reduce the time complexity of repeated validations for potential door coordinates.

Movement Logic

A move from cell A to an adjacent cell B is valid only if the altitude difference delta_h = Altitude(B) - Altitude(A) satisfies:
-3 <= delta_h <= 2

Teleportation Logic

A cell located at row r and column c on a map of width W is a candidate for a teleportation portal if its calculated ID satisfies specific criteria:
ID = (r * W) + c

The ID must correspond to a Fibonacci number that matches one of the provided "key" values (M1 or M2) in the input dataset.

Compilation and Execution

The project is written in standard C and can be compiled using the GCC compiler.

Prerequisites

GCC (GNU Compiler Collection)

Instructions

Clone the repository:

git clone [https://github.com/tharakadilshandmt/Optimal-Pathfinding-Engine-on-2D-Grid-Maps.git](https://github.com/tharakadilshandmt/Optimal-Pathfinding-Engine-on-2D-Grid-Maps.git)
cd Optimal-Pathfinding-Engine-on-2D-Grid-Maps


Compile a task (e.g., Task 3):

gcc task3.c -o pathfinder


Run the executable:
The program accepts input from standard input (stdin). You can redirect a text file containing the test case data.

./pathfinder < input.txt


Input Format (Task 3)

The input consists of the map dimensions, start/end coordinates, the map string, validation keys, and potential door coordinates.

H W           (Height Width)
S1 S2         (Start Row, Start Col)
E1 E2         (End Row, End Col)
MAP_STRING    (The flattened 2D map string)
M1            (First Fibonacci Key)
M2            (Second Fibonacci Key)
ND            (Number of potential doors)
R1 C1         (Door 1 Coordinates)
R2 C2         (Door 2 Coordinates)
...


Logic Flow (Task 3)

Input Parsing: The system reads the map dimensions, topology, and key coordinates.

Portal Identification: It iterates through the list of potential door coordinates, calculates their unique IDs, and validates them against the provided Fibonacci keys.

Distance Calculation:

Calculates the shortest path from Start to End.

Calculates distances from Start to both identified Portals.

Calculates distances from both Portals to End.

Optimization: The system compares the direct path cost against the cost of using the teleportation mechanism (Start -> Portal_A -> Portal_B -> End).

Result: The minimum of these values is output as the optimal distance.

Developed as part of the Computer Engineering curriculum at the University of Peradeniya (CO222).
