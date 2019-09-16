#ifndef SIXTEN_H
#define SIXTEN_H

/**
 * @file   sixten.h
 * @author Tero Isannainen <tero.isannainen@gmail.com>
 * @date   Mon Jun  4 21:41:30 2018
 *
 * @brief  Sixten definitions.
 *
 */

/*
 * Common headers:
 */

#ifndef SIXTEN_NO_STD_INCLUDE
#define SIXTEN_STD_INCLUDE
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <libgen.h>
#include <ctype.h>
#include <stdarg.h>
#include <assert.h>
#include <stdint.h>
#endif


/* ------------------------------------------------------------
 * Simple type definition features:
 */

/** Re-define type and related pointers. */
#define st_type( base, type )   \
    typedef base      type##_t; \
    typedef type##_t* type##_p;



/* ------------------------------------------------------------
 * Structure type definition.
 */

/**
 * Define struct and related typedefs for struct type ("_s"), pointer
 * type ("_t"), and reference type ("_p").
 *
 * Example:
 * @code
 *     Definition:
 *         st_struct(point) {
 *             st_int x;
 *             st_int y;
 *         };
 *
 *   Becomes:
 *       typedef struct point_struct_s point_s;
 *       typedef point_s* point_t;
 *       typedef point_s** point_p;
 *       struct point_struct_s {
 *           st_int x;
 *           st_int y;
 *       };
 * @endcode
 */
#define st_struct( name )                   \
    typedef struct name##struct_s name##_s; \
    typedef name##_s*             name##_t; \
    typedef name##_s**            name##_p; \
    struct name##struct_s

#define st_struct_type( name )              \
    typedef struct name##struct_s name##_s; \
    typedef name##_s*             name##_t; \
    typedef name##_s**            name##_p;

#define st_struct_body( name )              \
    struct name##struct_s

/**
 * Define enumeration and corresponding type. An enum is created with
 * name+"_e", a typedef is created with name+"_t".
 *
 * Example:
 *
 *   st_enum(some_runtype) {
 *     RUN_NONE,
 *     RUN_TASK,
 *     RUN_FUNC
 *   };
 *
 *   // Becomes...
 *   typedef enum st_runtype_e st_runtype_t;
 *   enum st_runtype_e {
 *     RUN_NONE,
 *     RUN_TASK,
 *     RUN_FUNC
 *   };
 */
#define st_enum( name )             \
    typedef enum name##_e name##_t; \
    enum name##_e


/* ------------------------------------------------------------
 * Basic data types.
 */

/** Boolean type. */
st_enum( st_bool ){ st_false = 0, st_true = 1 };

/** Void type. */
typedef void st_none;

/** Generic pointer type. */
typedef void* st_t;

/** Generic pointer type reference. */
typedef void** st_p;


st_type( int8_t, st_i8 );    /**< Character type. */
st_type( uint8_t, st_u8 );   /**< Character type. */
st_type( int64_t, st_i64 );  /**< Int type (64-bits). */
st_type( uint64_t, st_u64 ); /**< Unsigned int type (64-bits). */

st_type( char*, st_str );     /**< String type. */
st_type( double, st_flt );   /**< 64-bit floating point. .*/

st_type( uint64_t, st_size ); /**< Size of allocation type. */
st_type( int64_t, st_pos );   /**< Position in array. */
st_type( uint64_t, st_id );   /**< Identification number type. */


/** Nil pointer. */
#define st_nil NULL


/* ------------------------------------------------------------
 * Standards loops.
 */

/** Forever loop. */
#define st_loop for ( ;; )

/** For n-times loop. Loop counter is 'i'. */
#define st_for_n( n ) for ( int i = 0; i < ( n ); i++ )

/** For n-times loop. Loop counter is 'x'. */
#define st_for_n_x( n, x ) for ( int( x ) = 0; ( x ) < ( n ); ( x )++ )



/* ------------------------------------------------------------
 * Low level memory.
 */

#ifndef SIXTEN_NO_MEM_API

/* clang-format off */
#define st_new( type )                   calloc( 1, sizeof( type ) )
#define st_new_n( type, n )              calloc( ( n ), sizeof( type ) )
#define st_del( mem )                    free( mem )
#define st_alloc( size )                 calloc( 1, ( size ) )
#define st_realloc( mem, size )          realloc( ( mem ), ( size ) )
#define st_free( mem )                   free( mem )
#define st_strdup( str )                 strdup( str )
#define st_memcpy( src, dst, size )      memcpy( ( dst ), ( src ), ( size ) )
#define st_memcpy_type( src, dst, type ) memcpy( ( dst ), ( src ), sizeof( type ) )
#define st_memmov( src, dst, size )      memmove( ( dst ), ( src ), ( size ) )
#define st_memmov_type( src, dst, type ) memmove( ( dst ), ( src ), sizeof( type ) )
#define st_memclr( mem, size )           memset( ( mem ), 0, ( size ) )
#define st_memclr_type( mem, type )      memset( ( mem ), 0, sizeof( type ) )
#define st_memcmp( m1, m2, size )        memcmp( ( m1 ), ( m2 ), ( size ) )
#define st_memcmp_type( m1, m2, type)    memcmp( ( m1 ), ( m2 ), sizeof( type ) )
/* clang-format on */

#endif


/**
 * Default memory function callback.
 *
 * Params:
 * * obj: Container object.
 * * env: Program/library related environment.
 * * arg: Dynamic argument (transaction related context).
 */
typedef st_t ( *st_mem_cb_fn )( st_t obj, st_t env, st_t arg );



/* ------------------------------------------------------------
 * Standard streams.
 */

/* clang-format off */

#ifndef st_stdin
#    define st_stdin stdin
#endif

#ifndef st_stdout
#    define st_stdout stdout
#endif

#ifndef st_stderr
#    define st_stderr stderr
#endif

/* clang-format on */




/* ------------------------------------------------------------
 * Miscellaneous.
 */

inline st_none st_dummy( st_none ) {}


typedef void* ( *ui_f )( void* env, void* arg );

/**
 * Universal Interface.
 */
st_struct( ui )
{
    void* env; /**< Object. */
    ui_f  fun; /**< Object method. */
};


#endif
