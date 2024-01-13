# 3D to 2D Transformation

## Transformation Rules

(1,0,0) → (a,b)
(0,1,0) → (c,d)
(0,0,1) → (e,f)

## Generalized Formula

The generalized formula for the transformation is:

(x,y,z)→ (a⋅x + c⋅y + e⋅z, b⋅x + d⋅y + f⋅z)

This formula represents the transformation from 3D coordinates to 2D coordinates based on the given rules.


This formula represents the transformation from 3D coordinates to 2D coordinates based on the given rules.

## FdF Project

This project involves a 3D to 2D transformation implemented in C using the rules mentioned above. The code is organized into different source files, and the project structure is managed using a Makefile.

### Build Instructions

To build the project, you can use the provided Makefile. Here are the basic commands:

- `make`: Build the main executable.
- `make bonus`: Build a bonus executable with additional features.
- `make clean`: Remove object files.
- `make fclean`: Remove object files and executables.
- `make re`: Recompile the project.

### Running the Project

To run the main executable, use the following command:

```bash
./fdf [FILE/PATH.fdf]
```
```make bonus
./bonus_fdf [FILE/PATH.fdf]
