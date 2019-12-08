//
//  rx-trace.cpp
//  learn-cpp-rxcpp
//
//  Created by guxuan on 2019/12/8.
//  Copyright © 2019 guxuan. All rights reserved.
//

#include "rx-trace.hpp"

namespace rxcpp {
    struct trace_id {
        static inline trace_id make_next_id_subscriber() {
            static std::atomic<unsigned long> id(0xB0000000);
            return trace_id{++id};
        }
        
        unsigned long id;
    };
    
    inline bool operator==(const trace_id& lhs, const trace_id& rhs) {
        return lhs.id == rhs.id;
    }
}


