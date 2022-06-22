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