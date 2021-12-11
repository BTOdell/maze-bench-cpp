#pragma once

template <typename T>
class Array2D {
public:
    const unsigned int width;
    const unsigned int height;

private:
    T* data;

public:
    Array2D(unsigned int width, unsigned int height) noexcept
        : width(width), height(height), data(new T[width * height]()) {}
    Array2D(const Array2D&) = delete;
    Array2D(Array2D&&) = delete;
    ~Array2D() { delete[] this->data; }

    T get(unsigned int x, unsigned int y) const noexcept {
        return this->data[y * width + x];
    }

    void set(unsigned int x, unsigned int y, T value) noexcept {
        this->data[y * width + x] = value;
    }
};
