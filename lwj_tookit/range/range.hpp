#pragma once

#include <cstddef>
#include <stdexcept>

namespace detail_range {
    ///////////////////////////////////////
    //The range iterator
    ///////////////////////////////////////
    
    template<typename T>
    class iterator {
    public:
        using value_type = T;
        using size_type = std::size_t;

    private:
        size_type           cursor_;
        const value_type    step_;
        value_type          value_; 

    public:
        iterator(size_type cur_start, value_type begin_val, value_type step_val):
            cursor_(cur_start),
            step_(step_val),
            value_(begin_val) {
                value_ += (step_ * cursor_);
            }

        value_type operator*() const { return value_; }

        bool operator !=(const iterator& rhs) const {
            return (cursor_ != rhs.cursor_);
        }

        iterator& operator++(void) //prefix ++ operatro only
        {
            value_ += step_;
            ++ cursor_;
            return (*this);
        }
    };

    ///////////////////////////////////////
    //The range impl
    ///////////////////////////////////////

    template<typename T>
    class impl {
    public:
        using value_type        = T;
        using reference         = value_type&;
        using const_reference   = const value_type&;
        using iterator          = detail_range::iterator<value_type>;
        using const_iterator    = const detail_range::iterator<value_type>;
        using size_type         = typename iterator::size_type;

    private:
        const value_type begin_;
        const value_type end_;
        const value_type step_;
        const size_type  max_count_;

        size_type get_adjusted_count(void) const {
            if (step_ > 0 && begin_ >= end_) {
                throw std::logic_error("End value must be greater than begin value.");
            }else if (step_ < 0 && begin_ <= end_) {
                throw std::logic_error("End value must be less than begin value.");
            }

            size_type x = static_cast<size_type>((end_ - begin_) / step_);
            if(begin_ + (step_ * x) != end_) {
                ++x;
            }

            return x;
        }


    public:
        impl(value_type begin_value, value_type end_value, value_type step_value):
            begin_ (begin_value),
            end_   (end_value),
            step_  (step_value),
            max_count_ (get_adjusted_count()) {
            }

        size_type size(void) const {
            return max_count_;
        }

        const_iterator begin(void) const {
            return {0, begin_, step_};
        }

        const_iterator end(void) const {
            return {max_count_, begin_, step_};
        }
    };
}


template<typename T>
detail_range::impl<T> range(T end) {
    return {{}, end, 1};
}

template<typename T>
detail_range::impl<T> range(T begin, T end) {
    return {begin, end, 1};
}

template<typename T, typename U>
auto range(T begin, T end, U step) -> detail_range::impl<decltype(begin+step)> {
    using r_t = detail_range::impl<decltype(begin + step)>;
    return r_t(begin, end, step);
}
