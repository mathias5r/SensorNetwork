/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "Ativo"
 * 	found in "../Ativo.asn1"
 */

#ifndef	_BoolList_H_
#define	_BoolList_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BOOLEAN.h>
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* BoolList */
typedef struct BoolList {
	A_SEQUENCE_OF(BOOLEAN_t) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} BoolList_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_BoolList;

#ifdef __cplusplus
}
#endif

#endif	/* _BoolList_H_ */
#include <asn_internal.h>