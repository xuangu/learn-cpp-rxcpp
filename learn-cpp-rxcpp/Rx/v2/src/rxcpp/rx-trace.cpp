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
    
    inline bool operator!=(const trace_id& lhs, const trace_id& rhs) {
        return !(lhs==rhs);
    }
    
    inline bool operator<(const trace_id& lhs, const trace_id& rhs) {
        if ((lhs.id & 0xF0000000) != (rhs.id & 0xF0000000)) {
            std::terminate();
        }
        
        return lhs.id < rhs.id;
    }

    inline bool operator>(const trace_id& lhs, const trace_id& rhs) {
        if ((lhs.id & 0xF0000000) != (rhs.id & 0xF0000000)) {
            std::terminate();
        }
        
        return lhs.id > rhs.id;
    }

    inline std::ostream& operator<< (std::ostream& os, const trace_id&id) {
        return os << std::hex << id.id << std::dec;
    }
}


