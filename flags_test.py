import random
import subprocess

def generate_random_values():
    cflags = "cspdiuxX"
    flags = "#0 -+"
    
    # Choose random values for each component
    cflag = random.choice(cflags)
    flag = random.choice(flags)
    precision = "." + str(random.randint(0, 9)) if random.choice([True, False]) else ""
    f_range = str(random.randint(0, 2147483647)) if random.choice([True, False]) else ""

    # Construct the test string based on the chosen values
    test_string = f"%{flag}{precision}{f_range}{cflag}"

    return test_string

def is_output_valid(output, format_specifier):
    lines = output.strip().split('\n')

    if len(lines) != 5:
        return False

    cflag_line = lines[0]
    flags_line = lines[1]
    range_line = lines[2]
    precision_line = lines[3]
    parsed_flags_line = lines[4]

    # Check validity based on the given parameters for each format specifier
    if format_specifier == "%c":
        return (
            cflag_line == "CFLAG = c" and
            flags_line == "FLAGS = -" and
            range_line.startswith("RANGE =") and
            precision_line == "PRECISION = 0" and
            parsed_flags_line == "PARSED_FLAGS = (null)"
        )

    elif format_specifier == "%s":
        return (
            cflag_line == "CFLAG = s" and
            flags_line == "FLAGS = -" and
            range_line.startswith("RANGE =") and
            precision_line.startswith("PRECISION =") and
            parsed_flags_line.startswith("PARSED_FLAGS =")
        )

    # Add similar checks for other format specifiers

    return False

# Example usage
if __name__ == "__main__":
    try:
        result = subprocess.check_output(["./parse", input_string])
        result_str = result.decode('utf-8') if isinstance(result, bytes) else result

        if is_output_valid(result_str, "%s"):  # Replace with the desired format specifier
            print("Output is valid.")
        else:
            print("Output is not valid.")
            print("Output: ", result_str)
    except subprocess.CalledProcessError as e:
        print(f"Error: {e}")

