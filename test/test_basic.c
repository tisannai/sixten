#include <string.h>

#include "unity.h"
#include "sixten.h"
#include "sixten_ass.h"
#include "sixten_dbg.h"


st_enum( val_type ){ VAL_OK = 0, VAL_ERR = 1 };


st_struct( klass )
{
    char*      name;
    int        value;
    val_type_t type;
};


void test_basic( void )
{
    klass_s ks;
    klass_t kt;
    klass_p kp;
    char*   name = "klass-name";
    int     arr[ 16 ];

    kt = st_alloc( sizeof( klass_s ) );
    kt->name = name;
    kt->value = 10;

    ks.name = kt->name;
    ks.value = kt->value;

    kp = &kt;

    TEST_ASSERT_TRUE( !strcmp( kt->name, name ) );
    TEST_ASSERT_TRUE( !strcmp( ks.name, name ) );
    TEST_ASSERT_TRUE( !strcmp( ( *kp )->name, name ) );

    st_for_n ( 16 ) {
        arr[ i ] = i;
    }

    st_for_n ( 16 ) {
        TEST_ASSERT_TRUE( arr[ i ] == i );
    }

    st_loop {
        st_for_n ( 16 ) {
            st_for_n_x ( 16, x ) {
                TEST_ASSERT_TRUE( arr[ x ] == x );
            }
        }
        break;
    }

    st_assert( 1, "Dummy assert" );
}
