#include <iostream>
#include <cmath> // Include the cmath header for the sqrt function
using namespace std;

// Enumeration for menu choices
enum CHOICE {
    SQUARE = 1, RECTANGLE, TRIANGLE, ISOSCELES_TRIANGLE, EXIT
};

// Function prototypes
void print_menu();
void print_square(int size);
void print_rectangle(int width, int height);
void print_triangle(int size);
void print_isosceles_triangle(int size);
int calc_square(int size);
int calc_rect(int width, int height);
int calc_tri(int base, int height);
int calc_isosceles_tri(int base, int height);

int main() {
    CHOICE choice;

    // Main menu loop
    do {
        print_menu();
        cout << "your choice: ";
        cin >> (int&)choice;

        int width, height, size;

        // Switch based on the user's choice
        switch (choice) {
        case SQUARE:
            cout << "enter size: ";
            cin >> size;
            print_square(size);
            cout << "Perimeter: " << calc_square(size) << endl;
            break;
        case RECTANGLE:
            cout << "enter width: ";
            cin >> width;
            cout << "enter height: ";
            cin >> height;
            print_rectangle(width, height);
            cout << "Perimeter: " << calc_rect(width, height) << endl;
            break;
        case TRIANGLE:
            cout << "enter base: ";
            cin >> width;
            cout << "enter height: ";
            cin >> height;
            print_triangle(width);
            cout << "Perimeter: " << calc_tri(width, height) << endl;
            break;
        case ISOSCELES_TRIANGLE:
            cout << "enter base: ";
            cin >> width;
            cout << "enter height: ";
            cin >> height;
            print_isosceles_triangle(width);
            cout << "Perimeter: " << calc_isosceles_tri(width, height) << endl;
            break;
        case EXIT:
            break;
        default:
            break;
        }
    } while (choice != EXIT);

    return 0;
}

// Function to print the menu
void print_menu() {
    cout << "------------" << endl;
    cout << "menu" << endl;
    cout << "--------------" << endl;
    cout << "1. square" << endl;
    cout << "2. rectangle" << endl;
    cout << "3. triangle" << endl;
    cout << "4. isosceles triangle" << endl;
    cout << "5. exit" << endl;
}

// Function to print a square
void print_square(int size) {
    print_rectangle(size, size);
}

// Function to print a rectangle
void print_rectangle(int width, int height) {
    for (int row = 0; row < height; ++row, cout << endl)
        for (int col = 0; col < width; ++col)
            cout << "* ";
}

// Function to print a right-angled triangle
void print_triangle(int size) {
    for (int row = 0; row < size; ++row, cout << endl)
        for (int col = 0; col <= row; ++col)
            cout << "* ";
}


// Function to print an isosceles triangle
void print_isosceles_triangle(int size) {
    for (int row = 0; row < size; ++row, cout << endl) {
        // Print leading spaces
        for (int space = 0; space < size - row - 1; ++space)
            cout << " ";

        // Print asterisks
        for (int col = 0; col < 2 * row + 1; ++col)
            cout << "*";
    }
}


// Function to calculate the perimeter of a square
int calc_square(int size) {
    return 4 * size;
}

// Function to calculate the perimeter of a rectangle
int calc_rect(int width, int height) {
    return 2 * (width + height);
}

// Function to calculate the perimeter of a right-angled triangle
int calc_tri(int base, int height) {
    // Assuming you want the perimeter, you need to sum up all three sides
    // Since you are dealing with a right-angled triangle, you can use the Pythagorean theorem
    int hypotenuse = sqrt(base * base + height * height);
    return base + height + hypotenuse;
}

// Function to calculate the perimeter of an isosceles triangle
int calc_isosceles_tri(int base, int height) {
    // Assuming the isosceles triangle has two equal sides and a base
    int side = sqrt(height * height + (base / 2) * (base / 2));
    return 2 * side + base;
}
