/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <memory>
#include <vector>


class Test {
private:
    int data;
public:
    Test() : data{0} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    Test(int data) : data {data} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    int get_data() const {return data; }
    ~Test() {std::cout << "\tTest destructor (" << data << ")" << std::endl; } //si se llamó
};

// Function prototypes
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
void fill(std::vector<std::shared_ptr<Test>> &vec, int num);
void display(const std::vector<std::shared_ptr<Test>>&vec);

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {

   std::shared_ptr<Test> s1 = std::make_shared<Test>(Test(1));
   std::shared_ptr<Test> s3 = std::make_shared<Test>(Test(3));
   std::shared_ptr<Test> s4 = {s1};

    std::vector<std::shared_ptr<Test>> myVector{s1, s3, s4};

    //std::unique_ptr<std::vector<std::shared_ptr<Test>>> p1 = std::make_unique<std::vector<std::shared_ptr<Test>>>(myVector);
    return std::make_unique<std::vector<std::shared_ptr<Test>>>(myVector);;
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int num) {

    int value;
    for(size_t i{0}; i < num ; ++i)
    {
        std::cout << "Enter data point [ " << i+1 << " ]: " ;
        std::cin >> value;

        vec.push_back(std::make_shared<Test>(value));
    }
}



//void display(const std::vector<Test>&vec) {
void display(const std::vector<std::shared_ptr<Test>>&vec) {

    std::cout << "well the vector del make() es este" << std::endl;

    std::cout << "\n=== Vector===========================================" << std::endl;
    for (const auto &v: vec)
        std::cout << v->get_data() << std::endl;
    std::cout << "\n=== End of Vector===========================================" << std::endl;

}




int main() {
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    return 0;
}
