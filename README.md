Mathematics 3D (M3D)
====================

[![Build Status](https://travis-ci.org/kermado/M3D.svg?branch=master)](https://travis-ci.org/kermado/M3D)
[![Coverage Status](https://img.shields.io/coveralls/kermado/M3D.svg)](https://coveralls.io/r/kermado/M3D)

Overview
--------

M3D is an extremely lightweight cross-platform C++ mathematics library intended for 3D computer graphics applications with OpenGL or DirectX. The API closely resembles that of Unity's mathematics classes. The following mathematical structures are currently included:

 * Vector2
 * Vector3
 * Vector4
 * Quaternion
 * Matrix2x2
 * Matrix3x3
 * Matrix4x4

Requirements
------------

[Boost](http://www.boost.org/) is required for compiling the unit tests. The library itself has no dependencies.

Building
--------

Use CMake to generate makefiles or platform-specific IDE projects. Unix (Linux and Mac OS X) users can compile and install the library as follows:

```
mkdir build
cd build
cmake ..
make
sudo make install
```

Windows users can use CMake to generate a Visual Studio project.

Authors
-------

 * Omar Kermad

License (MIT)
-------------

Copyright (C) 2014
Omar Kermad

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


[![Bitdeli Badge](https://d2weczhvl823v0.cloudfront.net/kermado/m3d/trend.png)](https://bitdeli.com/free "Bitdeli Badge")

