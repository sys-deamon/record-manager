# Record-Manager

## Overview
Record-Manager is a modular C++ CLI application designed to handle data entry, validation, and persistence for various user-defined metrics.

While the core architecture is designed to be domain-agnostic, the current implementation features a fully functional Sleep Tracking Module to demonstrate the system's capabilities in handling temporal data, boolean states, and user notes.

## My Goal
The goal of this project is to build a lightweight, terminal-based database interface that allows users to:
    - Define data structures (currently Sleep Intervals and Daily Logs).
    - Validate input strictly (Date/Time formats, Data types).
    - Persist data to a local SQL database (sqlite).
    - Query and filter records based on dynamic criteria.

## Current Features
The current build implements a specific use-case for tracking sleep health, featuring:
- Custom Validation Engine:
    - IsValidDate: Validates DD-MM-YYYY format, including leap years and day/month limits.
    - IsValidTime: Validates HH:MM (24-hour) format.

- Structured Data Entry:
    - Interval Recording: Tracks precise sleep/wake windows.
    - Daily Logging: Boolean tracking (Yes/No) for habits.

- Safe Input Handling:
    - Buffer cleaning (std::cin.ignore) to prevent skipped inputs.
    - Strict type checking (preventing char input in int fields).

## Technology Used

- Language: C++ (Focus on fundamentals: Pointers, Structs, Enums, Loops).
- Environment: Linux (Developed on Linux Mint).
- Tooling: GCC, GDB, Make.

## Roadmap & Future Goals
I intend to evolve this from a static sleep tracker into a dynamic record manager. Future milestones include:
- Database Integration (Priority):
    - Transitioning from transient memory (structs) to persistent storage using SQLite.
    - Implementing a schema that supports dynamic column definitions.

- Abstraction & Extensibility:
    - Refactoring specific Sleep_Record structs into generic Record objects.
    - Allowing users to define new record types (e.g., "Workout Log", "Budget Entry") without recompiling.

- Reporting Engine:
    - Building a query interface to count records matching specific filters (e.g., WHERE didSleep = 1).

- GUI

#### To do Later
- Use Regex for input validation instead of the current nested if-else approach
- Add operator Overloading for comparing structs and custom datatypes