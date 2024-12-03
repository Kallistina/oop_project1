# "Object-Oriented Programming - Attiki Odos Project

## Introduction

This is a simulator project for the course "Object-Oriented Programming". The task was to simulate the operation of a segment of the **Attiki Odos** highway. This simulation models vehicles passing through various tolls and segments of the highway, taking into account capacity, toll types, and delays.

## How the Program Works

The program takes several parameters from the command line:

- The number of simulation cycles
- The number of segments in the highway
- The maximum number of vehicles that can enter a segment through a toll
- The percentage of vehicles that are in a "ready" state to exit the segment

After receiving these parameters, an instance of `attica` is created with the appropriate arguments. The `operate` method of `attica` is repeatedly called for the number of simulation cycles (N).

## Class Overview

### 1. Vehicle Class

- **Private Members**:
    - `exit_node`: The destination node for the vehicle.
    - `gone`: A boolean indicating if the vehicle is still on the segment.
    - `ready`: A boolean indicating if the vehicle is ready to exit the segment.

- **Functions**:
    - `random()`: Used to generate random vehicles with random exit nodes.
    - Constructor initializes `exit_node`, `gone`, and `ready`.
    - `get_ready()`: Returns the `ready` status.
    - `set_ready()`: Sets the `ready` status.
    - `get_exit_node()`: Returns the `exit_node`.
    - `exit_attica()`: Checks if the vehicle is ready to leave the highway.
    - `time_to_go()`: Marks the vehicle as gone.
    - `is_gone()`: Returns if the vehicle is gone.

### 2. Toll Class

- **Protected Members**:
    - `queue`: A queue holding the vehicles at the toll.
    - `toll_capacity`: The maximum number of vehicles the toll can handle in one cycle.

- **Functions**:
    - `pass_vehicle()`: Simulates a vehicle passing through the toll.
    - `add_vehicle()`: Adds a vehicle to the queue.
    - `is_full()`: Checks if the toll is at maximum capacity.

### 3. Entrance Class

- **Private Members**:
    - `entry_queue`: A queue holding the vehicles entering the segment.
    - `segment_capacity`: The maximum number of vehicles that can enter the segment in one cycle.

- **Functions**:
    - `enter_vehicle()`: Adds a vehicle to the segment.
    - `is_full()`: Checks if the segment has reached its capacity.

### 4. Segment Class

- **Private Members**:
    - `segment_id`: The ID of the segment.
    - `entrances`: The entrances available for vehicles to enter.
    - `tolls`: The tolls where vehicles pay as they pass.

- **Functions**:
    - `add_entrance()`: Adds an entrance to the segment.
    - `add_toll()`: Adds a toll to the segment.
    - `operate()`: Simulates the operation of the segment for one cycle.

### 5. Attica Class

- **Private Members**:
    - `num_segments`: The number of segments in the highway.
    - `segments`: A vector holding all the segments.

- **Functions**:
    - `create_segment()`: Creates a new segment.
    - `operate()`: Runs the simulation for the given number of cycles.

## How to Run

To run the simulation, follow these steps:

1. Compile the program using the provided g++ command.
2. Run the executable:

```bash
./run <num_cycles> <num_segments> <max_vehicles_per_toll> <ready_percentage>
