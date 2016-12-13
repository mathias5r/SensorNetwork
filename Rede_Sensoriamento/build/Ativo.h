/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "Ativo"
 * 	found in "../Ativo.asn1"
 */

#ifndef	_Ativo_H_
#define	_Ativo_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Publish.h"
#include "Subscriber.h"
#include "Notify.h"
#include "Unsubscriber.h"
#include <constr_CHOICE.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum id_PR {
	id_PR_NOTHING,	/* No components present */
	id_PR_publish,
	id_PR_subscriber,
	id_PR_notify,
	id_PR_unsubscriber
} id_PR;

/* Ativo */
typedef struct Ativo {
	struct id {
		id_PR present;
		union Ativo__id_u {
			Publish_t	 publish;
			Subscriber_t	 subscriber;
			Notify_t	 notify;
			Unsubscriber_t	 unsubscriber;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} id;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Ativo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Ativo;

#ifdef __cplusplus
}
#endif

#endif	/* _Ativo_H_ */
#include <asn_internal.h>
