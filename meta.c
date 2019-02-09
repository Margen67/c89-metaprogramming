

#define		PREDECL_BIT(name, value, pos)		PREDECLBIT_##name##_pos##pos = ((value) & (1 << (pos))) ? 2 : 1
#define		PREENUM_BITS(name,  value)	enum{PREDECL_BIT(name,value, 0), PREDECL_BIT(name,value, 1),PREDECL_BIT(name,value, 2),PREDECL_BIT(name,value, 3),PREDECL_BIT(name,value, 4),PREDECL_BIT(name,value, 5),\
PREDECL_BIT(name,value, 6),PREDECL_BIT(name,value, 7),PREDECL_BIT(name,value, 8),PREDECL_BIT(name,value, 9),\
PREDECL_BIT(name,value, 10),PREDECL_BIT(name,value, 11),PREDECL_BIT(name,value, 12),PREDECL_BIT(name,value, 13),PREDECL_BIT(name,value, 14),PREDECL_BIT(name,value, 15),\
PREDECL_BIT(name,value, 16),PREDECL_BIT(name,value, 17),PREDECL_BIT(name,value, 18),PREDECL_BIT(name,value, 19),PREDECL_BIT(name,value, 20),PREDECL_BIT(name,value, 21),\
PREDECL_BIT(name,value, 22),PREDECL_BIT(name,value, 23),PREDECL_BIT(name,value, 24),\
PREDECL_BIT(name,value, 25),PREDECL_BIT(name,value, 26),PREDECL_BIT(name,value, 27),PREDECL_BIT(name,value, 28),PREDECL_BIT(name,value, 29),PREDECL_BIT(name,value, 30),PREDECL_BIT(name,value, 31)}

#define     COMPILETIME_CONSTANT_BIT(name, value, bit)        unsigned char bt_##bit[PREDECLBIT_##name##_pos##bit]

#define     CT_UINT(name, value)        PREENUM_BITS(name, value);\
typedef union {\
char val_;\
COMPILETIME_CONSTANT_BIT(name,value, 0);\
COMPILETIME_CONSTANT_BIT(name,value, 1);\
COMPILETIME_CONSTANT_BIT(name,value, 2);\
COMPILETIME_CONSTANT_BIT(name,value, 3);\
COMPILETIME_CONSTANT_BIT(name,value, 4);\
COMPILETIME_CONSTANT_BIT(name,value, 5);\
COMPILETIME_CONSTANT_BIT(name,value, 6);\
COMPILETIME_CONSTANT_BIT(name,value, 7);\
COMPILETIME_CONSTANT_BIT(name,value, 8);\
COMPILETIME_CONSTANT_BIT(name,value, 9);\
COMPILETIME_CONSTANT_BIT(name,value, 10);\
COMPILETIME_CONSTANT_BIT(name,value, 11);\
COMPILETIME_CONSTANT_BIT(name,value, 12);\
COMPILETIME_CONSTANT_BIT(name,value, 13);\
COMPILETIME_CONSTANT_BIT(name,value, 14);\
COMPILETIME_CONSTANT_BIT(name,value, 15);\
COMPILETIME_CONSTANT_BIT(name,value, 16);\
COMPILETIME_CONSTANT_BIT(name,value, 17);\
COMPILETIME_CONSTANT_BIT(name,value, 18);\
COMPILETIME_CONSTANT_BIT(name,value, 19);\
COMPILETIME_CONSTANT_BIT(name,value, 20);\
COMPILETIME_CONSTANT_BIT(name,value, 21);\
COMPILETIME_CONSTANT_BIT(name,value, 22);\
COMPILETIME_CONSTANT_BIT(name,value, 23);\
COMPILETIME_CONSTANT_BIT(name,value, 24);\
COMPILETIME_CONSTANT_BIT(name,value, 25);\
COMPILETIME_CONSTANT_BIT(name,value, 26);\
COMPILETIME_CONSTANT_BIT(name,value, 27);\
COMPILETIME_CONSTANT_BIT(name,value, 28);\
COMPILETIME_CONSTANT_BIT(name,value, 29);\
COMPILETIME_CONSTANT_BIT(name,value, 30);\
COMPILETIME_CONSTANT_BIT(name,value, 31);\
} name


#define GET_BT_REF(nullstruct, bit, chkbit, elz)       (bit == chkbit ? sizeof(nullstruct->bt_ ##chkbit ) == 2 :  elz)
#define     DECODE_CT_BIT(name, bit)        ((sizeof((name)->bt_##bit) == 2)<<bit)




#define     DECODE_CT_UINT__(name)            \
(DECODE_CT_BIT(name, 0) | DECODE_CT_BIT(name, 1) |DECODE_CT_BIT(name, 2) \
|DECODE_CT_BIT(name, 3) |DECODE_CT_BIT(name, 4) |DECODE_CT_BIT(name, 5) \
|DECODE_CT_BIT(name, 6) |DECODE_CT_BIT(name, 7) \
|DECODE_CT_BIT(name, 8) |DECODE_CT_BIT(name, 9)\
|DECODE_CT_BIT(name, 10) |DECODE_CT_BIT(name, 11)\
|DECODE_CT_BIT(name, 12) |DECODE_CT_BIT(name, 13)\
|DECODE_CT_BIT(name, 14) |DECODE_CT_BIT(name, 15)\
|DECODE_CT_BIT(name, 16) |DECODE_CT_BIT(name, 17)\
|DECODE_CT_BIT(name, 18) |DECODE_CT_BIT(name, 19)\
|DECODE_CT_BIT(name, 20) |DECODE_CT_BIT(name, 21)\
|DECODE_CT_BIT(name, 22) |DECODE_CT_BIT(name, 23)\
|DECODE_CT_BIT(name, 24) |DECODE_CT_BIT(name, 25)\
|DECODE_CT_BIT(name, 26) |DECODE_CT_BIT(name, 27)\
|DECODE_CT_BIT(name, 28) |DECODE_CT_BIT(name, 29)\
|DECODE_CT_BIT(name, 30) |DECODE_CT_BIT(name, 31))

#define DECODE_CT_UINT(name)        DECODE_CT_UINT__(name)
