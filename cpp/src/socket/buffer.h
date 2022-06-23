#pragma once

#include <deque>
#include <memory> // std::shared_ptr
#include <stdexcept>
#include <string> 
#include <string_view>
#include <sys/uio.h>
#include <vector>

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
  private:
    std::deque<Buffer> _buffers{};

  public:
    BufferList() = default;

    BufferList(Buffer buffer) : _buffers{buffer} {};

    BufferList(std::string&& str) noexcept {
      Buffer buffer{std::move(str)};
      append(buffer);
    }

    const std::deque<Buffer>& buffers() const {return _buffers;}

    void append(const BufferList& other);

    operator Buffer() const;

    void remove_prefix(size_t n);

    size_t size() const;

    std::string concatenate() const;

};

class BufferViewList {
  private:
    std::deque<std::string_view> _views{};
  public:

    BufferViewList(std::string_view str) { _views.push_back(str); }

    BufferViewList(const std::string& str) : BufferViewList(std::string_view(str)) {}

    BufferViewList(const char* str) : BufferViewList(std::string_view(str)) {}

    BufferViewList(const BufferList& buffers);

    void remove_prefix(size_t n);

    size_t size() const;

    std::vector<iovec> as_iovecs() const;

};

