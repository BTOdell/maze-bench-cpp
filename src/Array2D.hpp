#pragma once

template <typename T>
class Array2D {
public:
    const int width;
    const int height;

private:
    T* data;

public:
    Array2D(int width, int height) noexcept
        : width(width), height(height), data(new T[width * height]()) {}
    Array2D(const Array2D&) = delete;
    Array2D(Array2D&&) = delete;
    ~Array2D() { delete[] this->data; }

    T get(int x, int y) const noexcept {
        return this->data[y * width + x];
    }

    void set(int x, int y, T value) noexcept {
        this->data[y * width + x] = value;
    }
};
