/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "TAP-0310"
 * 	found in "../tap3.asn1"
 * 	`asn1c -S ../../skeletons`
 */

#ifndef	_HSCSDParameterModification_H_
#define	_HSCSDParameterModification_H_


#include <asn_application.h>

/* Including external dependencies */
#include "AiurRequested.h"
#include "NumberOfChannels.h"
#include "ChannelCoding.h"
#include "NumberOfChannelsUsed.h"
#include "InitiatingParty.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct DateTime;

/* HSCSDParameterModification */
typedef struct HSCSDParameterModification {
	AiurRequested_t	*aiur	/* OPTIONAL */;
	NumberOfChannels_t	*maxNumberOfChannels	/* OPTIONAL */;
	ChannelCoding_t	*channelCodingUsed	/* OPTIONAL */;
	NumberOfChannelsUsed_t	*numberOfChannelsUsed	/* OPTIONAL */;
	InitiatingParty_t	*initiatingParty	/* OPTIONAL */;
	struct DateTime	*modificationTimestamp	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} HSCSDParameterModification_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_HSCSDParameterModification;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ModificationTimestamp.h"

#endif	/* _HSCSDParameterModification_H_ */
#include <asn_internal.h>