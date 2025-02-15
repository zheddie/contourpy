#ifndef CONTOURPY_COMMON_H
#define CONTOURPY_COMMON_H

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

// quad/point index type, the same as for numpy array shape/indices (== npy_intp).  Also used for
// chunks.
typedef py::ssize_t index_t;

// Count of points, lines and holes.
typedef py::size_t count_t;

#ifndef _AIX
//There's a conflict in sys/types.h on AIX/IBM i
// Offsets into point arrays.
typedef uint32_t offset_t;
#endif

// Input numpy array classes.
typedef py::array_t<double, py::array::c_style | py::array::forcecast> CoordinateArray;
typedef py::array_t<bool,   py::array::c_style | py::array::forcecast> MaskArray;

// Output numpy array classes.
typedef py::array_t<double>   PointArray;
typedef py::array_t<uint8_t>  CodeArray;
typedef py::array_t<offset_t> OffsetArray;

#endif // CONTOURPY_COMMON_H
