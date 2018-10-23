#ifndef SIXTEN_ASS_H
#define SIXTEN_ASS_H

/**
 * @file   sixten_ass.h
 * @author Tero Isannainen <tero.isannainen@gmail.com>
 * @date   Mon Jun  4 21:41:30 2018
 *
 * @brief  Sixten assertion definitions.
 *
 */


/* ------------------------------------------------------------
 * Assertions.
 */

//#ifdef SIXTEN_ASSERT_API_ENABLE
//#if SIXTEN_USE_ASSERT == 1

void st_assert_used_fn( const char* cond,
                        const char* file,
                        int         line,
                        const char* func,
                        const char* format,
                        ... );
void st_assert_idle_fn( const char* cond,
                        const char* file,
                        int         line,
                        const char* func,
                        const char* format,
                        ... );

#define st_assert_used( cond, format, ... )                                                        \
    (void)( ( cond ) ||                                                                            \
            ( st_assert_used_fn( #cond, __FILE__, __LINE__, __FUNCTION__, format, ##__VA_ARGS__ ), \
              0 ) )

#define st_assert_idle( cond, format, ... )                                                        \
    (void)( ( cond ) ||                                                                            \
            ( st_assert_idle_fn( #cond, __FILE__, __LINE__, __FUNCTION__, format, ##__VA_ARGS__ ), \
              0 ) )

#define st_assert_q_used( cond ) \
    (void)( ( cond ) || ( st_assert_used_fn( #cond, __FILE__, __LINE__, __FUNCTION__, NULL ), 0 ) )

#define st_assert_q_idle( cond ) \
    (void)( ( cond ) || ( st_assert_idle_fn( #cond, __FILE__, __LINE__, __FUNCTION__, NULL ), 0 ) )


/* clang-format off */

#ifndef SIXTEN_ASSERT_DISABLE

#    define st_assert st_assert_used
#    define st_assert_q st_assert_q_used

#else /* SIXTEN_ASSERT_DISABLE */

#    define st_assert st_assert_idle
#    define st_assert_q st_assert_q_idle

#endif

/* clang-format on */

//#endif /* SIXTEN_ASSERT_API_DISABLE */


#endif
