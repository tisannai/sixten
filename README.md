# Sixten

## Introduction

Sixten is a support library for Tensix libraries (See: Tensix README
for details).

Sixten directly contains common header with basic types and common
utility functions in itself.


## Usage

Sixten include preprocessor definitions which affect how the library
is deployed.

1. SIXTEN_NO_STD_INCLUDE - When defined, the "typical" set of standard headers are not included.
2. SIXTEN_NO_MEM_API - When defined, Sixten does not define memory
   access functions. When not define, memory access function are
   defined and also SIXTEN_USE_MEM_API is defined as 1. This can be
   used in other libraries to enable Sixten based memory functions.
3. SIXTEN_NO_ASSERT - When defined, Sixten assertions are
   disables. Otherwise they are usable.
