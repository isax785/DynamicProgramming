import subprocess
import os

# OUTPUT_EXECUTABLE = "a.out"
OUTPUT_EXECUTABLE = "a.exe"

def compile_and_run_cpp(cpp_filepath, output_executable=OUTPUT_EXECUTABLE):
    """
    Compiles a C++ file and then runs the resulting executable.
    - cpp_file (str): Path to the C++ source file.
    - output_executable (str): Name of the executable to create.
    """
    compile_cpp(cpp_filepath, output_executable)
    run_cpp_executable(output_executable)


def compile_cpp(cpp_filepath, output_executable=OUTPUT_EXECUTABLE):
    """
    Compiles a C++ file
    - cpp_file (str): Path to the C++ source file.
    - output_executable (str): Name of the executable to create.
    """
    # 1. Compile the C++ code
    compile_command = ["g++", cpp_filepath, "-o", output_executable]
    print(f"Compiling: {' '.join(compile_command)}")
    try:
        compile_result = subprocess.run(compile_command, capture_output=True, text=True, check=True)
        print("Compilation successful!")
        if compile_result.stdout:
            print("Compiler Output (stdout):\n", compile_result.stdout)
        if compile_result.stderr:
            print("Compiler Output (stderr):\n", compile_result.stderr)
    except subprocess.CalledProcessError as e:
        print(f"Compilation failed with error code {e.returncode}")
        print("Compiler Error (stdout):\n", e.stdout)
        print("Compiler Error (stderr):\n", e.stderr)
        return

def run_cpp_executable(output_executable=OUTPUT_EXECUTABLE):
    """
    Runs a compiled C++ executable.
    - output_executable (str): Name of the executable.
    """
    run_command = [f"./{output_executable}"]
    print(f"\nRunning: {' '.join(run_command)}")
    try:
        run_result = subprocess.run(run_command, 
                                    capture_output=True, 
                                    text=True, 
                                    check=True)
        print("Execution successful! Program Output (stdout):\n", run_result.stdout)
        if run_result.stderr:
            print("Program Output (stderr):\n", run_result.stderr)
    except subprocess.CalledProcessError as e:
        print(f"Execution failed with error code {e.returncode}")
        print("Program Error (stdout):\n", e.stdout)
        print("Program Error (stderr):\n", e.stderr)
    finally:
        # Clean up the created executable (optional)
        if os.path.exists(output_executable):
            # os.remove(output_executable)
            print(f"\nExecutable '{output_executable}' kept for inspection.") # Or uncomment os.remove if you want to delete it
        pass
    return run_result
