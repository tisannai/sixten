/**
 * @file   sixten.c
 * @author Tero Isannainen <tero.isannainen@gmail.com>
 * @date   Mon Jun  4 21:41:30 2018
 *
 * @brief  Sixten definitions.
 *
 */


#include "sixten.h"


/* ------------------------------------------------------------
 * Assertions.
 */

/**
 * Enabled assertion function with message.
 *
 * @param cond Assert condition.
 * @param file File name.
 * @param line Line number.
 * @param func Function name.
 * @param format Message format.
 */
void st_assert_used_fn( const char* cond,
                        const char* file,
                        int         line,
                        const char* func,
                        const char* format,
                        ... )
{
    if ( format ) {
        va_list args;
        va_start( args, format );

        /* Produce runtime error. */
        fprintf( st_stderr, "ST-ASSERT at: %s:%d:%s: ", file, line, func );
        vfprintf( st_stderr, format, args );
        fputc( '\n', st_stderr );
    }

    __assert( cond, file, line );
}


/**
 * Disabled assertion function with message.
 *
 * @param cond Assert condition.
 * @param file File name.
 * @param line Line number.
 * @param func Function name.
 * @param format Message format.
 */
void st_assert_idle_fn( const char* cond,
                        const char* file,
                        int         line,
                        const char* func,
                        const char* format,
                        ... )
{
    (void)cond;
    (void)file;
    (void)line;
    (void)func;
    (void)format;
}


/* ------------------------------------------------------------
 * Debugging.
 */

/**
 * GDB breakpoint function.
 */
void st_dbg_break( void ) {}


/**
 * Temporary GDB breakpoint function.
 */
void st_dbg_break_tmp( void ) {}


int st_dbg_prn( const char* format, ... )
{
    int ret;

    ret = 0;

    if ( format ) {
        va_list args;
        va_start( args, format );
        ret = vfprintf( st_stdout, format, args ) + 1;
        fputc( '\n', st_stdout );
    }

    return ret;
}
