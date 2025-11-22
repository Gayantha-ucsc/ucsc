# 3D Board Game - Complete Code Documentation

## Overview

This is a C implementation of a 3D board game where players navigate through multiple floors to capture a flag. The game features a complex system with movement mechanics, status effects, obstacles, and special transportation elements like stairs and poles.

## Game Mechanics

### Core Concepts
- **3D Grid**: 3 floors × 10 width × 25 length (750 total cells)
- **Players**: 3 players (A, B, C) with different starting positions and directions
- **Objective**: First player to capture the flag wins
- **Movement**: Dice-based movement with direction changes every 4 rolls
- **Energy System**: Movement points consumed/gained based on cell properties

### Game Areas
- **Starting Area ('O')**: Floor 0, safe zones for each player
- **Normal Blocks ('X')**: Regular playable areas
- **Bridge ('B')**: Floor 1 connections
- **Canteen ('C')**: Special effect area that affects players
- **Void ('V')**: Impassable areas

## File Structure

### Core Files
- `main.c` - Entry point
- `game.c/h` - Main game loop and pathfinding
- `globals.c/h` - Global variables and configuration
- `structs.h` - Data structure definitions

### Game Logic Modules
- `player.c/h` - Player movement and mechanics
- `canteen.c/h` - Status effects and canteen mechanics
- `stairs.c/h` - Stair transportation system
- `poles.c/h` - Pole transportation system
- `initgame.c/h` - Game initialization and validation

### Support Systems
- `message.c/h` - Game event messaging system
- `linked_List.c/h` - Dynamic data structures
- `utilities.c/h` - Helper functions and utilities
- `test.c/h` - Debug and visualization tools

## Data Structures

### Core Structures

```c
typedef struct {
    int floor, width, length;
} Position;

typedef struct {
    int value;
    char type; // '-' (subtract), '+' (add), '*' (multiply)
} Energy;

typedef struct Cell {
    int floor, width, length;
    Energy energy;
    char effect;    // 'O'=none, 'P'=poison, 'D'=disoriented, 'T'=triggered, 'H'=happy
    char type;      // 'O'=start, 'X'=normal, 'B'=bridge, 'C'=canteen, 'V'=void
    char object;    // 'O'=none, 'W'=wall, 'P'=pole, 'S'=stair, 'F'=flag
    Bool is_Visited; // For pathfinding
    struct Cell* neighbours[4];   // N, W, S, E connections
    struct Cell* stairs[2];       // Stair connections
    struct Cell* pole;            // Pole connection
    struct Cell* teleport_Target[3]; // Special teleportation targets
} Cell;

typedef struct {
    Position position, start_Position;
    int roll, movement_Points, effect_Duration;
    char name, effect, direction;
} Player;
```

### Transportation Structures

```c
typedef struct {
    int starting_Floor, ending_Floor;
    int width, length;
} Pole;

typedef struct {
    int starting_Floor, starting_Width, starting_Length;
    int ending_Floor, ending_Width, ending_Length;
    int direction; // 0=down, 1=up, 2=bidirectional
} Stair;
```

## Game Configuration

### Input Files
- `seed.txt` - Random number generator seed
- `flag.txt` - Flag position `[floor,width,length]`
- `walls.txt` - Wall definitions `[floor,start_width,start_length,end_width,end_length]`
- `stairs.txt` - Stair definitions `[start_floor,start_width,start_length,end_floor,end_width,end_length]`
- `poles.txt` - Pole definitions `[start_floor,end_floor,width,length]`

### Configuration Constants
```c
#define NUMBER_OF_PLAYERS 3
#define NUMBER_OF_FLOORS 3
#define WIDTH_OF_A_FLOOR 10
#define LENGTH_OF_A_FLOOR 25
```

## Key Game Systems

### Movement System
1. **Dice Roll**: 1-6 movement points
2. **Direction Changes**: Every 4th roll triggers direction dice
3. **Movement Points**: Consumed based on cell energy properties
4. **Blocking**: Walls, void areas, and board boundaries block movement
5. **Status Effects**: 
   - Triggered players move double distance
   - Disoriented players change direction randomly
   - Poisoned players skip turns

### Status Effects (Canteen System)
- **Poison ('P')**: Skip 3 turns, then teleport to canteen
- **Disoriented ('D')**: Random direction changes for 4 turns, +50 movement points
- **Triggered ('T')**: Double movement for 4 turns, +50 movement points  
- **Happy ('H')**: +200 movement points, immediate exit
- **Clear ('O')**: Random movement points (10-100), immediate exit

### Transportation Systems
- **Stairs**: Connect different floors, direction changes every 5 rounds
- **Poles**: Slide down to lower floors instantly
- **Teleportation**: Canteen and starting area have special teleport rules

### Pathfinding
- Uses depth-first search to verify game is winnable
- Checks all players can reach the flag from their positions
- Prevents infinite loops and validates game state

## Message System

The game uses a sophisticated messaging system with function pointers to handle different event types:

```c
typedef struct MessageData {
    Player player_Before_Movement, player_After_Movement;
    int dice_Roll, number_Of_Cells_Moved;
    Pole* is_Pole_Used;
    Stair* is_Stair_Used;
    void (*messageFunction)(const struct MessageData* const);
} MessageData;
```

### Message Types
- Movement messages (normal, blocked, direction change)
- Status effect messages (poison, disoriented, triggered, happy)
- Transportation messages (stairs, poles)
- Game events (flag capture, infinite loops)

## Validation System

### Input Validation
- **Walls**: Cannot be in canteen, starting areas, or void
- **Stairs**: Must connect different floors, cannot be in walls/void
- **Poles**: Must go downward, cannot start from floor 0
- **Flag**: Cannot be in void, starting area, canteen, or walls

### Game State Validation
- **Pathfinding**: Ensures all players can potentially win
- **Loop Detection**: Prevents infinite movement cycles
- **Boundary Checking**: Prevents out-of-bounds movement

## Debug and Testing Features

### Debug Modes
- `DEBUG_MODE`: Enable comprehensive debugging
- `DEBUG_SIMULATE_GAME`: Auto-play with visualization
- `DEBUG_PRINT_MESSAGE_DATA`: Detailed message logging

### Visualization
- Color-coded cell display showing different game elements
- Player position tracking
- Object and effect visualization
- Real-time game state display

## Memory Management

- **Dynamic Allocation**: Used for messages, temporary objects
- **Linked Lists**: For flexible data storage during initialization
- **Array Conversion**: Macro for converting lists to arrays
- **Cleanup**: Proper memory deallocation for all dynamic structures

## Error Handling

- **File Operations**: Validates all input files exist and are readable
- **Memory Allocation**: Checks for allocation failures
- **Game Logic**: Validates moves and prevents invalid states
- **Logging**: Comprehensive error logging to `log.txt`

## Compilation and Usage

The game reads configuration files, initializes the board state, validates the setup, and runs the main game loop until a player captures the flag or an error occurs. All game events are logged and can be displayed with various visualization options.

## Key Algorithms

### Movement Algorithm
1. Apply status effects
2. Check if player can exit starting area (requires rolling 6)
3. Move player cell by cell in current direction
4. Handle objects (walls block, stairs/poles transport)
5. Consume/gain movement points
6. Check win condition
7. Handle low movement points (teleport to canteen)

### Pathfinding Algorithm
- Recursive depth-first search
- Marks visited cells to prevent cycles
- Considers all movement options (normal, stairs, poles, teleports)
- Validates game is winnable before starting

This documentation covers the complete codebase structure and game mechanics. The system is highly modular with clear separation of concerns and extensive error handling and validation.
