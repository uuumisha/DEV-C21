#pragma once

template <typename T> void Swap(T &a, T &b) {
	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}