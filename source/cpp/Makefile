# Makefile for the Google Alerts Query Generator

# --- Compiler and Flags ---
# CXX: The C++ compiler to use. g++ is a common choice.
# CXXFLAGS: Flags to pass to the compiler.
#   -std=c++20:  MANDATORY for this project, as it uses std::format.
#   -Wall:       Enables all standard warnings (highly recommended).
#   -Wextra:     Enables extra warnings beyond -Wall.
#   -O2:         Optimization level 2 for a release build.
#   -g:          Include debugging symbols (useful for tools like gdb).
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -O2 -g

# --- Project Files ---
# TARGET: The name of the final executable file.
# SRCS:   A list of all your C++ source files.
# OBJS:   Automatically converts the list of .cpp files to .o (object) files.
TARGET = generate_alerts
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

# --- Build Rules ---

# The 'all' rule is the default target.
# Typing 'make' or 'make all' will build the executable.
all: $(TARGET)

# Rule to link the object files into the final executable.
# It depends on all the object files being created first.
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Pattern rule to compile a .cpp source file into a .o object file.
# '$<' is the prerequisite (the .cpp file).
# '$@' is the target (the .o file).
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# --- Utility Rules ---

# The 'clean' rule removes all generated files (executables and object files).
# This is useful for forcing a complete rebuild from scratch.
clean:
	rm -f $(TARGET) $(OBJS)

# The 'run' rule will first build the project (if needed) and then execute it.
run: all
	./$(TARGET)

# --- Phony Targets ---
# Declares targets that are not actual files. This prevents 'make' from
# getting confused if a file named 'clean' or 'run' ever exists.
.PHONY: all clean run

