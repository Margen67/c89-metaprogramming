#pragma once
#define H1(s,i,x)   (x*65599u+(uint8_t)s[(i)<(sizeof(s)-1)?(sizeof(s)-1)-1-(i):(sizeof(s)-1)])
#define H4(s,i,x)   H1(s,i,H1(s,i+1,H1(s,i+2,H1(s,i+3,x))))
#define H16(s,i,x)  H4(s,i,H4(s,i+4,H4(s,i+8,H4(s,i+12,x))))
#define H64(s,i,x)  H16(s,i,H16(s,i+16,H16(s,i+32,H16(s,i+48,x))))


#define H256(s,i,x) H64(s,i,H64(s,i+64,H64(s,i+128,H64(s,i+192,x))))


#define HASH(s, name)    \
    enum {\
        name##_1 = H64(s,0,0),\
        name = ( name##_1 >> 16) ^  name##_1\
    }

#define     COMPILETIME_CONSTANT_BIT(value, bit)        unsigned char bt_##bit : 1 + (((unsigned )(value) >> bit)&1)

#define     CT_UINT(name, value)        typedef union {char val_; struct {COMPILETIME_CONSTANT_BIT(value, 0); COMPILETIME_CONSTANT_BIT(value, 1);COMPILETIME_CONSTANT_BIT(value, 2);COMPILETIME_CONSTANT_BIT(value, 3);};struct{COMPILETIME_CONSTANT_BIT(value, 4);COMPILETIME_CONSTANT_BIT(value, 5);\
COMPILETIME_CONSTANT_BIT(value, 6);COMPILETIME_CONSTANT_BIT(value, 7);};struct{COMPILETIME_CONSTANT_BIT(value, 8);COMPILETIME_CONSTANT_BIT(value, 9);\
COMPILETIME_CONSTANT_BIT(value, 10);COMPILETIME_CONSTANT_BIT(value, 11);};struct{COMPILETIME_CONSTANT_BIT(value, 12);COMPILETIME_CONSTANT_BIT(value, 13);COMPILETIME_CONSTANT_BIT(value, 14);COMPILETIME_CONSTANT_BIT(value, 15);};\
struct{COMPILETIME_CONSTANT_BIT(value, 16);COMPILETIME_CONSTANT_BIT(value, 17);COMPILETIME_CONSTANT_BIT(value, 18);COMPILETIME_CONSTANT_BIT(value, 19);};struct{COMPILETIME_CONSTANT_BIT(value, 20);COMPILETIME_CONSTANT_BIT(value, 21);\
COMPILETIME_CONSTANT_BIT(value, 22);COMPILETIME_CONSTANT_BIT(value, 23);};struct{COMPILETIME_CONSTANT_BIT(value, 24);\
COMPILETIME_CONSTANT_BIT(value, 25);COMPILETIME_CONSTANT_BIT(value, 26);COMPILETIME_CONSTANT_BIT(value, 27);};struct{COMPILETIME_CONSTANT_BIT(value, 28);COMPILETIME_CONSTANT_BIT(value, 29);COMPILETIME_CONSTANT_BIT(value, 30);COMPILETIME_CONSTANT_BIT(value, 31);};} name


#define GET_BT_REF(nullstruct, bit, chkbit, elz)       (bit == chkbit ? sizeof(nullstruct->bt_ ##chkbit ) == 2 :  elz)

#define GET_BTREF_IMPL(nullstruct, bit)        \
 (GET_BT_REF(nullstruct, bit, 0, GET_BT_REF(nullstruct, bit, 1, \
GET_BT_REF(nullstruct, bit, 2, GET_BT_REF(nullstruct, bit, 3, \
GET_BT_REF(nullstruct, bit, 4, GET_BT_REF(nullstruct, bit, 5, \
GET_BT_REF(nullstruct, bit, 6, GET_BT_REF(nullstruct, bit, 7, \
GET_BT_REF(nullstruct, bit, 8, GET_BT_REF(nullstruct, bit, 9, \
GET_BT_REF(nullstruct, bit, 10, GET_BT_REF(nullstruct, bit, 11, \
GET_BT_REF(nullstruct, bit, 12, GET_BT_REF(nullstruct, bit, 13, \
GET_BT_REF(nullstruct, bit, 14, GET_BT_REF(nullstruct, bit, 15, \
GET_BT_REF(nullstruct, bit, 16, GET_BT_REF(nullstruct, bit, 17, \
GET_BT_REF(nullstruct, bit, 18, GET_BT_REF(nullstruct, bit, 19, \
GET_BT_REF(nullstruct, bit, 20, GET_BT_REF(nullstruct, bit, 21, \
GET_BT_REF(nullstruct, bit, 22, GET_BT_REF(nullstruct, bit, 23, \
GET_BT_REF(nullstruct, bit, 24, GET_BT_REF(nullstruct, bit, 25, \
GET_BT_REF(nullstruct, bit, 26, GET_BT_REF(nullstruct, bit, 27, \
GET_BT_REF(nullstruct, bit, 28, GET_BT_REF(nullstruct, bit, 29, \
GET_BT_REF(nullstruct, bit, 30, GET_BT_REF(nullstruct, bit, 31, 0))))))))))))))))))))))))))))))) ))


#define GET_BTREF(structname, bit)          GET_BTREF_IMPL(((structname*)0), bit)



#define     DECODE_CT_BIT(name, bit)        (( ((name){{-1}}).bt_##bit != 1)  << bit)
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
#define DECODE_CT_UINT_BY_REF(ref_) DECODE_CT_UINT__(ref_)      

#define     CT_STRING_4BYTE(length, name, str, idx) \
            CT_UINT(name##_##idx, (length > idx ? str[idx] : 0) | \
            (length > (idx+1) ? str[idx+1] : 0) |  (length > (idx+2) ? str[idx+2] : 0) |\
            (length > (idx+3) ? str[idx+3] : 0) )
#define     CTSTRFIELD_IMPL(namecon, idx)      namecon##idx i##idx    
#define     CTSTRFIELD(name, idx)   CTSTRFIELD_IMPL(name##_ , idx)

#define     CT_STRING(name, str)      \
    enum {_length_##name = sizeof(str)};\
    CT_STRING_4BYTE(_length_##name, name, (str), 0);\
    CT_STRING_4BYTE(_length_##name, name, (str), 4);\
    CT_STRING_4BYTE(_length_##name, name, (str), 8);\
    CT_STRING_4BYTE(_length_##name, name, (str), 12);\
    CT_STRING_4BYTE(_length_##name, name, (str), 16);\
    CT_STRING_4BYTE(_length_##name, name, (str), 20);\
    CT_STRING_4BYTE(_length_##name, name, (str), 24);\
    CT_STRING_4BYTE(_length_##name, name, (str), 28);\
    CT_STRING_4BYTE(_length_##name, name, (str), 32);\
    CT_STRING_4BYTE(_length_##name, name, (str), 36);\
    CT_STRING_4BYTE(_length_##name, name, (str), 40);\
    CT_STRING_4BYTE(_length_##name, name, (str), 44);\
    CT_STRING_4BYTE(_length_##name, name, (str), 48);\
    CT_STRING_4BYTE(_length_##name, name, (str), 52);\
    CT_STRING_4BYTE(_length_##name, name, (str), 56);\
    CT_STRING_4BYTE(_length_##name, name, (str), 60);\
    CT_STRING_4BYTE(_length_##name, name, (str), 64);\
    CT_STRING_4BYTE(_length_##name, name, (str), 68);\
    CT_STRING_4BYTE(_length_##name, name, (str), 72);\
    CT_STRING_4BYTE(_length_##name, name, (str), 76);\
    CT_STRING_4BYTE(_length_##name, name, (str), 80);\
    CT_STRING_4BYTE(_length_##name, name, (str), 84);\
    CT_STRING_4BYTE(_length_##name, name, (str), 88);\
    CT_STRING_4BYTE(_length_##name, name, (str), 92);\
    CT_STRING_4BYTE(_length_##name, name, (str), 96);\
    CT_STRING_4BYTE(_length_##name, name, (str), 100);\
    CT_STRING_4BYTE(_length_##name, name, (str), 104);\
    CT_STRING_4BYTE(_length_##name, name, (str), 108);\
    CT_STRING_4BYTE(_length_##name, name, (str), 112);\
    CT_STRING_4BYTE(_length_##name, name, (str), 116);\
    CT_STRING_4BYTE(_length_##name, name, (str), 120);\
    CT_STRING_4BYTE(_length_##name, name, (str), 124);\
    CT_UINT(_lengthof_##name, sizeof(str)-1);\
typedef struct {\
    _lengthof_##name length;\
    name##_0 i0;\
    name##_4 i4;\
    name##_8 i8;\
    name##_12 i12;\
    name##_16 i16;\
    name##_20 i20;\
    name##_24 i24;\
    name##_28 i28;\
    CTSTRFIELD(name, 32);\
    CTSTRFIELD(name, 36);\
    CTSTRFIELD(name, 40);\
    CTSTRFIELD(name, 44);\
    CTSTRFIELD(name, 48);\
    CTSTRFIELD(name, 52);\
    CTSTRFIELD(name, 56);\
    CTSTRFIELD(name, 60);\
    CTSTRFIELD(name, 64);\
    CTSTRFIELD(name, 68);\
    CTSTRFIELD(name, 72);\
    CTSTRFIELD(name, 76);\
    CTSTRFIELD(name, 80);\
    CTSTRFIELD(name, 84);\
    CTSTRFIELD(name, 88);\
    CTSTRFIELD(name, 92);\
    CTSTRFIELD(name, 96);\
    CTSTRFIELD(name, 100);\
    CTSTRFIELD(name, 104);\
    CTSTRFIELD(name, 108);\
    CTSTRFIELD(name, 112);\
    CTSTRFIELD(name, 116);\
    CTSTRFIELD(name, 120);\
    CTSTRFIELD(name, 124);\
} name

#define CT_STRING_LENGTH(ctstring)      DECODE_CT_UINT_BY_REF((&(ctstring)->length))

#define CT_STRING_HASH(name, str)       \
    HASH(str, pre_hash_##name);\
    enum {__hashof_##name = pre_hash_##name};\
    CT_UINT(name, __hashof_##name)


#define POINTER_WITH_METADATA(type, metatype, name)      typedef union {type* ptr; metatype* meta;}name


#define POINTER_EXTRACT_META(ptr)           ((ptr).meta)
#define POINTER_EXTRACT_PTR(ptr)            ((ptr).ptr)


#define         UARRAY_4(name, val1, val2, val3, val4) \
    CT_UINT(name##_1, val1);\
     CT_UINT(name##_2, val2);\
      CT_UINT(name##_3, val3);\
       CT_UINT(name##_4, val4);\
typedef struct {\
    name##_1 idx0;\
    name##_2 idx4;\
    name##_3 idx8;\
    name##_4 idx12;\
}name
