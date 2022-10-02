#include <iostream>
#include <boost/thread.hpp>
#include <mutex>

using namespace std;

mutex a;

int THREAD_COUNT = 10;

class BOOST_CLASS {
    public:
        BOOST_CLASS();
        void fncs();
        void run();
    private:
        int number;

};

BOOST_CLASS::BOOST_CLASS() { 
    number = -1;
}

void BOOST_CLASS::fncs() {
    a.lock();
    number+=1;
    cout << number << endl; 
    a.unlock();
}

void BOOST_CLASS::run() {
  std::vector< boost::thread> threads;
    
    for(int i = 0; i < THREAD_COUNT; i++) {
        threads.push_back( boost::thread(&BOOST_CLASS::fncs, this) );
    }
    
    for(int i = 0; i < THREAD_COUNT; i++) {
        threads[i].join();
    }
}

int main(int argc, char** argv) {

    BOOST_CLASS bc;
    bc.run();

    return 0;
}
