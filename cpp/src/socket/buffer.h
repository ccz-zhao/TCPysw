#pragma once

#include <deque>
#include <memory> // std::shared_ptr
#include <stdexcept>
#include <string> 
#include <string_view>

class Buffer {
  private:
    std::shared_ptr<std::string> _storage{};
    size_t _starting_offset{};

  public:
    Buffer() = default;
    ~Buffer() = default;
    Buffer(const Buffer&) = default;
    Buffer(Buffer&&) = delete;
    Buffer& operator=(const Buffer&) = default;
    Buffer& operator=(Buffer&&) = delete;

    // Construct by taking ownership of a string
    Buffer(std::string&& str) noexcept : _storage(std::make_shared<std::string>(std::move(str))) {};

    // Expose contents as a std::string_view
    std::string_view str() const {
        if (!_storage) return {};
        return {_storage->data() + _starting_offset, _storage->size() - _starting_offset};
    }

    operator std::string_view() const {return str();}

    uint8_t at(const size_t n) {return str().at(n);}

    size_t size() const {return str().size();}

    // make a copy
    std::string copy() const {return std::string(str());}

    void remove_prefix(const size_t n);
};

class BufferList {
  
};
