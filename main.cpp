// Chris Cooper
// CSCI 441 
// Lab 00

// include headers
#include <iostream>
#include <string>


//namespace
using namespace std;

// function prototypes
class Vector3 {
public:
    float x;
    float y;
    float z;

    //default constructor
    Vector3() {
        x = 0;
        y = 0;
        z = 0;
        std::cout << "in Vector3 default constructor" << std::endl;
    }
    // Parameterized Constructor (perhaps make default 0,0,0)
    Vector3(float xx, float yy, float zz) : x(xx), y(yy), z(zz) {
        // nothing to do here as we've already initialized x, y, and z above
        std::cout << "in Vector3 parameterized constructor" << std::endl;
    }

    // Destructor - called when an object goes out of scope or is destroyed
    ~Vector3() {
        // this is where you would release resources such as memory or file descriptors
        // in this case we don't need to do anything
        std::cout << "in Vector3 destructor" << std::endl;
    }
};

Vector3 add(const Vector3& v, const Vector3& v2) { // v and v2 are copies, so any changes to them in this function won't affect the originals
    float new_x;
    float new_y;
    float new_z;
    new_x = (v.x + v2.x);
    new_y = (v.y + v2.y);
    new_z = (v.z + v2.z);
    return Vector3(new_x, new_y, new_z);
}
Vector3 operator+(const Vector3& v, const Vector3& v2){
    float new_x;
    float new_y;
    float new_z;
    new_x = (v.x + v2.x);
    new_y = (v.y + v2.y);
    new_z = (v.z + v2.z);
    return Vector3(new_x, new_y, new_z);
}

Vector3 operator*(float s, const Vector3& v) {
    float new_x;
    float new_y;
    float new_z;
    new_x = (v.x + s);
    new_y = (v.y + s);
    new_z = (v.z + s);
    return Vector3(new_x, new_y, new_z);
}

Vector3 operator*(const Vector3& v, float s){
    float new_x;
    float new_y;
    float new_z;
    new_x = (v.x + s);
    new_y = (v.y + s);
    new_z = (v.z + s);
    return Vector3(new_x, new_y, new_z);
}


std::ostream& operator << (std::ostream& stream, const Vector3& v) {
    // std::cout is a std::ostream object, just like stream
    // so use stream as if it were cout and output the components of
    // the vector
    stream << v.x << ", " << v.y << ", " << v.z << endl;
    return stream;
}


//void add(int a, int b){
//    cout << "the sum of these two numbers is " << (a + b) << "\n";
//}

int main(int argc, char** argv) {
//    cout << "hello world " << argv[0] << " " << 1234 << " " << std::endl;
    cout << "Please input your name:\n";
    string name;
    cin >> name;
    cout << "Hello " << name << ", the address of your string is: " << &name << endl;

    Vector3 a(1,2,3);   // allocated to the stack
    Vector3 b(4,5,6);

    Vector3 c = add(a,b); // copies 6 floats to the arguments in add (3 per Vector3),
    cout << "new data point should be 5, 7, 9. result: " << c.x << ", " << c.y << ", " << c.z << endl;

    Vector3 v(1,2,3);
    Vector3 v2(4,5,6);

    cout << "" << v+v2 << std::endl;

    auto* vHeap = new Vector3(0,0,0);
    vHeap->y = 5;
    cout << *vHeap;

    // Throwing stuff on the stack
    Vector3 array[10];

    //throwing stuff in the heap
    auto* array_of_vectors = new Vector3[100]; // allocates 100 consecutive vectors and returns a pointer to the first one

    delete [] array_of_vectors; // frees all the memory we just allocated

    // Vector3 P0, P1, P2 defined elsewhere
    // float t defined elsewhere
    //B = (1-t)*(1-t)*P0 + 2*(1-t)*t*P1 + t*t*P2;
    // 3 more floats copied into c when it returns
    // a and b are unchanged
//    cout << "Please enter two numbers\n";
//    char* a = 0;
//    int b = 0;
//    cin >> a;
//    cin.ignore();
//    cin >> b;
//    cin.ignore();
    //add(a, b);


    return 0;

}


