//
//  rx-sources.cpp
//  learn-cpp-rxcpp
//
//  Created by Gu,Xuan on 2019/12/31.
//  Copyright © 2019 guxuan. All rights reserved.
//
#include "rx-sources.hpp"
#include "rx-includes.hpp"

namespace rxcpp {

namespace sources {

struct tag_source {};

template<class T>
struct source_base {
    using value_type = T;
    using source_tag = tag_source;
};

template<class T>
class is_source {
    template<class C>
    static typename C::source_tag* check(int);
    template<class C>
    static void check(...);
public:
    static const bool value = std::is_convertible<decltype(check<rxu::decay_t<T>>(0)), tag_source*>::value;
};

}
    
    namespace rxs = sources;

}
