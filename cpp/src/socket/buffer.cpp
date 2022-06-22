#include "buffer.h"

void Buffer::remove_prefix(const size_t n) {
    if (n > str().size()) {
        throw std::out_of_range("Buffer::remove_prefix");
    }
    _starting_offset += n;
    if (_storage and _starting_offset == _storage->size()) {
        _storage.reset();
    }
}

void BufferList::append(const BufferList& other) {
    //_buffers.insert(_buffers.end(), other._buffers.begin(), other._buffers.end());
    for (const auto& buf : other._buffers) {
        _buffers.push_back(buf);
    }
}

BufferList::operator Buffer() const {
    switch (_buffers.size())
    {
        case 0:
            return {};
        case 1:
            return _buffers[0];        
        default: {
            throw std::runtime_error(
                "BufferList: please use concatenate() to combine a multi-Buffer BufferList into one Buffer");
        }
    }
}

std::string BufferList::concatenate() const {
    std::string str{};
    str.reserve(size());
    for (const auto& buf : _buffers) {
        str.append(buf);
    }
    return str;
}  

size_t BufferList::size() const {
    int ret{0};
    for (const auto& buf : _buffers) {
        ret += buf.size();
    }
    return ret;
}

void BufferList::remove_prefix(size_t n) {
    while (n > 0) {
        if (_buffers.empty()) {
            throw std::out_of_range("BufferList::remove_prefix");
        }
        if (n < _buffers.front().size()) {
            _buffers.front().remove_prefix(n);
            n = 0;
        } else {
            n -= _buffers.front().size();
            _buffers.pop_front();
        }
    }
}