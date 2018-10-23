#ifndef SIXTEN_DBG_H
#define SIXTEN_DBG_H

/**
 * @file   sixten_dbg.h
 * @author Tero Isannainen <tero.isannainen@gmail.com>
 * @date   Mon Jun  4 21:41:30 2018
 *
 * @brief  Sixten debug definitions.
 *
 */


/* ------------------------------------------------------------
 * Debugging.
 */


void st_dbg_break( void );
void st_dbg_break_tmp( void );

/**
 * Break if names match. NOTE: name1 should be variable and name2
 * constant.
 */
#define st_dbg_break_name( name1, name2 ) \
    if ( name1 )                          \
        if ( !strcmp( name1, name2 ) )    \
            st_dbg_break();

#define st_dbg_break_name_tmp( name1, name2 ) \
    if ( name1 )                              \
        if ( !strcmp( name1, name2 ) )        \
            st_dbg_break_tmp();


int st_dbg_prn( const char* format, ... );


#endif
