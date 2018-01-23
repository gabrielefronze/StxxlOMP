#include <stxxl/vector>
#include <iostream>
#include <thread>
#include <random>
#include <chrono>
#include "StopWatch.h"
#include "settings.h"

int main(){

    stxxl::config * cfg = stxxl::config::get_instance();
    settings::config_stxxl_disk(cfg);

    typedef stxxl::VECTOR_GENERATOR<uint64_t>::result stxxlvector;
    
    stxxlvector my_vector;

    {
        StopWatch stopwatch;
        
        for (int i = 0; i < settings::required_size; i++)
        {
            std::this_thread::sleep_for(std::chrono::nanoseconds(settings::sleep_time(settings::sleep_time(i))));
            my_vector.push_back((uint64_t)17);
        }
    }

    std::cout << my_vector[99] << std::endl;
    std::cout << my_vector.size() << std::endl;
    my_vector[100] = 0;

    {
        StopWatch stopwatch;

        for (int i = 0; i < my_vector.size(); i++)
        {
            assert(my_vector.back() == 17);
            my_vector.pop_back();
        }
    }

    std::cout << my_vector.size() << std::endl;

    assert(my_vector.size() == 0);

    return 0;
}
