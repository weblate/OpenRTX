/*
 * Copyright (C) 2020-2025 OpenRTX Contributors
 *
 * This file is part of OpenRTX.
 *
 * OpenRTX is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenRTX is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef MEMORY_PROFILING_H
#define MEMORY_PROFILING_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \return stack size of the caller thread.
 */
unsigned int getStackSize();

/**
 * \return absolute free stack of current thread.
 * Absolute free stack is the minimum free stack since the thread was
 * created.
 */
unsigned int getAbsoluteFreeStack();

/**
 * \return current free stack of current thread.
 * Current free stack is the free stack at the moment when the this
 * function is called.
 */
unsigned int getCurrentFreeStack();

/**
 * \return heap size which is defined in the linker script The heap is
 * shared among all threads, therefore this function returns the same value
 * regardless which thread is called in.
 */
unsigned int getHeapSize();

/**
 * \return absolute (not current) free heap.
 * Absolute free heap is the minimum free heap since the program started.
 * The heap is shared among all threads, therefore this function returns
 * the same value regardless which thread is called in.
 */
unsigned int getAbsoluteFreeHeap();

/**
 * \return current free heap.
 * Current free heap is the free heap at the moment when the this
 * function is called.
 * The heap is shared among all threads, therefore this function returns
 * the same value regardless which thread is called in.
 */
unsigned int getCurrentFreeHeap();

#ifdef __cplusplus
}
#endif

#endif /* MEMORY_PROFILING_H */
