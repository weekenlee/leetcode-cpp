#pragma once

namespace lwj {

    template <typename InputIterator, typename OutputIterator, typename Predicate>
    OutputIterator find_all(InputIterator first, InputIterator end, OutputIterator dest, Predicate pred) {
        while ( first != end ) {
            if(pred(*first)) {
                *dest = first;
                ++dest;
            }
            ++first;
        }
        return dest;
    }

}
