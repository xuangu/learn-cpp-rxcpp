//
//  rx-util.hpp
//  learn-cpp-rxcpp
//
//  Created by guxuan on 2020/1/2.
//  Copyright © 2020 guxuan. All rights reserved.
//

#ifndef rx_util_h
#define rx_util_h

#include "rx-includes.hpp"

namespace rxcpp
{
    namespace util {
        template<class T> using value_type_t = typename std::decay<T>::type::value_type;
        template<class T> using decay_t = typename std::decay<T>::type;
        template<class... TN> using result_of_t = typename std::result_of<TN...>::type;

        template<class T, std::size_t size>
        std::vector<T> to_vector(const T (&arr) [size]) {
            return std::vector<T>(std::begin(arr), std::end(arr));
        }
        
        template<class T>
        std::vector<T> to_vector(std::initializer_list<T> il) {
            return std::vector<T>(il);
        }

        template<class T0, class... TN>
        typename std::enable_if<!std::is_array<T0>::value && std::is_pod<T0>::value, std::vector<T0>>::type to_vector(T0 t0, TN... tn) {
            return to_vector({t0, tn...});
        }
    }

} // namespace namerxcpp


#endif /* rx_util_h */
