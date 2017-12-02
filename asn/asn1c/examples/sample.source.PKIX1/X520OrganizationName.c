/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "PKIX1Explicit88"
 * 	found in "../rfc3280-PKIX1Explicit88.asn1"
 * 	`asn1c -S ../../skeletons -pdu=Certificate -fcompound-names -fwide-types`
 */

#include "X520OrganizationName.h"

static const int permitted_alphabet_table_3[256] = {
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/*                  */
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	/*                  */
 1, 0, 0, 0, 0, 0, 0, 2, 3, 4, 0, 5, 6, 7, 8, 9,	/* .      '() +,-./ */
10,11,12,13,14,15,16,17,18,19,20, 0, 0,21, 0,22,	/* 0123456789:  = ? */
 0,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,	/*  ABCDEFGHIJKLMNO */
38,39,40,41,42,43,44,45,46,47,48, 0, 0, 0, 0, 0,	/* PQRSTUVWXYZ      */
 0,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,	/*  abcdefghijklmno */
64,65,66,67,68,69,70,71,72,73,74, 0, 0, 0, 0, 0,	/* pqrstuvwxyz      */
};
static const int permitted_alphabet_code2value_3[74] = {
32,39,40,41,43,44,45,46,47,48,49,50,51,52,53,54,
55,56,57,58,61,63,65,66,67,68,69,70,71,72,73,74,
75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,
97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,
113,114,115,116,117,118,119,120,121,122,};


static int check_permitted_alphabet_3(const void *sptr) {
	const int *table = permitted_alphabet_table_3;
	/* The underlying type is PrintableString */
	const PrintableString_t *st = (const PrintableString_t *)sptr;
	const uint8_t *ch = st->buf;
	const uint8_t *end = ch + st->size;
	
	for(; ch < end; ch++) {
		uint8_t cv = *ch;
		if(!table[cv]) return -1;
	}
	return 0;
}

static int check_permitted_alphabet_4(const void *sptr) {
	/* The underlying type is UniversalString */
	const UniversalString_t *st = (const UniversalString_t *)sptr;
	const uint8_t *ch = st->buf;
	const uint8_t *end = ch + st->size;
	
	if(st->size % 4) return -1; /* (size%4)! */
	for(; ch < end; ch += 4) {
		uint32_t cv = (ch[0] << 24)
				| (ch[1] << 16)
				| (ch[2] << 8)
				|  ch[3];
		(void)cv; /* Unused variable */
	}
	return 0;
}

static int check_permitted_alphabet_6(const void *sptr) {
	/* The underlying type is BMPString */
	const BMPString_t *st = (const BMPString_t *)sptr;
	const uint8_t *ch = st->buf;
	const uint8_t *end = ch + st->size;
	
	if(st->size % 2) return -1; /* (size%2)! */
	for(; ch < end; ch += 2) {
		uint16_t cv = (ch[0] << 8)
				| ch[1];
		if(!(cv <= 65533)) return -1;
	}
	return 0;
}

static int
memb_teletexString_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const TeletexString_t *st = (const TeletexString_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	size = st->size;
	
	if((size >= 1 && size <= 64)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_printableString_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const PrintableString_t *st = (const PrintableString_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	size = st->size;
	
	if((size >= 1 && size <= 64)
		 && !check_permitted_alphabet_3(st)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int asn_PER_MAP_printableString_3_v2c(unsigned int value) {
	if(value >= sizeof(permitted_alphabet_table_3)/sizeof(permitted_alphabet_table_3[0]))
		return -1;
	return permitted_alphabet_table_3[value] - 1;
}
static int asn_PER_MAP_printableString_3_c2v(unsigned int code) {
	if(code >= sizeof(permitted_alphabet_code2value_3)/sizeof(permitted_alphabet_code2value_3[0]))
		return -1;
	return permitted_alphabet_code2value_3[code];
}
static int
memb_universalString_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const UniversalString_t *st = (const UniversalString_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	size = st->size >> 2;	/* 4 byte per character */
	
	if((size >= 1 && size <= 64)
		 && !check_permitted_alphabet_4(st)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_utf8String_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const UTF8String_t *st = (const UTF8String_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	size = UTF8String_length(st);
	if((ssize_t)size < 0) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: UTF-8: broken encoding (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	if((size >= 1 && size <= 64)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_bmpString_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const BMPString_t *st = (const BMPString_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	size = st->size >> 1;	/* 2 byte per character */
	
	if((size >= 1 && size <= 64)
		 && !check_permitted_alphabet_6(st)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_oer_constraints_t asn_OER_memb_teletexString_constr_2 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(0..MAX)) */};
static asn_per_constraints_t asn_PER_memb_teletexString_constr_2 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_printableString_constr_3 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..64)) */};
static asn_per_constraints_t asn_PER_memb_printableString_constr_3 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 7,  7,  32,  122 }	/* (32..122) */,
	{ APC_CONSTRAINED,	 6,  6,  1,  64 }	/* (SIZE(1..64)) */,
	asn_PER_MAP_printableString_3_v2c,	/* Value to PER code map */
	asn_PER_MAP_printableString_3_c2v	/* PER code to value map */
};
static asn_oer_constraints_t asn_OER_memb_universalString_constr_4 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..64)) */};
static asn_per_constraints_t asn_PER_memb_universalString_constr_4 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 32,  32,  0,  2147483647 }	/* (0..4294967295) */,
	{ APC_CONSTRAINED,	 6,  6,  1,  64 }	/* (SIZE(1..64)) */,
	0, 0	/* No PER character map necessary */
};
static asn_oer_constraints_t asn_OER_memb_utf8String_constr_5 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(0..MAX)) */};
static asn_per_constraints_t asn_PER_memb_utf8String_constr_5 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_bmpString_constr_6 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..64)) */};
static asn_per_constraints_t asn_PER_memb_bmpString_constr_6 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 16,  16,  0,  65533 }	/* (0..65533) */,
	{ APC_CONSTRAINED,	 6,  6,  1,  64 }	/* (SIZE(1..64)) */,
	0, 0	/* No PER character map necessary */
};
static asn_oer_constraints_t asn_OER_type_X520OrganizationName_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_type_X520OrganizationName_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 3,  3,  0,  4 }	/* (0..4) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_X520OrganizationName_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct X520OrganizationName, choice.teletexString),
		(ASN_TAG_CLASS_UNIVERSAL | (20 << 2)),
		0,
		&asn_DEF_TeletexString,
		0,
		{ &asn_OER_memb_teletexString_constr_2, &asn_PER_memb_teletexString_constr_2,  memb_teletexString_constraint_1 },
		0, 0, /* No default value */
		"teletexString"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct X520OrganizationName, choice.printableString),
		(ASN_TAG_CLASS_UNIVERSAL | (19 << 2)),
		0,
		&asn_DEF_PrintableString,
		0,
		{ &asn_OER_memb_printableString_constr_3, &asn_PER_memb_printableString_constr_3,  memb_printableString_constraint_1 },
		0, 0, /* No default value */
		"printableString"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct X520OrganizationName, choice.universalString),
		(ASN_TAG_CLASS_UNIVERSAL | (28 << 2)),
		0,
		&asn_DEF_UniversalString,
		0,
		{ &asn_OER_memb_universalString_constr_4, &asn_PER_memb_universalString_constr_4,  memb_universalString_constraint_1 },
		0, 0, /* No default value */
		"universalString"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct X520OrganizationName, choice.utf8String),
		(ASN_TAG_CLASS_UNIVERSAL | (12 << 2)),
		0,
		&asn_DEF_UTF8String,
		0,
		{ &asn_OER_memb_utf8String_constr_5, &asn_PER_memb_utf8String_constr_5,  memb_utf8String_constraint_1 },
		0, 0, /* No default value */
		"utf8String"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct X520OrganizationName, choice.bmpString),
		(ASN_TAG_CLASS_UNIVERSAL | (30 << 2)),
		0,
		&asn_DEF_BMPString,
		0,
		{ &asn_OER_memb_bmpString_constr_6, &asn_PER_memb_bmpString_constr_6,  memb_bmpString_constraint_1 },
		0, 0, /* No default value */
		"bmpString"
		},
};
static const unsigned asn_MAP_X520OrganizationName_to_canonical_1[] = { 3, 1, 0, 2, 4 };
static const unsigned asn_MAP_X520OrganizationName_from_canonical_1[] = { 2, 1, 3, 0, 4 };
static const asn_TYPE_tag2member_t asn_MAP_X520OrganizationName_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (12 << 2)), 3, 0, 0 }, /* utf8String */
    { (ASN_TAG_CLASS_UNIVERSAL | (19 << 2)), 1, 0, 0 }, /* printableString */
    { (ASN_TAG_CLASS_UNIVERSAL | (20 << 2)), 0, 0, 0 }, /* teletexString */
    { (ASN_TAG_CLASS_UNIVERSAL | (28 << 2)), 2, 0, 0 }, /* universalString */
    { (ASN_TAG_CLASS_UNIVERSAL | (30 << 2)), 4, 0, 0 } /* bmpString */
};
static asn_CHOICE_specifics_t asn_SPC_X520OrganizationName_specs_1 = {
	sizeof(struct X520OrganizationName),
	offsetof(struct X520OrganizationName, _asn_ctx),
	offsetof(struct X520OrganizationName, present),
	sizeof(((struct X520OrganizationName *)0)->present),
	asn_MAP_X520OrganizationName_tag2el_1,
	5,	/* Count of tags in the map */
	asn_MAP_X520OrganizationName_to_canonical_1,
	asn_MAP_X520OrganizationName_from_canonical_1,
	-1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_X520OrganizationName = {
	"X520OrganizationName",
	"X520OrganizationName",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ &asn_OER_type_X520OrganizationName_constr_1, &asn_PER_type_X520OrganizationName_constr_1, CHOICE_constraint },
	asn_MBR_X520OrganizationName_1,
	5,	/* Elements count */
	&asn_SPC_X520OrganizationName_specs_1	/* Additional specs */
};
