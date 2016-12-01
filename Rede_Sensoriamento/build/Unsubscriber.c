/*
 * Generated by asn1c-0.9.27 (http://lionet.info/asn1c)
 * From ASN.1 module "Ativo"
 * 	found in "../Ativo.asn1"
 */

#include "Unsubscriber.h"

static asn_TYPE_member_t asn_MBR_Unsubscriber_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct Unsubscriber, hierarchy),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OBJECT_IDENTIFIER,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"hierarchy"
		},
};
static ber_tlv_tag_t asn_DEF_Unsubscriber_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_Unsubscriber_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* hierarchy */
};
static asn_SEQUENCE_specifics_t asn_SPC_Unsubscriber_specs_1 = {
	sizeof(struct Unsubscriber),
	offsetof(struct Unsubscriber, _asn_ctx),
	asn_MAP_Unsubscriber_tag2el_1,
	1,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_Unsubscriber = {
	"Unsubscriber",
	"Unsubscriber",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_Unsubscriber_tags_1,
	sizeof(asn_DEF_Unsubscriber_tags_1)
		/sizeof(asn_DEF_Unsubscriber_tags_1[0]), /* 1 */
	asn_DEF_Unsubscriber_tags_1,	/* Same as above */
	sizeof(asn_DEF_Unsubscriber_tags_1)
		/sizeof(asn_DEF_Unsubscriber_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_Unsubscriber_1,
	1,	/* Elements count */
	&asn_SPC_Unsubscriber_specs_1	/* Additional specs */
};

