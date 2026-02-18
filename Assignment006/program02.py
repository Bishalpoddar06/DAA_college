# Matrix Multiplication using Functions

def input_matrix(rows, cols, matrix_name):
    """
    Input a matrix from user
    
    Args:
        rows: number of rows
        cols: number of columns
        matrix_name: name of the matrix
    
    Returns:
        matrix: 2D list containing the matrix
    """
    matrix = []
    print(f"\nEnter elements for {matrix_name} ({rows}x{cols}):")
    for i in range(rows):
        row = []
        for j in range(cols):
            element = int(input(f"Element [{i+1}][{j+1}]: "))
            row.append(element)
        matrix.append(row)
    return matrix


def print_matrix(matrix, matrix_name):
    """
    Print a matrix in formatted way
    
    Args:
        matrix: 2D list containing the matrix
        matrix_name: name of the matrix
    """
    print(f"\n{matrix_name}:")
    for row in matrix:
        print("  ", end="")
        for element in row:
            print(f"{element:6d}", end=" ")
        print()


def multiply_matrices(matrix1, matrix2):
    """
    Multiply two matrices
    
    Args:
        matrix1: first matrix (m x n)
        matrix2: second matrix (n x p)
    
    Returns:
        result: resultant matrix (m x p)
        None if multiplication not possible
    """
    rows1 = len(matrix1)
    cols1 = len(matrix1[0]) if rows1 > 0 else 0
    rows2 = len(matrix2)
    cols2 = len(matrix2[0]) if rows2 > 0 else 0
    
    # Check if multiplication is possible
    if cols1 != rows2:
        return None
    
    # Initialize result matrix with zeros
    result = [[0 for _ in range(cols2)] for _ in range(rows1)]
    
    # Perform multiplication
    for i in range(rows1):
        for j in range(cols2):
            for k in range(cols1):
                result[i][j] += matrix1[i][k] * matrix2[k][j]
    
    return result


def main():
    print("=" * 60)
    print("Matrix Multiplication")
    print("=" * 60)
    
    # Input dimensions for first matrix
    print("\nFirst Matrix (A):")
    rows1 = int(input("Enter number of rows: "))
    cols1 = int(input("Enter number of columns: "))
    
    # Input dimensions for second matrix
    print("\nSecond Matrix (B):")
    rows2 = int(input("Enter number of rows: "))
    cols2 = int(input("Enter number of columns: "))
    
    # Check if multiplication is possible
    if cols1 != rows2:
        print("\n" + "=" * 60)
        print("ERROR: Matrix multiplication not possible!")
        print(f"Number of columns in A ({cols1}) must equal")
        print(f"number of rows in B ({rows2})")
        print("=" * 60)
        return
    
    # Input matrices
    matrix_a = input_matrix(rows1, cols1, "Matrix A")
    matrix_b = input_matrix(rows2, cols2, "Matrix B")
    
    # Display input matrices
    print("\n" + "=" * 60)
    print("INPUT MATRICES")
    print("=" * 60)
    print_matrix(matrix_a, f"Matrix A ({rows1}x{cols1})")
    print_matrix(matrix_b, f"Matrix B ({rows2}x{cols2})")
    
    # Multiply matrices
    result = multiply_matrices(matrix_a, matrix_b)
    
    # Display result
    print("\n" + "=" * 60)
    print("RESULT")
    print("=" * 60)
    print_matrix(result, f"Matrix A × B ({rows1}x{cols2})")
    print("\n" + "=" * 60)


if __name__ == "__main__":
    main()
    